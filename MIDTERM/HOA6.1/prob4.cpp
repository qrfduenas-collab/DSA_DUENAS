#include <iostream>

int recursiveBinarySearch(int data[], int low, int up, int key)
{
    if (low > up)
    {
        return -1;
    }

    int mid = (low + up) / 2;

    std::cout << "Checking: " << data[mid] << std::endl;

    if (data[mid] == key)
    {
        return mid;
    }

    if (key < data[mid])
    {
        return recursiveBinarySearch(data, low, mid - 1, key);
    }

    return recursiveBinarySearch(data, mid + 1, up, key);
}

int main()
{
    int data[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    int key = 8;

    int result = recursiveBinarySearch(data, 0, 9, key);

    if (result != -1)
    {
        std::cout << "Search element is found!" << std::endl;
        std::cout << "Index: " << result << std::endl;
    }
    else
    {
        std::cout << "No search element is found " << std::endl;
    }

    return 0;
}