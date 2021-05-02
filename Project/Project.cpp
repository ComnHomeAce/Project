// Project.cpp : This program simulates an ATM.

#include <iostream>
#include <iomanip>
using namespace std;

int mainMenu()
{
    int input;

    //Print menu
    cout << "\n     Main Menu";
    cout << "\n--------------------";
    cout << "\n1. Sign in";
    cout << "\n2. Balance";
    cout << "\n3. Deposit";
    cout << "\n4. Withdraw";
    cout << "\n5. Exit\n";
    cout << "\nMake a selection: ";

    //Get input
    cin >> input;

    //Return input and pass to selection
    return input;
}

void invalidEntry()
{
    //Print warning
    cout << "\n***Warning: Invalid entry***\n";
}

 
int main()
{
    int selection;  //Menu selection
    int account;    //Selected account number and index for accounts array
    double amount;  //Amount used for deposits and withdrawals

    //Set precision to always display two decimal places
    cout << fixed << setprecision(2);

    //Set initial value of sign in status to false
    bool signedIn = 0;

    //Initialize accounts array and load balances
    double accounts[10];
    for (int i = 0; i < 10; i++)
    {
        accounts[i] = 1000.00;
    }

    for (;;) //Infinite loop to keep user in menu
    {
        //Welcome message
        cout << "\n=======================================";
        cout << "\n============= Welcome  To =============";
        cout << "\n========== N.U. Credit Union ==========";
        cout << "\n============ San Diego, CA ============";
        cout << "\n=======================================\n";

        //Menu structure and loop when NOT signed in
        while (signedIn == 0)
        {
            //Print main menu and get selection
            selection = mainMenu();

            //Switch to force sign in
            switch (selection)
            {
            case 1: //Get account number
                cout << "\nEnter account number: ";
                cin >> account;

                //Loop for invalid account number entry
                while (account < 0 || account > 9)
                {
                    //Print warning
                    invalidEntry();

                    //Get account number
                    cout << "\nEnter account number: ";
                    cin >> account;
                }
                //Print successful sign in
                cout << "\nSigned in to account #" << account << "\n";
                
                //Set sign in status to true
                signedIn = 1;
                break;

            default: //Failing to select 'Sign in'
                //Print warning
                invalidEntry();
                break;
            }
        }

        //Menu structure and loop when signed in
        while (signedIn == 1)
        {
            //Switch for menu selections
            switch (selection = mainMenu())
            {
            case 1: //Sign in
                //Print warning
                invalidEntry();
                cout << "\nYou're already signed in to account #" << account << ". Select a different menu option.\n";
                cout << "\nSelect 'Exit' to be able to sign in to another account.\n";
                break;

            case 2: //Balance
                //Print balance
                cout << "\nBalance: $" << accounts[account] << "\n";

                //Print low balance warning
                if (accounts[account] < 100)
                    cout << "\n***Warning: Low balance***\n";
                break;

            case 3: //Deposit
                //Get amount
                cout << "\nEnter deposit amount: $";
                cin >> amount;

                if (amount > 0) //Deposit success
                {
                    //Update balance
                    accounts[account] += amount;
                    
                    //Print balance
                    cout << "\nBalance: $" << accounts[account] << "\n";
                }
                else //Deposit fail #1
                {
                    //Print warning
                    cout << "\n***Warning: Invalid amount***\n";
                    
                    //Get amount
                    cout << "\nEnter deposit amount: $";
                    cin >> amount;

                    if (amount > 0) //Deposit success
                    {
                        //Update balance
                        accounts[account] += amount;
                        
                        //Print balance
                        cout << "\nBalance: $" << accounts[account] << "\n";
                    }
                    else //Deposit fail #2
                    {
                        //Print warning
                        cout << "\n***Warning: Invalid amount***\n";
                    }
                }
                break;

            case 4: //Withdraw
                //Get amount
                cout << "\nEnter withdrawal amount: $";
                cin >> amount;

                if (accounts[account] - amount > 0) //Withdrawal success
                {
                    //Update balance
                    accounts[account] -= amount;

                    //Print balance
                    cout << "\nBalance: $" << accounts[account] << "\n";
                }
                else //Withdrawal fail #1
                {
                    //Print warning
                    cout << "\n***Warning: Insuficient balance***\n";

                    //Print balance
                    cout << "\nBalance: $" << accounts[account] << "\n";

                    //Get amount
                    cout << "\nEnter withdrawal amount: $";
                    cin >> amount;

                    if (accounts[account] - amount > 0) //Withdrawal success
                    {
                        //Update balance
                        accounts[account] -= amount;
                        
                        //Print balance
                        cout << "\nBalance: $" << accounts[account] << "\n";
                    }
                    else //Withdrawal fail #2
                    {
                        //Print warning
                        cout << "\n***Warning: Insuficient balance***\n";
                        
                        //Print balance
                        cout << "\nBalance: $" << accounts[account] << "\n";
                    }
                }
                break;

            case 5: //Exit
                //Print exit message
                cout << "\nGood bye. Signed out of account #" << account << "\n";
                
                //Set sign in status to false
                signedIn = 0;
                break;

            default: //Invalid entry
                //Print warning
                invalidEntry();
                break;
            }
        }
    }
}