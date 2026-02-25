#include "Expense.h"

#include<bits/stdc++.h>

string generateID(){
    string id = "";
    for(int i = 0;i<4;i++){
        id += to_string(rand()%10);
    }
    return id;
}

Expense::Expense(string ExpId , string desc, double amount, User* payer, vector<User*> group) {
    ExpId = "EXP" + generateID();
    description = desc;
    totalAmount = amount;
    paidBy = payer;
    participants = group;
}

 string Expense::getDescription()  {
    return description;
}

double Expense::getTotalAmount()  {
    return totalAmount;
}

User* Expense::getPayer()  {
    return paidBy;
}

 vector<User*> Expense::getParticipants()  {
    return participants;
}
