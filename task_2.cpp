#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define A cout << "\nhere"

int count(vector<int>&a, int p) {
    int count = 0;
    for(int i = 0; i < p; i++) {
        if((a[0]*i*i + a[1]*i + a[2])%p == 0) {
            ++count;
        }
    }
    return count;
}

vector<vector<int> > devi(int a) {
    vector<vector<int> > res;
    while(a > 1) {
        bool target = false;
        for(int i = 2; i < a; i++) {
            if(a % i == 0) {
                int flag = -1;
                for(int j = 0; j < res.size(); j++) {
                    if(res[j][0] == i) {
                        flag = j;
                        break;
                    }
                }
                if(flag != -1) {
                    res[flag][1]++;
                } else {
                    vector<int> val = {i, 1};
                    res.push_back(val);
                }
                a/=i;
                target = true;
                break;
            }
        }
        if(!target) {
            int flag = -1;
            for(int j = 0; j < res.size(); j++) {
                if(res[j][0] == a) {
                    flag = j;
                    break;
                }
            }
            if(flag != -1) {
                res[flag][1]++;
            } else {
                vector<int> val = {a, 1};
                res.push_back(val);
            }
            a=1;
        }
    }
    return res;
}

int Leg(int a, int p) {
    //cout << a << " " << p << endl;
    //cout << a << " " << p << endl;
    if(a==2) return pow(-1,((p*p-1)/8));
    if(p==2) return pow(-1,((a*a-1)/8));
    if(a==-1) return pow(-1, (p-1)/2);
    if(p==-1) return pow(-1, (a-1)/2);
    if(a==1) return 1;
    if(p==1) return 1;
    if(a==0) return 0;
    if(p==0) return 0;
    a = a%p;
    if(a < 0) a = p+a;
    if(a==2) return pow(-1,((p*p-1)/8));
    if(p==2) return pow(-1,((a*a-1)/8));
    if(a==-1) return pow(-1, (p-1)/2);
    if(p==-1) return pow(-1, (a-1)/2);
    if(a==1) return 1;
    if(p==1) return 1;
    if(a==0) return 0;
    if(p==0) return 0;
    //cout << a << " " << p << endl;
    // if(a < p) {
    //     return pow(-1, ((a-1)/2)* (p-1)/2) * Leg(p,a);
    // }
    vector<vector<int> > mas = devi(a);
    int res = 1;
    for(int i = 0; i < mas.size(); i++) {  
        res *= pow( pow( -1, ((a-1)/2)* (p-1)/2 ) * Leg( p, mas[i][0] ), mas[i][1] );
    }
    
    return res;
}

int solve(vector<int>a, int p) {
    int d = a[1]*a[1] - 4*a[0]*a[0];
    int res = Leg(d, p);
    if(res == 1) return 2;
    if(res == -1) return 0;
    if(res == 0) return 1;
}

int a_2(long p) {
    return (pow(-1, (p*p-1)/8));
}

int swap(long a, long b) {
    return pow(-1, ((a-1)/2 * (b-1)/2));
}

int main() {
    vector<int> a = {9,0,0};
    int p = 64;
    
    vector<vector<int> > mas = devi(8);

    //cout << ((int(sqrt(4)) * int(sqrt(4))) == 4);
    //cout << Leg(5000, 101);
    //cout << Leg(514, 727) << endl;
    //cout << count(a, p)
    
    // for(int i = 0; i < mas.size(); i++) {
    //     cout << mas[i][0] << " : " << mas[i][1] << endl; 
    // }
    
    //cout << a_2(2271);

    cout << swap(29, 2271);

    return 0;
}