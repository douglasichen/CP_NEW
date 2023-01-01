#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin>>N;
    vector<pair<char,string>> V(N);
    for (int i=0; i<N; i++)
        cin>>V[i].first>>V[i].second;
    string S; cin>>S;
    string ans="";
    for (int i=0; i<S.size();) {
        for (pair<char, string> p : V) {
            if (i+p.second.size()<=S.size()) {
                if (S.substr(i,p.second.size())==p.second) {
                    i+=p.second.size();
                    ans+=p.first;
                }
            }
        }
    }    
    cout << ans << endl;
}
