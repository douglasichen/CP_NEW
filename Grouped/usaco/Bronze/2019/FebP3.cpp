#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	
	int INF=1e9;

	int N; cin>>N;
	vector<int> type(N+1);
	vector<vector<int>> V(N+1, vector<int>(2)), F=V;
	for (int i=1; i<=N; i++) {
		string a; int b,c; cin>>a>>b>>c;
		if (a=="on") type[i]=1;
		else if (a=="off") type[i]=2;
		V[i]={b,c};
	}
	
	int at=0;
	type[0]=1;
	for (int i=0; i<N; i++) {
		if (type[i] && !type[i+1]) {
			at=i;
			break;
		}
	}

	vector<int> flow={-INF,INF};
	for (int i=at+1; i<=N; i++) {
		if (!type[i]) flow={max({flow[0], V[i][0],0}), max(min(flow[1], V[i][1]),0)};
		else if (type[i]==1) flow={max(0,flow[0]+V[i][0]), max(0,flow[1]+V[i][1])};
		else flow={max(0,flow[0]-V[i][1]), max(0,flow[1]-V[i][0])};
		F[i]=flow;
	}

	// for (int i=1; i<=N; i++) cout << type[i] << ' '; cout << endl;

	// for (int i=1; i<=N; i++)
	// 	cout << '(' << F[i][0] << ' ' << F[i][1] << ')';
	// cout << endl;
	for (int i=N-1; i>at; i--) {
		if (!type[i+1]) 
			F[i]={max({F[i][0], F[i+1][0],0}), max(0,min(F[i][1], F[i+1][1]))};
		else if (type[i+1]==1)
			F[i]={max({F[i][0], F[i+1][0]-V[i+1][1],0}), max(0,min(F[i][1], F[i+1][1]-V[i+1][0]))};
		else if (type[i+1]==2)
			F[i]={max({F[i][0], F[i+1][0]+V[i+1][0],0}), max(min(F[i][1], F[i+1][1]+V[i+1][1]),0)};
	}
	for (int i=at; i; i--) {
		if (type[i]==1) F[i]={max(0,F[i+1][0]-V[i][1]), max(F[i+1][1]-V[i][0],0)};
		else F[i]={max(0,F[i+1][0]+V[i][0]), max(0,F[i+1][1]+V[i][1])};
	}
	cout << F[1][0] << ' ' << F[1][1] << endl << F[N][0] << ' ' << F[N][1] << endl;
	// for (int i=1; i<=N; i++)
	// 	cout << '(' << F[i][0] << ' ' << F[i][1] << ')';
	// cout << endl;
}