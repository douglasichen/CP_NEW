#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

<<<<<<< HEAD
struct Node {
	ll x=0, y=0;
};

const int TSZ=1<<20;
ll ar[TSZ], dp[TSZ];
=======
<<<<<<< HEAD
const int TSZ=1<<20;
ll ar[TSZ], dp[TSZ];
=======
const int MAXN=200;
int ar[MAXN];
>>>>>>> bf4a286ae018ece9f90054e7bfc406e9865d112d
>>>>>>> 417aef188bf2666338f416c93edf217048bb3528

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ms(ar,0);
	ms(dp,0);

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 417aef188bf2666338f416c93edf217048bb3528
	int N,K; cin>>N>>K;
	for (int i=1; i<=N; i++) cin>>ar[i];
	
	for (int i=1; i<=N; i++) {
		int L=max(0,i-K), R=(i-1)/K*K;
		ll mx=0;
		for (int a=i; a>R; a--) mx=max(mx, ar[a]);
		for (int a=R; a>=L; a--) {
			dp[i]=max(dp[i], dp[a]+mx);
			mx=max(mx,ar[a]);
<<<<<<< HEAD
		}
	}

	// for (int i=1; i<=N; i++) cout << dp[i] << ' '; cout << endl;
	cout << dp[N] << endl;
}

/*
7 4
6 4 8 9 3 2 4 
*/
=======
		}
	}


	for (int i=1; i<=N; i++) cout << dp[i] << ' '; cout << endl;
	cout << dp[N] << endl;
}

/*
8 3
5 3 8 3 8 8 5 6 

*/
=======
	int N,C; cin>>N>>C;
	for (int i=0; i<N; i++) cin>>ar[i];
	ll ans=0;
	for (int a=0; a<N; a++) {
		for (int b=a+1; b<N; b++) {
			for (int c=b+1; c<N; c++) {
				vector<int> v={ar[a],ar[b],ar[c]};
				sort(v.begin(), v.end());
				int x=max({v[1]-v[0], v[2]-v[1], v[0]+C-v[2]});
				if (x<(C+1)/2) ans++;
			}
		}
	}
	cout << ans << endl;
}
>>>>>>> bf4a286ae018ece9f90054e7bfc406e9865d112d
>>>>>>> 417aef188bf2666338f416c93edf217048bb3528
