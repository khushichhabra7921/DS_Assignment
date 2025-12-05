#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(4); q.push(7); q.push(11);
    q.push(20); q.push(5); q.push(9);

    int n = q.size();
    queue<int> firstHalf;

    for (int i = 0; i < n/2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        cout << firstHalf.front() << " ";
        firstHalf.pop();

        cout << q.front() << " ";
        q.pop();
    }
}
