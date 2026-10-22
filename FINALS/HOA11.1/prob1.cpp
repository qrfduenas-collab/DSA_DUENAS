#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

bool unique(const std::vector<int>& A, long long& comparisons) {
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = i + 1; j < A.size(); ++j) {
            comparisons++;
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

std::vector<int> makeWorstCase(int n) {
    std::vector<int> worst_case(n);
    for (int i = 0; i < n; ++i) {
        worst_case[i] = i;
    }
    return worst_case;
}

auto start = std::chrono::high_resolution_clock::now();
auto end = std::chrono::high_resolution_clock::now();
double ms = std::chrono::duration<double, std::milli>(end - start).count();

int main() {
    std::vector<int> sizes = {100, 1000, 10000, 20000};

    std::cout << std::setw(8) << "n"
              << std::setw(16) << "comparisons"
              << std::setw(16) << "n(n-1)/2"
              << std::setw(14) << "time(ms)"
              << std::setw(10) << "unique?" << "\n";

    for (size_t i = 0; i < sizes.size(); ++i) {
        int n = sizes[i];
        std::vector<int> worst_case = makeWorstCase(n);
        long long comparisons = 0;

        start = std::chrono::high_resolution_clock::now();
        bool is_unique = unique(worst_case, comparisons);
        end = std::chrono::high_resolution_clock::now();
        ms = std::chrono::duration<double, std::milli>(end - start).count();
        long long expected = (long long)n * (n - 1) / 2;

        std::cout << std::setw(8) << n
                  << std::setw(16) << comparisons
                  << std::setw(16) << expected
                  << std::setw(14) << std::fixed << std::setprecision(4) << ms
                  << std::setw(10) << is_unique << "\n";
    }
    return 0;
}