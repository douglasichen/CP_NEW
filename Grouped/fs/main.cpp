#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

struct Node {
	ll x=0, y=0, z=0;
};

const int TSZ=1<<3;
ll ar[TSZ], dp[TSZ];
Node tree[TSZ*2], lazy[TSZ*2];

Node merge(Node a, Node b) {
	Node ret={0,0,max(a.z,b.z)};
	if (a.x+a.y>b.x+b.y) ret.x=a.x, ret.y=a.y;
	else ret.x=b.x, ret.y=b.y;
	return ret;
}

void printNode(Node node) {
    cout << "(" << node.x << "," << node.y << "," << node.z << ")";
}

void printTree() {
    for (int i=0; i<TSZ*2; i++) cout << "\t" << i << ": ", printNode(tree[i]), cout << endl;
    // cout << endl;
    
    // for (int i=TSZ; i<TSZ*2; i++) printNode(tree[i]), cout << ' ';
    // cout << endl;
}


void printRange(int a, int b) {
    cout << "(" << a << "," << b << ")";
}

void down(int node) {
	int left=node*2, right=node*2+1;

    cout << "\t[pushing " << node << " to " << left << " and " << right << "]" << endl;

	if (lazy[node].y) {
		lazy[left].y=lazy[node].y;
		lazy[right].y=lazy[node].y;
		tree[left].y=lazy[node].y;
		tree[right].y=lazy[node].y;
	}
	if (lazy[node].z) {
		lazy[left].z=lazy[node].z;
		lazy[right].z=lazy[node].z;
		tree[left].z=lazy[node].z;
		tree[right].z=lazy[node].z;
	}
	lazy[node].y=0;
	lazy[node].z=0;
}

// find l
int getL(int node, int segL, int segR, int val) {
	if (segR-segL==1) return segL;
	down(node);

	int left=node*2, right=node*2+1, mid=segL+segR>>1;
	if (tree[right].z>=val)	return getL(right, mid, segR, val);
	return getL(left, segL, mid, val);
}

Node uptY(int node, int segL, int segR, int l, int r, ll val) {
	if (r<=segL || l>=segR) {
        cout << "\t";
        printRange(segL,segR), cout << " is out of ", printRange(l,r), cout << endl;
        return tree[node];
    }
	if (l<=segL && segR<=r) {
        cout << "\t";
        cout << "setting lazy: " << node << " -> " << val << endl;
		lazy[node].y=val;
		lazy[node].z=val;

		tree[node].y=val;
		tree[node].z=val;
		return tree[node];
	}

	down(node);
	int mid=segL+segR>>1;
    tree[node]=merge(uptY(node*2, segL, mid, l, r, val), uptY(node*2+1, mid, segR, l, r, val));
    
    cout << "\t";
    cout << node << " joins " << node*2 << " and " << node*2+1 << " -> ", printNode(tree[node]);
    cout << endl;

    // cout << segL << ' ' << segR << ' ' << l << ' ' << r << endl;
    // printTree();
    // cout << node*2 << ' ' << node*2+1 << " becomes ", printNode(tree[node]), cout << endl;
    return tree[node];
	// return tree[node]=merge(uptY(node*2, segL, mid, l, r, val), uptY(node*2+1, mid, segR, l, r, val));
}

Node uptX(int node, int segL, int segR, int pos, int val) {
	if (pos<segL || pos>=segR) {
        cout << "\t";
        printRange(segL, segR), cout << " is out of " << pos << endl;
        return tree[node];
    }
	if (pos==segL && pos==segR-1) {
        cout << "\tset val of " << node << " -> " << val << endl;
		tree[node].x=val;
		return tree[node];
	}

	down(node);
	int mid=segL+segR>>1;

    tree[node]=merge(uptX(node*2, segL, mid, pos, val), uptX(node*2+1, mid, segR, pos, val));
    cout << "\t";
    cout << node << " joins " << node*2 << " and " << node*2+1 << " -> ", printNode(tree[node]);
    cout << endl;

    return tree[node];
	// return tree[node]=merge(uptX(node*2, segL, mid, pos, val), uptX(node*2+1, mid, segR, pos, val));
}

Node query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) {
        cout << "\t";
        printRange(segL, segR), cout << " is out of ", printRange(l,r), cout << endl;
        return {0,0,0};
    }
	if (l<=segL && segR<=r) {
        cout << "\t";
        printRange(segL, segR), cout << " is in ", printRange(l, r), cout << endl;
        return tree[node];
    }
	
	down(node);
	int mid=segL+segR>>1;
    
    Node res=merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
    cout << "\t";
    cout << node << " joins " << node*2 << " and " << node*2+1 << " -> ", printNode(tree[node]);
    cout << endl;

    return res;
	// return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
}




int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ms(ar,0);
	ms(dp,0);
	ms(tree,0);
	ms(lazy,0);


	int N,K; cin>>N>>K;
	for (int i=1; i<=N; i++) cin>>ar[i];
    for (int i=1; i<=N; i++) cout << ar[i] << ' '; cout << endl;
	
	for (int i=1; i<=N; i++) {
		int L=max(0,i-K), R=(i-1)/K*K;
		
        cout << "______________________\n";

		// set new seg from [x,i) to ar[i], where x is smallest index that is <ar[i];
		int l=getL(1,0,TSZ,ar[i]), r=i;
		if (tree[l+TSZ].z>ar[i]) l++;

        cout << "______________________\n";

        cout << "uptY: [" << l << "," << r << ") -> " << ar[i] << "\n";
		uptY(1,0,TSZ,l,r,ar[i]);
        
        cout << "query: [" << L << "," << R+1 << ")\n";
		Node ans=query(1,0,TSZ,L,R+1);
		dp[i]=ans.x+ans.y;

        cout << "uptX: " << i << "->" << dp[i] << "\n";
		uptX(1,0,TSZ,i,dp[i]);

        // cout << "l,r: " << l << ' ' << r << endl;
        // cout << "L,R: " << L << ' ' << R+1 << endl; 

        cout << endl;
	}

    for (int i=1; i<=N; i++) cout << dp[i] << ' '; cout << endl;
	cout << dp[N] << endl;
}

/*
8 3
5 3 8 3 8 8 5 6 

*/