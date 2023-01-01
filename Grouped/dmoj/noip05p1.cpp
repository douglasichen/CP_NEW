#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	pair<string,ll> best;
	ll tot=0;
	for (int i=0; i<N; i++) {
		string name; int g1,g2; char lead, west; int paper;
		cin>>name>>g1>>g2>>lead>>west>>paper;
		
		int scr=0;
		if (g1>80 && paper>=1) scr+=8000;
		if (g1>85 && g2>80) scr+=4000;
		if (g1>90) scr+=2000;
		if (west=='Y' && g1>85) scr+=1000;
		if (lead=='Y' && g2>80) scr+=850;
		if (scr>best.second) best={name,scr};
		tot+=scr;
	}
	cout << best.first << endl << best.second << endl << tot << endl;
	
}
