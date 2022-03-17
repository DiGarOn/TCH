#include <iostream>
#include <vector>

using namespace std;

int up(int m, int mi) {
    return m/mi;
}

int reverse(int M, int m) {
    for(int i = 1; i < 100; i++) {
        if((M*i)%m == 1) {
            return i;
        }
    }
}

int pr(vector<int>& m) {
    int res = 1;
    for(int i = 0; i < m.size(); i++) {
        res*=m[i];
    }
    return res;
}

int main() {
    vector<int> r = {1,2,3};
    vector<int> m = {13,17,19};
    int ma = pr(m);

    int res = 0;

    for(int i = 0; i < r.size(); i++) {
        int M = up(ma, m[i]);
        res += (r[i]*M*reverse(M, m[i]))%ma;
    }   

    cout << res;
    return 0;
}