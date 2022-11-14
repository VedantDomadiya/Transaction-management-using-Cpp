/*                                                             Transaction Management using C++
                                                               by IU2141050039,26,30,69
*/

#include <iostream>
#include <conio.h>

using namespace std;

// Class function
class debit
{
public:
    int OrigBal, amount, code, total_balance = 0, credit_score, n, i;
    char name[20];

    void get();
    void display();
    void cal();
    int check_balance();
};

void debit::get()
{
    cout << "\n\nHello this is a process to debit the amount \n\n\nEnter Length of Your Name : ";
    cin >> n;
    cout << "Enter account holder's name : ";
    for (i = 0; i < n; i++)
    {
        cin >> name[i];
    }

    cout << "Enter Safety Code : ";
    cin >> code;
    cout << "Enter Your current bank balance : ";
    cin >> OrigBal;
    cout << "\n\nPlease Enter the amount you want to debit into your account : ";
    cin >> amount;
    // cout << "Transaction status: Successful" << endl;
}

void debit::display()
{
    cout << "\n\nAccount holder's name : ";
    for (i = 0; i < n; i++)
    {
        cout << name[i];
    }
    cout << "\n\n\nYour current bank balance is : " << total_balance << "\nYour Credit score is : " << credit_score;
}

void debit::cal()
{
    total_balance = OrigBal;
    total_balance = total_balance + amount;
    credit_score = amount / 10;
}

class withdraw : public debit
{
public:
    void calc()
    {
        total_balance = OrigBal;
        if (amount < total_balance)
        {
            total_balance = total_balance - amount;
        }
        else
        {
            cout << "\n\nCant withdraw the given amount :(\n";
        }
    }
    void getdata();
};

void withdraw::getdata()
{
    cout << "\n\nHello this is a process to withdraw \n\n\nEnter Length of Your Name :--";
    cin >> n;
    cout << "\n\nEnter account holder's name : ";
    for (i = 0; i < n; i++)
    {
        cin >> name[i];
    }

    cout << "\n\nEnter Safety Code";
    cin >> code;
    cout << "\n\nEnter Your bank balance : ";
    cin >> OrigBal;
    cout << "\n\nPlease Enter the amount you want to debit into your account : ";
    cin >> amount;
}

int debit::check_balance()
{
    // else if ladder
    if (total_balance < 10000)
    {
        cout << "\n\nChecking your bank balance\nYour Balance is low" << endl;
    }
    else if (total_balance < 1000)
    {
        cout << "\n\nYour current balance is extremely low, you will need to debit money to achieve minimum account balance" << endl;
    }
    else if (total_balance < 0)
    {
        cout << "\n\nInvalid amount\n";
    }
    else{
        cout<<"Transaction status : Successful"<<endl;
    }
    return 0;
}

int main()
{
    int h;
    char x;

    cout << "Hello there O_O \nEnter Your Details Carefully" << endl;

    cout << "\n\nIf u want to debit abount Enter 'd' else Enter 'w' for withdraw :--";
    cin >> x;

    if (x == 'd')
    {
        h = 1;
    }
    if (x == 'w')
    {
        h = 2;
    }

    if (h == 1)
    {
        debit d1;
        d1.get();
        d1.cal();
        d1.check_balance();
        d1.display();
    }
    else
    {
        withdraw w1;
        w1.getdata();
        w1.calc();
        w1.check_balance();
        w1.display();
    }

    return 0;
}