/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:22:45 by abelfany          #+#    #+#             */
/*   Updated: 2023/01/04 10:27:24 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	char	*ft_alloc(int x, char c)
{
	char	*str;

	if (c == '+')
	{
		str = malloc(x * sizeof(char) + 1);
		if (!(str))
			return (0);
		str[x] = '\0';
	}
	if (c == '-')
	{
		str = malloc(x * sizeof(char) + 2);
		if (!str)
			return (0);
		str[0] = '-';
		str[x + 1] = '\0';
	}
	return (str);
}

static	char	*re(char *str, int a, long int x)
{
	int	b;

	b = 0;
	if (x > 0)
	{
		str = ft_alloc(a, '+');
		if (!(str))
			return (0);
		b = -1;
	}
	if (x < 0)
	{
		str = ft_alloc(a, '-');
		if (!(str))
			return (0);
		x *= -1;
		a++;
	}
	while (--a > b)
	{
		str[a] = x % 10 + 48;
		x = x / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	x;
	long int	l;
	int			a;
	char		*str;

	x = n;
	a = 0;
	l = n;
	str = NULL;
	if (l == 0)
    {
        str = malloc(2);
        str[0] = '0';
        str[1] = '\0';
    }
	if (l < 0)
		l = l * -1;
	while (l > 0)
	{
		l = l / 10;
		a++;
	}
	str = re(str, a, x);
	return (str);
}