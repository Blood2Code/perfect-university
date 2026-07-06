// Задание 7, часть В. Проверка сбалансированности скобок с помощью stack.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& expression) {
    stack<char> st;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;

            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string tests[] = {
        "()",
        "({[]})",
        "({[})",
        "(()",
        "(()())",
        "((()))"
    };

    for (const string& test : tests) {
        cout << test << " -> "
             << (isBalanced(test) ? "Сбалансировано" : "Не сбалансировано")
             << endl;
    }

    return 0;
}
