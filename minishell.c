/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:49:04 by hakader           #+#    #+#             */
/*   Updated: 2025/04/10 14:19:22 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_cmd(char **paths, char *cmd)
{
	char	*command;
	int		i;

	if (!cmd || !paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		command = ft_strjoin(paths[i], "/");
		command = ft_strjoin(command, cmd);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	char	**paths = ft_split(getenv("PATH"), ':');
	while (1)
	{
		char	*cmd = readline("minishell$ ");
		// printf("%s\n", cmd);
		char *path_cmd = check_cmd(paths, cmd);
		int	pid = fork();
		if (pid == 0)
		{
			if (path_cmd)
			{
				char	*path[] = {path_cmd, NULL};
				execve(path_cmd, path, envp);
			}
			else
				printf("command not foud: %s\n", cmd);
		}
		else
			waitpid(pid, NULL, 0);
	}
	return (0);
}
