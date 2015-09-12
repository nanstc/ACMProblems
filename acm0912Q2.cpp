#include <iostream>
using namespace std;

int n;
bool cr, ct;
int main() {
    cin >> n;
    while (n--) {
        cr = ct = false;
        int medal[6];
        for (int i= 0; i < 6; i++) {
            int j;
            cin >> j;
            medal[i] = j;
            cout << j << " ";
        }
        cout << endl;
        if (medal[0]+medal[1]+medal[2] > medal[3]+ medal[4]+medal[5]) ct = true;
        int temp = 0;
        while (temp < 4) {
            if (medal[temp] > medal[temp+3]) {
                cr = true;
                break;
            }
            else if (medal[temp] < medal[temp+3]) {
                cr = false;
                break;
            }
            else temp++;
        }
        if (cr && ct) cout << "both" << endl;
        else if (cr) cout << "color" << endl;
        else if (ct) cout << "count" << endl;
        else cout << "none" <<endl;
        cout << endl;
    }
}