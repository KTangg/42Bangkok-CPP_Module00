/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:48:58 by spoolpra          #+#    #+#             */
/*   Updated: 2022/04/28 14:14:11 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Construct new Account Initialise with given amount _nbWithdrawal = 0, _nbDeposits=0
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	// Count total account and Accumulate some of totalamount
	Account::_nbAccounts++;
	Account::_totalAmount = Account::_totalAmount + initial_deposit;

	// Print Create log format [YYYYMMDD_HHMMSS] index:X;amount:XX;created
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

	return ;
}

// Deconstruct Account
Account::~Account(void)
{
	// Print Create log format [YYYYMMDD_HHMMSS] index:X;amount:XX;closed
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;

	return ;
}

// DisplayTimestamp as [YYYYMMDD_HHMMSS] format
void	Account::_displayTimestamp(void)
{
	std::tm		*now;
	std::time_t	t;
	char		buff[64];

	t = std::time(NULL);
	now = std::localtime(&t);
	strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", now);
	std::cout << "[" << buff << "] ";
}

// Display Current status [YYYYMMDD_HHMMSS] index:X;amount:X;deposits:X;withdrawals:X format
void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;

	return ;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";deposit:";
	if (deposit < 0)
	{
		std::cout << "refused" << std::endl;
		return ;
	}
	std::cout << deposit;
	this->_amount = this->_amount + deposit;
	Account::_totalAmount = Account::_totalAmount + deposit;
	std::cout << ";amount:" << this->checkAmount();
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;

	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";withdrawal:";
	if (withdrawal > this->checkAmount() || withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	this->_amount = this->_amount - withdrawal;
	Account::_totalAmount = Account::_totalAmount - withdrawal;
	std::cout << ";amount:" << this->checkAmount();
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return (true);
}
