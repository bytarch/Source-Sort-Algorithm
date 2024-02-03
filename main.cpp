#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

template <typename T>
int partition(std::vector<T> &arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void sourceSort(std::vector<T> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        sourceSort(arr, low, pivotIndex - 1);
        sourceSort(arr, pivotIndex + 1, high);
    }
}

template <typename T>
void sourceSort(std::vector<T> &arr) {
    int n = arr.size();
    sourceSort(arr, 0, n - 1);
}

template <typename T>
void printArray(const std::vector<T> &arr) {
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != arr.end()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arrInt;
    std::vector<float> arrFloat;

    char choice;
    std::cout << "Would you like to input the data manually (press 'y') or use the provided sample data (press 'n')? (y/n): ";

    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int numInt;
        float numFloat;

        std::cout << "Enter integer elements (enter a non-integer to stop): ";
        while (std::cin >> numInt) {
            arrInt.push_back(numInt);
        }

        std::cin.clear();  // Clear the error flag from the failed input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input

        std::cout << "Enter float elements (enter a non-float to stop): ";
        while (std::cin >> numFloat) {
            arrFloat.push_back(numFloat);
        }
    } else {
        // Use pre-filled arrays
        arrInt = {654, 2123235, 1342, 322, 7, 39234, 23425, 636, 234, 23534, 6346, 4, 646, 657, 23423, 7};
        arrFloat = {654.5, 2123.235, 13.42, 3.22, 0.7, 39.234, 234.25, 6.36, 2.34, 2353.4, 634.6, 0.4, 6.46, 65.7, 2342.3, 0.7};
    }

    std::cout << "Unsorted integer array: ";
    printArray(arrInt);

    sourceSort(arrInt);

    std::cout << "\nSorted integer array using Source Sorting: ";
    printArray(arrInt);

    std::cout << "\n\nUnsorted float array: ";
    printArray(arrFloat);

    sourceSort(arrFloat);

    std::cout << "\nSorted float array using Source Sorting: ";
    printArray(arrFloat);

    return 0;
}
