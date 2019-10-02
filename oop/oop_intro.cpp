#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        int age;
        
    public:
        string get_name(){ return name; }
        void set_name(string name){ this->name = name; }
        int get_age(){ return age; }
        void set_age(int age){ this->age = age; }
        Person(string name, int age){ this->name = name; this->age = age; }
        ~Person(){ cout << this->name << " was destroyed!" << endl; }
};

int main() {
    cout << "Hi " << Person("Mindaugas", 30).get_name() << " !" << endl;
    
    return 0;
}
