#include <iostream> 
#include <string> 
#include <cstdlib>
#include <sstream>

using namespace std;

void print(int * arr, int num) {
    for (int i = 0; i < num; i ++) {
        cout << arr[i];
    }
}
int main() {
    int digits[1000];                              // original input in array
    int digits_high[1000];
    int digits_low[1000];
    int length;
    int curr = 0;
    bool consecutive = true;
    bool odd;
    string ugly;
    
    cin >> ugly;
    length = ugly.length();
    for (int i = 0; i < length; i++) {
        string digit = ugly.substr(i,1);
        digits[i] = stoi(digit);
    }
    do {
        bool temp;
        if (digits[curr] % 2 == 0) temp = false; // even is false, odd is true
        else temp = true;
        if (length == 1) {
            cout << ugly << endl;
            consecutive = true;
            break;
        }
        if (curr > 0 && odd == temp) {
            if (digits[curr] == 9) digits_high[curr]= 0;
            else digits_high[curr] = digits[curr]+1;
            if (digits[curr] == 0)  digits_low[curr] = 9;
            else digits_low[curr] = digits[curr]-1;
            for (int i = curr+1; i < length; i++) {
                if (digits_high[curr]%2 == 0 || digits_high[curr] == 0) {
                    digits_high[i] =1;
                    digits_low[i] =9;
                    curr++;
                }
                else {
                    digits_high[i] =0;
                    digits_low[i] =8;
                    curr++;
                }

            }
            /*print(digits_high, length);
            cout << endl;
            print(digits_low, length);
            cout << endl;
             */
            for (int i =0; i < length; i++) {
                int digit_high = digits_high[i];
                int digit_low  = digits_low[i];
                int digit_original = digits[i];
                //cout << digit_high << endl << digit_low << digit_original << endl;
                if (abs(digit_original - digit_high) < abs(digit_original - digit_low)) {
                    print(digits_high, length);
                    cout << endl;
                    break;
                    
                }
                else if (abs(digit_original - digit_high) > abs(digit_original - digit_low)) {
                    print(digits_low, length);
                    cout << endl;
                    break;
                }
                else {
                    if (i == length -1) {
                        print(digits_low, length);
                        cout << " ";
                        print(digits_high, length);
                        cout << endl;
                    }
                }
            }
            consecutive = false;
            
        }
        else {
            odd = temp;
            digits_high[curr]=digits[curr];
            digits_low[curr] = digits[curr];
            curr++;
        }

    }
    while (consecutive);
    
    
    return 0;
}

/*
 for (unsigned i =0; i < length; i++) {
 shigh << digits_high[i];
 slow << digits_low[i];
 soriginal << digits[i];
 }
 
 shigh >> high;
 slow >> low;
 soriginal >> original;
 
 if (abs(high - original) < abs(original - low)) cout << high << endl;
 else if (abs(high - original) > abs(original - low)) cout << low << endl;
 else cout << low << " " << high << endl;
 */
