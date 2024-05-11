#include "oop.h"
using namespace std;

class clsScreens
{
protected :
    static void _DrawScreenHeader(string Title,string SubTitle ="")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
            cout << "\n\t\t\t\t\t  " << SubTitle;
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }
};

class clsWithdrawScreen : protected clsScreens
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nName   : " << Client.Name();
        cout << "\nEmail       : " << Client.Email();
        cout << "\nPhone       : " << Client.Phone();
        cout << "\nAcc. Number : " << Client.Id();
        cout << "\nPassword    : " << Client.Pin();
        cout << "\nBalance     : " << Client.Balance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExit(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);


        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
           if( Client1.Withdraw(Amount))
           {
            cout << "\nAmount Withdrew Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.Balance();
           }
           else
           {
               cout << "\nCannot withdraw, Insuffecient Balance!\n";
               cout << "\nAmout to withdraw is: " << Amount;
               cout << "\nYour Balance is: " << Client1.Balance();
           }
        }
        else
            cout << "\nOperation was cancelled.\n";

    }

};

class clsDepositScreen : protected clsScreens
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nName        : " << Client.Name();
        cout << "\nEmail       : " << Client.Email();
        cout << "\nPhone       : " << Client.Phone();
        cout << "\nAcc. Number : " << Client.Id();
        cout << "\nPassword    : " << Client.Pin();
        cout << "\nBalance     : " << Client.Balance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExit(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.Balance();

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};

class clsTransactionsScreen :protected clsScreens
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eShowMainMenue = 4
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        cout << "\n Balances Screen will be here.\n";
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        cin.get();
        cin.get();
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("clear");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("clear");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("clear");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
			cout << "i'm here...\n";
        }
        }
    }
public:


static void ShowTransactionsMenue()
{
    system("clear");
    _DrawScreenHeader("\t  Transactions Screen");
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] Deposit.\n";
    cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
    cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
    cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

};
