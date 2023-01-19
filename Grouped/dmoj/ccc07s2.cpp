#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=1000;
vector<int> A[MAXN], B[MAXN];
int N, M;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	fill(A,A+MAXN,vector<int>{0,0,0});
	fill(B,B+MAXN,vector<int>{0,0,0});

	cin>>N;
	for (int i=0; i<N; i++) {
		cin>>A[i][0]>>A[i][1]>>A[i][2];
		sort(A[i].begin(),A[i].end());
	}
	auto srt=[](vector<int> a, vector<int> b) {
		return a[0]*a[1]*a[2]<b[0]*b[1]*b[2];
	};
	sort(A,A+N,srt);
	
	cin>>M;
	for (int i=0; i<M; i++) {
		cin>>B[i][0]>>B[i][1]>>B[i][2];
		sort(B[i].begin(),B[i].end());
	}

	for (int b=0; b<M; b++) {
		int ans=0;
		for (int a=0; a<N; a++) {
			if (B[b][0]<=A[a][0] && B[b][1]<=A[a][1] && B[b][2]<=A[a][2]) {
				ans=A[a][0]*A[a][1]*A[a][2];
				break;
			}
		}
		if (ans) cout << ans << endl;
		else cout << "Item does not fit." << endl;
	}
}