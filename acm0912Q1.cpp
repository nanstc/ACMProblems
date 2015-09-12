#include <iostream>

using namespace std;

int n;
bool m, z;
int main() {
    z = m = false;
    cin >> n;
    while (n--) {
        int j;
        for (int i = 0; i < 10; i++) {
            cin >> j;
            cout << j << " ";
            if (j == 18)  m = true;
            else if (j == 17) z = true;
        }
        cout << endl;
        if (m && z) cout << "both" << endl;
        else if (m) cout << "mack" << endl;
        else if (z) cout << "zack" <<endl;
        else cout << "none" <<endl;
        m = z = false;
        cout << endl;
    }
    return 0;
}