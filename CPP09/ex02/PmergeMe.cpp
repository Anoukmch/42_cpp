/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:00:11 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/15 22:11:22 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe( PmergeMe const & src) {
	*this = src;
}

// Destructors
PmergeMe::~PmergeMe( void ) {
}

// Operator overload
PmergeMe & PmergeMe::operator=( PmergeMe const & src) { 
	if ( this != &src ) {
		// Do something 
	}
	return ( *this );
}
