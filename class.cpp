#include"func.h"
int account ::retac() const { return ac; }
int account ::retdeposit() const { return deposit; }
char account ::rettype() const { return type; }
void account ::show_account()
{
    cout << "\n Account number : " << ac;
    cout << "\n Account holder name : " << name;
    cout << "\n Type of account : " << type;
    cout << "\n Balance amount : " << deposit;
}
void account ::report() const
{
    cout << ac << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}
void account ::dep(int x) { deposit += x; }
void account ::draw(int x) { deposit -= x; }
void account ::create_account()
{
    cout << "\n Enter the account number : ";
    cin >> ac;
    cout << "\n Enter the name of account holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n Enter the type of the account (C/S) : ";
    cin >> type;
    type = toupper(type);
    cout << "\n Enter the initial amount (>=500 for Saving and >=1000 for current ) : ";
    cin >> deposit;
    cout << "\n\n Account Created..";
}
void account ::modify()
{
    cout << "\n Account number : " << ac;
    cout << "\n Modify account holder name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n Modify type of account : ";
    cin >> type;
    type = toupper(type);
    cout << "\n Modify balance amount : ";
    cin >> deposit;
}