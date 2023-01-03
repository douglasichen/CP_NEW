#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int MAXN=177147;
int ar[MAXN];


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin>>N;
    for (int i=0; i<N; i++) cin>>ar[i];
    
    for (int e=3; e<=N; e*=3) {
        for (int i=0; i<N; i+=e) {
            vector<int> a,b,c;
            for (int at=i; at<i+e/3; at++) a.push_back(ar[at]);
            for (int at=i+e/3; at<i+e/3*2; at++) b.push_back(ar[at]);
            for (int at=i+e/3*2; at<i+e; at++) c.push_back(ar[at]);
            

            int at=i;
            for (int el : c) ar[at++]=el;
            for (int el : a) ar[at++]=el;
            for (int el : b) ar[at++]=el;
        }
    }
    for (int i=0; i<N; i++) cout << ar[i] << ' '; cout << '\n';
}