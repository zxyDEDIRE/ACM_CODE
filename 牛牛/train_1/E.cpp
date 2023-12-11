#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct seg{
	int l, r;
	bool operator < (const seg &A)const{
		if(l == A.l) return r < A.r;
		return l < A.l;
	}
}s[N];

priority_queue<int, vector<int>, greater<int> > q; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> s[i].l >> s[i].r;
	}

	sort(s + 1, s + 1 + n);

	int ans = 0, now = 0;
	for(int i = 1; i <= n; i ++){
		while(!q.empty() && now < s[i].l){
			int x = q.top(); q.pop();
			if(x >= now) {
				ans ++;
				now ++;
			}
		}
		if(now < s[i].l) now = s[i].l;
		q.push(s[i].r);
	}

	while(!q.empty()){
		int x = q.top(); q.pop();
		if(x >= now){
			ans ++;
			now ++;
		} 
	}
	cout << ans;
	return 0;
}