#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_prime(int prime)
{    int i;
	for(i=2;i<=sqrt(prime);i++)
	{
		if(prime%i==0)
		{
			return 0;
		}
	}
	return 1;
}
main()
{
	int count=0,sum=0,prime=2,currentprime,test;
    scanf("%d",&test);
	   getchar();
	while(test!=0)
	{
		if(is_prime(test))
	   
			count++;
		
		currentprime=prime;
    
		while(currentprime<test) 
		{   
			prime=currentprime;              
			
			while(prime<test)
			{
              if(is_prime(prime))
			  {
               sum=prime+sum;
			  }
	          if(sum==test)
			  {
               count++;
               break;
			  }
			  if(prime!=2)
		        prime+=2;
			  else
				  prime++;
			  while(!is_prime(prime))
		         prime+=2;
			}
            if(currentprime!=2)
		      currentprime+=2;
		      else
		      currentprime++;
		while(!is_prime(currentprime))
		      currentprime+=2;
			sum=0;
		}
	   printf("%d\n",count);
	   scanf("%d",&test);
	   getchar();
	   prime=2;
	   sum=0;
	   count=0;
     }
     return 0;
}