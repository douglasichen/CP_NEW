#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin>>N;
    vector<float> V(101);
    for (int i=1; i<=N; i++) cin>>V[i];
    int inp; cin>>inp; float a,b,P;
    while (inp!=77) {
        if (inp==99) {
            cin>>a>>b;
            for (int i=100; i>a+1; i--) V[i]=V[i-1];
            P=V[a];
            V[a]=b/100*P, V[a+1]=(1-b/100)*P;
        }
        else if (inp==88) {
            cin>>a;
            V[a]+=V[a+1];
            for (int i=a+1; i<100; i++) V[i]=V[i+1];
            V[100]=0;
        }
        cin>>inp;
    }
    while (V.back()==0) V.pop_back();
    for (int i=1; i<V.size(); i++) cout << V[i] << ' ';
    cout << endl;
}
