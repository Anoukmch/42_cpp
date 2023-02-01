#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		std::string setFname();
		std::string setLname();
		std::string setNname();
		std::string setNbr();
		std::string setSecret();

    private:
       std::string m_fName;
	   std::string m_lName;
	   std::string m_nMame;
	   std::string m_number;
	   std::string m_secret;
};

#endif

// Constructeur surchargé avec les infos envoyés
