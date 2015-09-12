#include <iostream>

using namespace std;
int n0, s, b, m, g;

int cut(int b) {
    return b * 2;
}

int main() {
    cin >> n0;
    int n = 1;
    while (n <= n0) {
        cin >> s >> b >> m;
        cout << "Practice #" << n << ": " << s << " " << b << endl;
        while (m--) {
            cin >> g;
            cout << g << " ";
            bool more = (g >= b);
            while (more) {
                b = cut(b);
                more = (g >= b);
            }
            b -= g;
            cout << b << endl;
        }
        cout << endl;
        n++;
    }
    return 0;
}