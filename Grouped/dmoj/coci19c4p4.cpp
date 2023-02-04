#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int E=31, MAXN=2e5+1;
int path[MAXN];
map<vector<bool>,vector<int>> pre;
vector<vector<int>> tree[MAXN], G[MAXN];
bitset<200001> hit, vis;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(path,0);

	int Q,sz=1; cin>>Q;
	if (Q<=2000) {
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
	else {
		for (int q=0; q<Q; q++) {
			string s; int a,b; cin>>s>>a>>b;
			if (s=="Add") {
				path[++sz]=path[a]^b;

				bitset<E> bs=path[sz];
				string s1=bs.to_string();
				vector<bool> s2;
				reverse(s1.begin(), s1.end());
				for (int e=0; e<E; e++) {
					s2.push_back(s1[e]-'0');
					pre[s2].push_back(sz);
				}
			}
			else {
				bitset<E> A=path[a]; // b=1
				A.flip();
				string s1=A.to_string();
				vector<bool> s2;
				reverse(s1.begin(), s1.end());
				int c=1;

				for (int e=0; e<E; e++) {
					s2.push_back(s1[e]-'0');
					if (pre.find(s2)==pre.end()) s2.back()=(s2.back() ? 0 : 1);
					if (pre.find(s2)!=pre.end()) c=pre[s2][0];
					else break;
				}
				int ans=path[a]^path[c];
				cout << ans << endl;
			}
		}	
	}
}