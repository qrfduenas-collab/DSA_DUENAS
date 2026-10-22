//NO.1

// #include <iostream>
// 
// double kelvinToFahrenheit(double kelvin) {
//     double fahrenheit = (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
//     return fahrenheit;
// }
// 
// int main() {
//     double kVal;
//     
//     std::cout << "Enter temperature in Kelvin: ";
//     std::cin >> kVal;
//     
//     double fValue = kelvinToFahrenheit(kVal);
//     
//     std::cout << kVal << " Kelvin's value is: " << fValue << " Fahrenheit." << std::endl;
//     
//     return 0;
// }

// NO.2

// #include <iostream>
// 
// int main() {
//     int num1, num2, ralph;
//     
//     std::cout << "Enter first number: ";
//     std::cin >> num1;
//     std::cout << "Enter second number: ";
//     std::cin >> num2;
//     
//     std::cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;
//     
//     ralph = num1;
//     num1 = num2;
//     num2 = ralph;
//     
//     std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;
//     
//     return 0;
// }


//NO.3 

// #include <iostream>
// #include <cmath>

// double calculateDistance(double x1, double y1, double x2, double y2);

// int main() {

//     double x1, y1, x2, y2;

//     std::cout << "Enter x1: ";
//     std::cin >> x1;

//     std::cout << "Enter y1: ";
//     std::cin >> y1;

//     std::cout << "Enter x2: ";
//     std::cin >> x2;

//     std::cout << "Enter y2: ";
//     std::cin >> y2;

//     double distance = calculateDistance(x1, y1, x2, y2);

//     std::cout << "Distance between the two points: " << distance << std::endl;

//     return 0;
// }

// double calculateDistance(double x1, double y1, double x2, double y2) {

//     return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

// }