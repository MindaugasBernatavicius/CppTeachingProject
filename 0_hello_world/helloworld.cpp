/*

// Inline comment
/*
 Multiline comment
*/

// liepia naudoti biblioteką <iostream> 
// <iostream> - reikalina tam, kad galėtume naudoti cout
#include <iostream>

// we will use standard namesapce (std)
// ... namespaces are used to contain and limit
// ... the scope of function, class, variable names
using namespace std;

// By convention, all C++, C, Java programs
// ... are executed starting from function called main()
// Let's exaplain all the words in main function:
// ... - main - is the name of the function
// ... - int - is the return type
// ... - () - parentheses, between those we specify parameters passed into the function
// ... - { - specifies the start of the block
// ... - The entire thing "int main()" is called function head (sometimes header)
// ... - The rest of the function, between curly braces {} - is the function body 
int main() {
    // cout - character output stream, which by default prints to STDOUT (standard output).
    // ... What is standard output? Usually the console
    // ... << - this symbols is the so called "insertion operator" - specifies the direction
    // ... where data will be put.
    // ... - "Hello world" is our data, the type of this data is string type (textual data).
    // string s {"Hello World" } ; // different ways to initialize a variable
    string s ("Hello World");
    std::cout << s;

    // by convention we return 0 from main, when the program finishes sucessfully, else we return not 0   
    // 0 is of datatype "int" that is why main() has int as return parameter at the
    return 0;
}
// ... - } - specifies the end of the block