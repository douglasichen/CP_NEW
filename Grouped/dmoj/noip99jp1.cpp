#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    // 0 1 2 3
    vector<vector<int>> dirs={{0,1}, {1,-1}, {1,0}, {-1,1}};
    vector<int> pos={0,0};

    int N; cin>>N; N--;
    int at=0;
    while (N) {
        vector<int> dir=dirs[at];
        if (at%2==0) {
            pos={pos[0]+dir[0], pos[1]+dir[1]};
            N--;
        }
        else {
            int it=max(pos[0],pos[1]);
            while (it && N) {
                pos={pos[0]+dir[0], pos[1]+dir[1]};
                it--;
                N--;
            }
        }
        at++;
        at%=4;
    }
    cout << pos[0]+1 << "/" << pos[1]+1 << endl;
}
