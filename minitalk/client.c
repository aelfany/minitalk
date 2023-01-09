/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:23:07 by abelfany          #+#    #+#             */
/*   Updated: 2023/01/09 21:01:43 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * _power(nb, power - 1));
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	swp;

	a = 0;
	b = size -1;
	while (a < size)
	{
		if (a < b)
		{
			swp = tab[a];
			tab[a] = tab[b];
			tab[b] = swp;
		}
		a++;
		b--;
	}
}

// void rev(int *tab)
// {
    
// }

void convert(int c, int pid)
{
    int a;
    int collect;
    int tab[8];
    pid = 0;
    a = 0;
    collect = 0;
    while(a < 8)
    {
        tab[a] = c % 2;
        c = c / 2;
        a++;
    }
    // ft_rev_int_tab(tab, 8);
    a = 0;
    while(a < 8)
        printf("%d", tab[a++]);
        printf("----------\n");
    a = 0;
    while(a < 7)
    {
        if(tab[a] != 0)
        {
            printf("-> %d\n", collect);
            collect = collect + (tab[a] * _power(2, a));
            collect *= 10;
            printf("--> %d\n", a);
        }
        a++;
    }
    printf("%d", collect);
}
// void HANDLER()
// {
//     printf("fuck you\n");
// }
int main(int ac , char **av)
{
    int pid;
    char *str;

    str = av[2];
    pid = ft_atoi(av[1]);
    //kill(pid, SIGUSR1); 
    if (ac == 3)
    {
        while (*str)
        {
            convert(*str, pid);
            str++;
        }
    }
}