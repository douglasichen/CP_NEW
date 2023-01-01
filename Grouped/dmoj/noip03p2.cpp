#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	bool imp=0;
	map<string, vector<pair<string,bool>>> G;
	map<string, string> gDay;
	int M,N,P; cin>>M>>N>>P;
	vector<string> names(M), coms={"I am guilty.", "I am not guilty.", "is guilty.", "is not guilty."},
					days={"Monday.", "Tuesday.", "Wednesday.", "Thursday.", "Friday.", "Saturday.", "Sunday."};
	for (int i=0; i<M; i++) cin>>names[i];

	// maps
	map<string,bool> isName, isCom, isDay;
	map<string,int> name2I, day2I;
	for (int i=0; i<M; i++) name2I[names[i]]=i;
	for (int i=0; i<7; i++) day2I[days[i]]=i;
	for (string s : names) isName[s]=1;
	for (string s : coms) isCom[s]=1;
	for (string s : days) isDay[s]=1;
	vector<int> dCnt(M);

	cin.ignore();
	for (int p=0; p<P; p++) {
		string line, from="", to="", com="", s=""; getline(cin,line);
		int L=line.size();
		for (int i=0; line[i]!=':'; i++) from+=line[i];
		
		for (int i=from.size()+2; i<L; i++) s+=line[i];
		for (int c=0; c<2; c++) if (s==coms[c]) to=from, com=coms[c];
		if (to.size()==0) {
			for (int i=from.size()+2; i<L && line[i]!=' '; i++) to+=line[i];
			if (isName[to]) {
				// opt 2, or 3
				string k="";
				for (int i=from.size()+2+to.size()+1; i<L; i++) k+=line[i];
				for (int c=2; c<4; c++) {
					if (k==coms[c]) {
						com=k;
						break;
					}	
				}
			}
		}
		if (isName[from] && isName[to] && isCom[com]) {
			int comInd=0;
			for (int c=0; c<4; c++) if (com==coms[c]) comInd=c;

			bool guilt=0;
			if (comInd==0 || comInd==2) guilt=1;
			else guilt=0;
			G[from].push_back({to, guilt});
		}

		// what day did they say it was?
		string day="";
		while (s.size() && s.back()!=' ') day+=s.back(), s.pop_back();
		if (s.size() && s.back()==' ') s.pop_back();
		reverse(day.begin(), day.end());
		
		if (isName[from] && s=="Today is" && isDay[day]) {
			// if (gDay[from].size()) imp=1;
			gDay[from]=day;
			dCnt[name2I[from]]++;
		}
	}
	// for (string name : names) {
	// 	for (pair<string,int> v : G[name]) {
	// 		cout << name << ' ' << v.first << ' ' << v.second << endl;
	// 	}
	// 	cout << endl;
	// }

	// for (string name : names)
	// 	cout << name << ": " << gDay[name] << endl;

	int K=1<<M;
	bitset<20> crim;
	while (--K) {
		bitset<20> liar=K;
		if (liar.count()!=N) continue;

		bitset<20> crimK(M);
		bool skip=0;
		for (int i=0; i<M; i++) {
			if (!liar[i]) {
				for (pair<string,bool> com : G[names[i]]) {
					int pos=name2I[com.first];
					if (com.second) crimK[pos]=1;
				}
			}
			else {
				for (pair<string,bool> com : G[names[i]]) {
					int pos=name2I[com.first];
					if (!com.second) crimK[pos]=1;
				}
			}
			//
			// if (!liar[i]) {
			// 	// person name[i] is telling truth
			// 	int cnt=0;
			// 	for (pair<string,bool> com : G[names[i]]) {
			// 		int pos=name2I[com.first];
			// 		if (com.second) crimK[pos]=1, cnt++;
			// 		else if (crimK[pos]) skip=1;
			// 	}
			// 	if (cnt>1) skip=1;
			// 	if (dCnt[i]>1) skip=1;
			// }
			// else {
			// 	for (pair<string,bool> com : G[names[i]]) {
			// 		int pos=name2I[com.first];
			// 		if (!com.second) crimK[pos]=1;
			// 		else if (crimK[pos]) skip=1;
			// 	}
			// }
		}
		// marked if someone said they are crim
		// now check if someone say they are not crim, if so, skip
		for (int i=0; i<M; i++) {
			if (!liar[i]) {
				for (pair<string,bool> com : G[names[i]]) {
					int pos=name2I[com.first];
					if (!com.second && crimK[pos]) skip=1;
				}
			}
			else {
				for (pair<string,bool> com : G[names[i]]) {
					int pos=name2I[com.first];
					if (com.second && crimK[pos]) skip=1;
				}
			}
		}

		bitset<7> today;
		// are the people aligning with the same day
		for (int i=0; i<M; i++) {
			string day=gDay[names[i]];
			if (day.size()) {
				if (!liar[i]) {
					today[day2I[day]]=1;
					if (dCnt[i]>1) skip=1;
				}
			}
		}

		if (crimK.count()==1 && today.count()<=1 && !skip) {
			crim|=crimK;
		}
	}
	// for (int i=0; i<M; i++) cout << crim[i] << ' '; cout << endl;
	if (imp) cout << "Impossible" << endl;
	else if (crim.count()==1) {
		int ans=0;
		for (int i=0; i<M; i++) if (crim[i]) ans=i;
		cout << names[ans] << endl;
	}
	else if (crim.count()>1) cout << "Cannot Determine" << endl;
	else cout << "Impossible" << endl;

}


