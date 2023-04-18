/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:46 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 15:18:25 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

# include <iostream>
# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm const & src);
		ShrubberyCreationForm( std::string const& target);
		ShrubberyCreationForm &operator=( ShrubberyCreationForm const & src);
		~ShrubberyCreationForm( void );

		std::string const& getTarget(void) const;
		void	ExecuteForm( void ) const;

	private :
		std::string _target;
};

#endif
