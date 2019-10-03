//
// Created by bernam on 9/20/2019.
//

#include <iostream>

int main(int argc, char ** argv){
    using namespace std;

    // simplest possible examples
    int age = 30;
    int * age_ptr = &age;
    cout << "Age address: " << age_ptr << " and value: " << * age_ptr << endl;
    cout << "Age address: " << &age << " and value: " << age << endl; // same thing using reference operator

    // TODO :: arrays

    // TODO :: passing to pointers and references to functions

    return 0;
}