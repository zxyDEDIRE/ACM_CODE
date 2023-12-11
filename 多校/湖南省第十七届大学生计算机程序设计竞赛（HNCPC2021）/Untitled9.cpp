#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, inf = 1e9;

char a[N];
int n;
struct node{
	int l, r, val, lth, rth;
}tr[N * 4];

void pushup(int p){
	tr[p].val = tr[p << 1].val + tr[p << 1 | 1].val;
}

void build(int p, int l, int r){
	tr[p] = {l, r, 0};
	if(l == r){
		tr[p].val = a[l] - '0';
		return ;
	}	
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}

void update(int p, int loc){
	if(tr[p].l == tr[p].r){
		tr[p].val = 0;
		return ;
	}	
	int mid = (l + r) >> 1;
	if(loc <= mid) update(p << 1, loc);
	else update(p << 1 | 1, loc);
	pushup(p);
}

int query(int p, int l, int r, int w){
	if(tr[p].val <= w) return inf;
	if(tr[p].l == tr[p].r) return tr[p].l;
	int mid = (l + r) >> 1; 
	if()	
}

void solve(){
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while(cin >> (a + 1)){
		solve();
	}		
	return 0;
}
/*
1234599999 4
9999912345
*/
