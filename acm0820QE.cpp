#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    int cashiers [3][k];
    for (int i = 0; i < k; i++) {
        cashiers[0][k] = 0;
    }
    int count = 0;
    int sum = 0;
    while (count < n) {
        int customer;
        cin >> customer;
        bool placed = false;
        for (int i = 0; i < k; i++) {
            if (cashiers[1][i] == 0) {
                cashiers[1][i] = customer;
                cout << i+1 << " ";
                ++cashiers[0][i];
                count++;
                placed = true;
                break;
            }
        }
        if (!placed) {
            int temp;
            int min = cashiers[2][0];
            for (int i = 0; i < k; i++) {
                if (cashiers[2][i] < min) {
                    temp = [i]; 
                cout << i+1 << " ";
                ++cashiers[0][i];
                count++;
                break;
                }
            }
        }
        if (!placed) {
            for (int i = 0; i < k; i++) {
                if (sum == 0) sum = (cashiers[1][i] + cashiers[2][i]);
                if ((cashiers[1][i] + cashiers[2][i]) * cashiers[0][i] < sum) {
                    ++cashiers[0][i];
                    int temp = cashiers[2][i];
                    cashiers[2][i] = customer;
                    cashiers[1][i] = temp;
                    cout << i+1 << " ";
                    count++;
                    break;
                }
            }
        }
        if (count == n) {
            cout << endl;
            break;
        }
    }
    return 0;
}