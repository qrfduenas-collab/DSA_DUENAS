// NO.1

// #include <iostream>
// #include <cmath>

// class Triangle {
// private:
//     double sideA, sideB, sideC;

// public:
//     Triangle(double A, double B, double C);
//     void setSides(double A, double B, double C);
//     bool validateTriangle();
//     double computeArea();
// };

// Triangle::Triangle(double A, double B, double C) {
//     sideA = A;
//     sideB = B;
//     sideC = C;
// }

// void Triangle::setSides(double A, double B, double C) {
//     sideA = A;
//     sideB = B;
//     sideC = C;
// }

// bool Triangle::validateTriangle() {
//     return (sideA + sideB > sideC &&
//             sideA + sideC > sideB &&
//             sideB + sideC > sideA);
// }

// double Triangle::computeArea() {
//     double s = (sideA + sideB + sideC) / 2;
//     return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
// }

// int main() {

//     Triangle set1(3, 4, 5);

//     if (set1.validateTriangle()) {
//         std::cout << "The shape is a valid triangle.\n";
//         std::cout << "Area = " << set1.computeArea() << std::endl;
//     }
//     else {
//         std::cout << "The shape is NOT a valid triangle.\n";
//     }

//     return 0;
// }

// NO.2

// #include <iostream>

// class Triangle {
// private:
//     double sideA, sideB, sideC;

// public:
//     Triangle(double A, double B, double C);
//     void setSides(double A, double B, double C);
//     bool validateTriangle();
//     double computePerimeter();
// };

// Triangle::Triangle(double A, double B, double C) {
//     sideA = A;
//     sideB = B;
//     sideC = C;
// }

// void Triangle::setSides(double A, double B, double C) {
//     sideA = A;
//     sideB = B;
//     sideC = C;
// }

// bool Triangle::validateTriangle() {
//     return (sideA + sideB > sideC &&
//             sideA + sideC > sideB &&
//             sideB + sideC > sideA);
// }

// double Triangle::computePerimeter() {
//     return sideA + sideB + sideC;
// }

// int main() {

//     Triangle set1(3, 4, 5);

//     if (set1.validateTriangle()) {
//         std::cout << "The shape is a valid triangle.\n;
//         std::cout << "Perimeter = " << set1.computePerimeter() << std::endl;
//     }
//     else {
//         std::cout << "The shape is NOT a valid triangle.\n";
//     }

//     return 0;
// }

//  NO. 3

// #include <iostream>
// #include <algorithm>

// class Triangle {
// private:
//     double sideA, sideB, sideC;

// public:
//     Triangle(double A, double B, double C);
//     void setSides(double A, double B, double C);
//     bool validateTriangle();
//     void determineTriangleType();
// };

// Triangle::Triangle(double A, double B, double C) {
//     sideA = A;
//     sideB = B;
//     sideC = C;
// }

// void Triangle::setSides(double A, double B, double C) {
//     sideA = A;
//     sideB = B;
//     sideC = C;
// }

// bool Triangle::validateTriangle() {
//     return (sideA + sideB > sideC &&
//             sideA + sideC > sideB &&
//             sideB + sideC > sideA);
// }

// void Triangle::determineTriangleType() {

//     double a = sideA;
//     double b = sideB;
//     double c = sideC;

//     if (a > c) std::swap(a, c);
//     if (b > c) std::swap(b, c);

//     if ((a * a + b * b) > (c * c))
//         std::cout << "Triangle is Acute-angled.\n";

//     else if ((a * a + b * b) < (c * c))
//         std::cout << "Triangle is Obtuse-angled.\n";

//     else
//         std::cout << "Triangle is Right-angled (Others).\n";
// }

// int main() {

//     Triangle set1(3, 4, 5);

//     if (set1.validateTriangle()) {
//         std::cout << "The shape is a valid triangle.\n";
//         set1.determineTriangleType();
//     }
//     else {
//         std::cout << "The shape is NOT a valid triangle.\n";
//     }

//     return 0;
// }