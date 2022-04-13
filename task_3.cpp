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
    vector<int> r = {10, 17, 11};
    vector<int> m = {63, 47, 40};
    int ma = pr(m);
    cout << "M: " << ma << endl;
    int res = 0;

    for(int i = 0; i < r.size(); i++) {
        int M = up(ma, m[i]);
        int M_re = reverse(M, m[i]);
        cout << "Mi: " << M << " M'i: " << M_re << endl;
        res += (r[i]*M*M_re)%ma;
    }   

    cout << res;
    return 0;
}