#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, MAX = 1e5;

int tr[2][N]; // 左端点前缀和  右端点前缀和
int sum[N][4];
int  n, q;

void update(int id, int i, int w){
	while(i <= n){
		tr[id][i] += w;
		i += (i & -i);
	}
}

int get_sum(int id, int i){
	int ans = 0;
	while(i > 0){
		ans += tr[id][i];
		i -= (i & -i);
	}
	return ans;
}

void solve(){
	for(int i = 1; i <= n; i ++){
		tr[0][i] = tr[1][i] = 0;
		for(int j = 0; j <= 3; j ++) sum[i][j] = 0;
	}
	
	for(int i = 1; i <= q; i ++){
		int op, l, r;
		cin >> op >> l >> r;
		if(op == 1){
			update(0, l, 1);
			update(1, r, 1);
			if(r-l<=2) sum[l][r-l]++;
			else sum[l][3]++;
		}
		else
		{	
			int ans=0;
			ans+=get_sum(0,r);
			ans-=get_sum(1,r-1);
			int ll=l+1;
			while(ll<=r)
			{
				int d=r-ll;
				while(d<=3)
				{
					ans-=sum[ll][d];
					d++;
			}
				ll++;
		}
			cout<<ans<<'\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> n >> q){
		solve();
	}
	return 0;
}
/*
10 3
1 1 4
1 2 3
2 1 3
10 3
1 1 1
1 2 2
2 1 2
10 3
1 1 1
1 3 3
2 1 3
1 2
1 1 1
2 1 1
4 4
1 1 4
2 2 3
1 1 4
2 2 3


*/