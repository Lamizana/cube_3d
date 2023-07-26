/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:57:44 by nminotte          #+#    #+#             */
/*   Updated: 2022/11/30 17:00:46 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

# include "../libft.h"

char	*ft_strjoin_free(char *s1, char *s2);
char	*get_next_line(int fd);
char	*get_line_stdin(int fd);
int		ft_strlnn(char *src);

#endif
