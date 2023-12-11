#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mul(ll a,ll b,ll p){
	return (a*b-(ll)(a/(long double)p*b+1e-3)*p+p)%p;
}
ll ksm(ll a,ll r,ll p){
	ll res=1;
	for(;r;a=mul(a,a,p),r>>=1){
		if(r&1){
			res=mul(res,a,p);
		}
	}
	return res;
}

bool miller_rabin(ll n){
	static ll p[9]={2,3,5,7,11,13,17,19,23};
	if(n==1)
		return false;
	ll d=n-1,r=0;
	for(;not(d&1);d>>=1)
		r+=1;
	bool res=true;
	for(int i=0;i<9 and p[i]<n and res;i+=1){
		ll x=ksm(p[i],d,n);
		if(x==1 or x==n-1)
			continue;
		for(int j=1;j<r;j+=1){
			x=mul(x,x,n);
			if(x==n-1)
				break;
		}
		if(x!=n-1)
			res=false;
	}
	return res;
}

vector<ll>pollard_rho(ll n){
	vector<ll>res;
	function<void(ll)>rho=[&](ll n){
		if(n==1)
			return;
		if(miller_rabin(n))
			return res.push_back(n),void();
		ll d=n;
		while(d==n){
			d=1;
			for(ll k=1,y=0,x=0,s=1,c=rand()%n;d==1;
				k<<=1,y=x,s=1){
				for(int i=1;i<=k;i+=1){
					x=(mul(x,x,n)+c)%n;
					s=mul(s,abs(x-y),n);
					if(not(i%127) or i==k){
						d=__gcd(s,n);
						if(d!=1)
							break;
					}
				}
			}
		}
		rho(d);rho(n/d);
	};
	rho(n);
	return res;
}
long long p,q;
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
pair<ll,ll>ans;
vector<ll>pr;
string o,o1;
int n;
int op=0;
int v[11];
int op1=0;
int v1[11];
bool check(long long a,long long b){
	string s=to_string(a);
	string s1=to_string(b);
	int l=0;
	for(int j=0;j<10;j++){
		v[j]=0;v1[j]=0;
	}
	for(int i=0;i<(int)o.size();i++){
		if(l<(int)s.size()&&s[l]==o[i]){
			l++;
		}
		else{
			v[o[i]-'0']++;
		}
	}
	if(l!=(int)s.size()) return false;
	l=0;
	for(int i=0;i<(int)o1.size();i++){
		if(l<(int)s1.size()&&s1[l]==o1[i]){
			l++;
		}
		else{
			v1[o1[i]-'0']++;
		}
	}
	if(l!=(int)s1.size()) return false;
	for(int i=0;i<10;i++){
		if(v[i]!=v1[i]) return false;
	}
	return true;
}
void dfs(int id,long long d,long long tp){
	if(id==n){
		cout<<p/d<<" "<<q/d<<'\n';
		if(q/d<ans.second && check(p/d,q/d)){
			ans={p/d,q/d};
		}
		return;
	}	
	dfs(id+1,d,tp);
	while(tp%pr[id]==0){
		d*=pr[id];tp/=pr[id];
		dfs(id+1,d,tp);
	}
}
void solve(){
	cin>>p>>q;
	o=to_string(p);
	o1=to_string(q);
	if(p==q){
		int mi=10;
		while(p){
			int t=p%10;
			if(t) mi=min(t,mi);
			p/=10;
		}
		cout<<mi<<" "<<mi<<'\n';
	}
	else{
		long long gc=gcd(p,q);
		cout<<p/gc<<" "<<q/gc<<'\n';
		long long d=gcd(232,16936);
		cout<<232/d<<" "<<16936/d<<'\n';
		if(gc==1){
			cout<<p<<" "<<q<<'\n';return;
		}
		pr=pollard_rho(gc);
		sort(pr.begin(),pr.end());
		pr.erase(unique(pr.begin(),pr.end()),pr.end());
		if((int)pr.size()==0) pr.push_back(gc);
		ans.first=p;ans.second=q;
		n=(int)pr.size();
		dfs(0,1,gc);
		cout<<ans.first<<" "<<ans.second<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(0));
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}