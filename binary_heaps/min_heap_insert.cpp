#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        size_t heapSize = heap.size();
        while (true) {
            size_t leftChild = 2 * index + 1;
            size_t rightChild = 2 * index + 2;
            size_t smallest = index;

            if (leftChild < heapSize && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }

            if (rightChild < heapSize && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (index != smallest) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    MinHeap() {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (isEmpty()) {
            throw out_of_range("Heap is empty");
        }

        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return min;
    }

    int getMin() const {
        if (isEmpty()) {
            throw out_of_range("Heap is empty");
        }

        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }
};

int main() {
    MinHeap minHeap;

    minHeap.insert(4);
    minHeap.insert(2);
    minHeap.insert(8);
    minHeap.insert(5);

    cout << "Min Heap: ";
    while (!minHeap.isEmpty()) {
        cout << minHeap.extractMin() << " ";
    }
    cout << endl;

    return 0;
}
