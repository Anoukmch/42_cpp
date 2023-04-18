/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:37 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 15:18:31 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

# include <iostream>
# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm const & src);
		PresidentialPardonForm( std::string const& target);
		PresidentialPardonForm &operator=( PresidentialPardonForm const & src);
		~PresidentialPardonForm( void );

		std::string const& getTarget(void) const;
		void	ExecuteForm( void ) const;

	private :
		std::string _target;
};

#endif
