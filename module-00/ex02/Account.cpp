/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:24:40 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/17 14:16:46 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts); 
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits); 
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals); 
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount); 
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}


void	Account::_displayTimestamp( void )
{
	std::time_t time;

	time = std::time(NULL);
	std::tm *format_time = std::localtime(&time);
	std::cout << "[";
	std::cout << 1900 + format_time->tm_year;
	std::cout << 1 + format_time->tm_mon;
	std::cout << format_time->tm_mday;
	std::cout << '_';
	std::cout << format_time->tm_hour; 
	std::cout << format_time->tm_min;
	std::cout << format_time->tm_sec;
	std::cout << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "deposit:" << deposit << ';';
	_amount += deposit;
	std::cout << "amount:" << _amount << ';';
	_nbDeposits += 1;
	std::cout << "nb_deposit:" << _nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}


bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	if (checkAmount() < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << "withdrawal:" << withdrawal << ';';
		std::cout << "amount:" << _amount << ';';
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}



void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}


Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed" << std::endl;
}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	_accountIndex = getNbAccounts();
	std::cout << "index:" << _accountIndex << ';'; 
	_amount = initial_deposit;
	std::cout << "amount:" << _amount << ';';
	std::cout << "created" << std::endl;
	_totalAmount += initial_deposit; 
	_nbAccounts += 1;
	_nbWithdrawals = 0;
	_nbDeposits = 0;

}