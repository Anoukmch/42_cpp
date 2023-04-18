/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:48:52 by amechain          #+#    #+#             */
/*   Updated: 2023/04/11 16:33:10 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

# include <exception>
# include <iostream>
#include "Form.hpp"

#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

class Form;

class Bureaucrat
{
	public :
		Bureaucrat();
		Bureaucrat( Bureaucrat const & src);
		Bureaucrat( const std::string name, int grade);
		Bureaucrat &operator=( Bureaucrat const & src);
		~Bureaucrat( void );

		std::string const& getName(void) const;
		int const& getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(Form & obj) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private :
		const std::string _name;
		int	_grade;

};

std::ostream &operator<<( std::ostream &flux, Bureaucrat const& var);

#endif