/*
3 1 3
A
B
C
A: Today is Monday.
B: Today is Tuesday.
C: Today is Wednesday.
*/

// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'

// void solve() {

// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);

// 	int M,N,P; cin>>M>>N>>P;
// 	vector<string> names(M);
// 	map<string,int> name2I;
// 	for (int i=0; i<M; i++) cin>>names[i], name2I[names[i]]=i;
	
// 	vector<vector<vector<int>>> G(N); // person has list of what they say: {about who, type}
// 	cin.ignore();
// 	for (int p=0; p<P; p++) {
// 		string line; getline(cin, line);
// 		int L=line.size();
// 		if (L>=16) {
// 			if (line.substr(L-16,16)=="I am not guilty.") {
// 				string from="";
// 				for (int i=0; line[i]!=':'; i++) from+=line[i];
// 				if (from.size()+16+2==line.size()) {
// 					int fromI=name2I[from];
// 					G[fromI].push_back({fromI, 0});
// 				}
// 			}
// 		}
// 		if (L>=14) {
// 			if (line.substr(L-14, 14)=="is not guilty.") {
// 				string from="";
// 				for (int i=0; line[i]!=':'; i++) from+=line[i];
// 				string to="";
// 				for (int i=from.size()+2; line[i]!=' '; i++) to+=line[i];

// 				if (from.size()+2+to.size()+1+14)
// 				int fromI=name2I[from], toI=name2I[to];
// 				G[fromI].push_back({toI, 3});
// 			}
// 		}
// 		if (L>=12) {
// 			if (line.substr(L-12,12)=="I am guilty.") {
// 				string from=line.substr(0, L-12-2);
// 				int fromI=name2I[from];
// 				G[fromI].push_back({fromI, 1});
// 			}
// 		}
// 		if (L>=10) {
// 			if (line.substr(L-10, 10)=="is guilty.") {
// 				string from="";
// 				for (int i=0; line[i]!=':'; i++) from+=line[i];
// 				string to="";
// 				for (int i=from.size()+2; line[i]!=' '; i++) to+=line[i];

// 				int fromI=name2I[from], toI=name2I[to];
// 				G[fromI].push_back({toI, 2});
// 			}
// 		}
// 	}
// 	for (int fromI=0; fromI<G.size(); fromI++) {
// 		for (vector<int> v : G[fromI]) {
// 			cout << v[0] << ' ' << v[1] << endl;
// 		}
// 		cout << endl;
// 	}
// }