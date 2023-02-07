#include "Contact.hpp"

// Constructors 
Contact::Contact() { }

// Destructor 
Contact::~Contact() { }

// Member functions
bool Contact::containsOnlyAlpha(std::string const s) {
    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
        if (!isalpha(*it) && *it != ' ' && *it != '-') { return (false); }
    }
    return (true);
}

bool Contact::containsOnlyDigits(std::string const s) {
    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
        if (!isdigit(*it) && *it != ' ') { return (false); }
    }
    return (true);
}

// Getters 
void Contact::getFname(std::string str) { return (_Fname); }
void Contact::getLname(std::string str) { return (_Lname); }
void Contact::getNname(std::string str) { return (_Nname); }
void Contact::getNbr(std::string str) { return (_Nbr); }
void Contact::getSecret(std::string str) { return (_Secret); }

// Setters
void Contact::setFname(std::string str) { _Fname = str; }
void Contact::setLname(std::string str) { _Lname = str; }
void Contact::setNname(std::string str) { _Nname = str; }
void Contact::setNbr(std::string str) { _Nbr = str; }
void Contact::setSecret(std::string str) { _Secret = str; }