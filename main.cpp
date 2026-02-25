#include<bits/stdc++.h>
#include "models/User.h"
#include "models/Expense.h"
#include "services/spendManager.h"
#include "services/Balance.h"

using namespace std;

int idCounter = 1;

string generateId() {
    return "EXP" + to_string(idCounter++);
}

int main() {
    spendManager userManager;
    Balance balanceTracker;

    int choice = 0;
    cout << "Welcome to Splitwise\n";

    while (true) {
        cout << "         MENU             \n";
        cout<<"******************************\n";
        cout << "1. Add user\n";
        cout << "2. Add expense\n";
        cout << "3. Show all users\n";
        cout << "4. Payback from user 1 to user 2\n";
        cout << "5. Show how much a user owes\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin>>choice;
        

        if (choice == 1) {
            string id, name;
            cout << "Enter ID: "; 
            cin >> id;
            cout << "Enter Name: "; 
            cin >> name;
            User* newUser = new User(id, name);
            userManager.addUser(newUser);
            cout << "User added.\n";
        } 
        else if (choice == 2) {
            string payerId, desc;
            double amount;
            int n;
            cout << "Payer ID: ";
             cin >> payerId;
            User* payer = userManager.getUser(payerId);
            if (!payer) { 
                cout << "User not found!\n"; 
                continue; 
            }
            
            cout << "Description: ";
             cin >> desc;
            cout << "Amount: "; 
            cin >> amount;
            cout << "Number of participants: "; 
            cin >> n;
            
            vector<User*> participants;
            cout << "Enter IDs of people with whom you want to split:\n";
            for(int i=0; i<n; i++) {
                string pid;
                cin >> pid;
                User* p = userManager.getUser(pid);
                if(p) participants.push_back(p);
            }
            string expId = generateId();//
            Expense* newExp = new Expense(expId, desc, amount, payer, participants);
            userManager.addExpense(newExp);
            balanceTracker.updateBalances(newExp);
            cout << "Expense added and balances updated.\n";
        }
        else if (choice == 3) {
            vector<User*> all = userManager.getAllUsers();
            if (all.empty()) {
                cout << "No users registered yet.\n";
            } else {
                cout << "--- Registered Users ---\n";
                for(User* u : all) cout << u->getName() << endl;
            }
        }
        else if (choice == 4) {
            string from, to;
            double amt;
            cout << "From (ID): ";
             cin >> from;
            cout << "To (ID): ";
            cin >> to;
            cout << "Amount: "; 
            cin >> amt;
            balanceTracker.payback(from, to, amt);
        }
        else if (choice == 5) {
            string id;
            cout << "Enter User ID: ";
            cin >> id;
            balanceTracker.showUserDebts(id);
        }
        else if (choice == 6) {
            cout << "Exit!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please pick a number between 1 and 6.\n";
        }
    }

    return 0;
}

