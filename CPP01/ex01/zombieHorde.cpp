/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:30:28 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 11:22:02 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombie_Horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie_Horde[i].setName(name);
	return (zombie_Horde);
}
