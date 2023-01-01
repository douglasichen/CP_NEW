#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	int N=people.size(), ts=1e6+1;
	
	// init tree
	vector<int> T(ts*2);
	
	// sort
	vector<vector<int>> ans;
	sort(people.begin(),people.end());
	
	// find start
	vector<bool> taken(N);
	for (int i=0; i<N; i++) {
		vector<int> v=people[i];
		if (v[1]==0) {
			ans.push_back(v);
			taken[i]=1;
			
			T[v[0]+ts]++;
			break;
		}
	}
	
	// build tree
	for (int i=ts-1; i>0; i--) T[i]=T[i<<1]+T[(i<<1)+1];

	// solve
	for (int i=0; i<N-1; i++) {
		for (int o=0; o<N; o++) {
			if (!taken[o]) {
				// is this an option? if so take that option
				vector<int> v=people[o];
				int cnt=0,a=v[0],b=1e6+1;
				for (a+=ts, b+=ts; a<b; a>>=1, b>>=1) {
					if (a&1) cnt+=T[a++];
					if (b&1) cnt+=T[--b];
				}
				// cout << v[0] << ": " << cnt << endl;
				if (cnt==v[1]) {// good option
					ans.push_back(v);
					taken[o]=1;
					
					// modify the tree
					int p=v[0];
					for (T[p+=ts]++; p>0; p>>=1) T[p>>1]++;
					break;
				}
			}
		}
		// cout << endl;
	}
		
	return ans;
}

int main() {
	vector<vector<int>> v={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	vector<vector<int>> ans=reconstructQueue(v);
	for (vector<int> a : ans) cout << a[0] << ' ' << a[1] << endl;

}