/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:56:23 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/19 19:21:34 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_paths(char **envp)
{
	int		i;
	char	*path;
	char	**all_path;

	i = 0;
	while (envp[i] && (ft_strnstr(envp[i], "PATH", 5) == NULL))
		i++;
	if (envp[i] == NULL)
	{
		ft_printf("(Error) PATH not found\n");
		exit(EXIT_FAILURE);
	}
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	all_path = ft_split(path, ':');
	free(path);
	return (all_path);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	paths = find_paths(envp);
	check_args(argc);
	check_files(argv);
	pipex(argv, paths, envp);
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	return (0);
}
