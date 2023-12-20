/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:30:35 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/20 21:33:16 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals;
	std::cout << std::endl;

	return;
}

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts++),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
	Account::_totalAmount += this->_amount;

	return;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;

	return;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << (this->_amount += deposit);
	std::cout << ";nb_deposits:" << ++this->_nbDeposits;
	std::cout << std::endl;
	++Account::_totalNbDeposits;
	Account::_totalAmount += deposit;

	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";

	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;

		return false;
	}

	std::cout << withdrawal;
	std::cout << ";amount:" << (this->_amount -= withdrawal);
	std::cout << ";nb_withdrawals:" << ++this->_nbWithdrawals;
	std::cout << std::endl;
	++Account::_totalNbWithdrawals;
	Account::_totalAmount -= withdrawal;

	return true;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;

	return;
}

void Account::_displayTimestamp(void)
{
	std::time_t const timer = std::time(NULL);
	std::tm const *timeinfo = std::localtime(&timer);
	char timestamp[19];

	std::strftime(timestamp, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << timestamp;

	return;
}

Account::Account(void)
{
	return;
}
