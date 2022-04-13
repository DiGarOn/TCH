#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    vector<vector<int> > mas = devi(513);
    for(int i = 0; i < mas.size(); i++) {
        cout << mas[i][0] << " : " << mas[i][1] << endl;
    }
    return 0;
}