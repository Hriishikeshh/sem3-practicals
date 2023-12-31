#include<iostream>
using namespace std;

class compare {
public:
    int addi(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    double addi(double a, double b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
};

int main() {
    compare obj;
    cout << obj.addi(2, 3) << endl;
    cout << obj.addi(3.4, 5.6) << endl;

    return 0;
}
