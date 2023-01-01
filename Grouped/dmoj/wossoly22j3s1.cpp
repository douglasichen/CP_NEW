#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	char c;
	vector<vector<char>> V(6, vector<char>(6));
	char ex=0;
	vector<bool> has('z'+1);
	for (int y=1; y<=5; y++)
		for (int x=1; x<=5; x++)
			cin>>c, V[y][x]=c, has[c]=1;
	
	for (char i='a'; i<='z'; i++) if (!has[i]) ex=i;

	while (N--) {
		string S,ans=""; cin>>S;
		for (int i=0; i<S.size(); i+=2) {
			if (S[i]==ex) {
				ans+=ex;
				i--;
			}
			else {
				ans+=V[S[i]-'A'+1][S[i+1]-'0'];
			}
		}
		cout << ans << endl;
	}
}
