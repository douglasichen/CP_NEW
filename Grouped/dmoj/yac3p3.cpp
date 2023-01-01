#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	bool gd=1;
	vector<int> dA(N+2), dB(N+2), psa(N+1), startA(N+2), endA(N+1), startB(N+1), endB(N+1), V(N+2), cntA(N+1), cntB(N+1);
	vector<vector<int>> A,B;
	for (int i=0; i<M; i++) {
		int x,l,r; cin>>x>>l>>r;
		if (x==1) dA[l]++, dA[r+1]--, startA[l]++, endA[r]++;
		else dB[l]++, dB[r+1]--, startB[l]++, endB[r]++;
	}
	for (int i=1; i<=N; i++) dA[i]+=dA[i-1], dB[i]+=dB[i-1];

	vector<int> intv(2);
	for (int i=1; i<=N; i++) {
		if (!startA[i] && !endA[i]) continue;
		if (startA[i]==dA[i]) intv[0]=i;
		if (endA[i]==dA[i]) intv[1]=i, A.push_back(intv);
	}
	for (int i=1; i<=N; i++) {
		if (!startB[i] && !endB[i]) continue;
		if (startB[i]==dB[i]) intv[0]=i;
		if (endB[i]==dB[i]) intv[1]=i, B.push_back(intv);
	}
	//
	

	fill(startA.begin(), startA.end(), 0), fill(endA.begin(), endA.end(), 0);
	fill(startB.begin(), startB.end(), 0), fill(endB.begin(), endB.end(), 0);
	for (vector<int> v : A) {
		for (int i=v[0], val=1; i<=v[1]; i++, val++) cntA[i]=1, psa[i]=1;
		startA[v[0]]=1, endA[v[1]]=1;
	}
	for (int i=1; i<=N; i++) psa[i]+=psa[i-1];


	for (vector<int> v : B) {
		for (int i=v[0]; i<=v[1]; i++) cntB[i]=1;
		startB[v[0]]=1, endB[v[1]]=1;
	}
	
	for (vector<int> v : B) {
		int cnt=psa[v[1]]-psa[v[0]-1];
		if (cnt>2) gd=0;
		else if (cnt==2) {
			if (!cntA[v[0]] || !cntA[v[1]] || !endA[v[0]] || !startA[v[1]]) gd=0;
		}

		if (!gd) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	vector<pair<vector<int>,int>> C;
	for (vector<int> i : A) C.push_back(make_pair(i,0));
	for (vector<int> i : B) C.push_back(make_pair(i,1));
	auto srt=[&](pair<vector<int>,int> &a, pair<vector<int>,int> &b){
		int szA=a.first[1]-a.first[0]+1, szB=b.first[1]-b.first[0]+1;
		if (szA==szB) return a.first[0]<b.first[0];
		return szA>szB;
	};
	sort(C.begin(),C.end(),srt);
	for (pair<vector<int>,int> p : C) {
		vector<int> v=p.first;
		if (!p.second) {
			int val=1;
			for (int i=v[0]; i<=v[1]; i++) {
				val=max(val,V[i]);
				while (val==V[i-1]) val++;
				V[i]=val;
			}
			if (V[v[1]]==V[v[1]+1]) V[v[1]]++;
		}
		else {
			int val=1;
			for (int i=v[1]; i>=v[0]; i--) {
				val=max(val,V[i]);
				while (val==V[i+1]) val++;
				V[i]=val;
			}
			if (V[v[0]]==V[v[0]-1]) V[v[0]]++;
		}
	}
	for (int i=1; i<=N; i++) {
		if (!V[i]) {
			V[i]=1;
			while (V[i]==V[i-1] || V[i]==V[i+1]) V[i]++;
		}
	}
	
	for (int i=1; i<=N; i++) cout << V[i] << ' '; cout << endl;
	
}