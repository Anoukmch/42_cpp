#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		void setFname(std::string str);
		void setLname(std::string str);
		void setNname(std::string str);
		void setNbr(std::string str);
		void setSecret(std::string str);

    private:
       std::string _Fname;
	   std::string _Lname;
	   std::string _Nname;
	   std::string _Nbr;
	   std::string _Secret;
};
 
#endif

// Check empty param 
// Display contact 
// Contains only alpha or digits 
