#include<bits/stdc++.h>
using namespace std;
vector<double>v;
double a,x,y;
int n,q;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lf",&a),v.push_back(a);
	sort(v.begin(),v.end());
	while(q--)
	{
		scanf("%lf%lf",&x,&y);
		if(n==0){
			printf("0\n");
		}
		double t=sqrt(x*x+y*y);
		int fl=upper_bound(v.begin(),v.end(),t)-v.begin();
		printf("%d\n",fl);
	}

}