#include <iostream>
using namespace std;

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
            cout << i << " : ";
            int count = 0;
			while (n % i == 0)
				n /= i;
                count++;
            cout << count << endl;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main() {
    int n = 234;

    cout << phi(n);

    return 0;
}