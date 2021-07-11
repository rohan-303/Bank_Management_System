#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include "account.h"
#include "bankfnct.h"
#include "customerfnct.h"
#include "intro.h"

using namespace std;

int main()
{
        char ch;
        bankfnct bf;
        customerfnct cf;
        intro i;
	int num;
	i.introduction();
	do
	{
	    cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<"    "<<"*************************"<<endl;
	    cout<<"\t\t\t\t"<<"    *"<<"\t    MAIN MENU\t"<<"    *"<<endl;
	    cout<<"\t\t\t\t"<<"    "<<"*************************"<<endl;
	    cout<<"\n\t\t-----------------------------------------------------------------"<<endl;
	    cout<<"\t\t|"<<" 01 "<<"|"<<" NEW ACCOUNT \t\t||"<<" 02 "<<"|"<<" DEPOSIT MONEY \t\t|"<<endl;
	    cout<<"\t\t-----------------------------------------------------------------"<<endl;
	    cout<<"\t\t|"<<" 03 "<<"|"<<" WITHDRAW MONEY \t\t||"<<" 04 "<<"|"<<" BALANCE ENQUIRY \t|"<<endl;
	    cout<<"\t\t-----------------------------------------------------------------"<<endl;
	    cout<<"\t\t|"<<" 05 "<<"|"<<" ALL ACCOUNT HOLDER LIST \t||"<<" 06 "<<"|"<<" CLOSE AN ACCOUNT \t|"<<endl;
	    cout<<"\t\t-----------------------------------------------------------------"<<endl;
	    cout<<"\t\t|"<<" 07 "<<"|"<<" MODIFY AN ACCOUNT \t||"<<" 08 "<<"|"<<" EXIT \t\t\t|"<<endl;
	    cout<<"\t\t-----------------------------------------------------------------"<<endl;
		cout<<"\n\n\t\tSelect Your Option (1-8) :  ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			cf.write_account();
			break;
		case '2':
			cout<<"\n\n\t\tEnter The account No. : "; cin>>num;
			cf.deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\t\tEnter The account No. : "; cin>>num;
			cf.deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\t\tEnter The account No. : "; cin>>num;
			cf.display_sp(num);
			break;
		case '5':
			bf.display_all();
			break;
		case '6':
			cout<<"\n\n\t\tEnter The account No. : "; cin>>num;
			bf.delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\t\tEnter The account No. : "; cin>>num;
			bf.modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\t\t\tThank you for visiting.."<<endl;
			cout<<"\t\t\tPress Any Key to Exit"<<endl;
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
}

