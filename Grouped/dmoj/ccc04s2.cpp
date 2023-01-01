#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N,K; cin>>N>>K;
    vector<vector<int>> V(K,vector<int>(N));
    for (int k=0; k<K; k++) {
        for (int i=0; i<N; i++) {
            cin>>V[k][i];
        }
    }
    vector<int> scr(N), ord(N);
    auto srt=[&](int a, int b) {
        return scr[a]>scr[b];
    };
    iota(ord.begin(), ord.end(),0);
    vector<int> wRank(N,1);

    for (int k=0; k<K; k++) {
        for (int i=0; i<N; i++) {
            scr[i]+=V[k][i];
        }
        
        sort(ord.begin(), ord.end(), srt);
        int rank=1;
        for (int i=1; i<N; i++) {
            if (scr[ord[i]]!=scr[ord[i-1]]) rank++;
            wRank[ord[i]]=max(wRank[ord[i]], rank);
        }
    }

    vector<int> ans;
    for (int i=0; i<N && scr[ord[i]]==scr[ord[max(0,i-1)]]; i++) {
        ans.push_back(ord[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i : ans) {
        cout << "Yodeller " <<  i+1 << " is the TopYodeller: score " << scr[i] << 
        ", worst rank " << wRank[i] << endl;
    }
    // cout << ord[0]+1 << ' ' << wRank[ord[0]] << endl;
}
