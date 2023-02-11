#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))
#define endl '\n';

const int MAXN=201;
int ar[MAXN];

void print(int a[]) {
	cout << a[0] << ' ' << a[1] << endl;
}

void print(vector<int> a) {
	cout << a[0] << ' '<<a[1] << endl;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, A[2], B[2], C[2], D[2];
	cin>>N>>A[0]>>A[1]>>B[0]>>B[1]>>C[0]>>C[1]>>D[0]>>D[1];

	if (A[0]!=C[0] && A[1]!=C[1]) swap(C,D);

	int y=abs(A[0]-B[0]), x=abs(A[1]-B[1]);
	vector<int> tar;
	if (y>=x) {
		if (A[0]<B[0]) tar={A[0]+1,A[1]};
		else tar={A[0]-1,A[1]};
	}
	else {
		if (A[1]<B[1]) tar={A[0],A[1]+1};
		else tar={A[0],A[1]-1};
	}

	y=abs(tar[0]-D[0]);
	x=abs(tar[1]-D[1]);
	// print(tar);
	// print({y,x});
	
	int ans=y+x+1;

	y=abs(B[0]-tar[0]);
	x=abs(B[1]-tar[1]);

	cout << ans << endl;
	ans+=(max(y,x)-min(y,x))*5 + 3*min(y,x);

	if (A==B) ans=0;
	cout << ans << endl;

}