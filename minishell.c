/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:49:04 by hakader           #+#    #+#             */
/*   Updated: 2025/04/05 16:05:35 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// char **split_path(char *path)
// {
//     int i = 0;
//     char **paths = NULL;
//     char *token = strtok(path, ":");

//     while (token != NULL)
//     {
//         paths = realloc(paths, sizeof(char *) * (i + 2));  // Allocate memory for one more element
//         paths[i] = strdup(token);  // Copy token into paths[i]
//         i++;
//         token = strtok(NULL, ":");
//     }

//     paths[i] = NULL;  // Null-terminate the array of paths
//     return paths;
// }

int main(int ac, char **av, char **envp)
{
	(void)ac;
	char *str;
	char *srch;
	int i = 0;
	char **path;

	char *path_env = getenv("PATH");
	if (!path_env)
	{
		printf("PATH not found in environment.\n");
		return 1;
	}
	path = ft_split(path_env, ':');
	// for (int i = 0; path[i]; i++)
	// 	printf("%s\n", path[i]);
	while (1)
	{
		str = readline("minishell$ ");
		if (str == NULL)
			break;
		i = 0;
		int found = 0;
		while (path[i] != NULL)
		{
			srch = ft_strjoin(path[i], str);
			if (access(srch, X_OK) == 0)
			{
				if (execve(srch, av, envp) == -1)
				{
					perror("execve");
				}
				free(srch);
				found = 1;
				break;
			}
			free(srch);
			i++;
		}
		if (!found)
			printf("command not found: %s\n", str);
		free(str);
	}
	for (i = 0; path[i] != NULL; i++)
		free(path[i]);
	free(path);

	return 0;
}

