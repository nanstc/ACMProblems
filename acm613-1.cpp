#include <iostream> 
#include <fstream> 
#include <istream> 
#include <string> 

using namespace std;

int main() {
    int pizza[8];
    int min = 0;
    for (int i = 0; i < 8 ; i++) {
        cin >> pizza[i];
    }
    for (int i = 0; i < 8; i++) {
        int total = pizza[i] + pizza[(i+1)%8] + pizza[(i+2)%8] + pizza[(i+3)%8];
        if (total > min) min = total;
    }
    cout << min<<endl;
    return 0;
}