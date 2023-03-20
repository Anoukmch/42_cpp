#include "Account.hpp"

// Constructors 
Account::Account( int initial_deposit ) {

}

// Destructors 
Account::~Account( void ) {}

// Getters 
int	Account::getNbAccounts( void ) {
	return _nbAccounts ;
}
static int	getTotalAmount( void );
static int	getNbDeposits( void );
static int	getNbWithdrawals( void );