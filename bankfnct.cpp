#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include "account.h"
#include "bankfnct.h"

using namespace std;

void bankfnct::modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.data",ios::binary|ios::in|ios::out);
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
			cout<<"\n\n\n\t\tEnter The New Details of account : "<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\tRECORD NOT FOUND.. ";
}

void bankfnct::delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.data",ios::binary);
	if(!inFile)
	{
		cout<<"\t\tFile could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.data",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.data");
	rename("Temp.data","account.data");
	cout<<"\n\n\t\tACCOUNT DELETED..";
}

void bankfnct::display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.data",ios::binary);
	if(!inFile)
	{
		cout<<"\t\tFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"\t\t====================================================\n";
	cout<<"\t\tA/c No.       NAME            TYPE          BALANCE\n";
	cout<<"\t\t====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


