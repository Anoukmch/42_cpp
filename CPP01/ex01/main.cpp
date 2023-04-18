/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:59:01 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 11:16:49 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int n = 10;
	Zombie* horde = zombieHorde(n, "Karl");

	for (int i = 0 ; i < n ; i++)
		horde[i].announce();
	delete[] horde;
	system("leaks ex01");
	return (0);
}
