/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:49:04 by hakader           #+#    #+#             */
/*   Updated: 2025/04/10 17:17:28 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	dest = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**aloc(char *cmd1, char *cmd2, char *cmd3, char *cmd4)
{
	char	**commad;

	if (!cmd1 || !cmd2 || !cmd3 || !cmd4)
		return (NULL);
	commad = malloc(sizeof(char *) * 5);
	if (!commad)
		return (NULL);
	commad[0] = ft_strdup(cmd1);
	commad[1] = ft_strdup(cmd2);
	commad[2] = ft_strdup(cmd3);
	commad[3] = ft_strdup(cmd4);
	commad[4] = NULL;
	return (commad);
}


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
	// char	**paths = ft_split(getenv("PATH"), ':');
	// while (1)
	// {
	// 	char	*cmd = readline("minishell$ ");
	// 	// printf("%s\n", cmd);
	// 	char *path_cmd = check_cmd(paths, cmd);
	// 	int	pid = fork();
	// 	if (pid == 0)
	// 	{
	// 		if (path_cmd)
	// 		{
	// 			char	*path[] = {path_cmd, NULL};
	// 			execve(path_cmd, path, envp);
	// 		}
	// 		else
	// 			printf("command not foud: %s\n", cmd);
	// 	}
	// 	else
	// 		waitpid(pid, NULL, 0);
	// }
	t_cmd	cmd;

	cmd.command = aloc("hello", "how", "are", "you");
	for (int i = 0; cmd.command[i]; i++)
		printf("%s\n", cmd.command[i]);
	cmd.next->command = aloc("hello1", "how1", "are1", "you1");
	for (int i = 0; cmd.next->command[i]; i++)
		printf("%s\n", cmd.next->command[i]);
	// free_arr(cmd.command);
	// free_arr(cmd.next->command);
	return (0);
}
