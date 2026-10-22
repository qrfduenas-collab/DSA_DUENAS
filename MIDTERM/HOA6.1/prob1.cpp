#include <iostream>

int main()
{
    int data[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int key = 18;
    int comparisons = 0;

    for (int i = 0; i < 10; i++)
    {
        comparisons++;

        if (data[i] == key)
        {
            std::cout << "Found: " << data[i] << std::endl;
            break;
        }
    }

    std::cout << "Comparisons: " << comparisons << std::endl;

    return 0;
}