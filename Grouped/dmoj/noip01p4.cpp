#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> sub(vector<int> &a, vector<int> &b) {
	return {a[0]-b[0], a[1]-b[1]};
}
vector<int> add(vector<int> &a, vector<int> &b) {
	return {a[0]+b[0], a[1]+b[1]};
}

double dis(vector<int> &a, vector<int> &b) {
	int x=a[0]-b[0], y=a[1]-b[1];
	return sqrt(x*x + y*y);
}



int s,t,A,B;
vector<vector<vector<int>>> cities;
vector<int> getCity;
vector<vector<int>> P;
vector<vector<pair<double,int>>> G;

double dijkstra(int start) {
	priority_queue<pair<double,int>, vector<pair<double,int>>, 
		greater<pair<double,int>>> pq;
	vector<bool> vis(s*4);
	pq.push({0,start});
	
	while (!pq.empty()) {
		auto top=pq.top(); pq.pop();
		vis[top.second]=1;
		if (getCity[top.second]==B)
			return top.first;
		for (auto child : G[top.second]) {
			if (!vis[child.second])
				pq.push({top.first+child.first, child.second});
		}
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>s>>t>>A>>B; A--, B--;
	cities.assign(s,vector<vector<int>>{});
	vector<int> T(s);
	for (int i=0; i<s; i++) {
		for (int o=0,x,y; o<3; o++)
			cin>>x>>y,
			cities[i].push_back({x,y});
		cin>>T[i];

		// get fourth point
		vector<int> a=cities[i][0], b=cities[i][1], c=cities[i][2];
		double ab=dis(a,b), ac=dis(a,c), bc=dis(b,c);
		if (ab>ac) swap(b,c), swap(ab, ac);
		
		vector<int> d, dif=sub(b,a);
		if (max({ab,ac,bc})==bc) d=add(c,dif);
		else d=sub(c,dif);

		cities[i].push_back(d);
	}
	
	// points id
	getCity.assign(s*4,0);
	P.assign(s*4,{});
	for (int i=0; i<s; i++)
		for (int p=0; p<4; p++)
			P.push_back(cities[i][p]),
			getCity[i*4+p]=i;

	
	G.assign(s*4,{}); // G[a][i]: connection to i.first with i.second dis
	int id1, id2;

	// internal
	for (int i=0; i<s; i++)
		for (int a=0; a<3; a++)
			for (int b=a+1; b<4; b++)
				id1=i*4+a, id2=i*4+b,
				G[id1].push_back({dis(cities[i][a],cities[i][b])*T[i], id2}),
				G[id2].push_back({dis(cities[i][a],cities[i][b])*T[i], id1});
	
	// external
	for (int a=0; a<s-1; a++)
		for (int p1=0; p1<4; p1++)
			for (int b=a+1; b<s; b++)
				for (int p2=0; p2<4; p2++)
					id1=a*4+p1, id2=b*4+p2,
					G[id1].push_back({dis(cities[a][p1], cities[b][p2])*t, id2}),
					G[id2].push_back({dis(cities[a][p1], cities[b][p2])*t, id1});

	// dijkstra
	double ans=DBL_MAX;
	for (int i=0; i<s*4; i++)
		if (getCity[i]==A)
			ans=min(ans, dijkstra(i));
	cout << fixed << setprecision(2) << ans << endl;
}