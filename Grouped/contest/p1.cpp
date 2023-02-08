#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()


int ans=0;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int a=1; a<=18; a++) {
		for (int b=1; b<=18; b++) {
			for (int c=1; c<=18; c++) {
				for (int d=1; d<=18; d++) {
					set<int> s;
					s.insert(a);
					s.insert(b);
					s.insert(c);
					s.insert(d);
					if (SZ(s)==4) ans++;
				}
			}
		}
	}
	cout<<ans << endl;
}