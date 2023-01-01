#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		int L=1, R=N; 
		while (L<R) {
			int mid=L+R>>1, cnt=0;
			cout << "? " << L << " " << mid << endl; cout.flush();
			for (int i=1, e; i<=mid-L+1; i++) {
				cin>>e;
				if (e==-1) return 0;
				if (L<=e && e<=mid) cnt++;
			}
			if (cnt&1) R=mid;
			else L=mid+1;
		}
		cout << "! " << L << endl;
	}
	return 0;
}