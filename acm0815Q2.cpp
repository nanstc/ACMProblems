#include <iostream> 
#include <string> 
using namespace std;

int n, g0, g, p0, p;

int main() {
    int num = 1;
    cin >> n;
    while (num <= n) {
        cin >> g >> p;
        g0 = g;
        p0 = p;
        cout << "Team #" << num << endl;
        cout << "Games: " << g << endl;
        cout << "Points: " << p << endl;
        cout << "Possible records:" << endl;
        int w, t, l;
        w = p / 3;
        while (w >= 0) {
            g -=w;
            p -= 3*w;
            if ( p == 0) {
                t = 0;
                l = g;
                cout << w << "-" << t << "-" << l << endl;
            }
            else {
                if (p <= g) {
                    t = p;
                    l = g - t;
                    cout << w << "-" << t << "-" << l << endl;
                }
            }
            g= g0;
            p = p0;
            w--;
        }
        cout << endl;
        num++;
    }
    return 0;
}