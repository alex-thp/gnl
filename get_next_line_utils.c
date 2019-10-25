/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:59:00 by ade-temm          #+#    #+#             */
/*   Updated: 2019/10/25 15:16:02 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(result = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	free((void*)s1);
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(result = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_result(t_list *lst)
{
	int		i;
	char	*result;
	
	i = 0;
	while (lst->result[i] != '\n' && lst->result[i])
		i++;
	if (!(result = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (lst->result[i] != '\n' && lst->result[i])
	{
		result[i] = lst->result[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int		is_n(char *buff)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_next(char *ret)
{
	int		i;
	int		j;
	char	*result;

	j = is_n(ret);
	if (ret[j] == '\n')
		j++;
	i = ft_strlen(&ret[j]);
	if (!(result = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (ret[j + i])
	{
		result[i] = ret[j + i];
		i++;
	}
	result[i] = '\0';
	free(ret);
	return (&result[0]);
}
