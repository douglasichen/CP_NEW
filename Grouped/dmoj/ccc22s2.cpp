#include <bits/stdc++.h>
using namespace std;

int main() {
  int num1, num2, num3, viola=0; 
  vector<pair<string, string>> sameG, difG; 
  vector<vector<string>> student; 

  cin>>num1; 
  sameG.resize(num1); 
  for(int a=0; a<num1; a++) cin>>sameG[a].first>>sameG[a].second; 

  cin>>num2; 
  difG.resize(num2); 
  for(int a=0; a<num2; a++) cin>>difG[a].first>>difG[a].second; 

  cin>>num3;
  student.resize(num3, vector<string>(3)); 
  for(int a=0; a<num3; a++) cin>>student[a][0]>>student[a][1]>>student[a][2]; 

  //cout<<endl;
  //for(vector<string> a:student) cout<<a[0]<<a[1]<<a[2]<<endl;
  
	vector<bool> sameUsed(num1), difUsed(num2);

 for(int a=0; a<num3; a++) {
    for(int b=0; b<num1; b++){
		if (sameUsed[b]) continue;
      int find1=count(student[a].begin(),student[a].end(),sameG[b].first);
      int find2=count(student[a].begin(),student[a].end(),sameG[b].second);
      if(find1^find2)
          viola++, sameUsed[b]=1;
    }
    for(int c=0; c<num2; c++){
		if (difUsed[c]) continue;
      int find1=count(student[a].begin(),student[a].end(),difG[c].first);
      int find2=count(student[a].begin(),student[a].end(),difG[c].second);
      if(find1 && find2)
          viola++, difUsed[c]=1;
    }
  }
	// cout << endl;
  	cout<<viola<<endl; 
}