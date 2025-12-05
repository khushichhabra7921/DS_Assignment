#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

Node* createNode(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->prev = temp->next = NULL;
    return temp;
}

// Insert at beginning
void insertBegin(int x) {
    Node* temp = createNode(x);
    if (!head) head = temp;
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insert at end
void insertEnd(int x) {
    Node* temp = createNode(x);
    if (!head) { head = temp; return; }

    Node* p = head;
    while (p->next) p = p->next;

    p->next = temp;
    temp->prev = p;
}

// Insert before a value
void insertBefore(int val, int newVal) {
    Node* p = head;
    if (!p) return;

    if (p->data == val) {
        insertBegin(newVal);
        return;
    }

    while (p && p->data != val)
        p = p->next;

    if (!p) return;

    Node* temp = createNode(newVal);
    temp->prev = p->prev;
    temp->next = p;
    p->prev->next = temp;
    p->prev = temp;
}

// Insert after a value
void insertAfter(int val, int newVal) {
    Node* p = head;

    while (p && p->data != val) p = p->next;

    if (!p) return;

    Node* temp = createNode(newVal);
    temp->next = p->next;
    temp->prev = p;

    if (p->next) p->next->prev = temp;
    p->next = temp;
}

// Delete a value
void deleteValue(int val) {
    if (!head) return;

    Node* p = head;

    if (p->data == val) {
        head = head->next;
        if (head) head->prev = NULL;
        delete p;
        return;
    }

    while (p && p->data != val)
        p = p->next;

    if (!p) return;

    if (p->next) p->next->prev = p->prev;
    p->prev->next = p->next;

    delete p;
}

// Search value
void searchDLL(int val) {
    Node* p = head;
    int pos = 1;

    while (p) {
        if (p->data == val) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Not found\n";
}

// Display DLL
void displayDLL() {
    Node* p = head;
    while (p) {
        cout << p->data << " <-> ";
        p = p->next;
    }
    cout << "NULL\n";
}
