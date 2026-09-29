#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Department {
public:
    string name;

    Department(string name) : name(name) {
        cout << "Department created: " << name << endl;
    }

    ~Department() {
        cout << "Department destroyed: " << name << endl;
    }
};

class Profile {
public:
    string email;

    Profile(string email) : email(email) {
        cout << "Profile created: " << email << endl;
    }

    ~Profile() {
        cout << "Profile destroyed: " << email << endl;
    }
};

class Employee {
private:
    // Employee exclusively owns the Profile
    unique_ptr<Profile> profile;

    // Employee shares ownership of Department
    shared_ptr<Department> department;

    // Employee can observe Department but does NOT own it
    weak_ptr<Department> departmentObserver;

public:
    Employee(string email, shared_ptr<Department> dept)
        : profile(make_unique<Profile>(email)),
          department(dept),
          departmentObserver(dept) {}

    void showDetails() {
        cout << "Email: " << profile->email << endl;

        cout << "Department: "
             << department->name << endl;

        // weak_ptr must be converted to shared_ptr before accessing
        if (auto dept = departmentObserver.lock()) {
            cout << "Observed Department: "
                 << dept->name << endl;
        }
    }
};

int main() {

    // -------------------------------
    // 1. shared_ptr
    // -------------------------------

    auto securityDept =
        make_shared<Department>("Cyber Security");

    cout << "Reference count: "
         << securityDept.use_count() << endl;


    // -------------------------------
    // 2. Create Employees
    // -------------------------------

    Employee e1("alice@company.com", securityDept);
    Employee e2("bob@company.com", securityDept);

    cout << "Reference count: "
         << securityDept.use_count() << endl;


    // -------------------------------
    // 3. Use the objects
    // -------------------------------

    e1.showDetails();
    e2.showDetails();


    // -------------------------------
    // 4. unique_ptr example
    // -------------------------------

    auto profile = make_unique<Profile>("extra@company.com");

    // auto anotherProfile = profile;        // ❌ Cannot copy

    auto anotherProfile = move(profile);     // ✅ Ownership transferred

    cout << "Profile email: "
         << anotherProfile->email << endl;


    // profile is now nullptr
    if (!profile) {
        cout << "profile no longer owns the Profile" << endl;
    }


    // -------------------------------
    // Program ends
    // -------------------------------

    return 0;
}
