#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
vector<vector<int>> sud(10, vector<int>(10));

bool block(vector<int> &v) {
	vector<int> pos={(v[0]-1)/3*3+1, ((v[1]-1)/3*3+1)};
	cout << pos[0] << " " << pos[1] << endl; 
	vector<bool> has(10);
	for (int x=pos[0]; x<pos[0]+3; x++) {
		for (int y=pos[1]; y<pos[1]+3; y++) {
			if (!sud[x][y]) continue;
			if (has[sud[x][y]]) return 0;
			has[sud[x][y]]=1;
		}
	}
	return 1;
}

bool cross(vector<int> &v) {
	vector<bool> has(10);
	for (int i=1; i<10; i++) {
		if (!sud[v[0]][i]) continue;
		if (has[sud[v[0]][i]]) return 0;
		has[sud[v[0]][i]]=1;
	}
	has=vector<bool>(10);
	for (int i=1; i<10; i++) {
		if (!sud[i][v[1]]) continue;
		if (has[sud[i][v[1]]]) return 0;
		has[sud[i][v[1]]]=1;
	}
	return 1;
}

bool add(vector<int> &v) {
	sud[v[0]][v[1]]=v[2];
	if (!block(v)) {
		return 0;
	}
	if (!cross(v)) {
		return 0;
	}
	return 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N=81;
	vector<vector<int>> V(N, vector<int>(3));
	for (int i=0; i<N; i++) cin>>V[i][0]>>V[i][1]>>V[i][2];
	for (int i=0; i<N; i++) {
		if (!add(V[i])) {
			cout << i+1 << endl;
			break;
		}
	}
}