#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while (T--) {
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
        

        int firstCol=0, lastCol=sz-1, firstRow=0, lastRow=sz-1;
        for (int x=0; x<sz; x++) {
            bool all0=1;
            for (int y=0; y<sz; y++) if (V[y][x]) all0=0;
            if (!all0) {
                firstCol=x;
                break;
            }
        }
        for (int x=sz-1; x>=0; x--) {
            bool all0=1;
            for (int y=0; y<sz; y++) if (V[y][x]) all0=0;
            if (!all0) {
                lastCol=x;
                break;
            }
        }
        for (int y=0; y<sz; y++) {
            bool all0=1;
            for (int x=0; x<sz; x++) if (V[y][x]) all0=0;
            if (!all0) {
                firstRow=y;
                break;
            }
        }
        for (int y=sz-1; y>=0; y--) {
            bool all0=1;
            for (int x=0; x<sz; x++) if (V[y][x]) all0=0;
            if (!all0) {
                lastRow=y;
                break;
            }
        }
        A=lastRow-firstRow+1, B=lastCol-firstCol+1;
        vector<int> colLen(B);
        vector<vector<string>> K(A, vector<string>(B));
        for (int y=firstRow; y<=lastRow; y++)
            for (int x=firstCol; x<=lastCol; x++) {
                int Y=y-firstRow, X=x-firstCol;
                K[Y][X]=to_string(V[y][x]);
                colLen[X]=max(colLen[X], int(K[Y][X].size()));
                if (K[Y][X]=="0") K[Y][X][0]=' ';
            }
        for (int y=0; y<A; y++)
            for (int x=0; x<B; x++)
                while (K[y][x].size()<colLen[x])
                    K[y][x]=' '+K[y][x];

        for (int y=0; y<A; y++)
            for (int x=0; x<B; x++)
                cout << K[y][x] << (x<B-1 ? ' ' : '\n');
        if (T) cout << endl;
        // for (int y=0; y<sz; y++)
        //     for (int x=0; x<sz; x++)
        //         cout << V[y][x] << (x==sz-1 ? '\n' : ' ');
    }
}