#ifndef EXPENSE_H
#define EXPENSE_H

#include<bits/stdc++.h>
using namespace std;

#include "User.h"

class Expense {

    private:
        static string expenseId; //unique for each expense
        string description;//Given by user 
        double totalAmount;
        User* paidBy;//user object
        vector<User*> participants;//all users

    public:
        Expense(string ExpId , string desc, double amount, User* payer, vector<User*> group);

         string getExpenseId();

        string getDescription() ;

        double getTotalAmount() ;

        User* getPayer();

        vector<User*> getParticipants() ;
};

#endif
