#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int TSZ=1<<10;
int tree[TSZ*2][TSZ*2];

int merge(int a, int b) {
	return a+b;
}

void printTree() {
	for (int y=0; y<TSZ*2; y++) {
		for (int x=0; x<TSZ*2; x++) {
			cout << tree[y][x] << ' ';
		}
		cout << endl;
	}
}

int uptY(int nodeX, int nodeY, int segL, int segR, int y, int val) {
	if (y<segL || y>=segR) return tree[nodeY][nodeX];
	if (y==segL && y==segR-1) return tree[nodeY][nodeX];
	int mid=segL+segR>>1;
	return tree[nodeY][nodeX]=merge(uptY(nodeX, nodeY*2, segL, mid, y, val),
									uptY(nodeX, nodeY*2+1, mid, segR, y, val));
}

int uptX(int node, int segL, int segR, int y, int x, int val) {
	if (x<segL || x>=segR) return tree[TSZ+y][node];
	if (x==segL && x==segR-1) tree[TSZ+y][node]=val;
	else {
		int mid=segL+segR>>1;
		tree[TSZ+y][node]=merge(uptX(node*2, segL, mid, y, x, val), uptX(node*2+1, mid, segR, y, x, val));
	}
	uptY(node, 1, 0, TSZ, y, val);

	return tree[TSZ+y][node];
}

int queryY(int nodeX, int nodeY, int segL, int segR, int y1, int y2) {
	if (y2<=segL || y1>=segR) return 0;
	if (y1<=segL && segR<=y2) return tree[nodeY][nodeX];
	int mid=segL+segR>>1;
	return merge(queryY(nodeX, nodeY*2, segL, mid, y1, y2), queryY(nodeX, nodeY*2+1, mid, segR, y1, y2));
}

int queryX(int node, int segL, int segR, int y1, int y2, int x1, int x2) {
	if (x2<=segL || x1>=segR) return 0;
	if (x1<=segL && segR<=x2) return queryY(node, 1, 0, TSZ, y1, y2);
	int mid=segL+segR>>1;
	return merge(queryX(node*2, segL, mid, y1, y2, x1, x2), queryX(node*2+1, mid, segR, y1, y2, x1, x2));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(tree, 0, sizeof(tree));
	
	int N,Q; cin>>N>>Q;
	char c;
	for (int y=0; y<N; y++)
		for (int x=0; x<N; x++)
			cin>>c, tree[TSZ+y][TSZ+x]=(c=='*');
	
	// construct 1D seg trees
	for (int y=TSZ; y<TSZ*2; y++)
		for (int x=TSZ-1; x; x--)
			tree[y][x]=merge(tree[y][x<<1], tree[y][x<<1|1]);
	
	// construct 2D seg tree
	for (int y=TSZ-1; y; y--)
		for (int x=0; x<TSZ*2; x++)
			tree[y][x]=merge(tree[y<<1][x], tree[y<<1|1][x]);
	
	// printTree();

	while (Q--) {
		int m, y1, x1; cin>>m>>y1>>x1; y1--, x1--;
		if (m==1) {
			uptX(1, 0, TSZ, y1, x1, tree[TSZ+y1][TSZ+x1]^1);
			// printTree(); cout << endl;
		}
		else {
			int y2, x2; cin>>y2>>x2;
			cout << queryX(1, 0, TSZ, y1, y2, x1, x2) << endl;
		}
	}
}

/*
4 9
..**
.***
*.*.
.***
1 4 4
2 4 4 4 4
1 1 3
2 2 4 2 4
1 1 4
2 4 1 4 1
1 2 3
2 3 3 4 3
2 1 1 3 4
*/