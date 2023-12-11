#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pii;

const int N = 1e5 + 10;

struct seg{
	int ls, rs, sum;
}tr[N * 100];

int n, T[N], tot;

void init(){
	for(int i = 0; i <= n; i ++) T[i] = 0;
	for(int i = 0; i <= tot; i ++) tr[i] = {0, 0, 0};
	tot = 0;
}

void update(int& p, int pre, int loc, int l = 1, int r = n){
	p = ++ tot;
	tr[p] = tr[pre];
	tr[p].sum ++;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(loc <= mid) update(tr[p].ls, tr[pre].ls, loc, l, mid);
	else update(tr[p].rs, tr[pre].rs, loc, mid + 1, r);
}

int query(int now, int pre, int ql, int qr, int l = 1, int r = n){
	if(!now) return 0;
	if(ql <= l && r <= qr){
		return tr[now].sum - tr[pre].sum;
	}
	int mid = (l + r) >> 1, ans = 0;
	if(ql <= mid) ans += query(tr[now].ls, tr[pre].ls, ql, qr, l, mid);
	if(qr > mid) ans += query(tr[now].rs, tr[pre].rs, ql, qr, mid + 1, r);
	return ans;
}

int a[N];
int R[N];
long long vi[N];

void solve(){
	cin >> n;
	init();
	ll ans = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] + 1 <= n) ans += query(T[i - 1], T[0], a[i] + 1, n);
		update(T[i], T[i - 1], a[i]);
	}

	set<int>lr;
	multiset<long long>s;

	R[1]=n;
	vi[1]=ans;
	
	lr.insert(1);
	s.insert(0);
	s.insert(ans);
	
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		long long val=*s.rbegin();
		cout<<val;
		if(i==n) cout<<'\n';
		else cout<<" ";
		x^=val;

		auto t=lr.upper_bound((int)x);
		t--;

		int l=*t;
		int r=R[l];

		s.erase(s.find(vi[l]));

		if(l==r){
			lr.erase(l);
		}
		else if(l==x){
			R[l+1]=r;
			lr.erase(l);
			lr.insert(l+1);

			long long res=vi[l];
			if(a[x] - 1 >= 1) res -= query(T[r], T[l], 1, a[x] - 1);
			vi[l+1]=res;
			s.insert(res);
		}
		else if(r==x){
			R[l]=r-1;
			long long res=vi[l];
			if(a[x] + 1 <= n) res -= query(T[r-1], T[l-1], a[x]+1, n);
			vi[l]=res;
			s.insert(res);
		}
		else{
			R[l]=x-1;
			R[x+1]=r;
			int lenl=x-l,lenr=r-x;
			long long res=vi[l];
			if(a[x] + 1 <= n) res -= query(T[x-1], T[l-1], a[x]+1, n);
			
			if(a[x] - 1 >= 1) res -= query(T[r], T[x], 1,  a[x] - 1);
			
			if(lenl<=lenr){
				vi[l]=0;
				long long re=0;
				for(int i = l; i < x; i ++){
					if(a[i] + 1 <= n) vi[l] += query(T[i - 1], T[l - 1], a[i] + 1, n);
					if(a[i] - 1 >=1) re += query(T[r], T[x], 1,a[i] - 1);
				}
				vi[x+1]=res-re-vi[l];
			}	
			else{
				vi[x+1]=0;
				long long re=0;
				for(int i = x+1; i <= r; i ++){
					if(a[i] + 1 <= n) vi[x+1] += query(T[i - 1], T[x], a[i] + 1, n);
					if(a[i] + 1 <= n) re += query(T[x-1], T[l - 1], a[i] + 1, n);
				}
				vi[l]=res-re-vi[x+1];
			}
			s.insert(vi[l]);s.insert(vi[x+1]);
			lr.insert(x+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}
/*
1
5
4 3 1 1 1
5 4 5 3 1
*/