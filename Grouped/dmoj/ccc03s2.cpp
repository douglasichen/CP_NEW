#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

map<char,bool> M={{'A',1},{'E',1},{'I',1},{'O',1},{'U',1},{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};


bool f(string A, string B) {
    string a="",b="";
    for (int i=A.size()-1; A[i]!=' '&& i>=0; i--) {
        a+=tolower(A[i]);
        if (M[A[i]]) break;
    }
    for (int i=B.size()-1; B[i]!=' '&& i>=0; i--) {
        b+=tolower(B[i]);
        if (M[B[i]]) break;
    }
    return a==b;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    cin.ignore();
    while (T--) {
        string a,b,c,d; getline(cin,a); getline(cin,b); getline(cin,c); getline(cin,d);
        if (f(a,b) && f(b,c) && f(c,d)) cout << "perfect" << endl;
        else if (f(a,b) && f(c,d)) cout << "even" << endl;
        else if (f(a,c) && f(b,d)) cout << "cross" << endl;
        else if (f(a,d) && f(b,c)) cout << "shell" << endl;
        else cout << "free" << endl;
    }
}
