#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

string grid[10][9];
bool vis[10][9];

string solve(int Y, int X) {
	vis[Y][X]=1;
	int res=0;
	if (!isalpha(grid[Y][X][0])) {
		return grid[Y][X];
	}
	for (int i=0; i<SZ(grid[Y][X]); i+=3) {
		int y=grid[Y][X][i]-'A', x=grid[Y][X][i+1]-'1';
		if (vis[y][x] && isalpha(grid[y][x][0])) return grid[Y][X]="*";

		string nxt=solve(y,x);
		if (nxt=="*") return grid[Y][X]="*";
		res+=stoi(nxt);
	}
	return grid[Y][X]=to_string(res);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(vis,0);
	for (int y=0; y<10; y++)
		for (int x=0; x<9; x++)	
			cin>>grid[y][x];
	for (int y=0; y<10; y++)
		for (int x=0; x<9; x++)
			if (!vis[y][x])
				solve(y,x);
	for (int y=0; y<10; y++)
		for (int x=0; x<9; x++)
			cout << grid[y][x] << (x<8 ? ' ' : '\n');
}