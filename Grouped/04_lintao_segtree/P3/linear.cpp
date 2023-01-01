#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

ofstream out, in;
clock_t startTime, endTime;



class DS {
	public:
		int N;
		vector<vector<int>> container;
		DS(int size) {
			N=size;
			container.assign(N,{});
		}

		int del(int l, int r, int x) {
			return 0;
		}

		void insert(int l, int r, int x) {

		}

		
};

void program() {
	// int N, Q; in>>N>>Q;
	// DS ds = new DS(N);

	// while (Q--) {
	// 	if ()
	// }


}





void printTime() {
	double time_taken = double(endTime - startTime) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}

void genIn(int a, int b, int seed) {
	// initialize random generator
	srand(seed);

	int L=a, R=a, N=a, X=a, Q=b, type;
	in << N << endl << Q << endl;
	while (Q--) {
		int type=rand()%2, l=rand()%L, r=rand()%(R-l)+l, x=rand()%X;
		in << type << ' ' << l << ' ' << r << ' ' << x << endl;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	out.open("linout.txt");
	in.open("linin1.txt");

	genIn(1000, 2000, 0);

	startTime = clock();

	program();
	
	endTime = clock();

	printTime();


	out.close();
	in.close();
}