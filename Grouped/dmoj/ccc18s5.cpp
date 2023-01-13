#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=1e5+1;
int dsuH[MAXN], dsuV[MAXN];
vector<int> edgesH[MAXN], edgesV[MAXN];
ll psa[MAXN];

int rootH(int a) {
    return dsuH[a]<0 ? a : dsuH[a]=rootH(dsuH[a]);
}

bool unifyH(int a, int b) {
    a=rootH(a), b=rootH(b);
    if (a==b) return 0;
    if (dsuH[a]>dsuH[b]) swap(a,b);
    dsuH[a]+=dsuH[b];
    dsuH[b]=a;
    return 1;
}


int rootV(int a) {
    return dsuV[a]<0 ? a : dsuV[a]=rootV(dsuV[a]);
}

bool unifyV(int a, int b) {
    a=rootV(a), b=rootV(b);
    if (a==b) return 0;
    if (dsuV[a]>dsuV[b]) swap(a,b);
    dsuV[a]+=dsuV[b];
    dsuV[b]=a;
    return 1;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    fill(dsuH, dsuH+MAXN, -1);
    fill(dsuV, dsuV+MAXN, -1);


    ll totCost=0, cost=0;
    int N,M,P,Q; cin>>N>>M>>P>>Q;
    for (int i=0,a,b,c; i<P; i++) {
        cin>>a>>b>>c;
        edgesH[i]={c,a,b};
        totCost+=1LL*N*c;
    }
    sort(edgesH, edgesH+P);
    
    vector<vector<int>> mstH={{0,0,0}}, mstV;
    for (int i=0; i<P; i++) {
        if (unifyH(edgesH[i][1], edgesH[i][2])) {
            mstH.push_back(edgesH[i]);
            cost+=1LL*N*edgesH[i][0];
        }
    }

    sort(mstH.begin()+1, mstH.end(), greater<vector<int>>());

    psa[0]=0;
    for (int i=1; i<SZ(mstH); i++) psa[i]=psa[i-1]+mstH[i][0];

    for (int i=0,a,b,c; i<Q; i++) {
        cin>>a>>b>>c;
        edgesV[i]={c,a,b};
        totCost+=1LL*M*c;
    }
    sort(edgesV, edgesV+Q);
    for (int i=0; i<Q; i++) {
        if (unifyV(edgesV[i][1], edgesV[i][2])) {
            mstV.push_back(edgesV[i]);
        }
    }
    // for (int i=1; i<SZ(mstH); i++)
    //     cout << mstH[i][0] << ' '; cout <<endl;
    
    // use which verticals?
    for (vector<int> vE : mstV) {
        int vC=vE[0], a=vE[1], b=vE[2];

        int L=0, R=SZ(mstH)-1;
        while (L<R) {
            int mid=L+R+1>>1;
            if (mstH[mid][0]<=vC) R=mid-1;
            else L=mid;
        }
        // cout << L << endl;
        cost-=psa[L];
        // cout << cost << endl;
        cost+=(1LL+L)*vC;   
    }

    // cout << totCost << endl;
    cout << totCost-cost << endl;
}