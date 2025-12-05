#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char a, char b) {
    return (a=='(' && b==')') ||
           (a=='{' && b=='}') ||
           (a=='[' && b==']');
}

bool isBalanced(string s) {
    stack<char> st;

    for (char c : s) {
        if (c=='(' || c=='{' || c=='[')
            st.push(c);
        else if (c==')' || c=='}' || c==']') {
            if (st.empty()) return false;
            if (!isMatching(st.top(), c)) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;

    cout << (isBalanced(s) ? "Balanced" : "Not Balanced");
}
