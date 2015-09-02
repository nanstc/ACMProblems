#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int t, x, y, n, h, y0, x0;
void checkSpread (int ** arr, int l, int w);
int main() {
    cin >> t;
    while (t--) {
        cin >> y >> x >> n >> h;
        int ** lattice;
        lattice = new int* [y];
        for (int length = 0 ; length < y; length++) {
            lattice[length] = new int [x];
            string str;
            cin >> str;
            int width = 0;
            for (char & c : str) {
                lattice[length][width] = c - '0';
                width++;
            }
        }
        while (n--) {
            cin >> y0 >> x0;
            y0 -= 1;
            x0 -= 1;
            lattice[y0][x0] += 1;
            checkSpread(lattice, y0, x0);
        }
        for (int length = 0 ; length < y; length++) {
            for (int width = 0; width < x; width++) {
                cout << lattice[length][width];
            }
            cout << endl;
        }

    }
    
    return 0;
}
void checkSpread (int ** arr, int l, int w) {
    if (arr[l][w] > h) {
        arr[l][w] -= 4;
        if (l-1 >= 0) {
            arr[l-1][w] += 1;
            checkSpread(arr, l-1, w);
        }
        if (l+1 < y) {
            arr[l+1][w] += 1;
            checkSpread(arr, l+1, w);
        }
        if (w-1 >= 0) {
            arr[l][w-1] += 1;
            checkSpread(arr, l, w-1);
        }
        if (w+1 < x) {
            arr[l][w+1] += 1;
            checkSpread(arr, l, w+1);
        }
    }

}

