/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:53:32 by ade-temm          #+#    #+#             */
/*   Updated: 2019/10/25 16:59:19 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1

t_list	*ft_lstnew(int fd, char *result, t_list *next)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->result = result;
	new->next = next;
	return (new);
}

int				get_next_line(int fd, char **line)
{
	int				r;
	char			*buff;
	static t_list	*lst = NULL;

	if (!(lst))
		lst = ft_lstnew(fd, NULL, NULL);
	r = 1;
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	buff[0] = '\0';
	buff[BUFFER_SIZE] = '\0';
	while (r && is_n(buff) == -1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			return (-1);
		buff[r] = '\0';
		if (lst->result)
			lst->result = ft_strjoin(lst->result, buff);
		else
			lst->result = ft_strdup(buff);
	}
	*line = ft_result(lst);
	lst->result = ft_next(lst->result);
	free(buff);
	if (ft_strlen(lst->result) > 0)
		return (1);
	return (0);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int				main(void)
{
	int		fd;
	char	**line;
	int		i;

	fd = open("get_next_line.c", O_RDWR);
	i = 0;
	while (i < 81)
	{
		printf("%d", get_next_line(fd, line));
		printf("%s\n", *line);
		free(*line);
		i++;
	}
}
