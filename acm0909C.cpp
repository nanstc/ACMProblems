#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,n0;
typedef long long ll;
int main() {
    cin >> n >> m;
    vector<ll> shop;
    vector<ll> joe;
    n0 = n;
    int temp;
    int w =0;
    for (int i=0; i < n; i++) {
        cin >> temp; shop.push_back(temp);
    }
    for (int j=0; j < m; j++) {
        cin >> temp; joe.push_back(temp);
    }
    sort(shop.begin(), shop.end());
    sort(joe.begin(), joe.end());
    int pos = 0;
    for (ll c : joe) {
        for (int s = pos; s < n0; s++) {
            if (shop[s]>= c) {
                w += (shop[s]-c);
                pos = s;
                break;
            }
        }
    }
    cout << w << endl;
    return 0;
}