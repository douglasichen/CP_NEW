#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N,M; cin>>N>>M;
		vector<vector<int>> G(N+2,vector<int>(M+2)), done=G;
		char c;
		for (int y=1; y<=N; y++)
			for (int x=1; x<=M; x++)
				cin>>c, G[y][x]=(c=='*');
		
		for (int y=1; y<=N-1; y++) {
			for (int x=1; x<=M-1; x++) {
				int dcnt=0, gcnt=0, acnt=0;
				vector<int> corn(2);
				for (int a=y; a<y+2; a++) 
					for (int b=x; b<x+2; b++) 
						dcnt+=done[a][b], gcnt+=G[a][b], corn=(G[a][b] ? corn : vector<int>{a,b});
				
				if (corn[0]) corn={corn[0]+(corn[0]==y ? -1 : 1), corn[1]+=(corn[1]==x ? -1 : 1)};
				for (int a=y-1; a<y+3; a++) 
					for (int b=x-1; b<x+3; b++) 
						acnt+=G[a][b];
				acnt-=G[corn[0]][corn[1]];

				if (!dcnt && acnt==3 && gcnt==3) 
					for (int a=y; a<y+2; a++) 
						for (int b=x; b<x+2; b++) 
							done[a][b]=1;
			}
		}

		bool gd=1;
		for (int y=1; y<=N; y++) 
			for (int x=1; x<=M; x++) 
				if (!done[y][x] && G[y][x]) 
					gd=0;
		cout << (gd ? "YES" : "NO") << endl;
	}
}