#ifndef PHILOSOPHERS_H
#define PHILOSPOHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	s_node	*prev;
	int	number;
	bool	fork;
	int	death;
	int	eat;
	int	sleep;
	int	dinners;
	s_node	*next;
}	t_node;

typedef struct s_linkedlist
{
	t_node	*head;
}	t_linkedlist;
