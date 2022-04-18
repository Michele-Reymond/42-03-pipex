/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:34:17 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/18 15:10:49 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int argc, char **argv)
{
	(void) argv;
	if (argc > 5)
	{
		ft_printf("(Error) Too much arguments\n");
		exit(EXIT_FAILURE);
	}
	else if (argc < 5)
	{
		ft_printf("(Error) Too few arguments\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	check_files(char **argv)
{
	if (access(argv[1], F_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}	
	if (access(argv[4], F_OK) != 0)
		open ("outfile", O_CREAT, 0644);
	if (access(argv[4], W_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[4]);
		exit(EXIT_FAILURE);
	}
}
