/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:13:03 by wchae             #+#    #+#             */
/*   Updated: 2022/03/30 10:40:11 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_handle(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

void	child_process(char **argv, char **envp, int *fds)
{
	int fd;
	fd = open_file(argv[1], 2);
	dup2(fds[WRITE_END], STDOUT_FILENO);
	close(fds[WRITE_END]);
	dup2(fd, STDIN_FILENO);
	close(fds[READ_END]);
	close(fd);
	execute(argv[2], envp);
}

int		open_file(char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0777);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0777);
	else if (i == 2)
		fd = open (argv, O_RDONLY | O_CLOEXEC, 0777);
	if (fd == -1)
		error_handle();
	return (fd);
}

void	parent_process(char **argv, char **envp, int *fds)
{
	int		fileout;
	
	fileout = open_file(argv[4], 1);
	dup2(fds[READ_END], STDIN_FILENO);
	close(fds[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(fds[WRITE_END]);
	close(fileout);
	execute(argv[3], envp);
}

int		main(int argc, char **argv, char **envp)
{
	int	fds[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(fds) == -1)
			error_handle();
		pid = fork();
		if (pid == -1)
			error_handle();
		if (pid == 0)
			child_process(argv, envp, fds);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fds);
	}
	else
		arg_error(0);
	return (0);
}
