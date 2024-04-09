/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:19:24 by jllarena          #+#    #+#             */
/*   Updated: 2024/04/08 13:13:41 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_and_exit_with_message(t_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->join_args != NULL)
			free(s->join_args);
		if (s != NULL)
			free(s);
	}
	exit(1);
}

int	is_array_sorted(t_stacks *s)
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
/*
Esta función valida los argumentos de línea de comandos.
Verifica si el número de argumentos es menor que 2. Si lo es, sale del
programa con un mensaje de error utilizando free_and_exit_with_message.
Itera sobre los argumentos (argv) y verifica cada uno de ellos:
Verifica si el primer carácter del argumento es nulo o un espacio en blanco.
Si es así, sale del programa con un mensaje de error.
Itera sobre cada carácter del argumento y verifica si son dígitos o
caracteres permitidos. Si no lo son, sale del programa con un mensaje
de error.*/

static void	number_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		free_and_exit_with_message(NULL, "");
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			free_and_exit_with_message(NULL, "Error\n");
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				free_and_exit_with_message(NULL, "Error\n");
			j++;
		}
	}
}
/*Función join_args:
Esta función une los argumentos de línea de comandos en una sola cadena,
separados por un espacio en blanco.
Utiliza la función ft_strjoin para unir cada argumento en la cadena tmp2.
En la segunda concatenacion añade un espacio al final.
Al finalizar, asigna la cadena resultante a join_args en la estructura
t_stacks(s).*/

static void	join_args(int argc, char **argv, t_stacks *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->join_args = ft_strdup(tmp);
	if (s->join_args == NULL)
		free_and_exit_with_message(s, "Error\n");
	if (tmp)
		free(tmp);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	number_arguments(argc, argv);
	s = malloc(sizeof * s);
	if (s == NULL)
		exit(1);
	initialize_stacks(argc, argv, s);
	join_args(argc, argv, s);
	parse_numbers(s);
	exit_if_sorted_or_has_duplicate(s, 0);
	create_index(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		size3(s);
	else if (s->a_size == 4)
		size4(s);
	else if (s->a_size == 5)
		size5(s);
	else
		radix_sort(s);
	exit_if_sorted_or_has_duplicate(s, 1);
	free_and_exit_with_message(s, "Error\n");
	return (0);
}
