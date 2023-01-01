#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<string> units={"cm", "m", "km"};
	vector<float> conv={0.01, 1, 1000};
	vector<vector<int>> V(rand()%4, vector<int>(2));
	for (vector<int> &v : V) {
		v={rand()%100, rand()%100};
	}
}