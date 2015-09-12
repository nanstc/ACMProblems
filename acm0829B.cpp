#include <iostream>
#include <vector>
using namespace std;
int n,p,k,r,c,a,b;

typedef pair <int, int> yx;
typedef pair <yx, bool> rc; //bool stands for "self"
typedef pair <rc, int> cell;

int main() {
    cin >> n;
    while (n--) {
        vector <cell> board;
        cin >> p >> k;
        while (p--) {
            cin >> r >> c >> a >> b;
            for (int i = r-a; i <= r+a; i++) {
                for (int j = c-b; j <= c+b; j++) {
                    if ((i != r) && (j != c)) {
                        yx temp = make_pair(i,j);
                        bool found = false;
                        for (vector<cell>::iterator pos = board.begin(); pos != board.end(); pos++) {
                            if (pos->first.first == temp) {
                                pos->second += 1;
                                found = true;
                            }
                        }
                        if (!found) {
                            board.push_back(make_pair(make_pair(temp, true),1));
                        }

                    }
                }
                
            }
            for (int i = r-b; i <= r+b; i++) {
                for (int j = c-a; j <= c+a; j++) {
                    if ((i != r) && (j != c)) {
                        yx temp = make_pair(i,j);
                        bool found = false;
                        for (vector<cell>::iterator pos = board.begin(); pos != board.end(); pos++) {
                            if (pos->first.first == make_pair(i,j)) {
                                if (!pos->first.second) pos->second += 1;
                                found = true;
                            }
                        }
                        if (!found) {
                            board.push_back(make_pair(make_pair(temp, true),1));
                        }
                        
                    }
                }
                
            }
            for (vector<cell>::iterator pos = board.begin(); pos != board.end(); pos++) {
                pos->first.second = false;
            }
        }

        int t = 0;
        for (vector<cell>::iterator pos = board.begin(); pos != board.end(); pos++) {
            if (pos->second >= k) {
                t++;
            }
        }
        cout << t << endl;

    }
    return 0;
}