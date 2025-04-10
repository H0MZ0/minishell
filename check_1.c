/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:23:55 by hakader           #+#    #+#             */
/*   Updated: 2025/04/10 14:13:47 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo") ||
		!ft_strcmp(cmd, "cd") ||
		!ft_strcmp(cmd, "pwd") ||
		!ft_strcmp(cmd, "export") ||
		!ft_strcmp(cmd, "unset") ||
		!ft_strcmp(cmd, "env") ||
		!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}
