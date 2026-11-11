
#include <iostream>
using namespace std;

class Program
{
public:

    // Завдання 1. Максимальна кількість повторень одиниці
    static int MaxConsecutiveOnes(int nums[], int size, int index, int current, int maximum)
    {
        if (index == size)
            return maximum;

        if (nums[index] == 1)
        {
            current++;

            if (current > maximum)
                maximum = current;
        }
        else
        {
            current = 0;
        }

        return MaxConsecutiveOnes(nums, size, index + 1, current, maximum);
    }

    // Завдання 2. Кількість чисел з парною кількістю цифр
    static int CountDigits(int number)
    {
        if (number == 0)
            return 0;

        return 1 + CountDigits(number / 10);
    }

    static int FindEvenNumbers(int nums[], int size, int index)
    {
        if (index == size)
            return 0;

        int digits = CountDigits(nums[index]);

        if (digits % 2 == 0)
            return 1 + FindEvenNumbers(nums, size, index + 1);

        return FindEvenNumbers(nums, size, index + 1);
    }
};

int main()
{
    // Завдання 1
    int nums1[] = { 1, 1, 0, 1, 1, 1 };
    int size1 = sizeof(nums1) / sizeof(nums1[0]);

    cout << "Task 1: ";
    cout << Program::MaxConsecutiveOnes(nums1, size1, 0, 0, 0);

    // Завдання 2
    int nums2[] = { 12, 345, 2, 6, 7896 };
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    cout << "\nTask 2: ";
    cout << Program::FindEvenNumbers(nums2, size2, 0);

    return 0;
}