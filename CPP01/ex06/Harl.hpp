/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:54:29 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 12:54:30 by amechain         ###   ########.fr       */
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
