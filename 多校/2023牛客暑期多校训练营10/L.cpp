#include<bits/stdc++.h>
using namespace std;
const int N=1010,mod=1e9+7;
long long ksm(long long a,long long b){
	long long res=1;
	a%=mod;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int n;
struct pp
{
	int r,g,b;
	bool operator == (const pp w){
		return (r==w.r)&&(g==w.g)&&(b==w.b);
	}
	bool operator >(const pp w){
		return r>w.r&&g>w.g&&b>w.b;
	}
}p[N];
int ans[N];
vector<int>tr[N];
int in[N],iin[N];
bool check(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(ans[i]>2) ans[i]=0;
		if(in[i]==0){
			q.push(i);
		}
		iin[i]=in[i];
	}
	while(!q.empty()){
		int u=q.front();
		// if(ans[u]>255) return false; 
		q.pop();
		for(auto v:tr[u]){
			--iin[v];
			if(v<=2){
				if(ans[v]<=ans[u]) return false;
			}
			else ans[v]=max(ans[v],ans[u]+1);
			if(iin[v]==0){
				if(v<=2){
					if(ans[v]<=ans[u]) return false;
				}
				q.push(v);
			}
		}
	}
	return true;
}
bool check1(){
	for(int i=1;i<=n;i++){
		if(ans[i]>255)return 0;
		for(int j=1;j<=n;j++){
			if(p[j]>p[i]&&ans[j]<=ans[i]){
				cout<<i<<" "<<j<<" "<<ans[i]<<" "<<ans[j]<<'\n';
				return true;
			}
		}
	}
	return false;
}
int get(int l,int r)
{
	return rand()%(r-l+1)+l;
}
void solve(){
	// cin>>n;
	n=1000;
	for(int i=1;i<=n;i++){
		// cin>>p[i].r>>p[i].g>>p[i].b;
		p[i].r=get(0,255);
		p[i].g=get(0,255);
		p[i].b=get(0,255);
		tr[i].clear();
		in[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(p[j]>p[i]){
				tr[i].push_back(j);
				in[j]++;
			}
		}
	}
	int f=0;
	for(int i=0;i<=255;i++){
		ans[1]=ans[2]=i;
		if(check()){
			if(check1()){
				cout<<n<<endl;
				for(int i=1;i<=n;i++)
					cout<<p[i].r<<" "<<p[i].g<<" "<<p[i].b<<endl;
				cout<<"NO\n";
				exit(0);
			}
			// for(int j=1;j<=n;j++){
			// 	cout<<ans[j]<<'\n';
			// }
			cout<<"OK"<<endl;
			return;
		}
	}
	// cout<<-1<<'\n';
	cout<<"OK"<<endl;
}

int main(){
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(0));
	int t=1e9;
	while(t--){
		// cout<<t<<endl;
		solve();
	}
	return 0;
}