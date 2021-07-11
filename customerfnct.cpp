#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include "account.h"
#include "customerfnct.h"

using namespace std;
void customerfnct::write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.data",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}
void customerfnct::display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.data",ios::binary);
	if(!inFile)
	{
		cout<<"\t\tFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tBALANCE DETAILS : \n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\n\t\tPLEASE CHECK AGAIN, ACCOUNT NUMBER INSERTED DOES NOT EXIST.";
}

void customerfnct::deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.data", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\t\tFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\tTO DEPOSIT AMOUNT ";
				cout<<"\n\t\tEnter The amount to get deposited : ";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\t\tTO WITHDRAW AMOUNT ";
				cout<<"\n\t\tEnter The amount to be withdraw : ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"\n\t\tINSUFFICIENT BALANCE";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\tRECORD UPDATED..";
			found=true;
	       }
         }
	File.close();
	if(found==false){
                cout<<"\n\n\t\tPLEASE CHECK AGAIN, ACCOUNT NUMBER INSERTED DOES NOT EXIST.";
		cout<<"\n\n\t\tRECORD NOT FOUND ";}
}


