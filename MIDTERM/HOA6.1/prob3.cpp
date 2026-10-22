#include <iostream>

int main()
{
    int data[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    int key = 8;
    int low = 0;
    int up = 9;
    int comparisons = 0;

    while (low <= up)
    {
        int mid = (low + up) / 2;

        comparisons++;

        std::cout << "Iteration " << comparisons
                  << ": mid = " << data[mid] << std::endl;

        if (data[mid] == key)
        {
            std::cout << "Search element is found!" << std::endl;
            std::cout << "Index: " << mid << std::endl;
            std::cout << "Comparisons: " << comparisons << std::endl;
            return 0;
        }
        else if (key < data[mid])
        {
            up = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    std::cout << "No search element is found " << std:: endl;

    return 0;
}