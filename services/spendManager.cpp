#include "spendManager.h"
using namespace std;

void spendManager::addUser(User* user)
{
    if (user == nullptr)
        return;

    string id = user->getUserId();
    users[id] = user;
}



void spendManager::addExpense(Expense* expense)
{
    
    if (expense == nullptr)
        return;

    
    expenses.push_back(expense);
}



User* spendManager::getUser(string userId)
{
    
    if (users.find(userId) != users.end())
    {
        return users[userId];
    }

    
    return nullptr;
}


vector<Expense*>& spendManager::getAllExpenses()
{
    return expenses;
}


vector<User*> spendManager::getAllUsers()
{
    
    vector<User*> allUsers;

    
    for (auto& entry : users)
    {
        allUsers.push_back(entry.second);
    }

    
    return allUsers;
}