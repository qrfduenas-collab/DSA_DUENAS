#include <iostream>
#include <string.h>

class Student{
private:

std::string studentName;
int studentAge;

public:

//  Constructor
Student(std::string newName = "Ralph Duenas" , int newAge = 18) {
    studentName = std::move(newName) ;
    studentAge = newAge;
    std::cout << "Constructor is successfully called." << std::endl;
};

// Deconstructor
~Student() {
    std::cout << "Destrucor called." << std::endl;
}

// Copy Constructor
Student(const Student &copyStudent) {
    std:: cout << "Copy constructor is called." << std::endl;
    studentName = copyStudent.studentName;
    studentAge = copyStudent.studentAge;
}
// Display Attributes
void printDetails() {
    std:: cout << this->studentName << " " << this->studentAge << std::endl;
}

};
int main() {

Student student1("Ralph", 18);
Student student2(student1);
Student student3;
student3 = student2;
return 0;
}