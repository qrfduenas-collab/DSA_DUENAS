#include <iostream>
#include <chrono>
#include <iomanip>

// Linear Recursive Power O(n)
int rpower(int x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

// Binary Recursive Power O(log n)
int brpower(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) {
        int y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        int y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    int x = 1; // x = 1 prevents integer overflow during runtime testing
    int exponents[] = {100, 1000, 5000, 10000, 20000};
    const int iterations = 5000; // Repeat to get a measurable average time

    // Print headers with fixed column widths
    std::cout << std::left
              << std::setw(15) << "Exponent (n)"
              << std::setw(20) << "rpower Avg (ns)"
              << std::setw(20) << "brpower Avg (ns)" << "\n";
    std::cout << "____________________________________________________________\n";

    for (int n : exponents) {
        // Measure rpower execution time over multiple iterations
        volatile int sink1 = 0;
        auto start1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i) {
            sink1 = rpower(x, n);
        }
        auto end1 = std::chrono::high_resolution_clock::now();
        auto t_rpower = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count() / iterations;

        // Measure brpower execution time over multiple iterations
        volatile int sink2 = 0;
        auto start2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i) {
            sink2 = brpower(x, n);
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        auto t_brpower = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count() / iterations;

        // Print formatted row matching fixed widths
        std::cout << std::left
                  << std::setw(15) << n << "| "
                  << std::setw(20) << t_rpower<< "| "
                  << std::setw(20) << t_brpower << "|\n";
    }

    return 0;
}