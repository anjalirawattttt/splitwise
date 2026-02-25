#ifndef SPENDMANAGER_H
#define SPENDMANAGER_H

#include <bits/stdc++.h>
#include "../models/User.h"
#include "../models/Expense.h"

class spendManager
{
private:
    // user id and user ka object save kro
    unordered_map<string, User *> users;
    // y particular user k all obj store krega
    vector<Expense *> expenses;

public:
    void addUser(User *user); // map m user add krdega

    void addExpense(Expense *expense); // expense add krdenge

    User *getUser(string userId); // get particular user

    vector<Expense *> &getAllExpenses(); // get all expenses

    vector<User*> getAllUsers();
};

#endif
