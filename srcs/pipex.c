/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:13:03 by wchae             #+#    #+#             */
/*   Updated: 2022/04/08 15:36:51 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_handle(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Use ./pipex file1 cmd1 cmd2 file2\n", 1);
	exit(0);
}

void	child_process(char **argv, char **envp, int *pipe_fd)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY | O_CLOEXEC, 0777);
	if (file_in == -1)
		error();
	dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
	close(pipe_fd[WRITE_END]);
	dup2(file_in, STDIN_FILENO);
	close(pipe_fd[READ_END]);
	close(file_in);
	execute_command(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *pipe_fd)
{
	int		file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_CLOEXEC, 0777);
	if (file_out == -1)
		error();
	dup2(pipe_fd[READ_END], STDIN_FILENO);
	close(pipe_fd[READ_END]);
	dup2(file_out, STDOUT_FILENO);
	close(pipe_fd[WRITE_END]);
	close(file_out);
	execute_command(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(argv, envp, pipe_fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, pipe_fd);
	}
	else
		error_handle();
	return (0);
}
