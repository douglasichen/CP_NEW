#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=1e5;
string same[MAXN][2], diff[MAXN][2];
map<string,map<string,bool>>  in;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int X; cin>>X;
    for (int i=0; i<X; i++) {
        cin>>same[i][0]>>same[i][1];
    }
    int Y; cin>>Y;
    for (int i=0; i<Y; i++) {
        cin>>diff[i][0]>>diff[i][1];
    }
    int G; cin>>G;
    for (int i=0; i<G; i++) {
        vector<string> v(3);
        for (int o=0; o<3; o++) cin>>v[o];
        for (int a=0; a<3; a++) {
            for (int b=0; b<3; b++) {
                if (a!=b) {
                    in[v[a]][v[b]]=1;
                }
            }
        }
    }
    int ans=0;
    for (int i=0; i<X; i++) {
        
    }
}