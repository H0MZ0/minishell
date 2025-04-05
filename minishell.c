/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:49:04 by hakader           #+#    #+#             */
/*   Updated: 2025/04/05 11:13:51 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	char *str;
	(void)envp;
	(void)av;
	if (ac > 1)
		put_error("Error:\nJust run it\n");
	for(int i = 5; envp[18][i]; i++)
		printf("%c", envp[18][i]);
	printf("\n");
	// char *path = &envp[18][5];
	// printf("%s", path);
	// printf("\n");
	char *argu[] = {"/bin/ls", NULL};
	while (1)
	{
		str = readline("");
		if (str == NULL)
			break ;
		if (strcmp(str, "ls") == 0)
			execve("/bin/ls", argu, envp);
		printf("%s\n", str);
	}
	// for (int i = 0; av[i]; i++)
	// 	printf("%s\n", av[i]);
}
