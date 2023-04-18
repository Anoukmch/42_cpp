/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:24:41 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 16:17:16 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl;

	Fixed e(20);
	Fixed f(52.2f);

	std::cout << std::endl;

	std::cout << "Floating-point representation using operator<< : " << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << std::endl;
	std::cout << "Floating-point representation using toFloat : " << std::endl;
	std::cout << "e is " << e.toFloat() << std::endl;
	std::cout << "f is " << f.toFloat() << std::endl;
	std::cout << std::endl;
	std::cout << "Integer representation using toInt : " << std::endl;
	std::cout << "e is " << e.toInt() << std::endl;
	std::cout << "f is " << f.toInt() << std::endl;
	std::cout << std::endl;
	return 0;
}
