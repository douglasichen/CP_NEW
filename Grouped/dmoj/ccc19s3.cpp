#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int UC=0;
vector<vector<bool>> U(3,vector<bool>(3));
vector<vector<int>> V(3,vector<int>(3));

void P() {
	int cnt=1;
	while (cnt) {
		cnt=0;
		for (int y=0; y<3; y++) {
			int u=0, i=0;
			for (int x=0; x<3; x++) u+=U[y][x], i=(U[y][x] ? x : i);
			vector<int> v=V[y];
			if (u==1) v[i]=(i==0 ? v[1]-v[2]+v[1] : (i==1 ? (v[0]+v[2])/2 : v[1]-v[0]+v[1])), cnt++, U[y][i]=0, UC--;
			V[y]=v;
		}
		for (int x=0; x<3; x++) {
			vector<int> v(3);
			int u=0, i=0;
			for (int y=0; y<3; y++) v[y]=V[y][x], u+=U[y][x], i=(U[y][x] ? y : i);
			if (u==1) v[i]=(i==0 ? v[1]-v[2]+v[1] : (i==1 ? (v[0]+v[2])/2 : v[1]-v[0]+v[1])), cnt++, U[i][x]=0, UC--;
			for (int y=0; y<3; y++) V[y][x]=v[y];
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	for (int y=0; y<3; y++) for (int x=0; x<3; x++) cin>>s, U[y][x]=(s=="X" ? 1 : 0), V[y][x]=(s=="X" ? 0 : stoi(s));
	for (int y=0; y<3; y++) for (int x=0; x<3; x++) UC+=U[y][x];
	if (UC==8) {
		int val=0;
		for (int y=0; y<3; y++) for (int x=0; x<3; x++) if (!U[y][x]) val=V[y][x];
		for (int y=0; y<3; y++) for (int x=0; x<3; x++) V[y][x]=val, U[y][x]=0;
		UC=0;
	}
	else if (UC==9) {
		for (int y=0; y<3; y++) for (int x=0; x<3; x++) U[y][x]=0;
		UC=0;
	}

	P();
	// if cross is empty then: 
	int val=0, h=0;
	bool uCross=1;
	for (int y=0; y<3; y++) if (!U[y][1]) uCross=0;
	for (int x=0; x<3; x++) if (!U[1][x]) uCross=0;
	if (uCross) {
		for (int x=0; x<3; x++) h+=!U[0][x], val=(!U[0][x] ? V[0][x] : val);
		if (h==1) for (int x=0; x<3; x++) V[0][x]=val, U[0][x]=0, UC-=x<2;
		P();
		val=0, h=0;
		for (int x=0; x<3; x++) h+=!U[2][x], val=(!U[2][x] ? V[2][x] : val);
		if (h==1) for (int x=0; x<3; x++) V[2][x]=val, U[2][x]=0, UC-=x<2;
	}
	P();
	
	int e=1;
	while (e) {
		e=0;
		val=0, h=0;
		for (int x=0; x<3; x++) h+=!U[1][x], val=(!U[1][x] ? V[1][x] : val);
		if (h==1) for (int x=0; x<3; x++) V[1][x]=val, U[1][x]=0, UC-=x<2, e++;
		P();
		val=0, h=0;
		for (int y=0; y<3; y++) h+=!U[y][1], val=(!U[y][1] ? V[y][1] : val);
		if (h==1) for (int y=0; y<3; y++) V[y][1]=val, U[y][1]=0, UC-=y<2, e++;
		P();
	}
	val=0, h=0;
	for (int x=0; x<3; x++) h+=!U[0][x], val=(!U[0][x] ? V[0][x] : val);
	if (h==1) for (int x=0; x<3; x++) V[0][x]=val, U[0][x]=0, UC-=x<2;
	P();
	val=0, h=0;
	for (int x=0; x<3; x++) h+=!U[2][x], val=(!U[2][x] ? V[2][x] : val);
	if (h==1) for (int x=0; x<3; x++) V[2][x]=val, U[2][x]=0, UC-=x<2;

	while (UC) P();
	// for (int y=0; y<3; y++) for (int x=0; x<3; x++) if (U[y][x]) cout << "E";

	for (int y=0; y<3; y++) for (int x=0; x<3; x++) cout << V[y][x] << (x<2 ? ' ' : '\n');
}