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
        ~Person(){ 
            // cout << this->name << " was destroyed!" << endl; 
        }
};

class Util {
    public:
        static void bubble_sort(Person people[], int size){
            for(unsigned int i = 0; i < size; i++){
                bool sorted = true;
                for(unsigned int j = 0; j < size-i-1; j++) {
                    if (people[j].get_age() > people[j + 1].get_age()) {
                        sorted = false;
                        Person temp = people[j];
                        people[j] = people[j + 1];
                        people[j + 1] = temp;
                    }
                }
                if(sorted)
                    break;
            }
        }
};

int main() {
    Person people[] = { 
        Person("Mindaugas", 30), 
        Person("Tadas", 37), 
        Person("Lopas", 29)
    };
    
    int size = sizeof(people)/sizeof(people[0]);
    
    cout << "Before sorting: ";
    for(int i = 0; i < size; i++){
        cout << "{ " + people[i].get_name() + " is " + to_string(people[i].get_age()) + " }";
    }
    
    Util::bubble_sort(people, size);
    
    cout << "\nAfter sorting: ";
    for(int i = 0; i < size; i++){
        cout << "{ " + people[i].get_name() + " is " + to_string(people[i].get_age()) + " }";
    }
    
    return 0;
}
