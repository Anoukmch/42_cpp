#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	public:
		Contact();
		~Contact();
		void setFname(std::string const str);
		void setLname(std::string const str);
		void setNname(std::string const str);
		void setNbr(std::string const str);
		void setSecret(std::string const str);
		std::string const getFname(void) const;
		std::string const getLname(void) const;
		std::string const getNname(void) const;
		std::string const getNbr(void) const;
		std::string const getSecret(void) const;

    private:
       std::string _Fname;
	   std::string _Lname;
	   std::string _Nname;
	   std::string _Nbr;
	   std::string _Secret;
};
 
#endif
