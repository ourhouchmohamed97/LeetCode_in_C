// Simple Bank System

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    long long *balance;  // Array to hold balances for each account
    int size;            // Number of accounts
} Bank;

/**
 * Create a new Bank instance with given balances.
 */
Bank* bankCreate(long long* balance, int balanceSize) {
    Bank* bank = (Bank*)malloc(sizeof(Bank));
    bank->balance = (long long*)malloc(sizeof(long long) * balanceSize);
    for (int i = 0; i < balanceSize; i++) {
        bank->balance[i] = balance[i];
    }
    bank->size = balanceSize;
    return bank;
}

/**
 * Helper function to check if an account number is valid.
 */
bool isValidAccount(Bank* obj, int account) {
    return account >= 1 && account <= obj->size;
}

/**
 * Transfer money from account1 to account2.
 */
bool bankTransfer(Bank* obj, int account1, int account2, long long money) {
    if (!isValidAccount(obj, account1) || !isValidAccount(obj, account2))
        return false; // Invalid account numbers
    if (obj->balance[account1 - 1] < money)
        return false; // Not enough balance to transfer
    obj->balance[account1 - 1] -= money;
    obj->balance[account2 - 1] += money;
    return true;
}

/**
 * Deposit money into an account.
 */
bool bankDeposit(Bank* obj, int account, long long money) {
    if (!isValidAccount(obj, account))
        return false;
    obj->balance[account - 1] += money;
    return true;
}

/**
 * Withdraw money from an account.
 */
bool bankWithdraw(Bank* obj, int account, long long money) {
    if (!isValidAccount(obj, account))
        return false;
    if (obj->balance[account - 1] < money)
        return false;
    obj->balance[account - 1] -= money;
    return true;
}

/**
 * Free all allocated memory.
 */
void bankFree(Bank* obj) {
    free(obj->balance);
    free(obj);
}
