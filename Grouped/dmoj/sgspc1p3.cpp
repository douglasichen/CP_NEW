#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int md=1e9+7;
vector<int> dsu;
vector<ll> power;
ll totPow=0;

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

void join(int a, int b) {
	a=root(a), b=root(b);
	if (a==b) return;
	if (dsu[a]>dsu[b]) swap(a,b);

	vector<ll> bef={power[a],power[b]};
	power[a]*=power[b]; power[a]%=md;
	power[b]=0;
	totPow+=power[a]-bef[0];
	totPow+=power[b]-bef[1];
	
	dsu[a]+=dsu[b];
	dsu[b]=a;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	// take input, init arrays, set power
	int N; cin>>N;
	dsu.assign(N,-1);
	power.assign(N,0);
	for (ll &i : power) cin>>i, totPow+=i;

	vector<vector<int>> B(N-1, vector<int>(2));
	for (int i=0; i<N-1; i++) {
		cin>>B[i][0]>>B[i][1];
		sort(B[i].begin(), B[i].end());
	}

	int M; cin>>M;
	vector<vector<int>> Q(M-1, vector<int>(2));
	for (int i=0,a; i<M-1; i++) {
		cin>>a>>Q[i][0]>>Q[i][1];
		sort(Q[i].begin(), Q[i].end());
	}
	int x; cin>>x;
	
	// solve
	vector<bool> add(N-1,1);
	vector<vector<int>> sQ=Q;
	sort(B.begin(), B.end());
	sort(sQ.begin(), sQ.end());
	
	// maybe this doesnt work properly
	for (int a=0, b=0; a<N-1 && b<M-1; a++) {
		while (b<M-1 && sQ[b][0]<B[a][0]) b++;
		if (b>=M-1 || sQ[b][0]>B[a][0]) continue;
		
		// now first nodes are equal
		while (b<M-1 && sQ[b][1]<B[a][1]) b++;
		if (b>=M-1 || sQ[b][1]>B[a][1]) continue;

		// now both nodes are equal
		add[a]=0;
	}
	for (int i=0; i<N-1; i++) {
		if (add[i]) join(B[i][0]-1, B[i][1]-1);
	}

	vector<ll> ans(M);
	ll first=totPow;
	for (int i=M-2; i>=0; i--) {
		vector<int> q=Q[i];
		join(q[0]-1, q[1]-1);
		ans[i]=totPow;
		if (i==M-2) first=totPow;
	}

	
	ans[M-1]=first;
	for (int i=0; i<M-(M%2); i+=2)
		cout << ans[i]%md << endl;
}