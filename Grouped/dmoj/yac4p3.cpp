#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N,M,B,K=0, ans=0;
vector<vector<int>> G, E;
vector<int> A;

void solve(vector<int> c) {
	A.assign(N+1,-1);
	
	stack<int> S;
	vector<bool> vis(N+1);
	S.push(1), vis[1]=1;
	while (!S.empty()) {
		int top=S.top(); S.pop();
		for (int col : c) {
			bool gd=1;
			for (int child : G[top]) gd&=(A[child]!=col);
			if (gd) {
				A[top]=col;
				break;
			}
		}

		for (int child : G[top])
			if (!vis[child])
				S.push(child),
				vis[child]=1;
	}
	for (int &i : A) if (i<0) i=0;

	int res=INT_MAX;
	for (vector<int> &e : E)
		res=min(res, A[e[0]]^A[e[1]]);
	if (res>ans) ans=res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M>>B;
	G.assign(N+1, {});
	E.assign(M, vector<int>(2));
	for (vector<int> &e : E) 
		cin>>e[0]>>e[1],
		G[e[0]].push_back(e[1]),
		G[e[1]].push_back(e[0]);		
	
	while (B) K++, B>>=1;
	B=1<<(K-1);

	solve({B,B-1});
	solve({B,B-1,0});
	
	cout << ans << endl;
	for (int i=1; i<=N; i++) cout << A[i] << ' '; cout << endl;
}