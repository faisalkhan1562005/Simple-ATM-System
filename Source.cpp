#include <iostream>
using namespace std;

int main()
{
    double balance = 0.0;
    int maxTrans = 5;
    int transCount = 0;
    int pin = 1234;
    int enteredPin;
    int accountType;
    string accountTypeStr;
    double slipCharge = 2.5;
    int choice;
    bool authenticated = false;

    cout << "*** Welcome to the ATM! ***\n";
    cout << "***************************\n\n";

    // PIN Authentication
    cout << "Please enter your 4-digit PIN: ";
    while (!(cin >> enteredPin))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a numeric 4-digit PIN: ";
    }

    if (enteredPin == pin)
    {
        authenticated = true;
        cout << "PIN Verified.\n";
    }
    else
    {
        cout << "Incorrect PIN. Exiting...\n";
        return 0;
    }

    // Choose Account Type
    cout << "Select Account Type:\n";
    cout << "1. Savings\n";
    cout << "2. Current\n";
    cout << "3. Other\n";
    cout << "Enter your choice: ";

    while (!(cin >> accountType) || (accountType < 1 || accountType > 3))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
    }

    if (accountType == 1)
    {
        accountTypeStr = "Savings";
    }
    else if (accountType == 2)
    {
        accountTypeStr = "Current";
    }
    else
    {
        accountTypeStr = "Other";
    }

    cout << accountTypeStr << " Account selected.\n";

    // Set initial balance
    cout << "Enter initial balance: ";
    while (!(cin >> balance) || balance < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input: ";
    }

    // Main ATM Menu
    do
    {
        cout << "\n*** ATM Menu: ***\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Change PIN\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        while (!(cin >> choice) || (choice < 1 || choice > 5))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid option. Please enter a number between 1 and 5: ";
        }

        // Slip printing option
        int printSlip;
        switch (choice)
        {
        case 1: 
            cout << "Current balance: $" << balance << endl;
            transCount++;

            // Prompt to print slip with details
            cout << "Would you like to print a slip? (1 for Yes, 0 for No): ";
            while (!(cin >> printSlip) || (printSlip < 0 || printSlip > 1))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter 1 for Yes or 0 for No: ";
            }

            if (printSlip && balance >= slipCharge)
            {
                balance -= slipCharge;
                cout << "\n*** Transaction Slip ***\n";
                cout << "Transaction: Balance Check\n";
                cout << "Account Type: " << accountTypeStr << endl;
                cout << "Remaining balance: $" << balance << endl;
                cout << "Slip Charge: $" << slipCharge << endl;
                cout << "****************************\n";
            }
            else if (printSlip && balance < slipCharge)
            {
                cout << "Insufficient balance for slip charge.\n";
            }
            break;


        case 2: // Deposit
        {
            double deposit;
            cout << "Enter amount to deposit: ";
            while (!(cin >> deposit) || deposit <= 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a positive deposit amount: ";
            }
            balance += deposit;
            cout << "You deposited: $" << deposit << endl;
            cout << "New balance: $" << balance << endl;
            transCount++;

            // Prompt to print slip with details
            cout << "Would you like to print a slip? (1 for Yes, 0 for No): ";
            while (!(cin >> printSlip) || (printSlip < 0 || printSlip > 1))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter 1 for Yes or 0 for No: ";
            }

            if (printSlip && balance >= slipCharge)
            {
                balance -= slipCharge;
                cout << "\n*** Transaction Slip ***\n";
                cout << "Transaction: Deposit\n";
                cout << "Amount Deposited: $" << deposit << endl;
                cout << "Account Type: " << accountTypeStr << endl;
                cout << "Remaining balance: $" << balance << endl;
                cout << "Slip Charge: $" << slipCharge << endl;
                cout << "***********************************\n";
            }
            else if (printSlip && balance < slipCharge)
            {
                cout << "Insufficient balance for slip charge.\n";
            }
            break;
        }

        case 3: // Withdraw
        {
            double withdraw;
            cout << "Enter amount to withdraw: ";
            while (!(cin >> withdraw) || withdraw <= 0 || withdraw > balance)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                if (withdraw > balance)
                {
                    cout << "Insufficient funds. Enter a smaller amount: ";
                }
                else
                {
                    cout << "Invalid input. Please enter a positive amount within your balance: ";
                }
            }
            balance -= withdraw;
            cout << "You withdrew: $" << withdraw << endl;
            cout << "New balance: $" << balance << endl;
            transCount++;

            // Prompt to print slip with details
            cout << "Would you like to print a slip? (1 for Yes, 0 for No): ";
            while (!(cin >> printSlip) || (printSlip < 0 || printSlip > 1))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter 1 for Yes or 0 for No: ";
            }

            if (printSlip && balance >= slipCharge)
            {
                balance -= slipCharge;
                cout << "\n****** Transaction Slip ******\n";
                cout << "Transaction: Withdrawal\n";
                cout << "Amount Withdrawn: $" << withdraw << endl;
                cout << "Account Type: " << accountTypeStr << endl;
                cout << "Remaining balance: $" << balance << endl;
                cout << "Slip Charge: $" << slipCharge << endl;
                cout << "*********************************\n";
            }
            else if (printSlip && balance < slipCharge)
            {
                cout << "Insufficient balance for slip charge.\n";
            }
            break;
        }

        case 4: // Change PIN
        {
            int oldPin, newPin;
            cout << "Enter your current PIN: ";
            while (!(cin >> oldPin))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a numeric PIN: ";
            }

            if (oldPin == pin)
            {
                cout << "Enter new PIN: ";
                while (!(cin >> newPin))
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input. Please enter a numeric PIN: ";
                }
                pin = newPin;
                cout << "PIN changed successfully.\n";
            }
            else
            {
                cout << "Incorrect current PIN.\n";
            }
            break;
        }


        case 5: 
            cout << "** Thank you for using the ATM! Goodbye **\n";
            break;
        }

        // Transaction limit check
        if (transCount >= maxTrans)
        {
            cout << "Transaction limit reached. Exiting...\n";
            break;
        }
    } while (choice != 5);

    return 0;
}