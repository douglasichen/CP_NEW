#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int N; cin>>N;
	unordered_map<int,int> woodsCount;
	vector<int> woods;
	for (int i=0; i<N; i++) {
		int w; cin>>w;
		if (woodsCount[w]==0) woods.push_back(w);
		woodsCount[w]++;
	}
	
	vector<int> heights(4001);
	for (int i=0; i<woods.size(); i++) {
		for (int o=i; o<woods.size(); o++) {
			// cout << i << " " << o << endl;
			if (i==o) {
				int w=woods[i];
				if (woodsCount[w]>=2) {
					int h=w*2;
					int amount=woodsCount[w]/2;
					heights[h]+=amount;
					
				}
			}
			else {
				int w1=woods[i], w2=woods[o];
				int h=w1+w2;
				int amount=min(woodsCount[w1],woodsCount[w2]);
				heights[h]+=amount;
			}
		}
	}

	int length=0, dif=0;
	for (int h : heights) length=max(length,h);
	for (int h : heights) dif+=(h==length);
	cout << length << " " << dif << endl;
}