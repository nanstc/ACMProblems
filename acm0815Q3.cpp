#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;

int n, c, d;
int i = 1;
int jump = 0;

int main() {
    cin >> n;
    while (i <= n) {
        cin >> c >> d;
        char arr[c];
        cin >> arr;
        cout << "Day #" << i << endl;
        cout << c << " " << d << endl;
        for (int j =0; j < c; j++) {
            cout << arr[j];
        }
        cout << endl;
        int m = 0;
        int count = 0;
        bool visited = false;
        for (int j =0; j < c; j++) {
            if (arr[j] == 'X') {
                count ++;
                visited = true;
            }
            if ((arr[j]== '.') && (visited == true)) {
                m = max(m, count);
                count = 0;
                visited = false;
            }
        }
        if (m > d) cout << false << endl;
        else if (d > (c-2)) cout << true << endl;
        else {
            int pos = 0;
            while (pos < (c-1)) {
                for (int j = d+1+pos; j > pos; j--) {
                    if (j >= (c-1)) {
                        jump++;
                        pos = c;
                        cout << jump << endl;
                        jump = 0;
                        break;
                    }
                    else {
                        if (arr[j] == '.') {
                            pos = j;
                            jump++;
                            break;
                        }
                    }
                }
            }
        }
        cout << endl;
        i++;
    }
    return 0;
}