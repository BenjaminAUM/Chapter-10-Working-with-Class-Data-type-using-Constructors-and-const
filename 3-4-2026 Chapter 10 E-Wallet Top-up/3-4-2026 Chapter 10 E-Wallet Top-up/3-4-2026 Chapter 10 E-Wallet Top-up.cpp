// 3-4-2026 Chapter 10 E-Wallet Top-up.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

class EWallet
{
private:
	float balance;

public:
	void setbalance(int bal)
	{
		if (bal < 0)
		{
			cout << "Invalid input!" << endl;
			return;
		}
		else
		{
			balance = bal;
		}
	}

	void amount_spent(int amount)
	{
		if (amount > balance)
		{
			cout << "Insufficent funds!" << endl;
			cout << "Payment declined!" << endl;
		}
		else
		{
			balance -= amount;
		}
	}

	int getbalance()
	{
		return balance;
	}
};

int main()
{
	EWallet acc;
	float spend_amount;

	acc.setbalance(500);

	cout << "Enter amount spent: ";
	cin >> spend_amount;

	acc.amount_spent(spend_amount);

	cout << "Final balance: " << acc.getbalance() << endl;

	return 0;
}