#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	for (int t=0; t<T; t++) {
		int A,B; cin>>A>>B;
		int a=0, b=1;
		if (A>B) swap(A,B), swap(a,b);
		for (int i=0; i<A; i++) cout << a << b, B--;
		for (int i=0; i<B; i++) cout << b;
		cout << endl;
	}
}