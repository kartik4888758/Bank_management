accounts = {}

def create_account():
    account_number = len(accounts) + 1
    account_holder = input("Enter account holder's name: ")
    initial_balance = float(input("Enter initial balance: "))
    accounts[account_number] = {
        'account_holder': account_holder,
        'balance': initial_balance
    }
    print("Account created successfully!")

def deposit():
    account_number = int(input("Enter account number: "))
    amount = float(input("Enter the deposit amount: "))
    if account_number in accounts:
        accounts[account_number]['balance'] += amount
        print("Deposit successful!")
    else:
        print("Account not found!")

def withdraw():
    account_number = int(input("Enter account number: "))
    amount = float(input("Enter the withdrawal amount: "))
    if account_number in accounts:
        if accounts[account_number]['balance'] >= amount:
            accounts[account_number]['balance'] -= amount
            print("Withdrawal successful!")
        else:
            print("Insufficient funds!")
    else:
        print("Account not found!")

def check_balance():
    account_number = int(input("Enter account number: "))
    if account_number in accounts:
        balance = accounts[account_number]['balance']
        print(f"Account balance: ${balance:.2f}")
    else:
        print("Account not found!")

while True:
    print("\nBanking Options:")
    print("1. Create Account")
    print("2. Deposit")
    print("3. Withdraw")
    print("4. Check Balance")
    print("5. Exit")
    choice = input("Enter your choice (1/2/3/4/5): ")

    if choice == "1":
        create_account()
    elif choice == "2":
        deposit()
    elif choice == "3":
        withdraw()
    elif choice == "4":
        check_balance()
    elif choice == "5":
        print("Exiting the program. Goodbye!")
        break
    else:
        print("Invalid choice. Please select a valid option.")
