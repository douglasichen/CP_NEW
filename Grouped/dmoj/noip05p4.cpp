#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


string trim(string S) {
	string temp="";
	for (char c : S) if (c!=' ') temp+=c;
	return temp;
}

string addPlus(string A) {
	if (A[0]!='-') A.insert(A.begin(), '+');
	return A;
}

pair<int,int> calc(string A) {
	string num="";
	int aCnt=0, sm=0, base=1, sign=1;
	vector<int> brackVals;
	for (int i=0; i<A.size(); i++) {
		if (A[i]=='(') {
			base*=sign;
			brackVals.push_back(sign);
			sign=1;
		}
		else if (A[i]==')') {
			base*=brackVals.back();
			brackVals.pop_back();
		}
		else if (A[i]=='+') sign=1;
		else if (A[i]=='-') sign=-1;
		else if (A[i]=='a') aCnt+=(base*sign);
		else if (isdigit(A[i])) {
			num+=A[i];
			if (i==A.size()-1 || !isdigit(A[i+1])) {
				sm+=base*sign*stoi(num);
				num="";
			}
		}
	}
	return {aCnt, sm};
}

bool same(string A, string B) {
	A=trim(A), B=trim(B);
	return calc(A)==calc(B);
}	

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string F,ans=""; getline(cin,F);
	int T; cin>>T; cin.ignore();
	for (char ch='A'; ch<'A'+T; ch++) {
		string S; getline(cin,S);
		if (same(F,S)) ans+=ch;
	}
	cout << ans << endl;
}