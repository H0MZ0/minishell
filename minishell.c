/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:49:04 by hakader           #+#    #+#             */
/*   Updated: 2025/04/09 10:08:39 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	char *str;
	char *srch;
	int i = 0;
	char **path;

	char *path_env = getenv("PATH");
	if (!path_env)
		return (printf("Error:\nPATH not found\n"), 1);
	path = ft_split(path_env, ':');
	while (1)
	{
		str = readline("minishell$ ");
		if (str == NULL)
			break;
		i = 0;
		int found = 0;
		while (path[i] != NULL)
		{
			if (ft_strcmp(str, "exit") == 0)
				exit (0);
			srch = ft_strjoin(path[i], str);
			if (access(srch, X_OK) == 0)
			{
				pid_t pid = fork();
				if (pid == 0)
				{
					if (execve(srch, av, envp) == -1)
					{
						perror("execve");
						exit(1);
					}
				}
				else if (pid > 0)
				{
					int status;
					waitpid(pid, &status, 0);
				}
				else
					perror("fork");
				free(srch);
				found = 1;
				break;
			}
			free(srch);
			i++;
		}
		if (!found)
			printf("%s: command not found\n", str);
		free(str);
	}
	free_arr(path);
	return (0);
}

