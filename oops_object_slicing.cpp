#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name = "Employee";

    virtual void work() {
        cout << "Employee working\n";
    }
};

class Developer : public Employee {
public:
    string language = "C++";

    void work() override {
        cout << "Developer coding\n";
    }

    void debugCode() {
        cout << "Debugging code\n";
    }
};

int main() {

    Developer d;

    d.name = "Ravi";
    d.language = "C++";

    // Object slicing
    Employee e = d;

    cout << "Employee name: " << e.name << endl;

    // Calls Employee::work()
    // because e is now a separate Employee object
    e.work();

    // Not possible:
    // e.language;     // ❌ Employee doesn't have language
    // e.debugCode();  // ❌ Employee doesn't have debugCode()

    // No slicing when using a pointer
    Employee* ptr = &d;

    ptr->work();      // ✅ Developer::work()

    return 0;
}
