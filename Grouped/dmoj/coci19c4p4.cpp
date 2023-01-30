#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXQ=2e5+1, E=31;
int qs[MAXQ][3], path[MAXQ], sz[MAXQ], node2flat[MAXQ], ans[MAXQ], nodeAdded[MAXQ];
vector<int> tree[MAXQ];
map<int,set<int>> mp;

int genSize(int node) {
	int cnt=1;
	for (int child : tree[node]) {
		cnt+=genSize(child);
	}
	return sz[node]=cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(qs,0);
	ms(path,0);
	ms(sz,0);
	ms(node2flat,0);
	ms(ans,0);
	ms(nodeAdded,0);

	int Q; cin>>Q;
	for (int q=0; q<Q; q++) {
		string s; cin>>s;
		qs[q][0]=(s=="Query");
		cin>>qs[q][1]>>qs[q][2];
	}

	// generate tree
	int tsz=1;
	for (int q=0; q<Q; q++) {
		if (!qs[q][0]) {
			int x=qs[q][1], y=qs[q][2];
			tree[x].push_back(++tsz);
			path[tsz]=path[x]^y;
			nodeAdded[q]=tsz;
		}
	}

	// flatten tree
	vector<int> flat;
	stack<int> st; st.push(1);
	while (SZ(st)) {
		int node=st.top(); st.pop();
		flat.push_back(node);
		for (int child : tree[node]) {
			st.push(child);
		}
	}

	genSize(1);

	for (int i=0; i<SZ(flat); i++) {
		// insert all prefixes
		for (int e=E; e>=0; e--) {
			mp[path[flat[i]]>>e].insert(i);
		}
		node2flat[flat[i]]=i;
	}

	for (int q=Q-1; q>=0; q--) {
		if (qs[q][0]) {
			// query
			int a=qs[q][1], b=qs[q][2], c=b;

			int shift=0;
			for (int e=E; e>=0; e--) {
				// shift e;
				shift<<=1;
				shift+=((path[a]>>e)&1)^1;

				// now I have the flip I am looking for
				// check if this shift has a flattened location between L and R
				int L=node2flat[b], R=L+sz[b];
				auto it=mp[shift].lower_bound(L);
				if (it!=mp[shift].end() && *it<R) {
					c=flat[*it];
				}
				else break;
			}
			
			ans[q]=path[a]^path[c];
		}
		else {
			// delete node
			int node=nodeAdded[q];
			for (int e=E; e>=0; e--) {
				mp[path[node]>>e].erase(node2flat[node]);
			}
		}
	}

	for (int q=0; q<Q; q++) {
		if (qs[q][0]) cout << ans[q] << endl;
	}
}