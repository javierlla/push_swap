/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:56:30 by jllarena          #+#    #+#             */
/*   Updated: 2024/04/04 18:04:42 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	size4_part1(t_stacks *s)
{
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[0] < s->a[3]
		&& s->a_size == 4)
		push("pb", s);
	if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[1] < s->a[3]
		&& s->a_size == 4)
	{
		swap("sa", s->a, s->a_size);
		push("pb", s);
	}
}

void	size4_part2(t_stacks *s)
{
	if (s->a[0] > s->a[2] && s->a[1] > s->a[2] && s->a[2] < s->a[3]
		&& s->a_size == 4)
	{
		rotate(s->a, s->a_size, "up", "a");
		swap("sa", s->a, s->a_size);
		push("pb", s);
	}
	if (s->a[0] > s->a[3] && s->a[1] > s->a[3] && s->a[2] > s->a[3]
		&& s->a_size == 4)
	{
		rotate(s->a, s->a_size, "down", "a");
		push("pb", s);
	}
}

void	size4(t_stacks *s)
{
	if (s->a_size == 4)
	{
		size4_part1(s);
		size4_part2(s);
	}
	if (s->a_size == 3)
		size3(s);
	push("pa", s);
}

int	size5_2(t_stacks *s, int i)
{
	if (s->a[0] > s->a[2] && s->a[1] > s->a[2] && s->a[2] < s->a[3]
		&& s->a[2] < s->a[4] && i == 0)
	{
		rotate(s->a, s->a_size, "up", "a");
		swap("sa", s->a, s->a_size);
		push("pb", s);
		i++;
	}
	if (s->a[0] > s->a[3] && s->a[1] > s->a[3] && s->a[2] > s->a[3]
		&& s->a[3] < s->a[4] && i == 0)
	{
		rotate(s->a, s->a_size, "down", "a");
		rotate(s->a, s->a_size, "down", "a");
		push("pb", s);
		i++;
	}
	if (s->a[0] > s->a[4] && s->a[1] > s->a[4] && s->a[2] > s->a[4]
		&& s->a[3] > s->a[4] && i == 0)
	{
		rotate(s->a, s->a_size, "down", "a");
		push("pb", s);
		i++;
	}
	return (i);
}

void	size5_part1(t_stacks *s, int *i)
{
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[0] < s->a[3]
		&& s->a[0] < s->a[4] && *i == 0)
	{
		push("pb", s);
		(*i)++;
	}
	if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[1] < s->a[3]
		&& s->a[1] < s->a[4] && *i == 0)
	{
		swap("sa", s->a, s->a_size);
		push("pb", s);
		(*i)++;
	}
}
/*void	size4(t_stacks *s)
{
	if (s->a_size == 4)
	{
		if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[0] < s->a[3]
			&& s->a_size == 4)
			push("pb", s);
		if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[1] < s->a[3]
			&& s->a_size == 4)
		{
			swap("sa", s->a, s->a_size);
			push("pb", s);
		}
		if (s->a[0] > s->a[2] && s->a[1] > s->a[2] && s->a[2] < s->a[3]
			&& s->a_size == 4)
		{
			rotate(s->a, s->a_size, "up", "a");
			swap("sa", s->a, s->a_size);
			push("pb", s);
		}
		if (s->a[0] > s->a[3] && s->a[1] > s->a[3] && s->a[2] > s->a[3]
			&& s->a_size == 4)
		{
			rotate(s->a, s->a_size, "down", "a");
			push("pb", s);
		}
	}
	if (s->a_size == 3)
		size3(s);
	push("pa", s);
}*/

/*
void	size5(t_stacks *s)
{
	int	i;

	i = 0;
	if (s->a_size == 5)
	{
		if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[0] < s->a[3]
			&& s->a[0] < s->a[4] && i == 0)
		{
			push("pb", s);
			i++;
		}
		if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[1] < s->a[3]
			&& s->a[1] < s->a[4] && i == 0)
		{
			swap("sa", s->a, s->a_size);
			push("pb", s);
			i++;
		}
		i = size5_2(s, i);
	}
	size4(s);
	if (i == 1)
	{
		push("pa", s);
		if (s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
	}
}*/