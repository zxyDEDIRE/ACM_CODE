#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const double eps=1e-8;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
const int maxm=1e6+5;
double f[305][305][305];
int a[5],n; 
int main(int argc,char const *argv[]){
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		a[x]++;
	}	
	for(int k=0;k<=n;++k){
		for(int j=0;j<=n;++j){
			for(int i=0;i<=n;++i){
				if(i||j||k){
					if(i)f[i][j][k]+=f[i-1][j][k]*i/(i+j+k);
        			if(j)f[i][j][k]+=f[i+1][j-1][k]*j/(i+j+k);
    	    		if(k)f[i][j][k]+=f[i][j+1][k-1]*k/(i+j+k);
	        		f[i][j][k]+=(double)n/(i+j+k);
         		}
			}
		}
	}
	printf("%.15lf\n",f[a[1]][a[2]][a[3]]);
	cout<<f[2][0][0]<<endl;
	cout<<f[0][0][0]<<endl;
	cout<<f[1][0][0]<<endl;
	return 0;
}