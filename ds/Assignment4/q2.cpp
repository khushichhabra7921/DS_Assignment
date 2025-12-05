#include <iostream>
using namespace std;

#define MAX 5

int cq[MAX], front = -1, rear = -1;

bool isEmpty() { return front == -1; }
bool isFull() { return (rear + 1) % MAX == front; }

void enqueueCQ(int x) {
    if (isFull()) {
        cout << "Circular Queue Full\n";
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    cq[rear] = x;
}

void dequeueCQ() {
    if (isEmpty()) {
        cout << "Circular Queue Empty\n";
        return;
    }
    cout << "Dequeued: " << cq[front] << endl;
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void displayCQ() {
    if (isEmpty()) {
        cout << "Circular Queue Empty\n";
        return;
    }
    cout << "Circular Queue: ";
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

void peekCQ() {
    if (isEmpty()) cout << "Empty\n";
    else cout << "Front: " << cq[front] << endl;
}

int main() {
    int ch, val;

    while (true) {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.isEmpty\n5.isFull\n6.Peek\n7.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cin >> val; enqueueCQ(val); break;
            case 2: dequeueCQ(); break;
            case 3: displayCQ(); break;
            case 4: cout << (isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 5: cout << (isFull() ? "Full\n" : "Not Full\n"); break;
            case 6: peekCQ(); break;
            case 7: return 0;
        }
    }
}
