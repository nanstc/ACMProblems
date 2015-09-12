
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int n;
long double r, u, s, a;
int main() {
    cin >> n;
    while (n--) {
        cout << fixed << setprecision(5);
        cin >> r;
        u = (2.0 + sqrt(2) + sqrt(6));
        s = r * u;
        a = s*s;
        cout << a << endl;
    }
    return 0;
}

