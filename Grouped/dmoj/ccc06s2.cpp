#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);


    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    int N=a.size();
    map<char,char> M;
    for (int i=0; i<N; i++) M[b[i]]=a[i];
    for (int i=0; i<c.size(); i++) cout << (M[c[i]] ? M[c[i]] : '.');
    cout << endl;
}
