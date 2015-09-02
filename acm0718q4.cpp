#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int t,m,n,q;
int main() {
    cin >> t;
    while (t--) {
        string str;
        getline(cin, str);
        stringstream stream(str);
        int count = 1;
        while (stream) {
            switch (count) {
                case 1:
                    stream >> m;
                    break;
                case 2:
                    stream >> n;
                    break;
                case 3:
                    stream >> q;
                    break;
            }
            count++;
        }
        int dic[m];
        for (int i =0; i < m; i++) {
            string temp;
            cin >> temp;
            dic[i] = temp.length();
            cout << "valune at array " << i << ": " << dic[i] << endl;;
        }
    }
    return 0;
}