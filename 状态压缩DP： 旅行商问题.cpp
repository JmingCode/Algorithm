//  [3/18/2014 Sjm]
/*
״̬ѹ��DP �� ����������
���� ��
��1������·�߹��� (n-1)! �֣���ֵ�ܴ�
��2�����������Ѿ����ʵĶ���ļ��ϣ����0������δ���ʹ��Ķ��㣩ΪS����ǰ���ڵĶ���Ϊ v,
	 �� dp[S][v] ��ʾ�� v ��������ʣ������ж��㣬���ջص����� 0 ��·����Ȩ���ܺ͵���Сֵ��
	 ���ڴ� v ���������ƶ��������һ���ڵ� u(u������S),��������µ���ʽ��
	 dp[V][0] = 0;
	 dp[S][v] = min{ dp[S �� {u}][u] + d(v, u) | u������S }
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

int dp[1 << MAX_N][MAX_N]; // ���仯����ʹ�õ�����

/*
// �Ѿ����ʹ��Ľڵ㼯��Ϊ S����ǰλ��Ϊ v
int Rec(int S, int v) 
{ 
	if (dp[S][v] >= 0) return dp[S][v]; 

	// �Ѿ����ʹ����нڵ㲢�ջص� 0 �ŵ�
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
// �Ż���
void Solve()
{
	// ���㹻���ֵ��ʼ������
	for (int S = 0; S < (1 << n); S++)
		fill(dp[S], dp[S] + n, INF);
	dp[(1 << n) - 1][0] = 0;
	// ���ݵ���ʽ���μ���
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

