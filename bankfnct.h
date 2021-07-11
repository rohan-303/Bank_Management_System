#ifndef BANKFNCT_H
#define BANKFNCT_H


class bankfnct
{
    public:

        void display_all();  //function to display all account holder's list which includes their Acc no,Name,Type of account and remaining Balance.
        void modify_account(int); //function to allow customer to modify their Name,Type of account and Balance.
        void delete_account(int); //function to delete an account.

    protected:

    private:
};

#endif // BANKFNCT_H

