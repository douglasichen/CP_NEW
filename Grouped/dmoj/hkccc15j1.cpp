#include<bits/stdc++.h>
using namespace std;
int main() {
	int N; cin>>N;
	vector<string> A(N), B(N);
	for (int i=0; i<N; i++) cin>>A[i];
	for (int i=0; i<N; i++) cin>>B[i];
	int a=0, b=0;
	for (int i=0; i<N; i++) {
		if (A[i]=="rock") {
			if (B[i]=="paper") b++;
			else if (B[i]=="scissors") a++;
		}
		else if (A[i]=="paper") {
			if (B[i]=="scissors") b++;
			else if (B[i]=="rock") a++;
		}
		else {
			if (B[i]=="rock") b++;
			else if (B[i]=="paper") a++;
		}
	}
	cout << a << ' ' << b << endl;
}