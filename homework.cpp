#include <iostream>
#include "Array.h"

int main() {

    StaticArray<int, 5> arr = {10, 20, 30, 40, 50};

    std::cout << "Element at index 2: " << arr.at(2) << std::endl;
    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Array size: " << arr.size() << std::endl;

    return 0;
}
