#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

double a,b,c,d;
double F(double x) {
	return a*x*x*x + b*x*x + c*x + d;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>a>>b>>c>>d;
	vector<vector<double>> spots;
	for (double L=-100, R=-99.5, y1, y2; R<=100; L+=0.6, R+=0.6) {
		y1=F(L), y2=F(R);
		if (min(y1,y2)<=0 && max(y1,y2)>=0)
			spots.push_back({L,R});
	}
	vector<double> ans;
	double L,R,M,Y;
	for (vector<double> &s : spots) {
		L=s[0], R=s[1];
		if (F(L)>F(R)) swap(L,R);
		while (abs(R-L)>0.00001) {
			M=(R+L)/2.0, Y=F(M);
			if (Y<=0) L=M;
			else R=M;
		}
		ans.push_back(L);
	}
	for (int i=0; i<ans.size(); i++) 
		cout << fixed << setprecision(2) << round(ans[i]*100)/100 << (i<ans.size()-1 ? ' ' : '\n');
}