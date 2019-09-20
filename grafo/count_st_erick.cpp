#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
 
using namespace std;
 
int N, M, bitmask;
 
ll pd[1<<19];
int vis[1<<19];
int val[19];
int check[19], out[19], in[19];
int mask;
 
ll solve(int x)
{
	if(x == mask)
		return 1;
	if(vis[x])
		return pd[x];
	vis[x] = 1;
	ll r = 0;
	for(int i = 0; i < N; i++)
		if(!(x & (1<<i)) && ((in[i] & x) == in[i]))
			r = (r + val[i] * solve(x | (1 << i))) % MOD;
	return pd[x] = r % MOD;
}
 
int dfs(int x)
{
	if(check[x])
		return 1;
	check[x] = 1;
	for(int j = 0, i = 1; i <= out[x]; j++, i <<= 1)
	{
		if(i&out[x])
			dfs(j);
	}
	return 0;
}
 
int has_cycle()
{
	for(int i = 0; i < N; i++)
	{
		if(!check[i])
		{
			if(dfs(i))
			{
				return 1;
			}
		}
	}
	return 0;
}
 
int main()
{
	int u, v;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &val[i]);
	mask = (1 << N) - 1;
	while(M--)
	{
		scanf("%d %d", &u, &v);
		u--, v--;
		out[u] |= 1 << v;
		in[v] |= 1 << u;
	}
	if(has_cycle())
		return !printf("0\n");
	printf("%I64d\n", solve(0));
	return 0;
}

