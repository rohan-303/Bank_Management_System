#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include "account.h"
using namespace std;

void account::create_account()
{
	cout<<"\n\n\n\n\t\tEnter The account No. :";
	cin>>acno;
	cout<<"\n\t\tEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\tEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\tEnter The Initial amount(MIN of 500 for Saving and MIN of 1000 for current ) : ";
	cin>>deposit;
	cout<<"\n\n\n\t\t\t\t\tACCOUNT CREATED..........";
}

void account::show_account() const
{
	cout<<"\n\t\tAccount No. : "<<acno;
	cout<<"\n\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\tType of Account : "<<type;
	cout<<"\n\t\tBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\n\t\tAccount No. : "<<acno;
	cout<<"\n\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\tModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() const
{
	cout<<"\t\t"<<acno<<setw(10)<<" "<<name<<setw(15)<<" "<<type<<setw(17)<<deposit<<endl;
}


int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}


