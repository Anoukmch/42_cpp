#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors
Account::Account() : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
}

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0){
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";created" << std::endl;
}

// Destructors
Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";closed" << std::endl;
}

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

// Members function - public
void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:"
	<< _totalAmount << ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";deposits:" <<_nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
	<< _amount << ";deposit:" << deposit
	<< ";amount:" << (_amount + deposit) << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
	<< _amount << ";withdrawal:";

	if ((_amount - withdrawal) < 0) {
		std::cout << "refused" << std::endl;
		return false;
	}
	else {
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << withdrawal << ";amount:" << (_amount - withdrawal) << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
	}
	return true;
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

// Members function - private
void	Account::_displayTimestamp( void ) {
	std::time_t timeInSec;
	struct tm *timeStruct;

	std::time(&timeInSec);
	timeStruct = std::localtime(&timeInSec);

	std::cout << "[" << timeStruct->tm_year + 1900;
	if (timeStruct->tm_mon < 10)
		std::cout << "0";
	std::cout << timeStruct->tm_mon;
	if (timeStruct->tm_mday < 10)
		std::cout << "0";
	std::cout << timeStruct->tm_mday << "_";
	if (timeStruct->tm_hour < 10)
		std::cout << "0";
	std::cout << timeStruct->tm_hour;
	if (timeStruct->tm_min < 10)
		std::cout << "0";
	std::cout << timeStruct->tm_min;
	if (timeStruct->tm_sec < 10)
		std::cout << "0";
	std::cout << timeStruct->tm_sec << "] ";
}

