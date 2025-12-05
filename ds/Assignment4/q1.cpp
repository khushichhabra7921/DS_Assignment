#include <iostream>
using namespace std;

#define MAX 100

int q[MAX], front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX - 1;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1) front = 0;
    q[++rear] = x;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Dequeued: " << q[front] << endl;
    if (front == rear) front = rear = -1;
    else front++;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Front element: " << q[front] << endl;
}

int main() {
    int ch, val;
    while (true) {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.isEmpty\n5.isFull\n6.Peek\n7.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cin >> val; enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: cout << (isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 5: cout << (isFull() ? "Full\n" : "Not Full\n"); break;
            case 6: peek(); break;
            case 7: return 0;
        }
    }
}
