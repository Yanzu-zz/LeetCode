#include <iostream>
#include <vector>

using namespace std;

class Bank
{
private:
  vector<long long> accounts;

  bool isAccountValid(int account)
  {
    return account > 0 && account <= accounts.size();
  }

public:
  Bank(vector<long long> &balance)
  {
    // initials the account info
    this->accounts = balance;
  }

  bool transfer(int account1, int account2, long long money)
  {
    // check if the account doesn't exist
    if (!isAccountValid(account1) || !isAccountValid(account2))
      return false;

    // We should check the balance of the (both) account greater than the money which will be transfered
    if (this->accounts[account1 - 1] < money)
      return false;

    // Transfer the money to account2 from account1
    this->accounts[account1 - 1] -= money;
    this->accounts[account2 - 1] += money;

    return true;
  }

  bool deposit(int account, long long money)
  {
    if (!isAccountValid(account))
      return false;

    this->accounts[account - 1] += money;

    return true;
  }

  bool withdraw(int account, long long money)
  {
    if (!isAccountValid(account))
      return false;

    if (this->accounts[account - 1] < money)
      return false;

    this->accounts[account - 1] -= money;

    return true;
  }
};

int main(void)
{

  return 0;
}
