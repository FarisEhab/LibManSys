#include <iostream>

using namespace std;
class Base {
public:
    virtual ~Base() {}
};
class Derived : public Base {
    void hello() {
        cout << "Hello\n";
    }
};
int main() {
    
    return 0;
}