#include "minishell.h"

void ft_lst_delete_node_export(t_export **export, char *str)
{
    t_export *node_to_delete = (*export);
    t_export *previous_node = (*export);
    int check = 0;
    while(node_to_delete && strcmp(node_to_delete->variable, str) != 0)
    {
        if(check != 0)
            previous_node = previous_node->next;
        check = 1;
        node_to_delete = node_to_delete->next;
    }
    if(node_to_delete && node_to_delete->next)
        previous_node->next = node_to_delete->next;
    node_to_delete = NULL;
}


int main(int ac, char **av, char **env)
{
    t_parsed    *lexe;
    lexe = malloc(sizeof(t_parsed));
    lexe->in = 0;
    lexe->out = 1;
    lexe->args = malloc(6 * sizeof(lexe->args));
    lexe->args[0] = ft_strdup("pwd");
    lexe->args[1] = NULL;
    lexe->args[2] = NULL;
    lexe->args[3] = ft_strdup("vc");
    lexe->args[4] = ft_strdup("vv");
    lexe->args[5] = NULL;
    lexe->envs = env;
    lexe->next = NULL;
    ft_execution(lexe);
    exit(1);
    t_export *export;
    export = malloc(sizeof(t_export));
    fill_export_with_env(export, lexe);
    // ft_export(lexe, &export);
    ft_unset(lexe, &export);
    show_env(&export, lexe);

    // lexe->args[3] = ft_strdup("cd");
    // lexe->args[4] = ft_strdup("cd");
    // lexe->args[5] = ft_strdup("cd");
    // lexe->args[6] = NULL;
    lexe->next = NULL;
    ft_cd(lexe);
}