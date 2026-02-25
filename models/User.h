#include<bits/stdc++.h>
#ifndef USER_H
#define USER_H


using namespace std;
class User {
private:
    string userId;
    string name;

public:
    User(const string &id, const string &n);
    string getUserId() const;
    string getName() const;
};

#endif