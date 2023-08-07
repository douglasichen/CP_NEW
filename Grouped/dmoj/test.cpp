#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

ll ans=0;

bool in(int &l, int &r, int &i) {
	return l<i && i<r;
}

int a,b,c,d,e;

void permute(string& s, int l, int r){
    if (l == r) {
		// check if `s` is good
		
		for (int i=0; i<SZ(s); i++) {
			switch (s[i]) {
				case 'A': a=i; break;
				case 'B': b=i; break;
				case 'C': c=i; break;
				case 'D': d=i; break;
				case 'E': e=i; break;
			}
		}
		bool gd=0;
		if (a<e) {
			if (in(a,e,b) && in(a,e,c) && in(a,e,d)) gd=1;
		}
		else {
			if (in(e,a,b) && in(e,a,c) && in(e,a,d)) gd=1;
		}
		ans+=gd;
	}
    else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}
 
// Driver Code
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

    string str = "ABCDEFGHIJKL";
    int n = str.size();
    permute(str, 0, n - 1);
	cout << ans << endl;
}