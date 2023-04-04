#include "minishell.h"

void ft_export(t_parsed *lexe, t_export **export)
{
    int i = 1;
    t_export *tmp;

    if(strcmp(lexe->args[0], "export") == 0 && lexe->args[1] == NULL)
        show_export(export, lexe);
    else
    {
        check_valide_args_for_export(lexe->args);
        while(lexe->args[i])
        {
            if(arg_exist(str_befor_equal(lexe->args[i], 1), export))
            {
                if(there_is_plus_equal(lexe->args[i]))
                {
                    ft_join_value(export, lexe->args[i]);
                }
                else
                {
                    ft_lst_delete_node_export(export, str_befor_equal(lexe->args[i], 1));
                    ft_lstadd_back_texport(export, ft_lstnew_texport());
                    tmp = *export;
                    while(tmp->next)
                        tmp = tmp->next;
                    tmp->there_is_equal = check_char_is_exist(lexe->args[i]);
                    tmp->variable = str_befor_equal(lexe->args[i], tmp->there_is_equal);
                    tmp->value = str_after_equal(lexe->args[i], tmp->there_is_equal);
                }
            }
            else
            {
                ft_lstadd_back_texport(export, ft_lstnew_texport());
                tmp = *export;
                while(tmp->next)
                    tmp = tmp->next;
                tmp->there_is_equal = check_char_is_exist(lexe->args[i]);
                tmp->variable = str_befor_equal(lexe->args[i], tmp->there_is_equal);
                tmp->value = str_after_equal(lexe->args[i], tmp->there_is_equal);
            }
            i++;
        }
    }
}

int there_is_plus_equal(char *str)
{
    int i = 0;
    while(str[i + 1])
    {
        if(str[i] == '+' && str[i + 1] == '=')
        {
            return 1;
        }
        i++;
    }
    return 0;
}

void ft_join_value(t_export **export, char *str)
{
    t_export *tmp = (*export);
    while(tmp && strcmp(tmp->variable, str_befor_equal(str, 1)) != 0)
    {
        tmp = tmp->next;
    }
    tmp->value = ft_strjoin(tmp->value, str_after_equal(str, 1));
}

int arg_exist(char *str, t_export **export)
{
    t_export *tmp = (*export);
    while(tmp && strcmp(tmp->variable, str) != 0)
    {
        tmp = tmp->next;
    }
    if(!tmp)
        return 0;
    return 1;
}

void check_valide_args_for_export(char **strs)
{
    int i = 1;
    int j = 0;
    while(strs[i])
    {
        j = 0;
        while(strs[i][j] && strs[i][j] != '=')
        {

            if(strs[i][j] &&((strs[i][j] >= 'a' && strs[i][j] <= 'z') || (strs[i][j] >= 'A' && strs[i][j] <= 'Z') || strs[i][j] == '_' || strs[i][j] == '+'))
            {
                j++;
            }
            else
            {
                write(1, "error\n", 6);
                exit(1);
            }
        }
        i++;
    }
}

void show_export(t_export **export, t_parsed *lexe)
{
    t_export *tmp = (*export);
    while(tmp)
    {
        if(tmp->there_is_equal == 0)
        {
            ft_putstr_fd("declare -x " , lexe->out);
            ft_putstr_fd(tmp->variable , lexe->out);
            write(lexe->out, "\n", 1);
        }
        else if (tmp->there_is_equal == 1 && tmp->value == NULL)
        {
            ft_putstr_fd("declare -x " , lexe->out);
            ft_putstr_fd(tmp->variable , lexe->out);
            write(lexe->out, "=\"\"",4);
            write(lexe->out, "\n", 1);

        }
        else
        {
            ft_putstr_fd("declare -x " , lexe->out);
            ft_putstr_fd(tmp->variable , lexe->out);
            ft_putstr_fd("=" , lexe->out);
            ft_putstr_fd("\"" , lexe->out);
            ft_putstr_fd(tmp->value , lexe->out);
            ft_putstr_fd("\"" , lexe->out);
            write(lexe->out, "\n", 1);
        } 
        tmp = tmp->next;
    }
}