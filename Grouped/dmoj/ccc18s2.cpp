#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    int N,mn=INT_MAX; cin>>N;
    vector<vector<int>> V(N, vector<int>(N)), tmp;
    for (int y=0; y<N; y++)
        for (int x=0; x<N; x++)
            cin>>V[y][x], mn=min(mn, V[y][x]);
    for (int r=0; r<4; r++) {
        if (V[0][0]==mn) {
            for (int y=0; y<N; y++) 
                for (int x=0; x<N; x++)
                    cout << V[y][x] << (x<N-1 ? ' ' : '\n');
            return 0;
        }
        tmp=V;
        for (int x=0; x<N; x++)
            for (int y=0; y<N; y++)
                V[x][y]=tmp[N-y-1][x];
    }
}