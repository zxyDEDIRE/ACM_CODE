
import java.math.BigInteger;
import java.util.*;

class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int T;
		T=in.nextInt();
		for(int i=1;i<=T;i++)
		{
			BigInteger n=in.nextBigInteger();
			BigInteger a=new BigInteger("2");
			BigInteger b=new BigInteger("4");
			BigInteger f=new BigInteger("4");
			BigInteger now=b;
			while(now.compareTo(n)<0)
			{
				now=f.multiply(b).subtract(a);
				a=b;
				b=now;
			}
			System.out.println(b);
		}
	}
}
/*
4x=x+1+x-1
*/