#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* deleteAll(Node* head, int key, int &count) {
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
