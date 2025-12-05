#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

Node* createNode(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// (a) Insert at beginning
void insertBegin(int x) {
    Node* temp = createNode(x);
    temp->next = head;
    head = temp;
}

// (b) Insert at end
void insertEnd(int x) {
    Node* temp = createNode(x);
    if (!head) {
        head = temp;
        return;
    }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

// (c) Insert before/after a value
void insertBefore(int val, int newVal) {
    if (!head) return;

    if (head->data == val) {
        insertBegin(newVal);
        return;
    }

    Node* p = head;
    while (p->next && p->next->data != val)
        p = p->next;

    if (p->next) {
        Node* temp = createNode(newVal);
        temp->next = p->next;
        p->next = temp;
    }
}

void insertAfter(int val, int newVal) {
    Node* p = head;
    while (p && p->data != val)
        p = p->next;

    if (p) {
        Node* temp = createNode(newVal);
        temp->next = p->next;
        p->next = temp;
    }
}

// (d) Delete first node
void deleteBegin() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// (e) Delete last node
void deleteEnd() {
    if (!head) return;

    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }

    Node* p = head;
    while (p->next->next)
        p = p->next;

    delete p->next;
    p->next = NULL;
}

// (f) Delete specific node
void deleteValue(int val) {
    if (!head) return;

    if (head->data == val) {
        deleteBegin();
        return;
    }

    Node* p = head;
    while (p->next && p->next->data != val)
        p = p->next;

    if (p->next) {
        Node* temp = p->next;
        p->next = p->next->next;
        delete temp;
    }
}

// (g) Search
void search(int key) {
    Node* p = head;
    int pos = 1;
    while (p) {
        if (p->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Not found\n";
}

// (h) Display
void display() {
    Node* p = head;
    while (p) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

int main() {
    int ch, val, pos, newVal;

    while (true) {
        cout << "\n1.InsertBegin 2.InsertEnd 3.InsertBefore 4.InsertAfter\n"
             << "5.DeleteBegin 6.DeleteEnd 7.DeleteValue\n"
             << "8.Search 9.Display 10.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cin >> val; insertBegin(val); break;
            case 2: cin >> val; insertEnd(val); break;
            case 3: cin >> val >> newVal; insertBefore(val, newVal); break;
            case 4: cin >> val >> newVal; insertAfter(val, newVal); break;
            case 5: deleteBegin(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> val; deleteValue(val); break;
            case 8: cin >> val; search(val); break;
            case 9: display(); break;
            case 10: return 0;
        }
    }
}
