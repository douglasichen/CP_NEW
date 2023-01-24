
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=51;
int ar[MAXN][MAXN], house[MAXN][MAXN], on[MAXN][MAXN], vis[MAXN][MAXN];
vector<vector<int>> locs;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(ar,0);
	ms(house,0);
	
	int N; cin>>N;
	int totH=0;
	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			char c; cin>>c;
			if (c!='.') house[y][x]=1, totH++;
		}
	}
	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			cin>>ar[y][x];
			locs.push_back({y,x});
		}
	}

	sort(locs.begin(),locs.end(),[&](vector<int> a, vector<int> b){
		return ar[a[0]][a[1]]<ar[b[0]][b[1]];
	});

	queue<vector<int>> qu;

	int ans=1e7;
	for (int a=0; a<N*N; a++) {
		int h=0;
		bool start=0;
		ms(vis,0);
		ms(on,0);
		for (int b=a; b<N*N; b++) {
			vector<int> A=locs[a], B=locs[b];
			int dif=ar[B[0]][B[1]]-ar[A[0]][A[1]];

			bool gd=0;
			for (int y=B[0]-1; y<=B[0]+1; y++) {
				for (int x=B[1]-1; x<=B[1]+1; x++) {
					if (on[y][x] && !start) {
						start=1;
						gd=1;
					}
					if (on[y][x] && vis[y][x]) {
						gd=1;
					}
				}
			}
			on[B[0]][B[1]]=1;

			if (gd) vis[B[0]][B[1]]=1, qu.push(B);
			while (SZ(qu)) {
				vector<int> at=qu.front(); qu.pop();
				if (house[at[0]][at[1]]) h++;
				for (int y=at[0]-1; y<=at[0]+1; y++) {
					for (int x=at[1]-1; x<=at[1]+1; x++) {
						if (on[y][x] && !vis[y][x]) {
							vis[y][x]=1;
							qu.push({y,x});
						}
					}
				}
			}

			if (h==totH) ans=min(ans,dif);
		}
	}

	cout << ans << endl;

}