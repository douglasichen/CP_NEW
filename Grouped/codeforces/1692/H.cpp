#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Node {
	long long pre, suff, sum, sub;
	long long subL, subR, preR, suffL;
	public:
	Node(long long e, int i) {
		pre=suff=sum=sub=e;
		subL=subR=preR=suffL=i;
	}
	Node() {}
};

vector<Node> T(4e5);

Node merge(Node A, Node B) {
	Node res;
	
	long long a=A.pre, b=A.sum+B.pre, c;
	res.preR=(a>b ? A.preR : B.preR);
	res.pre=max(a,b);

	a=B.suff, b=B.sum+A.suff;
	res.suffL=(a>b ? B.suffL : A.suffL);
	res.suff=max(a,b);

	res.sum=A.sum+B.sum;

	a=A.sub, b=B.sub, c=A.suff+B.pre;
	long long best=max({a,b,c});
	if (best==a) res.subL=A.subL, res.subR=A.subR;
	else if (best==b) res.subL=B.subL, res.subR=B.subR;
	else res.subL=A.suffL, res.subR=B.preR;
	res.sub=best;

	return res;
}

int N;
void modify(int p, long long val) {
	p+=N;
	T[p]=Node(val, p-N);
	for (p>>=1; p; p>>=1) T[p]=merge(T[p<<1], T[p<<1|1]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int TE; cin>>TE;
	while (TE--) {
		cin>>N;
		
		map<int, vector<int>> M;
		for (int i=0,e; i<N; i++) cin>>e, M[e].push_back(i);
		for (int i=0; i<N; i++) T[i+N]=Node(-1,i);
		for (int i=N-1; i; i--) T[i]=merge(T[i<<1], T[i<<1|1]);
		vector<long long> best(4); best[1]=-1e9;
		for (auto p : M) {
			int val=p.first;
			
			vector<int> v=p.second;
			for (int i : v) modify(i, 1);
			// for (int i=1; i<2*N; i++) cout << T[i].subL << "," << T[i].subR << " "; cout << endl;
			
			deque<int> A, B;
			for (int a=N, b=N<<1; a<b; a>>=1, b>>=1) {
				if (a&1) A.push_back(a), a++;
				if (b&1) b--, B.push_front(b);
			}
			vector<int> O;
			for (int i : A) O.push_back(i);
			for (int i : B) O.push_back(i);
			Node res=T[O[0]];
			for (int i=1; i<O.size(); i++) res=merge(res, T[O[i]]);
			
			vector<long long> ans={val, res.sub, res.subL, res.subR};
			if (ans[1]>best[1]) best=ans;

			// change back
			for (int i : v) modify(i, -1);
		}

		cout << best[0] << ' ' << best[2]+1 << ' ' << best[3]+1 << endl;
	}
}