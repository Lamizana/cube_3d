/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:48:02 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/19 11:41:11 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# include "../libft.h"

int		ft_toupper(int c);
int		ft_tolower(int c);
long	ft_atoi(const char *str);
int		ft_atoi_color(char *str);
char	*ft_itoa(int n);

#endif
