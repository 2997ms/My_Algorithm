#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

char test[1005];
double wor, sen, syl;//61 2 108

bool check2(char x)
{
	if (x == 'a' || x == 'e' || x == 'o' || x == 'u' || x == 'y' || x == 'i' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int check(char *x)
{
	int len = strlen(x);
	int i, res, start;
	if (x[0] == 'r')
	{
		i = 0;
	}
	while (!((x[len - 1] >= 'a'&&x[len - 1] <= 'z') || (x[len - 1] >= 'A'&&x[len - 1] <= 'Z')))
	{
		len--;
	}

	start = 0;
	while (!((x[start] >= 'a'&&x[start] <= 'z') || (x[start] >= 'A'&&x[start] <= 'Z')))
	{
		start++;
	}

	res = 0;
	if (len <= 3)
	{
		res++;
		return 1;
	}
	if (x[len - 2] == 'e'&&x[len - 1] == 's')
	{
		len = len - 2;
	}
	else if (x[len - 2] == 'e'&&x[len - 1] == 'd')
	{
		len = len - 2;
	}
	else if (x[len - 1] == 'e')
	{
		if (x[len - 2] != 'l')
		{
			len = len - 1;
		}
	}
	if (check2(x[0]))
	{
		res++;
	}
	for (i = 1; i < len; i++)
	{
		if (check2(x[i]) && !check2(x[i - 1]))
		{
			res++;
		}
	}

	return res;
}

int main()
{


	wor = 0;
	sen = 0;
	syl = 0;

	int len;
	char temp;
	double res;
	while (scanf("%s", test) != EOF)
	{
		wor++;
		len = strlen(test);
		
		temp = test[len - 1];
		if (temp == '.' || temp == '?' || temp == ':' || temp == ';' || temp == '!')
		{
			sen++;
		}
		syl += check(test);
	}
	res = 206.835 - 1.015*(wor / sen) - 84.6*(syl / wor);
	printf("%.2f\n", res);
	//system("pause");
	return 0;
}
