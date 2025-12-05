#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx])
                minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

int main() {
    int a[] = {64, 25, 12, 22, 11};
    int n = 5;
    selectionSort(a, n);
    for (int x : a) cout << x << " ";
}
