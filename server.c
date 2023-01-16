/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:23:11 by abelfany          #+#    #+#             */
/*   Updated: 2023/01/16 15:23:36 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
qwdqwdq
#include<stdio.h>
 akjsdlaksjlaksjdlaksjdlaksdj
int	_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * _power(nb, power - 1));
}

int ft_strlen(char *str)
{
    int x;

    x = 0;
    while(str[x])
        x++;
    return (x);
}
// void handler(int num)
// {
//     static int a;
//     static unsigned char st;

//     if (a == 0)
//         a = 1;
//     // x++;
//     // printf("%d\n", a);
//     if(num == SIGUSR2)
//         st += a;
//     a *= 2;
//     if(a == 256)
//     {
//         if(st == 0)
//             write(1, "\n", 1);
//         write(1, &st, 1);
//         a = 1;
//         st = 0;
//     }
        
// }
void resend_ok()
{
    
}

void handler(int num, siginfo_t *info)
{
    static int pid;
    static int a;
    static unsigned char st;
    if (info->si_pid != pid)
    {
        pid = info->si_pid;
        a = 0;
        st = 0;
    }
    st = st + ((num - 30)* _power(2, a));
    a++;
    if(a == 8)
    {
        if(st == 0)
        {
            write(1, "\n", 1);
            resend_ok();
        }
        write(1, &st, 1);
        a = 0;
        st = 0;
    }
}
int main()
{
    struct sigaction sig;
    int pid = getpid();
   // signal(SIGINT, handler);
    ft_putnbr(pid);
    // write(1, "\n", 1);
    sig.sa_handler=(void *)handler;
    sig.sa_flags = SA_SIGINFO;
    // signal(SIGTERM, handler);
    while(1)
    {
        // sleep(1);
        sigaction(SIGUSR1,&sig,NULL);
        sigaction(SIGUSR2,&sig,NULL);
        pause();
    }
}
