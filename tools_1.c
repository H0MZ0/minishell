/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:58:34 by hakader           #+#    #+#             */
/*   Updated: 2025/04/07 16:15:21 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	put_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	size_t	i;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	src = (char *)s + start;
	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		*str = *src;
		str++;
		src++;
		i++;
	}
	*str = '\0';
	str = str - i;
	return (str);
}

void	free_arr(char **str)
{
	int	i;

	i = 0;
	if (!str || !(*str))
		return ;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	if (!str1 || !str2)
		return (1);
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
