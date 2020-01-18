#include <math.h>
#include <iostream>
#include "Person.hpp"

// can use namespaces in cpp files
using namespace std;

Person::Person(){ cout << "Person created!" << endl; }
Person::~Person(){ cout << this->name << " was destroyed!" << endl; }

string Person::removeTrailingZeros(string original) {
    while(original.find(".") != string::npos
        && (original.substr(original.length()-1, 1) == "0"
        || original.substr(original.length()-1, 1) == "."))
    {
        original.pop_back();
    }
    return original;
}

string Person::getName(){
    return this->name;
}

void Person::setName(string name){
    (*this).name = name;
    // this->name = name;
}

int Person::getAge(){
    return this->age;
}

void Person::setage(int age){
    this->age = age;
}

double Person::getHeight(){
    return this->height;
}

void Person::setHeight(double height){
    this->height = height;
}

string Person::toString() {
    return "Person: { age: " + to_string(this->age)
           + ", height: " + removeTrailingZeros(to_string(this->height))
           + ", name: "   + this->name + " }";
}