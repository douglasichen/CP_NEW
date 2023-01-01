#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int md=998244353;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        int ans=0, twos=0, neg=0;
        vector<int> V(N);
        vector<int> B;
        for (int i=0, e; i<N; i++) {
            cin>>e; V[i]=e;
            if (e!=0) B.push_back(e), twos+=(abs(e)==2), neg+=(e<0);
            if (e==0 || i==N-1) {
                if (neg&1) {
                    int cut2=0;
                    for (int &val : B) {
                        cut2+=(abs(val)==2);
                        if (val<0) break; 
                    }
                    ans=max(ans,twos-cut2);
                    cut2=0;
                    for (int at=B.size()-1; at>=0; at--) {
                        int val=B[at];
                        cut2+=(abs(val)==2);
                        if (val<0) break;
                    }
                    ans=max(ans,twos-cut2);
                }
                else ans=max(ans,twos);
                twos=0;
                neg=0;
                B.clear();
            }
        }
    
        if (ans) {
            int calc=1;
            for (int i=0; i<ans; i++) {
                calc<<=1;
                calc%=md;
            }
            ans=calc;
        }
        else {
            // answer is 1 if there is a positive one or 2 negative ones next to eachtoerh
            // answer is 0 if all is 0
            if (N==1) ans=V[0];
            else {
                for (int i=0; i<N; i++) {
                    if (V[i]==1 || i<N-1 && V[i]==-1 && V[i+1]==-1)
                        ans=1;
                }
            }
        }
		if (ans<0) ans+=md;

        cout << ans << endl;
    }
}
