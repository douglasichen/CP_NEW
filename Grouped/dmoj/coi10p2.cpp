#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	// 86400 seconds in one day
	const int TM=86400;
	vector<long long> D(TM*2+1);
	int N; cin>>N;
	cin.ignore();
	for (int i=0; i<N; i++) {
		string s; getline(cin,s);
		int h1=stoi(s.substr(0,2)), m1=stoi(s.substr(3,2)), s1=stoi(s.substr(6,2));
		int h2=stoi(s.substr(11,2)), m2=stoi(s.substr(14,2)), s2=stoi(s.substr(17,2));
		int a=h1*60*60+m1*60+s1, b=h2*60*60+m2*60+s2;
		if (b<a) b+=TM;
		D[a]++;
		D[b+1]--;
	}
	for (int i=1; i<TM*2; i++) D[i]+=D[i-1];
	for (int i=0; i<TM; i++) D[i]+=D[i+TM];
	for (int i=1; i<TM; i++) D[i]+=D[i-1];

	int Q; cin>>Q;
	cin.ignore();
	for (int i=0; i<Q; i++) {
		string s; getline(cin,s);
		int h1=stoi(s.substr(0,2)), m1=stoi(s.substr(3,2)), s1=stoi(s.substr(6,2));
		int h2=stoi(s.substr(11,2)), m2=stoi(s.substr(14,2)), s2=stoi(s.substr(17,2));
		int a=h1*60*60+m1*60+s1, b=h2*60*60+m2*60+s2;
		double ans=0;
		if (a<=b) {
			double sm=D[b]-(a ? D[a-1] : 0), sz=b-a+1;
			ans=sm/sz;
		}
		else {
			double sm=D[b]+D[TM-1]-D[a-1], sz=(b+1)+(TM-a);
			ans=sm/sz;
		}
		cout << setprecision(10) << ans << endl;
	}
}