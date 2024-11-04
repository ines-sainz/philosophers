/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:12:51 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/15 11:12:52 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(int i)
{
	if (i == 1)
		write(2, "Only 4 or 5 arguments.\n", 24);
	if (i == 2)
		write(2, "The arguments can only be a positive int above 0.\n", 51);
	if (i == 3)
		write(2, "Problem setting philosophers.\n", 31);
	if (i == 4)
		write(2, "Problem setting forks.\n", 24);
	return (1);
}

int	main(int argc, char **argv)
{
	t_simulation	sim;

	if (argc != 5 && argc != 6)
		return (error(1));
	sim.first_philo = NULL;
	sim.first_fork = NULL;
	sim.t_must_eat = 0;
	if (parse(argv, &sim) == 1)
		return (error(2));
	printf("nº philos: %zu\nt to die: %zu\nt to eat: %zu\nt to sleep: %zu\nt must eat: %zu\n ... \n",
		sim.n_philos, sim.t_to_die, sim.t_to_eat, sim.t_to_sleep, sim.t_must_eat);
	if (set_philos(&sim) == 1)
		return (error(3));
	if (set_forks(&sim) == 1)
		return (error(4));
	print_philos(&sim);
	print_forks(&sim);
	write(1, "all ok\n", 8);
	return (0);
}

/*
void    *saludo()
{
    printf("Hola, mundo\n");
}

int main(void)
{
    pthread_t   hilo;
    int         resultado;
                                      ->son las características del hilo
    resultado = pthread_create(&hilo, NULL, saludo, NULL);->parámetros de la función
                                                    ->funcion con las tareas del hilo
    if (resultado == 0)
        return (1);
    ->espera al hilo antes de salir
    pthread_join(hilo, NULL);
                        ->valor que devuelve la funcion se almacena aquí
}
*/
