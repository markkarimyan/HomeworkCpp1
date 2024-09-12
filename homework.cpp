#include <iostream>
#include <stdexcept>

template <typename T, std::size_t N>
class StaticArray {
private:
    T arr[N];

public:

    StaticArray(std::initializer_list<T> initList) {
        if (initList.size() != N) {
            throw std::length_error("Initializer list size does not match array size.");
        }

        std::size_t i = 0;
        for (auto& value : initList) {
            arr[i++] = value;
        }
    }

    T& at(std::size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    const T& at(std::size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    T& operator[](std::size_t index) {
        return arr[index];
    }

    const T& operator[](std::size_t index) const {
        return arr[index];
    }

    T& front() {
        return arr[0];
    }

    const T& front() const {
        return arr[0];
    }

    T& back() {
        return arr[N - 1];
    }

    const T& back() const {
        return arr[N - 1];
    }

    T* data() {
        return arr;
    }

    const T* data() const {
        return arr;
    }

    bool empty() const {
        return N == 0;
    }

    std::size_t size() const {
        return N;
    }

    std::size_t max_size() const {
        return N;
    }
};

int main() {

    StaticArray<int, 5> arr = {10, 20, 30, 40, 50};

    std::cout << "Element at index 2: " << arr.at(2) << std::endl;
    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Array size: " << arr.size() << std::endl;

    return 0;
}
