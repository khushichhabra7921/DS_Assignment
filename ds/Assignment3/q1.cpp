#include <iostream>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

bool isFull() {
    return top == MAX - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = x;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << stackArr[top--] << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << stackArr[top] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, val;
    while (true) {
        cout << "\n1.Push\n2.Pop\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: cout << (isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 4: cout << (isFull() ? "Full\n" : "Not Full\n"); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: return 0;
            default: cout << "Invalid Option\n";
        }
    }
}
