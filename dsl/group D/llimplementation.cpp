#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char val) {
        data = val;
        next = NULL;
    }
};

class stack {
    Node* top;

public:
    stack() {
        top = NULL;
    }

    bool isempty() {
        return top == NULL;
    }

    void push(char val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (!isempty()) {
            char x = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return x;
        }
        else {
            cout << "Stack Underflow! ";
            return 0;
        }
    }

    char getTop() {
        return top->data;
    }
};

bool isoperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

int pre(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '(') {
        return 0;
    }
    return -1;
}

string post(string s) {
    string post = "";
    stack obj;
    int n = s.size();
    for (int i = 0; i < n; i++) {

        if (isoperand(s[i])) {
            post = post + s[i];
        }

        else if (s[i] == ')') {
            while (obj.getTop() != '(') {
                post = post + obj.pop();
            }
            obj.pop();
        }

        else {
            if (obj.isempty()) {
                obj.push(s[i]);
            }
            else {
                while (!obj.isempty() && obj.getTop() != '(' && (pre(s[i]) <= pre(obj.getTop()))) {
                    post = post + obj.pop();
                }
                obj.push(s[i]);
            }
        }
    }
    while (!obj.isempty()) {
        post = post + obj.getTop();
        obj.pop();
    }
    return post;
}

// int evaluation(string s) {
//     stack obj;
//     int n = s.size();
//     int c;
//     for (int i = 0; i < n; i++) {
//         if (isoperand(s[i])) {
//             cout << "Enter the value of " << s[i] << ": ";
//             cin >> c;
//             obj.push(c);
//         }
//         else {
//             int x1, x2, r;
//             x2 = obj.pop();
//             x1 = obj.pop();
//             switch (s[i]) {
//             case '+':
//                 r = x1 + x2;
//                 obj.push(r);
//                 break;
//             case '-':
//                 r = x1 - x2;
//                 obj.push(r);
//                 break;
//             case '*':
//                 r = x1 * x2;
//                 obj.push(r);
//                 break;
//             case '/':
//                 r = x1 / x2;
//                 obj.push(r);
//                 break;
//             default:
//                 break;
//             }
//         }
//     }
//     return obj.pop();
// }

int main() {
    cout << "Enter the balanced expression: ";
    string str, s;
    cin >> str;
    s = post(str);
    cout << "\nPostfix Expression: " << s << endl;
    // int result;
    // result = evaluation(s);
    // cout << "Answer: " << result;
    // return 0;
}
