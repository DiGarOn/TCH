#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> num = {0, 0, -5, 13};
    int p = 17;
    for(int i = 0; i < p; i++) {
        if( int(pow(i,4) + num[0]*pow(i,3) + num[1] * pow(i, 2) + num[2] * i + num[3])%p == 0) {
            cout << i << endl;
        }
    }

    return 0;
}