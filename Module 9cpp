#include <iostream>
#include <string>
using namespace std;

// Base Class
class User {
protected:
    string username;

public:
    User(string name) {
        username = name;
    }

    // Virtual function
    virtual void accessLevel() {
        cout << username << " has general access.\n";
    }

    // Virtual destructor (good practice)
    virtual ~User() {}
};

// Derived Class: Employee
class Employee : public User {
public:
    Employee(string name) : User(name) {}

    void accessLevel() override {
        cout << username << " (Employee): View inventory only.\n";
    }
};

// Derived Class: Manager
class Manager : public User {
public:
    Manager(string name) : User(name) {}

    void accessLevel() override {
        cout << username << " (Manager): View and update inventory.\n";
    }
};

// Derived Class: Admin
class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void accessLevel() override {
        cout << username << " (Admin): Full access (add, update, delete inventory).\n";
    }
};

int main() {
    // Create objects
    User* u1 = new Employee("Alice");
    User* u2 = new Manager("Bob");
    User* u3 = new Admin("Charlie");

    // Demonstrate polymorphism
    u1->accessLevel();
    u2->accessLevel();
    u3->accessLevel();

    // Clean up memory
    delete u1;
    delete u2;
    delete u3;

    return 0;
}
