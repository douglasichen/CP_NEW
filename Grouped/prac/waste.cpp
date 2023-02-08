// start from end???
// recursive function
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M; cin>>M>>N;
	vector<vector<int>> go(1000001);
    vector<vector<int>> room(M+2, vector<int>(N+2, 0));
    for (int r = 1; r <= M; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> room[r][c];
			go[room[r][c]].push_back(r*c);
        }
    }
    vector<bool> vis(1000001,false);
    queue<int> backlog; backlog.push(M*N);

	vis[M*N]=1;
	while (backlog.empty()==false){
		int cell = backlog.front(); backlog.pop();
		if (cell==1) {
			cout<<"yes\n";
			return 0;
		}
		for (int i : go[cell])
			if (!vis[i])
				backlog.push(i),
				vis[i]=1;
	}
	cout<<"no\n";
}