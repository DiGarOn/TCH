#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    for(int i = 0; i < 19*19; i++) {
        if((163+19*1752*i)%(19*19) == 0) cout << i;
    }
    return 0;
}