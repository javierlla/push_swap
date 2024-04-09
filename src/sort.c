/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:19:34 by jllarena          #+#    #+#             */
/*   Updated: 2024/04/04 18:04:38 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	size3(t_stacks *s)
{
	if (s->a_size == 2)
	{
		if (s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
	}
	else if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		;
	else if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		rotate(s->a, s->a_size, "down", "a");
		swap("sa", s->a, s->a_size);
	}
	else if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		swap("sa", s->a, s->a_size);
	else if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rotate(s->a, s->a_size, "down", "a");
	else if (s->a[1] < s->a[2] && s->a[0] > s->a[1] && s->a[0] > s->a[2])
		rotate(s->a, s->a_size, "up", "a");
	else if (s->a[1] > s->a[2] && s->a[0] > s->a[1] && s->a[0] > s->a[2])
	{
		rotate(s->a, s->a_size, "up", "a");
		swap("sa", s->a, s->a_size);
	}
}

void	size5(t_stacks *s)
{
	int	i;

	i = 0;
	if (s->a_size == 5)
	{
		size5_part1(s, &i);
		i = size5_2(s, i);
	}
	size4(s);
	if (i == 1)
	{
		push("pa", s);
		if (s->a[0] > s->a[1])
			swap("sa", s->a, s->a_size);
	}
}

int	is_stack_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	radix_sort_stack_b(t_stacks *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_stack_sorted(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			rotate(s->b, s->b_size, "up", "b");
		else
			push("pa", s);
	}
	if (is_stack_sorted(s))
		while (s->b_size != 0)
			push("pa", s);
}
/*Extracción del bit en la posición j:

La expresión ((s->a[0] >> j) & 1) se utiliza para extraer el bit en la 
posición j del primer elemento de la pila a.
s->a[0] representa el primer elemento de la pila a.
El operador >> desplaza los bits del valor de s->a[0] a la derecha j veces,
 dejando el bit en la posición j en la posición más a la derecha.
El operador & realiza una operación AND bit a bit con 1, lo que resulta en 1
 si el bit en la posición j es 1 y 0 si es 0.
Interpretación del bit:

Si el resultado de ((s->a[0] >> j) & 1) es 0, significa que el bit en la 
posición j del primer elemento de la pila a es 0.
Si el resultado es 1, significa que el bit en la posición j es 1.
Movimiento de elementos:

Si el bit en la posición j es 0, se mueve el primer elemento de la pila a a 
la pila b utilizando la función push("pb", s). Esto se hace porque en el 
algoritmo de Radix Sort, los números se ordenan basándose en sus bits, y 
los números con un bit 0 en la posición j se consideran "menores" y deben 
estar en la parte inferior de la secuencia ordenada.
Si el bit en la posición j es 1, se realiza una rotación hacia arriba en 
la pila a utilizando la función rotate(s->a, s->a_size, "up", "a"). 
Esto se hace para mantener los números con un bit 1 en la posición j en la
parte superior de la secuencia ordenada.*/

void	radix_sort(t_stacks *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = s->a_size;
		while (size-- && !is_stack_sorted(s))
		{
			if (((s->a[0] >> j) & 1) == 0)
				push("pb", s);
			else
				rotate(s->a, s->a_size, "up", "a");
		}
		radix_sort_stack_b(s, s->b_size, bit_size, j + 1);
	}
	while (s->b_size != 0)
		push("pa", s);
}
