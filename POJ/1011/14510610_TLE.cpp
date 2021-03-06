#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num_s,sum,temp;
int stick[70];
bool visit[70];

bool dfs(int num,int length,int stick_st,int * stick,bool *visit)
{
	if(num==(sum/temp))
		return true;
	int i;
	int sample=-1;
	for(i=stick_st;i<=num_s;i++)
	{
		if(visit[i]||stick[i]==sample)continue;

		visit[i]=true;
		if(length+stick[i]<temp)
		{
			if(dfs(num,length+stick[i],i+1,stick,visit))
			{
				return true;
			}
			else
			{
				sample=stick[i];
			}
		}
		else if(length+stick[i]==temp)
		{
			if(dfs(num+1,0,1,stick,visit))
			{
				return true;
			}
			else
			{
				sample=stick[i];
			}
		}
		visit[i]=false;
	}
	return false;
}

bool cmp(const int a,const int b)
{
	return a>b;
}

int main()
{	
	int i;
	while(1)
	{
		scanf("%d",&num_s);
		if(num_s==0)
			break;

		sum=0;
		for(i=1;i<=num_s;i++)
		{
			scanf("%d",&stick[i]);
			visit[i]=false;
			sum += stick[i];
		}
		sort(stick+1,stick+1+num_s,cmp);

		for(temp=stick[1];temp<=sum;temp++)
		{
			if(sum%temp==0)
			{
				if(dfs(1,0,1,stick,visit))//第一个数代表当前完成第几根木棒了
					                      //第二个数代表当前已经完成的长度
						                  //第三个数代表木棒从第几个开始找起的
				{
					cout<<temp<<endl;
					break;
				}
			}
		}
	}
	return 0;
}

