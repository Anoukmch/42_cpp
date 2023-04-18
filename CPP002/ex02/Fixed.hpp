/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:46:42 by amechain          #+#    #+#             */
/*   Updated: 2023/04/06 11:57:29 by amechain         ###   ########.fr       */
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

		bool operator==(Fixed const& a) const;
		bool operator!=(Fixed const& a) const;
		bool operator>(Fixed const& a) const;
		bool operator>=(Fixed const &a) const;
		bool operator<(Fixed const &a) const;
		bool operator<=(Fixed const &a) const;

		Fixed operator+(Fixed const& a) const;
		Fixed operator-(Fixed const& a) const;
		Fixed operator*(Fixed const& a) const;
		Fixed operator/(Fixed const& a) const;

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed & min(Fixed const& a, Fixed const& b);
		static const Fixed & max(Fixed const& a, Fixed const& b);

	private:
		int _fixPt;
		static const int _fracBits = 8;

};

std::ostream &operator<<( std::ostream &flux, Fixed const& var);

#endif
