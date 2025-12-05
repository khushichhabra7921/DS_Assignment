#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIdx = left, maxIdx = right;

        if (a[minIdx] > a[maxIdx])
            swap(a[minIdx], a[maxIdx]);

        for (int i = left + 1; i < right; i++) {
            if (a[i] < a[minIdx]) minIdx = i;
            if (a[i] > a[maxIdx]) maxIdx = i;
        }

        swap(a[left], a[minIdx]);
        swap(a[right], a[maxIdx]);

        left++;
        right--;
    }
}

int main() {
    int a[] = {5, 3, 8, 6, 2, 7};
    int n = 6;
    improvedSelectionSort(a, n);
    for (int x : a) cout << x << " ";
}
