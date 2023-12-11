#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int vis[N];//编号为i的人 帮他辩护的人是vis[i]
vector<int>g[N]; // 存的是能帮i辩护的人的编号
int d[N];//帮他辩护的人的数量
map<pair<int,int>, bool>mp;
int main(){
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		int u, v;
		cin >> u >> v;
		mp[{u, v}] = 1;
		g[v].push_back(u);
		d[v] ++;
	}

	queue<int>q;
	for(int i = 1; i <= n; i ++){
		if(d[i] == 1) q.push(i);
		else if(d[i] == 0){
			cout << "NO";
			return 0;
		}
	}

	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int v : g[u])
		{
			if(vis[v] == u) continue ;
			vis[u] = v; // v帮u辩护
			if(vis[v]) break;// v有人帮他辩护就不需要了
			if(mp.count({u, v})){//那么u就不能帮v辩护了
				mp.erase({u, v});
				d[v] --;   //帮v辩护的人少1
				if(d[v] == 1) q.push(v);
				else if(d[v] == 0){
					cout << "NO";
					return 0;
				}             
			}
			break;
		}
		if(!vis[u]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}