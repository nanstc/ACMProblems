#include <iostream>
using namespace std;

int t, n, v;
bool d = true;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int coins[n];
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
            if (i != 0) {
                if ((2* coins[i-1]) > coins[i]) d = false;
            }
        }
        cout << "Denominations: ";
        for (int i = 0; i < n; i++) cout << coins[i] << " ";
        cout << endl;
        if (d) cout << "Good coin denominations!" << endl;
        else cout << "Bad coin denominations!" << endl;
        cout << endl;
        d = true;
    }
    return 0;
}