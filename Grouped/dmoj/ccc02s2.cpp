#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    int A,B; cin>>A>>B;
	vector<string> ans;
    if (A==0) cout << 0 << endl;
    else {
        if (A>B) ans.push_back(to_string(A/B)), A=A%B;
		if (A) ans.push_back(to_string(A/gcd(A,B))+"/"+to_string(B/gcd(A,B)));
    }
	if (ans.size()==1) cout << ans[0] << endl;
	else cout << ans[0] << ' ' << ans[1] << endl;
}
