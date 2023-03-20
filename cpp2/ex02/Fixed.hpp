/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:05 by mcombeau          #+#    #+#             */
/*   Updated: 2023/03/18 19:01:13 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const & src);
		Fixed( int const n );
		Fixed( float const f );
		~Fixed( void );

		Fixed &	operator=( Fixed const & src);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		//MY CODE
		bool operator==(Fixed const& a);
		bool operator!=(Fixed const& a);
		bool operator>(Fixed const &a);
		bool operator>=(Fixed const &a);
		bool operator<(Fixed const &a);
		bool operator<=(Fixed const &a);

		Fixed operator+(Fixed const& a);
		Fixed operator-(Fixed const& a);
		Fixed operator*(Fixed const& a);
		Fixed operator/(Fixed const& a);

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed & min(Fixed const& a, Fixed const& b);
		static const Fixed & max(Fixed const& a, Fixed const& b);
		

	private:
		int					_fixPt;
		static const int	_fracBits = 8;
};

std::ostream& operator<<( std::ostream& os, const Fixed& number );

#endif

// Comparer les fonctions OCR avec les prototypes de cplusplus.com
// Celles dans une classe, celle hors classe
// why operator < > should be const in order to use the min and max const function ? 