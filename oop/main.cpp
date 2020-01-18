#include <iostream>
#include "Person.hpp"

using namespace std;

ostream& operator<< (ostream& outs, Person& obj) {
    return outs << obj.toString();
}

int main() {
    Person p1;
    p1.setage(15);
    p1.setName("Mindaugas");
    p1.setHeight(180.5);

    cout << p1.toString() << endl;
    cout << p1 << endl;
}