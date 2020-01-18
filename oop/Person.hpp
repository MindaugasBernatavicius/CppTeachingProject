#ifndef CPP_PROJECT_PERSON_HPP
#define CPP_PROJECT_PERSON_HPP

#endif //CPP_PROJECT_PERSON_HPP

#include <string>

// no namespace declarations in the header files
// ... because header files are pasted in by the pre processor and if
// ... header files are added here, it can lead to errors

class Person {
    private:
        std::string name;
        int age;
        double height;
        std::string removeTrailingZeros(std::string original);

    public:
        Person();
        ~Person();
        std::string getName();
        void setName(std::string name);
        int getAge();
        void setage(int age);
        double getHeight();
        void setHeight(double height);
        std::string toString();
};