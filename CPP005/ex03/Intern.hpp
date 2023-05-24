/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:11:39 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 17:38:10 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

# include <iostream>
#include "AForm.hpp"

class Intern
{
	public :
		Intern();
		Intern( Intern const & src);
		Intern &operator=( Intern const & src);
		~Intern( void );

		AForm* makeForm( std::string const& _formName, std::string const& _formTarget ) const;

		class FormDontExists : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private :

};

#endif