#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector<int> F(N+1);
		
		auto cmp=[](int a, int b) {return a>b;};
		multiset<int, decltype(cmp)> E(cmp);
		for (int i=0, val; i<N; i++) {
			cin>>val, F[val]++;
			if (F[val]>=2) E.insert(val);
		}
		vector<long long> ans(N+1,-1);
		int i;
		for (i=0; i<=N && F[i]; i++) ans[i]=F[i];
		ans[i]=0;
		long long beh=i, cnt=0;
		for (i+=1; i<=N; i++) {
			if (beh!=-1) {
				if (E.empty() || *E.rbegin()>=beh) break;
				auto it=E.upper_bound(beh);

				cnt+=beh-(*it);
				E.erase(it);
			}
			ans[i]=cnt+F[i];

			if (F[i]==0) beh=i; 
			else beh=-1;
		}
		for (int e=0; e<=N; e++) cout << ans[e] << ' '; cout << endl;
	}	
}