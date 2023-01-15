/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:42:37 by abelfany          #+#    #+#             */
/*   Updated: 2023/01/06 11:47:46 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        nb *= -1;
        ft_putchar('-');
    }
    if(nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}