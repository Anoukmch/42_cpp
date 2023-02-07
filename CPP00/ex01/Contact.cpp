#include "Contact.hpp"

// Constructors 
Contact::Contact() { }

// Destructor 
Contact::~Contact() { }

void Contact::setFname(std::string str) { _Fname = str; }

void Contact::setLname(std::string str) { _Lname = str; }

void Contact::setNname(std::string str) { _Nname = str; }

void Contact::setNbr(std::string str) { _Nbr = str; }

void Contact::setSecret(std::string str) { _Secret = str; }
