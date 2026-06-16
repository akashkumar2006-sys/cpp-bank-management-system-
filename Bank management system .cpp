#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount
{
public:
    int accountNumber;
    string name;
    double balance;

    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;
        cin.ignore();

        cout << "Enter Account Holder Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void displayAccount()
    {
        cout << "\n--------------------------";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << name;
        cout << "\nBalance        : Rs. " << balance;
        cout << "\n--------------------------\n";
    }
};

void createAccount()
{
    BankAccount acc;

    ofstream file("accounts.txt", ios::app);

    acc.createAccount();

    file << acc.accountNumber << "|"
         << acc.name << "|"
         << acc.balance << endl;

    file.close();

    cout << "\nAccount Created Successfully!\n";
}

void viewAccounts()
{
    ifstream file("accounts.txt");

    int accNo;
    string name;
    double balance;
    char separator;

    cout << "\n===== ACCOUNT RECORDS =====\n";

    while (file >> accNo)
    {
        file >> separator;
        getline(file, name, '|');
        file >> balance;

        cout << "\nAccount Number : " << accNo;
        cout << "\nName           : " << name;
        cout << "\nBalance        : Rs. " << balance;
        cout << "\n-------------------------";
    }

    file.close();
}

void searchAccount()
{
    ifstream file("accounts.txt");

    int searchAcc;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> searchAcc;

    int accNo;
    string name;
    double balance;
    char separator;

    while (file >> accNo)
    {
        file >> separator;
        getline(file, name, '|');
        file >> balance;

        if (accNo == searchAcc)
        {
            cout << "\nAccount Found!\n";
            cout << "\nName : " << name;
            cout << "\nBalance : Rs. " << balance << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nAccount Not Found!\n";

    file.close();
}

int main()
{
    int choice;

    do
    {
        cout << "\n=================================";
        cout << "\n      BANKING MANAGEMENT";
        cout << "\n=================================";
        cout << "\n1. Create Account";
        cout << "\n2. View Accounts";
        cout << "\n3. Search Account";
        cout << "\n4. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;

        case 2:
            viewAccounts();
            break;

        case 3:
            searchAccount();
            break;

        case 4:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}