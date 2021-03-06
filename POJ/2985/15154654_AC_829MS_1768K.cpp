#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>;
#include <set>
#include <map>
using namespace std;

#define INF 0x3fffffff
typedef long long ll;

const ll mod = 1e9 + 7;
const int maxn = 200005;

int n, m;
int fa[maxn], num[maxn], ans[maxn];

int lowbit(int x)
{
	return (x&(-x));
}

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
	fa[x] = y;
}

void add(int x, int y)
{
	while (x <= n)
	{
		ans[x] += y;
		x += lowbit(x);
	}
}

int getsum(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += ans[x];
		x -= lowbit(x);
	}
	return res;
}

void solve()
{
	int i, u, v, k, oper, group_n;
	int le, ri, mid;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		fa[i] = i;
		num[i] = 1;
	}
	add(1, n);
	group_n = n;
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &oper);
		if (oper == 1)
		{
			scanf("%d", &k);
			k = group_n - k + 1;
			le = 1; ri = n;

			while (le < ri)
			{
				mid = (le + ri) >> 1;
				if (getsum(mid) >= k)
					ri = mid;
				else
					le = mid + 1;
			}
			printf("%d\n", ri);
		}
		else
		{
			scanf("%d%d", &u, &v);
			u = find(u);
			v = find(v);
			if (u == v)continue;
			merge(u, v);
			add(num[u], -1);
			add(num[v], -1);
			
			num[v] = num[u] + num[v];
			add(num[v], 1);
			group_n--;
		}
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	solve();
	//system("pause");
	return 0;
}