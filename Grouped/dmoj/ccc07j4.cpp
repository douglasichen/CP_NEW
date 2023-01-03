#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string A,B; getline(cin,A), getline(cin,B);
	map<char,int> X,Y;
	for (char c : A) if (c!=' ') X[c]++;
	for (char c : B) if (c!=' ') Y[c]++;
	cout << (X==Y ? "Is an anagram." : "Is not an anagram.") << endl;
}