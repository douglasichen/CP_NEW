#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		string S, s; cin>>S; 
		while (S.size() && S[0]=='0') S.erase(S.begin());	
		s=S;
		cout << s << endl;

		while (s.size()>2) {
			int N=s.size();

			// s = s - dig
			if (s[N-1]<=s[N-2]) s[N-2]=s[N-2]-s[N-1]+'0';
			else {
				s[N-2]=s[N-2]+10-s[N-1]+'0';
				for (int i=N-3; i>=0; i--) {
					if (s[i]=='0') s[i]='9';
					else {
						s[i]--;
						break;
					}
				}
			}
			
			
			s.pop_back();

			// print
			while (s.size() && s[0]=='0') s.erase(s.begin());
			
			cout << s << endl;
		}
		if (stoi(s)%11==0) cout << "The number " << S << " is divisible by 11.\n";
		else cout << "The number " << S << " is not divisible by 11.\n";
		cout << (T ? "\n" : "");
	}	
}