/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:20:29 by amechain          #+#    #+#             */
/*   Updated: 2023/04/11 16:29:18 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

# include <iostream>
#include "Bureaucrat.hpp"

#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

class Bureaucrat;

class Form
{
	public :
		Form();
		Form( Form const & src);
		Form &operator=( Form const & src);
		~Form( void );
		Form( const std::string name, const int gradeSign, const int gradeExe); // Try to remove the const to see if it work

		std::string const& getName(void) const;
		bool const& getIsSigned(void) const;
		int const& getGradeSign(void) const;
		int const& getGradeExe(void) const;

		void	beSigned(Bureaucrat const& obj);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class AlreadySigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private :
		const std::string 	_name;
		bool 				_isSigned;
		const int 			_gradeSign;
		const int 			_gradeExe;
};

std::ostream &operator<<( std::ostream &flux, Form const& var);

#endif
