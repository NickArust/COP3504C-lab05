#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include "StringData.h"

// shorthand
using std::string;
using std::cout;
using std::endl;
using std::vector;

// prototype
int linearSearch(vector<string>, string);
int binarySearch(vector<string>, string);

int main() {
    // starting and ending times in nanoseconds
    long long start;
    long long end; //creates varibles

    // data pulled from header file
    vector<string> data = getStringData(); // imports data

    // first test
    cout << endl << "Test 1: \"not_here\"" << endl;
    cout << "==================" << endl;
    cout << "Linear Search" << endl;
    start = systemTimeNanoseconds();
    cout << "Result: " << linearSearch(data, "not_here") << endl;
    end = systemTimeNanoseconds();
    cout << "Time taken (nanoseconds): " << end - start << endl << endl;

    cout << "Binary Search" << endl;
    start = systemTimeNanoseconds();
    cout << "Result: " << binarySearch(data, "not_here") << endl;
    end = systemTimeNanoseconds();
    cout << "Time taken (nanoseconds): " << end - start << endl;

    // second test
    cout << endl << "Test 2: \"mzzzz\"" << endl;
    cout << "===============" << endl;
    cout << "Linear Search" << endl;
    start = systemTimeNanoseconds();
    cout << "Result: " << linearSearch(data, "mzzzz") << endl;
    end = systemTimeNanoseconds();
    cout << "Time taken (nanoseconds): " << end - start << endl << endl;

    cout << "Binary Search" << endl;
    start = systemTimeNanoseconds();
    cout << "Result: " << binarySearch(data, "mzzzz") << endl;
    end = systemTimeNanoseconds();
    cout << "Time taken (nanoseconds): " << end - start << endl;

    // third test
    cout << endl << "Test 2: \"aaaaa\"" << endl;
    cout << "===============" << endl;
    cout << "Linear Search" << endl;
    start = systemTimeNanoseconds();
    cout << "Result: " << linearSearch(data, "aaaaa") << endl;
    end = systemTimeNanoseconds();
    cout << "Time taken (nanoseconds): " << end - start << endl << endl;

    cout << "Binary Search" << endl;
    start = systemTimeNanoseconds();
    cout << "Result: " << binarySearch(data, "aaaaa") << endl;
    end = systemTimeNanoseconds();
    cout << "Time taken (nanoseconds): " << end - start << endl;

    return 0;
}

/**
 * Uses a linear search to find specified element in the dataSet. Returns index of element, or -1 if not found.
 * @param dataSet the data to search in
 * @param element the index of the element being searched (-1 if not found)
 * @return index of element, or -1 if not found
 */
int linearSearch(vector<string> dataSet, string element) {
    // loop through all elements in the data set
    for (int i = 0; i < dataSet.size(); i++) {
        if (dataSet.at(i) == element) {
            return i;
        }
    }

    // if the loop completes we can assume the element doesn't exist
    return -1;
}

/**
 * Uses a binary search to find specified element in the dataSet. Returns index of element, or -1 if not found.
 * @param dataSet the dataset to search within
 * @param element the element to search for
 * @return index of element, or -1 if not found
 */
int binarySearch(vector<string> dataSet, string element) {
    int left = 0; // set a left pointer
    int right = dataSet.size() - 1; // set a right pointer

    while (left <= right) {
        // define the middle by averaging the left and right
        int mid = right - (right - left) / 2;

        if (dataSet.at(mid) == element) {
            return mid;
        } else if (dataSet.at(mid) < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // if the loop terminates without return, we can assume the element is not found
    return -1;
}