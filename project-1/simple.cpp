/* simple.cpp
 * Owen Strength
 *
 * complie: g++ -std=c++11 simple.cpp -o simple
 *
 * 01/19/2024
 * This program calculates the factorial of a number and the standard deviation of a set of numbers.\
 * The user inputs the number of elements in the set and the elements themselves.
 * the elements are stored in a dynamic array.
 *
 * References:
 * standard_deviation.cpp by Dr. Li on Canvas
 * factorial.cpp by Dr. Li on Canvas
 * dynamic arrays: https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/
 */

#include <iostream>
#include <cmath>

// standard_deviation.cpp by Dr. Li on Canvas
double calculateFactorial(int n)
{
    double factorial = 1.0;
    for (int i = 1; i <= n; ++i)
    {
        factorial *= i;
    }
    return factorial;
}

// factorial.cpp by Dr. Li on Canvas
double calculateStandardDeviation(float data[], int size)
{
    float sum = 0.0, mean, standardDeviation = 0.0;
    for (int i = 0; i < size; ++i)
    {
        sum += data[i];
    }
    mean = sum / size;
    for (int i = 0; i < size; ++i)
        standardDeviation += pow(data[i] - mean, 2);
    return sqrt(standardDeviation / size);
}

int main()
{
    // get the number of elements
    int size;
    std::cout << "Enter the number of elements (less than 10): ";
    std::cin >> size;

    while (size >= 10)
    {
        std::cout << "Enter the number of elements (MUST BE less than 10!): ";
        std::cin >> size;
    }

    // put the elements into a dynamic array
    float *data = new float[size];
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Enter the element #" << i + 1 << ": ";
        std::cin >> data[i];
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << "Factorial for " << data[i] << ": " << calculateFactorial(data[i]) << std::endl;
    }

    double standardDeviation = calculateStandardDeviation(data, size);

    std::cout << "Standard Deviation: " << standardDeviation << std::endl;

    // delete the dynamic array
    delete[] data;
    return 0;
}
