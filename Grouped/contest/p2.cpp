#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=1001;
int ar[MAXN][MAXN], row[MAXN][MAXN], col[MAXN][MAXN];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ms(ar,0);
    ms(row,0);
    ms(col,0);

    int N,M; cin>>N>>M;
    for (int y=1; y<=N; y++) {
        for (int x=1; x<=M; x++) {
            int a; cin>>a;
            ar[y][x]=a;
            if (a) {
                row[y][x]++;
                col[y][x]++;
            }
        }
    }
    for (int y=1; y<=N; y++) {
        for (int x=1; x<=M; x++) {
            row[y][x]+=row[y][x-1];
            col[y][x]+=col[y-1][x];
        }
    }
    // for (int y=1; y<=N; y++) {
    //     for (int x=1; x<=M; x++) {
    //         cout << row[y][x] << ' ';

    //     }
    //     cout << endl;
    // }

    int ans=0;
    for (int y=1; y<=N; y++) {
        for (int x=1; x<=M; x++) {
            if (!ar[y][x]) {
                // cout << y << ' ' << x << ": ";
                if (row[y][M]-row[y][x]) ans++;//, cout << "right" << ' ', cout << row[y][M] << '\n';
                if (row[y][x-1]-row[y][0]) ans++;//, cout << "left" << ' ';
                if (col[N][x]-col[y][x]) ans++;//, cout << "down" << ' ';
                if (col[y-1][x]-col[0][x]) ans++;//, cout << "up" << ' ';
                // cout << endl;
            }
        }
    }
    cout << ans << endl;
}