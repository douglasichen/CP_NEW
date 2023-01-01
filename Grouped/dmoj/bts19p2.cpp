#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int X,Y,H,V,T;
int calc(int x, int y) {
	if ((2*x-y)%3==0) {
		int a=(2*x-y)/3, b=(2*y-x)/3;
		if (a>=0 && b>=0)
			return a+b;
	}
	return INT_MAX;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>X>>Y>>H>>V>>T;
	int ans=INT_MAX;
	for (int x=X; x<X+H; x++)
		ans=min(ans,calc(x,Y));
	for (int y=Y; y<Y+V; y++)
		ans=min(ans,calc(X,y));
	
	if (ans<T) cout << "YES" << endl;
	else cout << "NO" << endl;
}