#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {

	srand(time(NULL));
	
	cout << 8 << " " << rand()%3+2 << "\n";
	for (int i=0; i<8; i++) cout << rand()%8+1 << " "; cout << endl;

}