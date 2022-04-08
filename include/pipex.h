/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:09:51 by wchae             #+#    #+#             */
/*   Updated: 2022/04/08 15:18:25 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"

# define READ_END	0
# define WRITE_END	1

void	error(void);
int		open_file(char *argv, int i);
void	execute_command(char *argv, char **envp);

#endif