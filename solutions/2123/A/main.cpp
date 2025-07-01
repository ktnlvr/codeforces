#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long x;
        cin >> x;
        if (x % 4) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}