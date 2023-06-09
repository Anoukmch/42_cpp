/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:42 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 16:33:44 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

# include <iostream>
# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src);
		RobotomyRequestForm( std::string const& target);
		RobotomyRequestForm &operator=( RobotomyRequestForm const & src);
		~RobotomyRequestForm( void );

		std::string const& getTarget(void) const;
		void	ExecuteForm( void ) const;

		static int		test;

	private :
		std::string _target;
};

#endif