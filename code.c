#include <stdio.h>


struct BankAccount {
    int accountNumber;
    char accountHolder[100];
    double balance;
};


struct BankAccount createAccount(int accountNumber, char accountHolder[100], double initialBalance) {
    struct BankAccount newAccount;
    newAccount.accountNumber = accountNumber;
    strcpy(newAccount.accountHolder, accountHolder);
    newAccount.balance = initialBalance;
    return newAccount;
}


void deposit(struct BankAccount *account, double amount) {
    account->balance += amount;
}


void withdraw(struct BankAccount *account, double amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
    } else {
        printf("Insufficient balance\n");
    }
}


void checkBalance(struct BankAccount account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.accountHolder);
    printf("Balance: %.2lf\n", account.balance);
}

int main() {
    struct BankAccount accounts[10];
    int accountCount = 0;

    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (accountCount < 10) {
                    int accountNumber;
                    char accountHolder[100];
                    double initialBalance;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter account holder name: ");
                    scanf("%s", accountHolder);
                    printf("Enter initial balance: ");
                    scanf("%lf", &initialBalance);

                    accounts[accountCount] = createAccount(accountNumber, accountHolder, initialBalance);
                    accountCount++;
                    printf("Account created successfully.\n");
                } else {
                    printf("Maximum account limit reached.\n");
                }
                break;
            case 2:
                if (accountCount > 0) {
                    int accountNumber;
                    double amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter amount to deposit: ");
                    scanf("%lf", &amount);

                    int found = 0;
                    for (int i = 0; i < accountCount; i++) {
                        if (accounts[i].accountNumber == accountNumber) {
                            deposit(&accounts[i], amount);
                            printf("Amount deposited successfully.\n");
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available.\n");
                }
                break;
            case 3:
                if (accountCount > 0) {
                    int accountNumber;
                    double amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter amount to withdraw: ");
                    scanf("%lf", &amount);

                    int found = 0;
                    for (int i = 0; i < accountCount; i++) {
                        if (accounts[i].accountNumber == accountNumber) {
                            withdraw(&accounts[i], amount);
                            printf("Amount withdrawn successfully.\n");
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available.\n");
                }
                break;
            case 4:
                if (accountCount > 0) {
                    int accountNumber;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);

                    int found = 0;
                    for (int i = 0; i < accountCount; i++) {
                        if (accounts[i].accountNumber == accountNumber) {
                            checkBalance(accounts[i]);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available.\n");
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
