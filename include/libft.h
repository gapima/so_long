/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapima <gapima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:44:18 by gapima            #+#    #+#             */
/*   Updated: 2024/01/15 17:03:40 by gapima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define UPPER_HEX "0123456789ABCDEF"
# define LOWER_HEX "0123456789abcdef"

int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
int		*ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
int		print_char(char c);
int		print_str(char *str);
int		print_ptr(unsigned long nbr, char *base);
int		print_nbr(int nbr, char *str, int index, int flag_check);
int		print_unint(unsigned int nbr);
int		print_hex(unsigned int nbr, char *str, int index, int hash_check);

#endif