#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<string> mDays = {"00","31","28","31","30","31","30","31","31","30","31","30","31"};

	map<string,int> monthDig = {
		{"January", 1},
		{"February", 2},
		{"March", 3},
		{"April", 4},
		{"May", 5},
		{"June", 6},
		{"July", 7},
		{"August", 8},
		{"September", 9},
		{"October", 10},
		{"November", 11},
		{"December", 12},
	};

	vector<string> months={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	int T; cin>>T; cin.ignore();
	while (T--) {
		string S; getline(cin, S);
		int N=S.size();
		string temp="";
		vector<int> done(N+1);
		for (int i=7; i<N; i++) {
			if (i-7) {
				if (!done[i-8])
					temp+=S[i-8];
				done[i-8]=1;
			}
			if (accumulate(done.begin()+(i-7), done.begin()+(i+1), 0)) continue;
			if (isdigit(S[i]) && isdigit(S[i-1]) && 
				isdigit(S[i-3]) && isdigit(S[i-4]) && 
				isdigit(S[i-6]) && isdigit(S[i-7]) &&
				(i-7 ? !isalpha(S[i-8]) && !isdigit(S[i-8]) : 1) &&
				(i+1<N ? !isalpha(S[i+1]) && !isdigit(S[i+1]) : 1) &&
				(S[i-2]=='/' && S[i-5]=='/' || S[i-2]=='.' && S[i-5]=='.')) {
				
				string s=S.substr(i-7, 8);
				string a=s.substr(0,2), b=s.substr(3,2), c=s.substr(6,2);
				string day="0", month="0", year="0";
				if (s[2]=='/')
					day=a,
					month=b,
					year=c;
				else
					year=a,
					month=b,
					day=c;
				if (year<"25") year="20"+year;
				else year="19"+year;

				// cout << (day<=mDays[(stoi(month)>12 ? 0 : stoi(month))]) << endl;
				if ("01"<=day && day<=mDays[(stoi(month)>12 ? 0 : stoi(month))]) {
					if (s[2]=='.') temp+=year+'.'+month+'.'+day;
					else temp+=day+'/'+month+'/'+year;
					for (int o=i-7; o<=i; o++) done[o]=1;
				}
			}
		}
		int at=N;
		while (!done[at]) at--;
		at++;
		for (int i=at; i<N; i++) temp+=S[i];
		// cout << temp << endl;
		// third edit
		swap(temp, S);
		temp="";
		N=S.size();
		for (string month : months) {
			int M=month.size();
			for (int i=0; i<N-M; i++) {
				if (S.substr(i, M)==month && 
				(i ? !isalpha(S[i-1]) && !isdigit(S[i-1]) : 1) &&
				(i+M+8<N ? !isalpha(S[i+M+8]) && !isdigit(S[i+M+8]) : 1)) {
					if (i+M+7<N) {
						string s=S.substr(i+M, 7);
						if (s[0]==' ' && isdigit(s[1]) && isdigit(s[2]) &&
							s[3]==',' && s[4]==' ' && isdigit(s[5]) && isdigit(s[6])) {
								string day=s.substr(1,2), year=s.substr(5,2);
								if (year<"25") year="20"+year;
								else year="19"+year;
								if ("0"<=day && day<=mDays[monthDig[month]])
									S.replace(S.begin()+(i+M+5), S.begin()+(i+M+5+2), year);
							}
					}
				}
			}
		}
		cout << S << endl;
	}	
}