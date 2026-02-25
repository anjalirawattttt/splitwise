#include "Balance.h"
#include <bits/stdc++.h>
using namespace std;

void Balance::updateBalances(Expense *expense)
{
    if (expense == nullptr)
        return; // koi expense nhi h

    User *payer = expense->getPayer();
    userIdToName[payer->getUserId()] = payer->getName();

    vector<User *> participants = expense->getParticipants();
    for(User* p : participants) {
        userIdToName[p->getUserId()] = p->getName();
    }

    double totalAmount = expense->getTotalAmount();

    //imp point - > isme totalAmt/users
    double share = totalAmount / participants.size();

    for (User *participant : participants)
    {
        //khudko pay nhi kr skte 
        if (participant->getUserId() == payer->getUserId())
            continue;

        // participant owes payer 'share'
        string u1 = participant->getUserId();
        string u2 = payer->getUserId();

        double amountToPay = share;

        // Agr payer ne already cash de rkhe h to leave it 
        if (balances.count(u2) && balances[u2].count(u1) && balances[u2][u1] > 0)
        {
            double amountToReduce = min(balances[u2][u1], amountToPay);
            balances[u2][u1] -= amountToReduce;
            amountToPay -= amountToReduce;
        }
        //else pse dedo
        if (amountToPay > 0)
        {
            balances[u1][u2] += amountToPay;
        }
    }
}

void Balance::showBalances()
{
    bool hasBalance = false;
    cout << endl
         << "--- Current Balances ---" << endl;

    for (auto const &payer : balances)
    {
        string giver = payer.first;
        for (auto const &payee : payer.second)
        {
            string lender = payee.first;
            double amount = payee.second;
            if (amount > 0)
            { 
                string giverName = userIdToName.count(giver) ? userIdToName[giver] : giver;
                string lenderName = userIdToName.count(lender) ? userIdToName[lender] : lender;
                cout << giverName << " owes " << lenderName << ": " << amount << endl;
                hasBalance = true;
            }
            else
            {
                cout << "Enter valid amount" << endl;
            }
        }
    }
    if (!hasBalance)
    {
        cout << "No balances outstanding." << endl;
    }
}

void Balance::payback(string fromId, string toId, double amount) {
    if (balances[fromId][toId] >= amount) {
        balances[fromId][toId] -= amount;
        cout << "Payment of " << amount << " recorded.\n";
    } else {
        double currentDebt = balances[fromId][toId];
        balances[fromId][toId] = 0;
        double extra = amount - currentDebt;
        balances[toId][fromId] += extra;
        cout << "Debt cleared! Extra " << extra << " is now owed by " << toId << " to " << fromId << endl;
    }
}

void Balance::showUserDebts(string userId) {
    bool found = false;
    string currentUserName = userIdToName.count(userId) ? userIdToName[userId] : userId;
    cout << "--- Debts for " << currentUserName << " ---\n";
    
    // What user owes others
    if (balances.count(userId)) {
        for (auto const& pair : balances[userId]) {
            if (pair.second > 0) {
                string otherId = pair.first;
                string otherName = userIdToName.count(otherId) ? userIdToName[otherId] : otherId;
                cout << "You owe " << otherName << ": " << pair.second << endl;
                found = true;
            }
        }
    }

    // What others owe user
    for (auto const& outerPair : balances) {
        if (outerPair.second.count(userId) && outerPair.second.at(userId) > 0) {
            string otherId = outerPair.first;
            string otherName = userIdToName.count(otherId) ? userIdToName[otherId] : otherId;
            cout << otherName << " owes you: " << outerPair.second.at(userId) << endl;
            found = true;
        }
    }

    if (!found) cout << "No pending debts.\n";
}
