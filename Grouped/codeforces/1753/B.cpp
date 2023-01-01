#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,X; cin>>N>>X;
	vector<int> cnt(X+1);
	for (int i=0,a; i<N; i++) cin>>a, cnt[a]++;
	bool gd=0, ans=1;
	for (int i=1; i<X; i++)	{
		cnt[i+1]+=cnt[i]/(i+1), cnt[i]%=(i+1);
		if (cnt[i]) {
			ans=0;
			break;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}