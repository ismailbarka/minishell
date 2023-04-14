/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:42:56 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 17:23:00 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_moves
{
	struct s_moves	*next;
	int				data;
}	t_moves;

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
	int				index;
}	t_stack;

typedef struct s_mins
{
	int		min1;
	int		min2;
	char	*str;
}	t_mins;

typedef struct s_chars
{
	char	**buff2d;
	char	*str;
	char	**strs;
}	t_chars;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_listsize(t_stack *list);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_back_one(t_moves **lst, t_moves *new);
t_stack	*ft_lstnew(int content);
t_moves	*ft_lstnew_one(int content);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	**ft_split(const char *s, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *s_a);
void	sa(t_stack **head, t_moves **m_c);
void	sb(t_stack **head, t_moves **m_c);
void	pb(t_stack **s_a, t_stack **s_b, t_moves **m_c);
void	pa(t_stack **s_a, t_stack **s_b, t_moves **m_c);
void	ra(t_stack **s_a, t_moves **m_c);
void	rb(t_stack **s_a, t_moves **m_c);
void	rra(t_stack **s_a, t_moves **m_c);
void	rrb(t_stack **s_a, t_moves **m_c);
void	sort_three(t_stack **s_a, t_moves **m_c);
void	sort_five(t_stack **s_a, t_stack **s_b, t_moves **m_c);
void	push_smaller(t_stack **s_a, t_stack **s_b, t_moves **m_c);
void	sort_two(t_stack **s_a, t_moves **m_c);
int		index_pos(int count, t_stack **s_a);
void	sort_hundred(t_stack **s_a, t_stack **s_b, t_moves **m_c);
int		ft_big_pos(t_stack **s_b);
void	ss(t_stack **s_a, t_stack **s_b, t_moves **m_c);
int		there_is_count(int count, t_stack **s_a);
int		ft_big_pos_one(t_stack **s_b);
void	sort_500(t_stack **s_a, t_stack **s_b, t_moves **m_c);
void	push_first_20(int count, t_stack **s_a, t_stack **s_b, t_moves **m_c);
void	rr(t_stack **s_a, t_stack **s_b, t_moves **m_c);
char	*ft_strdup(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin_one(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	check_empty_string(char **av);
void	ft_check_args(char **strs);
char	*ft_join_args(char **av);
void	ft_add_strs_to_list(char **strs, t_stack *list);
void	ft_indexlst(t_stack **s_a);
int		not_indexeed(t_stack **s_a);
void	check_duplicat(t_stack *s_a, int i);
void	ft_strcmp(int a, t_stack *s_a, int i);
void	sa_(t_stack **head);
void	ss_(t_stack **s_a, t_stack **s_b);
void	pa_(t_stack **s_a, t_stack **s_b);
void	ra_(t_stack **s_a);
void	rr_(t_stack **s_a, t_stack **s_b);
void	rra_(t_stack **s_a);
void	check_duplicat(t_stack *s_a, int i);
void	push_back_to_a(t_stack **s_a, t_stack **s_b, t_moves **m_c);
void	push_first_500(int count, t_stack **s_a, t_stack **s_b, t_moves **m_c);
int		finder(t_stack **stack, int pos);
int		highest_index(t_stack *stack);
void	push_back_to_a(t_stack **s_a, t_stack **s_b, t_moves **m_c);
int		there_is_count(int count, t_stack **s_a);
int		index_pos(int count, t_stack **s_a);
void	edit_s_b(int count, t_stack **s_b, t_moves **m_c);
void	push_first_20(int c, t_stack **s_a, t_stack **s_b, t_moves **moves_c);
int		minpos(int min, t_stack **s_a);
int		ft_big_pos_two(t_stack *temp, t_stack **s_b, int count, int bigger);
void	sort_hundred_one(t_stack **s_a, t_stack **s_b, t_moves **m_c, int c);
void	p_s_t(t_stack **s_a, t_mins min, t_moves **m_c);
void	p_s_o(t_stack **s_a, t_mins min, t_stack **s_b, t_moves **m_c);
int		str_cmpp(char *s1, char *s2);
int		check_word_one(char *str);
void	check_word(char *strs);
void	do_cmnds_one(t_stack *s_a, t_stack *stack_b, t_chars chars, int i);
void	do_cmnds(t_chars chars, int i, t_stack *s_a, t_stack *stack_b);
void	read_from_pipe_one(char *buff, char *new);
char	**read_from_pipe(void);
void	ok_ko(t_stack *s_a);
void	push_smaller_two(int *a, t_stack **b, t_stack **c, t_moves **d);
void	push_smaller_one(t_stack **a, int *b, t_stack **c, t_moves **d);
void	ft_check_args_two(int *check);
void	check_sorted(t_stack **s_a);
void	ft_lstclear(t_stack **lst);
void	ft_lstclear_one(t_moves **lst);
void	free_all(t_stack **s_a, t_moves **m_c, char **ss, char *s);

#endif
