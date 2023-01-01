#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector<vector<int>> v;
		for (int at=1; at*at<=N; at++)
			if (N%at==0)
				v.push_back({at,N/at});

		bool ans=0;
		for (int i=0; i<v.size(); i++)
			for (int o=i+1; o<v.size(); o++)
				if (abs(v[i][0]-v[i][1])==v[o][0]+v[o][1])
					ans=1;
		cout << N << (ans ? " is nasty" : " is not nasty") << endl;
	}	
}