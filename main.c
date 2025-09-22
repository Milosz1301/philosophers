/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstawski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:21:52 by mstawski          #+#    #+#             */
/*   Updated: 2025/09/17 15:34:22 by mstawski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philophers.h"

t_node	*create_philosopher(int	number)
{
	t_node philosopher;

	philosopher = malloc(sizeof(t_node));
	if (!philosopher)
		return (NULL);
	philosopher->prev = NULL;
	philosopher->number = number;
	philosopher->fork = true;
	philosopher->death = NULL;
	philosopher->eat = NULL;
	philosopher->sleep = NULL;
	philosopher->dinners = NULL;
	philosopher->next = NULL;
}

void	create_table(**t_linkedlist table, int chairs_nb)
{
	t_node	philosopher;
	int	i;

	i = 1;
	philosopher = create_philosopher(i);
	(*table)->head = &philosopher;
	while (i < chairs)
	{
		philosopher->next = create_philopher(++i);
		philosopher->previous = philosopher;
		philosopher = philosopher->next;
	}
	philosopher->next = (*table)->head;
	(*table)->head = philosopher;
}

void	parsing(int args, char **input)
{
	int	i;
	int	j;

	if (args != 6)
		exit(1);
	i = 0;
	while (input[++i])
	{
		j = -1;
		while (input[i][++j])
		{
			if (!(input[i][j] > 47 && input[i][j] < 58))
				exit_with_error();
		}
	}
}

int	main(int argc, char *argv[])
{
	t_linkedlist *table;
	int	philosphers_nb;

	parsing(argc, argv);
	philosophers_nb = ft_atoi(argv[1]);
	create_table(&table, philosophers_nb);
}
