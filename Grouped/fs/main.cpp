#include <bits/stdc++.h>
using namespace std;

string solve(string n){
    int i = n[n.length() - 1] - '0';
    n.pop_back();
    int k = n[n.length() - 1] - '0';
    bool is = true;
    int s = 0;
    if(i > k){
    int j = (n.length() - 1);
    for(j = (n.length() - 2); is; j--){
        s++;
        if(j == 0){
            is = false;
            string b;
            if(n[0] - '0' > 1){
                string rep = to_string((n[0] - '0') - 1);
                b+=rep;
            }
            for(int k = 0; k < (n.length() - 2); k++){
                b = b+"9";
            }
            n = b + to_string((k + 10) - i);
            return n;
        }
        if((n[j] != '0')){
            is = false;
            k+=10;
            string l = to_string((n[j] - '0') - 1);
            n[j] = l[0];
            string m = to_string(k - i);
            n[(n.length() - 1)] = m[0];
            for(int o = 1; o < s; o++){
                string nine = "9";
                n[(n.length() - 1) - o] = nine[0];
            }
            return n;
        }
    }
  } else{
    string m = to_string(k - i);
    n[(n.length() - 1)] = m[0];
    return n;
  }

}


int main() {
    int q; cin >> q;
    for(int j = 0; j < q; j++){
    string n; cin >> n;
    string m = n;
    bool is = false;
    cout << n << endl;
    while(n.length() > 1){
        bool die = false;
        if(n.length() == 2){
            int x = n[0] - '0';
            int y = n[1] - '0';
            if(y > x){
                die = true;
            }
        }
        if(die){
            is = false;
            n = "1";
        } else{
            n = solve(n);
        }
        
        if(n == "11"){
            n = "1";
            cout << "11" << endl;
            is = true;
        } else if(n == "0"){
            is = true;
        }
        else if(n.length() < 2){
            is = false;
            cout << n << endl;
        } else{
            cout << n << endl;
        }
    }

    if(n == "0"){
        is = true;
    }
    

    if(is){
      if(n != "0"){
        cout << "11" << endl;
      }
        cout << "The number " << m << " is divisible by 11." << endl;
    } else{
        cout << "The number " << m << " is not divisible by 11." << endl;
    }
    if(j != q - 1){
        cout << "\n";
    }
  }
}