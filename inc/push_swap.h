/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:13:04 by jllarena          #+#    #+#             */
/*   Updated: 2024/04/04 19:08:46 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		radix_sort(t_stacks *s);
void		parse_numbers(t_stacks *s);
void		create_index(t_stacks *s);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		free_and_exit_with_message(t_stacks *s, char *msg);
void		exit_if_sorted_or_has_duplicate(t_stacks *s, int i);
int			is_array_sorted(t_stacks *s);
int			ft_atol(const char *n, t_stacks *s);
void		size4(t_stacks *s);
void		size4_part1(t_stacks *s);
void		size4_part2(t_stacks *s);
void		size3(t_stacks *s);
void		size5(t_stacks *s);
void		size5_part1(t_stacks *s, int *i);
int			size5_2(t_stacks *s, int i);
int			ft_isdigit(int c);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		ft_putendl_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_count_words(char const *s, char c);

#endif