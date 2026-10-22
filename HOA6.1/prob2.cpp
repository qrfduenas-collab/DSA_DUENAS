#include <iostream>

int countRepeating(int data[], int size, int key)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i] == key)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int data[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    int key = 18;

    int result = countRepeating(data, 10, key);

    std::cout << "Total number of occurences: "
              << key << ": " << result << std::endl;

    return 0;
}