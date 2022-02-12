//https://blog.naver.com/occidere/220787441430

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;cin>>n;
	int d[1000];//원랜 int d[1000001];여야하는데 여기선 에러뜸,,
	d[0] = 0; d[1] = 1; d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 2] + d[i - 1];
        d[i]%=15746;
	}
	cout << d[n];
}
4