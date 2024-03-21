#include <iostream>
#include <stack>
#include <unordered_map>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    return 0; // assuming '('
}

void infixToPostfix(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == ' ')
            continue;
        if (isalpha(c))
            std::cout << c << ' ';
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                std::cout << st.top() << ' ';
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop(); // Pop '('
        }
        else { // operator
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                std::cout << st.top() << ' ';
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        std::cout << st.top() << ' ';
        st.pop();
    }
}

int main() {
    std::string infixExpression = "a + b * (c - d) / e";
    infixToPostfix(infixExpression);
    return 0;
}
