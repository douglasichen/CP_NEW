#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin>>N;
    vector<vector<int>> A(N, vector<int>(3));
    for (int i=0; i<N; i++) cin>>A[i][0]>>A[i][1]>>A[i][2];
    int M; cin>>M;
    vector<vector<int>> B(M, vector<int>(3));
    for (int i=0; i<M; i++) cin>>B[i][0]>>B[i][1]>>B[i][2];
    for (vector<int> &v : A) sort(v.begin(), v.end());
    for (vector<int> &v : B) sort(v.begin(), v.end());
    auto srt=[](vector<int> a, vector<int> b) {
        return a[0]*a[1]*a[2]<b[0]*b[1]*b[2];
    };
    sort(A.begin(), A.end(), srt);
    // sort(B.begin(), B.end(), srt);
    for (int j=0; j<M; j++) {
        int box=-1;
        for (int i=0; i<N; i++) {
            vector<int> a=A[i], b=B[j];
            // int areaA=a[0]*a[1]*a[2], areaB=b[0]*b[1]*b[2];
            if (b[0]<=a[0] && b[1]<=a[1] && b[2]<=a[2]) {
                box=i;
                break;
            }
        }
        if (box==-1) cout << "Item does not fit." << endl;
        else cout << A[box][0]*A[box][1]*A[box][2] << endl;
    }
}
