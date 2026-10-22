#include <iostream>
#include <vector>
#include <string>

int R, A;
std::vector<std::vector<int>> mat;
int calls = 0;

// Imagine a traveler stepping through a grid, spending budget on each tile to find paths that match the exact target cost.
int countPaths(int i, int j, int cost) {
    calls++;

    if (i >= R || j >= A || cost < 0)
        return 0;

    if (i == R - 1 && j == A - 1) {
        if (cost == mat[i][j])
            return 1;
        return 0;
    }

    int down = countPaths(i + 1, j, cost - mat[i][j]);
    int right = countPaths(i, j + 1, cost - mat[i][j]);
    return down + right;
}

void printPaths(int i, int j, int cost, std::string path) {
    if (i >= R || j >= A || cost < 0)
        return;

    path += std::to_string(mat[i][j]);

    if (i == R - 1 && j == A - 1) {
        if (cost == mat[i][j])
            std::cout << "  " << path << "\n";
        return;
    }

    path += " -> ";
    printPaths(i + 1, j, cost - mat[i][j], path);
    printPaths(i, j + 1, cost - mat[i][j], path);
}

int main() {
    int K;

    std::cout << "Enter number of rows and columns: ";
    std::cin >> R >> A;
    mat.assign(R, std::vector<int>(A));
    std::cout << "Enter the " << (R * A) << " matrix values:\n";
    for (int i = 0; i < R; i++) {
        std::cout << "Row " << (i + 1) << " (" << A << " numbers): ";
        for (int j = 0; j < A; j++) {
            std::cin >> mat[i][j];
        }
    }

    std::cout << "Enter the target cost: ";
    std::cin >> K;

    int r1 = countPaths(0, 0, K);

    std::cout << "\nRecursion      : " << r1 << " path(s), " << calls << " calls\n";

    std::cout << "\nPaths with cost " << K << ":\n";
    printPaths(0, 0, K, "");

    return 0;
}

