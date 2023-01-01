#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int MAX_N=100, MAX_VAL=25000;
int T, N, A[MAX_N+1];
bitset<MAX_VAL+1> dp;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

	cin>>T;
	while (T--) {
		dp=0;

		cin>>N;
		dp[0]=1;
		for (int i=1; i<=N; i++) cin>>A[i];
		sort(A+1, A+N+1);
		int mx=*max_element(A+1, A+N+1);
		
		// walk through A. [ans++ and modify dp] if A[i] is addable
		int b=0;
		for (int a=1; a<=N; a++) {
			// can I make A[a] with the already added elements?
			bool can=dp[A[a]];
			if (!can) {
				// Since I can't make A[a], add A[a] to the dp and ans++;
				b++;
				for (int num=1; num<=MAX_VAL; num++) 
					dp[num] = dp[num] | (num-A[a]>=0 ? dp[num-A[a]] : 0);
			}
		}	
		cout << b << endl;
	}
}
