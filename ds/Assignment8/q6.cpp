class MaxHeap {
public:
    vector<int> heap;

    void push(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;

        while (i > 0 && heap[(i-1)/2] < heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int top() { return heap[0]; }

    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void heapifyDown(int i) {
        int n = heap.size();
        int largest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < n && heap[l] > heap[largest]) largest = l;
        if (r < n && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
};
