/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:20:29 by amechain          #+#    #+#             */
/*   Updated: 2023/06/05 18:32:46 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

# include <iostream>
#include "Bureaucrat.hpp"

#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

class Bureaucrat;

class AForm
{
	public :
		AForm();
		AForm( AForm const & src);
		AForm &operator=( AForm const & src);
		virtual ~AForm( void );
		AForm( const std::string name, const int gradeSign, const int gradeExe);

		std::string const& getName(void) const;
		bool const& getIsSigned(void) const;
		int const& getGradeSign(void) const;
		int const& getGradeExe(void) const;

		void	beSigned(Bureaucrat const& obj);
		void execute(Bureaucrat const & executor) const;
		virtual void	ExecuteForm( void ) const = 0; // OR PROTECTED ?

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

		class NotSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private :
		const std::string 	_name;
		bool 				_isSigned;
		const int 			_gradeSign;
		const int 			_gradeExe;
};

std::ostream &operator<<( std::ostream &flux, AForm const& var);

#endif
