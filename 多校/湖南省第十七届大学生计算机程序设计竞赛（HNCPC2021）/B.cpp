#include<bits/stdc++.h>
using namespace std;

int n, m;
void solve()
{
	int r, c, v;
	cin >> r >> c >> v;
	int sum = 0;
	for(int i = 1; i <= n; i ++){
		int x = i, y = 1;
		int left = sum + 1;
		sum = sum += min(m - y + 1, x);
		int right = sum;
//					printf("l = %d r = %d\n",left,right);
		if(x + y == r + c){
			if(left <= v && v <= right){
				cout << "Yes\n";
			}
			else cout << "No\n";
			return ;
		} 
	}
	
	for(int i = 2; i <= m; i ++){
		int x = n, y = i;
		int left = sum + 1;
		sum += min(m - y + 1, n);
		int right = sum;
		
//			printf("l = %d r = %d\n",left,right);
		if(x + y == r + c){
			if(left <= v && v <= right){
				cout << "Yes\n";
			}
			else cout << "No\n";
			return ;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin >> n >> m)
		solve(); 
	return 0;
}
