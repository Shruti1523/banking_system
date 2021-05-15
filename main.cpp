#include "func.h"
int main()
{
    int num;
    char n;
    do
    {
        cout << "\n\n\t MAIN MENU";
        cout << "\n\n\t 01. NEW ACCOUNT";
        cout << "\n\n\t 02. DEPOSIT AMOUNT";
        cout << "\n\n\t 03. WITHDRAW AMOUNT";
        cout << "\n\n\t 04. BALANCE ENQUIRY";
        cout << "\n\n\t 05. ALL ACCOUNT HOLDER LIST";
        cout << "\n\n\t 06. CLOSE AN ACCOUNT";
        cout << "\n\n\t 07. MODIFY AN ACCOUNT";
        cout << "\n\n\t 08. EXIT";
        cout << "\n\n\t SELECT YOUR OPTION (1-8)...";
        cin >> n;
        system("cls");
        switch (n)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout << "\n\n\t Enter the account no. : ";
            cin >> num;
            dep_draw(num, 1);
            break;
        case '3':
            cout << "\n\n\t Enter the account no. : ";
            cin >> num;
            dep_draw(num, 2);
            break;
        case '4':
            cout << "\n\n\t Enter the account no. : ";
            cin >> num;
            display(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            cout << "\n\n\t Enter the account no. : ";
            cin >> num;
            delete_account(num);
            break;
        case '7':
            cout << "\n\n\t Enter the account no. : ";
            cin >> num;
            modify_account(num);
            break;
        case '8':
            cout << "\n\n\t Thanks for using bank management system. ";
            exit(0);
            break;
        default:
            cout << "\a";
            break;
        }
        cin.ignore();
        cin.get();
    } while (n != 8);
    return 0;
}