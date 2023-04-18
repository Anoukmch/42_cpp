/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:55:43 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 12:55:44 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H
#include <iostream>
#include <string>

class Harl
{
    private:
        void debug();
        void info();
        void warning();
        void error();

    public:
    	Harl();
		~Harl();
		void complain(std::string level);
};

#endif
