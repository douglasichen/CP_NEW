#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=51;
int psa[MAXN][MAXN];

int sm(short y1, short x1, short y2, short x2) {
	return psa[y2][x2]-psa[y1-1][x2]-psa[y2][x1-1]+psa[y1-1][x1-1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(psa,0);

	int N; cin>>N;
	for (int y=1; y<=N; y++)
		for (int x=1; x<=N; x++)
			cin>>psa[y][x],
			psa[y][x]+=psa[y-1][x]+psa[y][x-1]-psa[y-1][x-1];

	ll ans=0;
	int mySm=0;
	for (int a=1; a<=N; a++) {
		for (int b=1; b<=N; b++) {
			map<int,int> fr;
			for (int y=1; y<=a; y++) {
				for (int x=1; x<=b; x++) {
					mySm=sm(y,x,a,b);
					fr[mySm]++;
				}
			}
			for (int y=a+1; y<=N; y++) {
				for (int x=b+1; x<=N; x++) {
					mySm=sm(a+1,b+1,y,x);
					ans+=fr[mySm];
				}
			}
		}
	}

	for (int a=N; a>=1; a--) {
		for (int b=1; b<=N; b++) {
			map<int,int> fr;
			for (int y=N; y>=a; y--) {
				for (int x=1; x<=b; x++) {
					mySm=sm(a,x,y,b);
					fr[mySm]++;
				}
			}
			for (int y=a-1; y>=1; y--) {
				for (int x=b+1; x<=N; x++) {
					mySm=sm(y,b+1,a-1,x);
					ans+=fr[mySm];
				}
			}
		}
	}
	cout << ans << endl;
}