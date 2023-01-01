#include <bits/stdc++.h>
using namespace std;

string A,B;

bool solve() {
    if (A.size()<B.size()) return 0;
    for (int i=0; i<B.size(); i++) {
        int a=0, b=0;
        while (a<A.size() && b<B.size()) {
            while (b>0 && A[a]!=B[b]) b--;
            if (A[a]==B[b]) a++, b++;
            else a++;
        }
        if (b==B.size()) return 1;
        for (int o=0; o<=B.size(); o++) swap(B[o], B[(o+1)%B.size()]);
    }
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    cin>>A>>B;
    cout << (solve() ? "yes" : "no") << "\n";
}