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
    const size_t j = 5;
Student studentList[j] = {};

std::string namesList[j] = {"Dane", "Angela", "Andrew", "Nic", "Jarel"};

int ageList[j] = {15, 16, 18, 19, 16};

for(int i = 0; i < j; i++){  // loop a
Student *ptr = new Student(namesList[i], ageList[i]);
studentList[i] = *ptr;

}
for(int i = 0; i < j; i++){ // loop b
studentList[i].printDetails();
}
return 0;
}


