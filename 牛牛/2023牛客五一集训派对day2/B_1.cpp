#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=2e3+9;
typedef pair<double,double> pdd;
int n;
double x[maxn],y[maxn];
map<pdd,int> res;
int main(){
	scanf("%d",&n);
	rep(i,0,n) scanf("%lf%lf",x+i,y+i);
	int ans=0;
	rep(i,0,n) {
		res.clear();
		rep(j,i+1,n){
			if(x[i]*y[j]==x[j]*y[i]) continue;
			double d=x[i]*y[j]-x[j]*y[i],d1=x[i]*x[i]+y[i]*y[i],d2=x[j]*x[j]+y[j]*y[j];
			double X=(y[i]*d2-y[j]*d1)/d,Y=(x[i]*d2-x[j]*d1)/d;
			ans=max(ans,++res[{X,Y}]);
		}
	}
	printf("%d\n",ans+1);
}