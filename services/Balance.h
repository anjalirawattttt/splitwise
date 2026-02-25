#ifndef BALANCE_H
#define BALANCE_H

#include<bits/stdc++.h>
using namespace std;
#include "../models/Expense.h"

class Balance {
private:
    // {A -> [{B,X ruppes} , {C,Y ruppes}]}
    unordered_map<string,unordered_map< string, double>> balances;
    unordered_map<string, string> userIdToName;

public:
    void updateBalances(Expense* expense);
    void showBalances();
    void payback(string fromId, string toId, double amount);
    void showUserDebts(string userId);
};

#endif
