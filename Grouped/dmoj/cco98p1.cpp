#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    vector<__int128> V(201);
    
    for (int N=1; N;) {
        cin>>N;
        if (!N) break;
        cout << V[N] << '\n';
    }
}