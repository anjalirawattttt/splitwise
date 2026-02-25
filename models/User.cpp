#include "User.h"
#include <string>
using namespace std;

User::User(const string& id, const string& n) {
    userId = id;
    name = n;
}

string User::getUserId() const {
    return userId;
}

string User::getName() const {
    return name;
}