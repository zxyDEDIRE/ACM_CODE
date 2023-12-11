#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int cnt;
string s[N];
string f[N];
int pre[N], idx[N]; // idx[i]:长度为i的最长上升子序列的最后一个单词的最小值对应的原数组下标， 
int last[N];
// pre[i]: 以第i个单词为最后一个单词的字典序最小的最长上升子序列的前一个
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string t;
	cin >> t;
	int n = t.length();
	for(int i = 0; i < n;){
		s[++ cnt] = t[i ++];
		while(i < n && t[i] >= 'a') s[cnt].push_back(t[i ++]);
	}
	// for(int i=1;i<=cnt;i++)
	// 	cout<<s[i]<<endl;

	int len = 1;
	f[1] = s[1];
	idx[1] = 1;
	for(int i = 2; i <= cnt; i ++)
	{
		int id = (lower_bound(f + 1, f + 1 + len, s[i]) - f) - 1;
		// cout<<i<<" "<<id<<endl;
		if(f[id + 1].empty()) {
			f[++ len] = s[i];
			idx[len] = i;
		}	
		else if(f[id + 1] > s[i]){
			f[id + 1] = s[i];
			idx[id + 1] = i;
		}
		pre[i] = idx[id]; 
	}
	
	int id = idx[len];
	vector<int>v; 
	while(id){
		v.push_back(id);
		id = pre[id];
	}
	for(int i = v.size() - 1; i >= 0; i --){
		cout << s[v[i]];
	}
	return 0;
}
/*
BACD
*/