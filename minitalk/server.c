/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:23:11 by abelfany          #+#    #+#             */
/*   Updated: 2023/01/08 21:50:03 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_strlen(char *str)
{
    int x;

    x = 0;
    while(str[x])
        x++;
    return (x);
}
void handler(int num)
{
    (void)num;
    write(STDOUT_FILENO, "fuck you \n", 10);
    // exit(0);
}
int main()
{
    int pid = getpid();
   // signal(SIGINT, handler);
    ft_putnbr(pid);
    write(1, "\n", 1);
    signal(SIGTERM, handler);
    while(1)
    {
        sleep(1);
        // pause();
    }
}