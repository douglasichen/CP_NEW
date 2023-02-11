#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int Q=30;
    cout << Q << endl;
    int sz=1, X=20;
    for (int i=0; i<Q; i++) {
        string a=(rand()%2 ? "Add" : "Query");
        int b=rand()%sz+1, c=(a=="Add" ? X%rand() : rand()%sz+1);
        cout << a << ' ' << b << ' ' << c << endl;
        if (a=="Add") sz++;
    }   
}