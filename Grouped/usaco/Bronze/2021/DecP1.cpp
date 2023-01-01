#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> A={0},B={0};
	char c;
	for (int i=1; i<=N; i++) {
		cin>>c;
		if (c=='G') A.push_back(i);
		else B.push_back(i);
	}
	A.push_back(N+1), B.push_back(N+1);

	long long a=0;
	for (int i=1; i<A.size()-1; i++) {
		int left=A[i]-A[i-1]-1, right=A[i+1]-A[i]-1;
		a+=1LL*left*right;
		a+=max(left-1,0);
		a+=max(right-1,0);
	}
	for (int i=1; i<B.size()-1; i++) {
		int left=B[i]-B[i-1]-1, right=B[i+1]-B[i]-1;
		a+=1LL*left*right;
		a+=max(left-1,0);
		a+=max(right-1,0);
	}
	cout << a << endl;
}