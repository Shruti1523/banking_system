#include "func.h"

void write_account()
{
    account acc;
    ofstream file;
    file.open("Account.dat", ios::binary | ios::app);
    acc.create_account();
    file.write(reinterpret_cast<char*>(&acc),sizeof(account));
    file.close();
}
void dep_draw(int n , int choice)
{
    int amount,balance;
    account acc;
    bool found= false;
    fstream file;
    file.open("Account.dat", ios::binary | ios::in | ios::out);
    if(!file)
    {
        cout<<"File could not be open !! Press any key...";
		return;
    }
    while(!file.eof() && found==false)
    {
        file.read(reinterpret_cast<char*>(&acc),sizeof(account));
        if(acc.retac()==n)
        {
            acc.show_account();
            if(choice==1)
            {
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter the amount to be deposited...";
				cin>>amount;
				acc.dep(amount);
            }
            if(choice==2)
            {
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw...";
				cin>>amount;
                balance=acc.retdeposit()-amount;
                if((balance<500 && acc.rettype()=='S') || (balance<1000 && acc.rettype()=='C'))
                {
                    cout<<"\tINSUFFICIENT BALANCE";
                }
                else
                {
                    acc.draw(amount);
                }
            }
            int pos=(-1)*static_cast<int>(sizeof(acc));
            file.seekp(pos,ios::cur);
            file.write(reinterpret_cast<char *> (&acc), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
        }

    }
    file.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
}
void display(int n)
{
    account acc;
    bool flag=false;
    ifstream file;
    file.open("Account.dat", ios::binary);
    if(!file)
	{
		cout<<"\n File could not be open !! Press any key...";
		return;
	}
    while(!file.eof() && flag==false)
    {
        file.read(reinterpret_cast<char*>(&acc),sizeof(account));
        if(acc.retac()==n)
        {
            cout<<"\n BALANCE DETAIL\n : ";
            acc.show_account();
            flag=true;
        }
    }
    if(flag==false)
        cout<<"\n Account number does not exist. ";
        file.close();
}
void display_all ()
{
    account acc;
    ifstream file;
    file.open("Account.dat", ios::binary);
    if(!file)
    {
        cout<<"File could not be open !! Press any key...";
		return;
    }
    cout<<"\n\n\t\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
    while(file.read(reinterpret_cast<char*>(&acc),sizeof(account)))
    {
        acc.report();
    }
    file.close();
}
void delete_account(int n)
{
    account acc;
    ifstream infile;
    ofstream outfile;
    infile.open("Account.dat", ios::binary );
    if(!infile)
	{
		cout<<"File could not be open !! Press any key...";
		return;
	}
    infile.seekg(0,ios::beg);
    outfile.open("Temp.dat", ios::binary );
    while(infile.read(reinterpret_cast<char*>(&acc), sizeof(account)))
    {
        if(acc.retac()!=n)
        {
            outfile.write(reinterpret_cast<char*>(&acc), sizeof(account));
        }
    }
    infile.close();
    outfile.close();
    remove("Account.dat");
    rename("Temp.dat","Account.dat");
    cout<<"\n\t RECORD DELETED...";
}
void modify_account(int n)
{
    account acc;
    bool flag=false;
    fstream file;
    file.open("Account.dat", ios::binary | ios ::in | ios::out);
    if(!file)
    {
        cout<<"\n File could not be open !! Press any key...";
		return;
    }
    while(!file.eof() && flag==false )
    {
        file.read(reinterpret_cast<char*>(&acc),sizeof(account));
        if(acc.retac()==n)
        {
            acc.show_account();
            cout<<"\n Enter the new details of the account : ";
            acc.modify();
            int pos= (-1)*static_cast<int>(sizeof(account));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char*>(&acc), sizeof(account));
            cout<<"\n\n\t Record Updated";
			flag=true;
        }
         if(flag==false)
            cout<<"\n Account number does not exist. ";
        file.close();
    }
}
