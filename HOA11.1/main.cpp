#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>
#include <cmath>

// Step 1 & 2: Define the Student class with operator overloads
class Student {
private:
    std::pair<int, int> name;
    bool vaccinated;

public:
    // Constructor
    Student(std::pair<int, int> n, bool v) : name(n), vaccinated(v) {}

    // Getters
    auto get_name() const { return name; }
    auto is_vaccinated() const { return vaccinated; }

    // Overloaded Operators for STL sort and comparison
    bool operator==(const Student& p) const {
        return this->name == p.name;
    }

    bool operator<(const Student& p) const {
        return this->name < p.name;
    }

    bool operator>(const Student& p) const {
        return this->name > p.name;
    }
};

// Step 3: Random Student Generator
auto generate_random_Student(int max) {
    std::random_device rd;
    std::mt19937 rand(rd());
    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, max);

    auto random_name = std::make_pair(uniform_dist(rand), uniform_dist(rand));
    bool is_vaccinated = uniform_dist(rand) % 2 ? true : false;
    return Student(random_name, is_vaccinated);
}

// Step 5: Logic for checking if vaccination is needed (Binary Search)
bool needs_vaccination(Student P, std::vector<Student>& people) {
    auto first = people.begin();
    auto last = people.end();

    while (first < last) {
        auto range_length = std::distance(first, last);
        auto mid_element_index = range_length / 2;
        auto mid_element = *(first + mid_element_index);

        if (mid_element == P) {
            if (!mid_element.is_vaccinated())
                return true;
            else
                return false;
        } 
        else if (mid_element > P) {
            last = first + mid_element_index;
        } 
        else {
            first = first + mid_element_index + 1;
        }
    }

    // Student not found in list -> requires vaccination
    return true;
}

// Step 4: Search test function with execution timer
void search_test(int size, Student p) {
    std::vector<Student> people;
    for (auto i = 0; i < size; i++)
        people.push_back(generate_random_Student(size));

    std::sort(people.begin(), people.end());

    // Start clock
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    bool search_result = needs_vaccination(p, people);
    
    // Stop clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time taken to search = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << " microseconds" << std::endl;

    if (search_result)
        std::cout << "Student (" << p.get_name().first << " " << p.get_name().second
                  << ") needs vaccination." << std::endl;
    else
        std::cout << "Student (" << p.get_name().first << " " << p.get_name().second
                  << ") does not need vaccination." << std::endl;
}

// Step 6: Driver code
int main() {
    auto p = generate_random_Student(1000);
    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);
    return 0;
}

