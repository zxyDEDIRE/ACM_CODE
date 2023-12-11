#include<bits/stdc++.h>
using namespace std;

const int N=6e6+10;

int n;
int a[N];
long long nw[N];
int sum[N];
int top;
void solve(){
	top=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int f=1;
		if(a[i]<0) f=-1,a[i]=-a[i];
		int t=i;
		while(a[i]){
			if(a[i]&1) nw[t]+=f;
			a[i]/=2;
			top=max(top,t);
			t++;
		}
		for(int j=i;j<=top;j++){
			nw[j+1]+=nw[j]/2;
			nw[j]%=2;
		}
		if(nw[top+1]){
			top++;
			while(abs(nw[top])>1){
				if(nw[top]&1) nw[top+1]+=nw[top]/2;
				nw[top]%=2;
				top++;
			}
		}
		t=0;
		for(int j=top;j>=i;j--){
			if(nw[j]){
				if(nw[j]<0) t=-1;
				else t=1;
				break;
			}
		}
		sum[i]=sum[i-1];
		if(t==0){
			if(sum[i]<0) cout<<'-';
			else if(sum[i]>0) cout<<'+';
			else cout<<0;
		}
		else if(t<0){
			cout<<'-';
		}
		else{
			cout<<'+';
		}
		if(nw[i]<0) sum[i]=-1;
		else if(nw[i]>0) sum[i]=1;
	}cout<<'\n';
}
/*
4
8 -4 2 -1
*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}

	return 0;
}