/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:46:42 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 16:17:40 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const& copy);
		Fixed(const int integer);
		Fixed(const float fPoint);
		~Fixed();
		Fixed & operator=(const Fixed & var);

		int getRawBits( void ) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int _fixPt;
		static const int _fracBits = 8;

};

std::ostream &operator<<( std::ostream &flux, Fixed const& var);

#endif
