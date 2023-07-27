/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:40:11 by nminotte          #+#    #+#             */
/*   Updated: 2023/07/27 13:42:42 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEST_H
# define FT_TEST_H

# include "../libft.h"

int	ft_isalnum(int c);
int	ft_isprint(int c);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_isalpha(int c);
int	ft_strcmp_str(char *s1, char *s2);
int	ft_char_in_set(char c, char *str);

#endif
