#include "minishell.h"

int ft_is_n(char *str)
{
    if(str[0] != '-')
        return 0;
    int i = 1;
    while(str[i] == 'n')
        i++;
    if(str[i])
        return 0;
    return 1;
}

void ft_echo(t_parsed *lexe)
{
    int is_n = 0 ;

    if(strcmp("echo", lexe->args[0]) != 0)
    {
        return ;
    }
    int i = 1;
    while(lexe->args[i])
    {
        if(ft_is_n(lexe->args[i]))
        {
            is_n = 1;
            i++;
        }
        else
            break;
    }
    int check = 0;
    while(lexe->args[i])
    {
        if(check != 0)
            write(lexe->out, " ", 1);
        ft_putstr_fd(lexe->args[i],lexe->out);
        i++;
        check = 1;
    }
    if(!is_n)
        write(lexe->out,"\n", 1);
}