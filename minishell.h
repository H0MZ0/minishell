/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:49:02 by hakader           #+#    #+#             */
/*   Updated: 2025/04/05 12:59:32 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

//TOOLS
size_t  ft_strlen(const char *str);
void    put_error(char *msg);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	**ft_strcpy(char **dest, char *src);

//SPLIT
char	**ft_split(char const *s, char c);

//strjoin
char	*ft_strjoin(char const *s1, char const *s2);

#endif
