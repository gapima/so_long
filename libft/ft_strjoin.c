/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:41:49 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/12 09:21:12 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;
	int		count;

	if (s1 == NULL)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	count = -1;
	while (s1[++count] != '\0')
		dest[count] = s1[count];
	count = -1;
	while (s2[++count] != '\0')
		dest[count + s1_len] = s2[count];
	dest[count + s1_len] = '\0';
	free(s1);
	return (dest);
}
