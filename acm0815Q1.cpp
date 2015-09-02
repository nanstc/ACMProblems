#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n, l, v, c;

int main() {
    cin >> n;
    while (n--) {
        v = 0;
        c = 0;
        string name;
        cin >> name;
        l = name.length();
        char array[l];
        strcpy (array, name.c_str());
        for (int i =0 ; i < l; i++) {
            if (array[i] == 'a' || array[i] == 'e' || array[i] == 'i' || array[i] == 'o'|| array[i] == 'u') {
                v++;
            } else c++;
        }
        if (v > c) {
            cout << name <<endl;
            cout << true << endl;
        }
        else {
            cout << name <<endl;
            cout << false << endl;
        }
    }
    return 0;
}