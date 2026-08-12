#include <iostream>

int main (){

    int A;
    int B;

std:: cout << "Input the value of A:";
std:: cin >> A;

std:: cout << "--------------------" << std:: endl;

std:: cout << "Input the value of B:";
std:: cin >> B;

if (A > B){
    std:: cout << "A is greater than B ";
}
else if (B > A){
    std:: cout << "B is greather than A ";
}
else {
    std:: cout << "A and B are equal ";
}
return 0;

}
