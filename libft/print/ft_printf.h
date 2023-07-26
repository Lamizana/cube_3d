/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:55:55 by nminotte          #+#    #+#             */
/*   Updated: 2022/10/18 20:14:04 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

int	ft_putstr_fd(char *s, int fd);
int	ft_putendl_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnbr_u(unsigned int n);
int	ft_putbase(unsigned long long n, char *base);
int	ft_putaddress(unsigned long long ptr);
int	ft_printf(const char *src, ...);

#endif
