#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors
Account::Account() : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
}

// Account::Account( int initial_deposit ) {

// }

// Destructors
Account::~Account( void ) {}

// Getters
int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}
int	Account::getTotalAmount( void ) {
	return _totalAmount;
}
int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

/* GOAL : Display the log file in the terminal */
