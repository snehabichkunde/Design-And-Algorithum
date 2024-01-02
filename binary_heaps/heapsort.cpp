#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
private:
    vector<int> data;
    size_t size;

    void heapify(int index, size_t heapSize) {
        size_t largest = index;
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;

        if (left < heapSize && data[left] > data[largest]) {
            largest = left;
        }

        if (right < heapSize && data[right] > data[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(data[index], data[largest]);
            heapify(largest, heapSize);
        }
    }

    void buildMaxHeap() {
        for (int i = size / 2 - 1; i >= 0; --i) {
            heapify(i, size);
        }
    }

public:
    HeapSort(vector<int>& arr) : data(arr), size(arr.size()) {}

    void sort() {
        buildMaxHeap();

        for (int i = size - 1; i >= 1; --i) {
            swap(data[0], data[i]);
            heapify(0, i);
        }
    }

    void display() const {
        for (const auto& element : data) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    cout << "Enter the elements: ";
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    HeapSort sorter(arr);

    cout << "Original: ";
    sorter.display();

    sorter.sort();

    cout << "Sorted: ";
    sorter.display();

    return 0;
}
