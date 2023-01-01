#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int A,B; cin>>A>>B;
    int N=B-A;
    int sz=int(sqrt(N))+10;
    vector<vector<int>> V(sz, vector<int>(sz));    
    vector<int> pos={sz/2, sz/2};
    vector<vector<int>> dirs={{1,0}, {0,1}, {-1,0}, {0,-1}};
    int at=0, rep=0;

    V[pos[0]][pos[1]]=A;
    A++;
    while (N) {
        if (at%2==0) rep++;
        int r=rep;
        
        while (r && N) {
            pos={pos[0]+dirs[at][0], pos[1]+dirs[at][1]};
            V[pos[0]][pos[1]]=A;
            r--;
            N--;
            A++;
        }
        at=(at+1)%4;
    }
    for (int y=1; y<sz-1; y++) {
        for (int x=1; x<sz-1; x++) {
            // cout << V[y][x] << ' ';
            if (V[y][x]) cout << V[y][x] << ' ';
            if (V[y][x]==0 && V[y][x-1]) cout << endl;
        }
        // cout << endl;
    }
    
}
