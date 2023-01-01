#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	vector<int> choose={1,0,1,2,1,0,1};
	vector<string> ops={"A3", "A4", "A5"};
	vector<int> done={0,0,0};
	for (int i=8; i<=30; i++) {
		int ch=choose[i%7];
		cout << 2016-done[ch] << ' ' << ops[ch] << endl;
		done[ch]++;
	}
} 