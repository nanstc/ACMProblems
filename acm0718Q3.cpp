#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int testCase, gcd, n, array[10000];
    double amount;
    cin >> testCase;
    while (testCase--) {
        cin >> amount >> n;
        amount = amount*100;
        gcd = amount;
        gcd /= __gcd((int)gcd, 100);
        for (int i =0; i < n; i++) {
            int temp;
            cin >> temp;
            while (temp % 2 == 0) temp /= 2;
            array[i] = temp;
            array[0] = __gcd(array[0],array[i]);

        }
        cout << "array values are: ";
        for (int i =0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout <<endl;
        if (((int)amount % 25 == 0) && gcd % array[0] == 0) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}