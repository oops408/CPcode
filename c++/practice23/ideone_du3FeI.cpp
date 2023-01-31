#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

map<char, int> priority = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3},
};

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool is_higher_priority(char a, char b) {
    return priority[a] > priority[b];
}

string infix_to_rpn(string expression) {
    string rpn;
    stack<char> operators;

    for (char c : expression) {
        if (isalpha(c)) {
            rpn += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (operators.top() != '(') {
                rpn += operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (is_operator(c)) {
            while (!operators.empty() && operators.top() != '(' && is_higher_priority(operators.top(), c)) {
                rpn += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        rpn += operators.top();
        operators.pop();
    }

    return rpn;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string expression;
        getline(cin, expression);

        cout << infix_to_rpn(expression) << endl;
    }

    return 0;
}