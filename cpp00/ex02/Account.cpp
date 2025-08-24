/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:12:53 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/24 11:50:03 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += initial_deposit;
	_nbAccounts++;
	Account::_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";created\n";
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";closed\n";
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm		*ltm = std::localtime(&now);
	std::cout << '['
				<< 1900 + ltm->tm_year
				<< std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
				<< std::setw(2) << ltm->tm_mday
				<< '_'
				<< std::setw(2) << ltm->tm_hour
				<< std::setw(2) << ltm->tm_min
				<< std::setw(2) << ltm->tm_sec
				<< "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< "accounts:"
				<< Account::getNbAccounts()
				<< ";total:"
				<< Account::getTotalAmount()
				<< ";deposits:"
				<< Account::getNbDeposits()
				<< ";withdrawals:"
				<< Account::getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< this->_amount
				<< ";deposit:"
				<< deposit
				<< ";amount:"
				<< this->_amount + deposit
				<< ";nb_deposits:"
				<< ++this->_nbDeposits
				<< std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< this->_amount
				<< ";withdrawal:";
	if (this->_amount - withdrawal < 0)
		return (std::cout << "refused\n", false);
	std::cout	<< withdrawal
				<< ";amount:"
				<< this->_amount - withdrawal
				<< ";nb_withdrawals:"
				<< ++this->_nbWithdrawals
				<< std::endl;
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout 	<< "index:" 
				<< this->_accountIndex
				<< ";amount:" 
				<< this->_amount
				<< ";deposits:" 
				<< this->_nbDeposits
				<< ";withdrawals:" 
				<< this->_nbWithdrawals
				<< std::endl;
}
