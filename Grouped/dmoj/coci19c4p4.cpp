#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=200001;
vector<vector<int>> tree[MAXN], G[MAXN];
bitset<200001> hit, vis;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q; cin>>Q;
	int sz=1;
	for (int q=0; q<Q; q++) {
		string s; int x,y; cin>>s>>x>>y;
		if (s=="Add") {
			sz++;
			G[x].push_back({sz,y});
			G[sz].push_back({x,y});

			tree[x].push_back({sz,y});
		}
		else {
			// hit subtree y. 
			queue<int> qu; qu.push(y);
			while (SZ(qu)) {
				int node=qu.front(); qu.pop();
				hit[node]=1;
				for (vector<int> child : tree[node]) qu.push(child[0]);
			}

			// go from A to longest one in b
			int ans=0;
			queue<vector<int>> ku; ku.push({x,0}); // node, xor;
			vis[x]=1;
			while (SZ(ku)) {
				vector<int> node=ku.front(); ku.pop();
				if (hit[node[0]]) ans=max(ans,node[1]);
				for (vector<int> child : G[node[0]]) {
					if (!vis[child[0]]) {
						vis[child[0]]=1;
						ku.push({child[0], node[1]^child[1]});
					}
				}
 			}

			cout << ans << endl;

			vis=0;
			hit=0;
		}	
	}
}