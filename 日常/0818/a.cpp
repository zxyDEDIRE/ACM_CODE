 #include <stdio.h> 
 int main()
{
	int n,len; int num[15];
	while(scanf("%d",&n)!=EOF)
	{	// 辗转相除法的实现
	    /*begin*/
        len=0;
        while(n)
        {
            num[++len]=n%2;
            n/=2;
        }
        for(int i=len;i>=1;i--)
            printf("%d",num[i]);
        printf("\n");

        /*end*/
	}
	return 0;
}