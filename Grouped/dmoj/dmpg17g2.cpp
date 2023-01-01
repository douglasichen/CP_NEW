#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

struct Node {
	long long mxPs, mxSs, sm, mxSub;

	public:
	Node(long long e) {
		mxPs=mxSs=sm=mxSub=e;
	}
	public:
	Node(){}
	
	string str() {
		return to_string(mxPs) + " " + to_string(mxSs) + " " + to_string(sm) + " " + to_string(mxSub);
	}
};

vector<Node> T;

Node merge(Node A, Node B) {
	Node node=Node();
	node.mxPs=max(A.mxPs, A.sm+B.mxPs);
	node.mxSs=max(B.mxSs, B.sm+A.mxSs);
	node.sm=A.sm+B.sm;
	node.mxSub=max({A.mxSub, B.mxSub, A.mxSs+B.mxPs});
	return node;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	T.assign(N<<1, Node());
	long long e;
	for (int i=0; i<N; i++) cin>>e, T[i+N]=Node(e);
	for (int i=N-1; i>0; i--) T[i]=merge(T[i<<1], T[i<<1|1]);//, cout << "merging: " << (i<<1) << " and " << (i<<1|1) << " -> " << i << endl;
	for (int i=0; i<Q; i++) {
		char c; long long a, b; cin>>c>>a>>b;
		if (c=='S') {
			a+=N-1;
			T[a]=Node(b);
			for (a>>=1; a; a>>=1) T[a]=merge(T[a<<1], T[a<<1|1]);
		}
		else {
			if (a==b) {
				cout << T[a+N-1].mxSub << endl;
				continue;
			}
			// for (int i=1; i<2*N; i++) cout << T[i].mxSub << ' '; cout << endl;
			deque<int> A, B;
			for (a+=N-1, b+=N; a<b; a>>=1, b>>=1) {
				if (a&1) A.push_back(a), a++;
				if (b&1) b--, B.push_front(b);
			}
			vector<int> V;
			for (int i : A) V.push_back(i);
			for (int i : B) V.push_back(i);
			Node res=T[V[0]];
			for (int i=1; i<V.size(); i++) res=merge(res, T[V[i]]);
			cout << res.mxSub << endl;
		}
	}
}