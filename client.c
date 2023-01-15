/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:23:07 by abelfany          #+#    #+#             */
/*   Updated: 2023/01/13 19:10:50 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// int	_power(int nb, int power)
// {
// 	if (power < 0)
// 		return (0);
// 	if (power == 0)
// 		return (1);
// 	return (nb * _power(nb, power - 1));
// }

// void	ft_rev_int_tab(int *tab, int size)
// {
// 	int	a;
// 	int	b;
// 	int	swp;

// 	a = 0;
// 	b = size -1;
// 	while (a < size)
// 	{
// 		if (a < b)
// 		{
// 			swp = tab[a];
// 			tab[a] = tab[b];
// 			tab[b] = swp;
// 		}
// 		a++;
// 		b--;
// 	}
// }

// void rev(int *tab)
// {
    
// }

void convert(unsigned int c, int pid)
{
    int a;
    int collect;
    int tab[8];
    // pid = 0;
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
    {
        usleep(100);
        if(tab[a] == 0)
            kill(pid, SIGUSR1);
        if(tab[a] == 1)
            kill(pid, SIGUSR2);
        a++;
    }
    // a = 0;
    // while(a < 8)
    //     printf("%d", tab[a++]);
    //  printf("----------\n");   
    // a = 0;
    // while(a < 8)
    // {
    //     collect = collect + (tab[a] * _power(2, a));
    //     a++;
    // }
    // printf("%d", collect);
}
// void HANDLER()
// {
//     printf("fuck you\n");
// }
int main(int ac , char **av)
{
    int pid;
    char *str;

    //kill(pid, SIGUSR1); 
    if (ac == 3)
    {
        str = av[2];
        pid = ft_atoi(av[1]);
        while (*str)
        {
            convert(*str, pid);
            str++;
        }
        convert(0, pid);
    }
}