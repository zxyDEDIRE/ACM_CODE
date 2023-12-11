#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p,n,a,c,m,l;
	double b;
	
	scanf("%d",&a);
	
	p=(int*)malloc(3000000*sizeof(int));
	
	for(n=0;n<1000000;n++){
		p[n]=0;
	}
	
	for(n=0;n<a;n++){
		scanf("%lf %d",&b,&c);
		
		for(m=1;m<=c;m++){	
			
			l=b*m/1;
			
			if(p[l]==0){
				p[l]=1;
			}else{
				p[l]=0;
			}	
		}
	}
	
	for(n=0;n<2000000;n++){
		if(p[n]=1){
			printf("%d",n);
		}
	}
	
	return 0;
}