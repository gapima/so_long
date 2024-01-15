/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:42:20 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/12 08:42:29 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		count;

	if (s == NULL)
		return (NULL);
	count = -1;
	while (s[++count] != '\0')
		if (s[count] == (char)c)
			return (&s[count]);
	if ((char)c == '\0')
		return (&s[count]);
	return (NULL);
}
