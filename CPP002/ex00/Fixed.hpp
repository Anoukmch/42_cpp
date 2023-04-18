/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:46:42 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 15:22:44 by amechain         ###   ########.fr       */
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
		~Fixed();
		Fixed & operator=(const Fixed & var);

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _fixPt;
		static const int _fracBits = 8;

};

#endif
