#include<bits/stdc++.h>
#include<string>
using namespace std;

class Stack {
public:
    int size;
    int top;
    int* arr;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        if (size - top > 0) {
            top++;
            arr[top] = data;
        }
        else {
            cout << "stack is full" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
        else {
            cout << "stack is empty" << endl;
        }
    }

    int getTop() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            return 0;  // empty stack
        }
    }

    int prec(char c) {
        if (c == '^') {
            return 3;
        }
        else if (c == '/' || c == '*') {
            return 2;
        }
        else if (c == '+' || c == '-') {
            return 1;
        }
        else {
            return -1;
        }
    }
};

int evaluation(string s) {
    Stack obj(s.size());

    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            int value;
            cout << "Enter value for " << s[i] << ": ";
            cin >> value;
            obj.push(value);
        }
        else {
            int x1, x2, r;
            x2 = obj.getTop();
            obj.pop();
            x1 = obj.getTop();
            obj.pop();
            switch (s[i]) {
                case '+':
                    r = x1 + x2;
                    obj.push(r);
                    break;

                case '-':
                    r = x1 - x2;
                    obj.push(r);
                    break;

                case '*':
                    r = x1 * x2;
                    obj.push(r);
                    break;

                case '/':
                    r = x1 / x2;
                    obj.push(r);
                    break;

                case '$':
                    r = x1 ^ x2;
                    obj.push(r);
                    break;

                default:
                    break;
            }
        }
    }
    return obj.getTop();
}

int main() {
    string exp, result;
    exp = "(a+b*c)/(x+y/z)";
    int n = exp.length();

    Stack st(n + 1);
    for (int i = 0; i < n; i++) {
        string t;
        t = exp[i];

        if ((t >= "a" && t <= "z") || (t >= "A" && t <= "Z")) {
            result += t;
        }
        else if (t == "{" || t == "(" || t == "[") {
            st.push(t[0]);
        }
        else if (t == "}" || t == ")" || t == "]") {
            if (st.getTop() != '[' && st.getTop() != '{' && st.getTop() != '(') {
                result += st.getTop();
                st.pop();
            }
            st.pop();
        }
        else {
            while (st.getTop() != '\0' && st.prec(t[0]) <= st.prec(st.getTop())) {
                result += st.getTop();
                st.pop();
            }
            st.push(t[0]);
        }
    }

    while (st.getTop() != '\0') {
        result += st.getTop();
        st.pop();
    }

    cout << "Postfix expression: " << result << endl;
    cout << "Evaluation: " << evaluation(result) << endl;

    return 0;
}
