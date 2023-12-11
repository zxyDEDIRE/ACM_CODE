/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e4+100;
const int N=2e4+10;
struct node_1{
	ll a[N], b[N];
	ll sum[N];
	char s[N];
	ll k;
	int num;
	int n;

	bool check(int x) {
	    for (int l = 1; l + x - 1 <= num; l++) {
	        int r = min(x + l - 1, num);
	        int mid = (l + r) / 2;
	        ll all = b[mid] * (mid - l + 1ll) - (sum[mid] - sum[l - 1]);
	        all += (sum[r] - sum[mid - 1]) - b[mid] * (r - mid + 1);
	        if (all <= k) {
	            return 1;
	        }
	    }
	    return 0;
	}

	int solve(int N,int K,string S) {
		n=N;
		k=K;
		for(int i=1;i<=n;i++)
			s[i]=S[i-1];
		// cin>>n>>k>>s+1;
	    num=0;
	    for (int i = 1; i <= n; i++) {
	        if (s[i] == '6') {
	            a[++num] = i;
	        }
	    }

	    for (int i = 1; i <= num; i++) {
	        b[i] = a[i] - i;
	    }
	   
	    for (int i = 1; i <= num; i++) {
	        sum[i] = sum[i - 1] + b[i];
	    }
	    int l = 0, r = N;
	    while (l < r) {
	        int mid = l + r + 1 >> 1;
	        if (check(mid)) {
	            l = mid;
	        } else {
	            r = mid - 1;
	        }
	    }
	    // cout << l << endl;
	    return l;
	}
}A;
struct node_2{
	int pre[maxn];
	int p[maxn];
	string str;
	ll n,m,k;
	bool check(int len)
	{
		int pr=(1+len+1)/2;
		ll sum=0;
		for(int i=1;i<len;i++)
			sum+=1ll*(p[i+1]-p[i]-1)*min(i,len-i);
		if(sum<=k)return 1;
		// cout<<sum<<endl;
		for(int i=2;i+len-1<=m;i++)
		{
			int now=(i+i+len-1+1)/2;
			sum-=pre[p[pr]]-pre[p[i-1]-1];
			if(len%2==0)
           		sum+=pre[p[i+len-1]]-pre[p[pr]-1];
        	else sum+=pre[p[i+len-1]]-pre[p[now]-1];
			if(sum<=k)return 1;
			pr=now;
		}
		return 0;
	}
	int solve(int N,int K,string S)
	{
		n=N;
		k=K;
		str=S;
		// cin>>n>>k>>str;
		int AS;
		m=0;
		for(int i=1;i<=n;i++)
		{
			if(str[i-1]=='6')p[++m]=i;
			pre[i]=pre[i-1]+(str[i-1]=='9');
		}
		int l=0,r=m,ans=0;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check(mid))ans=l,l=mid;
			else r=mid;
		}
		while(ans<m&&check(ans+1))ans++;
		return ans;
	}
}B;
void solve()
{
	srand(time(0));
	while(1)
	{
		int n=15;
		string now="";
		for(int i=1;i<=n;i++)
		{
			int x=rand()%2;
			if(x&1)now=now+"9";
			else now=now+"6";
		}
		int ans_1=A.solve(n,7,now);
		int ans_2=B.solve(n,7,now);
		cout<<ans_1<<" "<<ans_2<<endl;
		if(ans_1!=ans_2){
			cout<<endl;
			cout<<ans_1<<" "<<ans_2<<endl;
			cout<<n<<" "<<7<<" "<<now<<endl;
			return ;
		}
	}
	
}
signed main(){
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);


		solve();


	return 0;
}