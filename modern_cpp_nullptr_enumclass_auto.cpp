#include <iostream>
using namespace std;

enum class Status {
    SUCCESS,
    FAILED
};

int main() {

    auto x = 10;

    int* ptr = nullptr;

    Status status = Status::SUCCESS;

    cout << x << endl;

    if (ptr == nullptr) {
        cout << "Null pointer\n";
    }

    if (status == Status::SUCCESS) {
        cout << "Success\n";
    }
}