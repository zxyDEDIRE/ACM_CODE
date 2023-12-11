#include<bits/stdc++.h>
using namespace std;
const int N = 100;
string str[N];
int n, m;

bool check(int x, int y){
	for(int i = x; i < n; i ++){
		if(str[i][y] == '.') return true;
		if(y - 1 >= 0 && str[i][y - 1] == 'o') return false;
		if(y + 1 < m && str[i][y + 1] == 'o') return false;
	}
	return true;
}
void solve(){
	for(int i = 0; i < n; i ++){
		cin >> str[i];
	}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++){
			if(str[i][j] == 'o'){
				if(check(i, j)){
					cout << "2018\n";
					return ;
				}
			}	
		}
	}
	cout << "2020\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin>>n>>m)
		solve();
	return 0;
}
/*
11 2
o.
o.
o.
o.
o.
..
o.
o.
o.
o.
oo

*/


