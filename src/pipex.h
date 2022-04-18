/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:00:15 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/18 15:32:52 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

void	pipex(char **argv, char **paths, char **envp);
void	first_child_process(char **argv, char **paths, int fd[], char **envp);
void	scd_child_process(char **argv, char **paths, int fd[], char **envp);
char	**find_paths(char **envp);
void	check_args(int argc);
void	check_files(char **argv);

#endif
