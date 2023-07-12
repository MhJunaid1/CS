#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void removeMax() {
        if (heap.empty()) {
            return;
        }

        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(5);
    maxHeap.insert(7);
    maxHeap.insert(3);
    maxHeap.insert(12);

    while (!maxHeap.isEmpty()) {
        std::cout << maxHeap.getMax() << " ";
        maxHeap.removeMax();
    }

    return 0;
}
