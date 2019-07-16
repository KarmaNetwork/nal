#include <iostream>
#include <string>

using namespace std;

template <typename Impl>
struct Interface {
    inline bool operator == (const Impl &other) {
        cout << "call Interfaces other" << endl;
        return true;
    }

    void mixin() {
        cout << "mixin" << endl;
    }

    inline operator int() {
        return 10;
    }

    Interface (const string &s) {
        cout << s << endl;
    }
};

struct Child: Interface<Child> {
    using Interface<Child>::Interface;
};

int main() {
    Child a("hello");
    return 0;
}

