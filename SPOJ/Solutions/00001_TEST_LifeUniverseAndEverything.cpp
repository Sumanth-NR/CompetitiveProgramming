#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n != 42) {
        cout << n << "\n";
        cin >> n;
    }

    return 0;
}