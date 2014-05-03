//  [3/18/2014 Sjm]
/*
状态压缩DP ： 旅行商问题
分析 ：
（1）所有路线共有 (n-1)! 种，数值很大
（2）假设现在已经访问的顶点的集合（起点0当做还未访问过的顶点）为S，当前所在的顶点为 v,
	 用 dp[S][v] 表示从 v 出发访问剩余的所有顶点，最终回到顶点 0 的路径的权重总和的最小值，
	 由于从 v 出发可以移动到任意的一个节点 u(u不属于S),因此有如下递推式：
	 dp[V][0] = 0;
	 dp[S][v] = min{ dp[S ∪ {u}][u] + d(v, u) | u不属于S }
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 10, INF = 0x3f3f3f3f;

int n;
int d[MAX_N][MAX_N];   

int dp[1 << MAX_N][MAX_N]; // 记忆化搜索使用的数组

/*
// 已经访问过的节点集合为 S，当前位置为 v
int Rec(int S, int v) 
{ 
	if (dp[S][v] >= 0) return dp[S][v]; 

	// 已经访问过所有节点并刚回到 0 号点
	if ((1 << n) - 1 == S && 0 == v) return dp[S][v] = 0;

	int res = INF;
	for (int u = 0; u < n; u++)
		if (!(S >> u & 1)) res = min(res, Rec(S | 1 << u, u) + d[v][u]);
	return dp[S][v] = res;
}

void Solve()
{
	memset(dp, -1, sizeof(dp));
	printf("%d\n", Rec(0, 0));
}
*/
// 优化：
void Solve()
{
	// 用足够大的值初始化数组
	for (int S = 0; S < (1 << n); S++)
		fill(dp[S], dp[S] + n, INF);
	dp[(1 << n) - 1][0] = 0;
	// 根据递推式依次计算
	for (int S = (1 << n) - 2; S >= 0; S--)
		for (int v = 0; v < n; v++)
			for (int u = 0; u < n; u++)
				if (!(S >> u) & 1) dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + d[v][u]);
	printf("%d\n", dp[0][0]);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &d[i][j]);
	//system("pause");
	return 0;
}

