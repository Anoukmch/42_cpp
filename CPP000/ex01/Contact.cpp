/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:25:00 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 18:30:38 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructors 
Contact::Contact() { }

// Destructor 
Contact::~Contact() { }

// Getters 
std::string const Contact::getFname(void) const { return (_Fname); }
std::string const Contact::getLname(void) const { return (_Lname); }
std::string const Contact::getNname(void) const { return (_Nname); }
std::string const Contact::getNbr(void) const { return (_Nbr); }
std::string const Contact::getSecret(void) const { return (_Secret); }

// Setters
void Contact::setFname(std::string const str) { _Fname = str; }
void Contact::setLname(std::string const str) { _Lname = str; }
void Contact::setNname(std::string const str) { _Nname = str; }
void Contact::setNbr(std::string const str) { _Nbr = str; }
void Contact::setSecret(std::string const str) { _Secret = str; }