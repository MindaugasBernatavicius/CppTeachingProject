#include <iostream>
#include <string>
#include <functional>

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
        
        // when we sort, we only need to change the possitions of  the adjecent variables 
        // if second is bigger (sorting in decreasing order) or second is smaller (reverse). 
        // If they are equal or if the order is correct, we don't need to change anything
        static bool compare_inc(Person p1, Person p2){
            return (p1.age == p2.age || p1.age > p2.age) ? true : false;
        }
        
        static bool compare_dec(Person p1, Person p2){
            return (p1.age == p2.age || p1.age < p2.age) ? true : false;
        }
};

class Animal {
    private:
        string name;
        int weight;
        
    public:
        string get_name(){ return name; }
        void set_name(string name){ this->name = name; }
        int get_weight(){ return weight; }
        void set_weight(int weight){ this->weight = weight; }
        Animal(string name, int weight){ this->name = name; this->weight = weight; }
        ~Animal(){}

        static bool compare_inc(Animal a1, Animal a2){
            return (a1.weight == a2.weight || a1.weight > a2.weight) ? true : false;
        }
        
        static bool compare_dec(Animal a1, Animal a2){
            return (a1.weight == a2.weight || a1.weight < a2.weight) ? true : false;
        }
};

class SortUtil {
    public:
        template<class T>
        static void bubble_sort_generic(T elements[], int size, bool (* compare)(T p1, T p2)){
            for(unsigned int i = 0; i < size; i++){
                bool sorted = true;
                for(unsigned int j = 0; j < size-i-1; j++) {
                    if (compare(elements[j], elements[j+1])) {
                        sorted = false;
                        T temp = elements[j];
                        elements[j] = elements[j + 1];
                        elements[j + 1] = temp;
                    }
                }
                if(sorted)
                    break;
            }
        }
};

int main() {
    
    // 0. Example: sorting one type of object
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

    // SortUtil::bubble_sort_generic<Person>(people, size, &Person::compare_inc);
    SortUtil::bubble_sort_generic<Person>(people, size, &Person::compare_dec);
    
    cout << "\nAfter sorting: ";
    for(int i = 0; i < size; i++){
        cout << "{ " + people[i].get_name() + " is " + to_string(people[i].get_age()) + " }";
    }
    
    // 1. Sorting another type of object
    Animal zoo[] = { 
        Animal("Tiger", 100000), 
        Animal("Bear", 300000), 
        Animal("Ant", 1)
    };
    
    int size_zoo = sizeof(zoo)/sizeof(zoo[0]);
    
    cout << "\n\nBefore sorting: ";
    for(int i = 0; i < size_zoo; i++){
        cout << "{ " + zoo[i].get_name() + " is " + to_string(zoo[i].get_weight()) + " }";
    }

    SortUtil::bubble_sort_generic<Animal>(zoo, size_zoo, &Animal::compare_inc);
    // SortUtil::bubble_sort_generic<Animal>(zoo, size_zoo, &Animal::compare_dec);
    
    cout << "\nAfter sorting: ";
    for(int i = 0; i < size_zoo; i++){
        cout << "{ " + zoo[i].get_name() + " is " + to_string(zoo[i].get_weight()) + " }";
    }
    
    return 0;
}
