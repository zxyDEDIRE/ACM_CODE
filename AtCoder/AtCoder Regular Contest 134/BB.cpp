/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
string solve(int n,string str)
{
	// cin>>n>>str;
	str=" "+str;
	for(int i=1;i<=n;i++)
		p[i]=i;
	sort(p+1,p+1+n,[&](int a,int b){
		if(str[a]==str[b])return a>b;
		return str[a]<str[b];
	});
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" ";cout<<endl;
	int l=1,r=n+1;
	for(int i=1;i<=n;i++)
	{
		while(l<=n&&p[l]>=r)l++;
		while(l<=n&&p[l]<i)l++;
		if(l<=n&&p[l]>i&&str[i]>str[p[l]]&&p[l]<=r)
		{
			r=p[l];
			// cout<<i<<" "<<l<<" "<<p[l]<<" "<<r<<endl;
			// cout<<str[i]<<" "<<str[r]<<endl;
			swap(str[i],str[r]);
			l++;
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<str[i];
	// cout<<endl;
	string ans=str.substr(1,n);
	return ans;
}
string solve_1(int n,string s)
{
	// int n; cin >> n;
	// string s; cin >> s;

	vector<vector<int>>ch(26, vector<int>());
	for (int i = 0; i < n; i ++)
	{
		ch[(int)(s[i] - 'a')].push_back(i);
	}
	int i = 0, j = n - 1;
	while (i < j)
	{
		int x = 0;
		while (x < 26)
		{
			while (ch[x].empty() == false && ch[x].back() > j) ch[x].pop_back();
			if (ch[x].empty() || ch[x].back() < i) x ++;
			else break;
		}
		if (s[i] <= 'a' + x) 
		{
			i ++;
			continue;
		}
		j = ch[x].back();
		swap(s[i], s[j]);
		i ++; -- j;
	}
	// cout << s << "\n";
	return s;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	srand(time(0));
	// cout<<solve_1(4,"mrqd")<<endl;
	// return 0;
	while(1)
	{	
		int n=rand()%10;
		string str;
		for(int i=0;i<n;i++)
		{
			int x=rand();
			str+=(char)('a'+x%26);
		}
		string ans_1,ans_2;
		ans_1=solve_1(n,str);
		ans_2=solve(n,str);
		if(ans_1!=ans_2){
			cout<<str<<endl<<ans_1<<endl<<ans_2<<endl;
			return 0;
		}
		// Sleep(1000);	
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

mrqd

dmqr

dqrm
drqm
*/