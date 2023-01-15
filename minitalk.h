/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:38:53 by abelfany          #+#    #+#             */
/*   Updated: 2023/01/13 19:10:59 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <signal.h>

char        *ft_itoa(int n);
long long   ft_atoi(const char *str);
void        ft_putnbr(int nb);
void        convert(unsigned int c, int pid);
int	        _power(int nb, int power);