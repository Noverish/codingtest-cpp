#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    cout << gcd(120, 25) << endl;
}
