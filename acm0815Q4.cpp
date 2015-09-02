#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
int i = 1;
int t = 0;
bool wayToSort(int i, int j) {
    return i > j;
}
int main() {
    cin >> n;
    while (i<=n) {
        cin >> c;
        int temp [c];
        for (int i = 0; i < c; i++) {
            cin >> temp[i];
        }
        sort(temp, temp + c);
        int temp2[c*4];
        for (int j = 0; j < c*4; j++) {
            cin >> temp2[j];
        }
        sort(temp2, temp2 + c*4, wayToSort);
        int people [c][5];
        for (int i = 0; i < c; i++) {
            people[i][0] = temp[i];
            for (int j = 1; j < 5; j++) {
                people[i][j] = temp2[j+4*i-1];
            }
        }
        for (int i =0; i < c; i++) {
            int localmax = 0;
            for (int j = 1; j < 5 ; j++) {
                localmax = max(localmax, people[i][j]);
            }
            int maxt = people[i][0] + localmax;
            t = max(t,maxt);
        }
        cout << "Trip #" << i <<": " << t <<endl;
        t = 0;
        i++;
    }
    return 0;
}