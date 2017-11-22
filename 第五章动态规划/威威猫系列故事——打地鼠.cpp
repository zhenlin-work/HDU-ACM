/**************************************************************************************************************************************
Problem Description
威威猫最近不务正业，每天沉迷于游戏“打地鼠”。
每当朋友们劝他别太着迷游戏，应该好好工作的时候，他总是说，我是威威猫，猫打老鼠就是我的工作！
无话可说...
我们知道，打地鼠是一款经典小游戏，规则很简单：每隔一个时间段就会从地下冒出一只或多只地鼠，玩游戏的人要做的就是打地鼠.
假设：
1、每一个时刻我们只能打一只地鼠，并且打完以后该时刻出现的所有地鼠都会立刻消失；
2、老鼠出现的位置在一条直线上，如果上一个时刻我们在x1位置打地鼠，下一个时刻我们在x2位置打地鼠，那么，此时我们消耗的能量为abs( x1 - x2 )；
3、打第一只地鼠无能量消耗。
现在，我们知道每个时刻所有冒出地面的地鼠位置，若在每个时刻都要打到一只地鼠，请计算最小需要消耗多少能量。
Input
输入数据包含多组测试用例； 每组数据的第一行是2个正整数N和K（1 <= N <= 20, 1 <= K <= 10 )，
表示有N个时刻，每个时刻有K只地鼠冒出地面； 接下来的N行，每行表示一个时刻K只地鼠出现的坐标（坐标均为正整数，且<=500）。
Output
请计算并输出最小需要消耗的能量，每组数据输出一行。
Sample Input
2 2
1 10
4 9
3 5
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
Sample Output
1
1
*********************************************************************************************************************************************/
//动态规划。和数塔问题类似。从最后时刻往前推，每次算出当前时刻之后的最小能量消耗。状态转移方程即为 	dp[i][j] = dp[i + 1][min] + abs(position[i][j] - position[i + 1][min]);
//比如倒数第二时刻开始，每个点的最小能量即是计算当前点和最后时刻的每个点的距离取最小值。
//倒数第三时刻每个点的最小能量即是倒数第二时刻的点的能量 加上 当前时刻到倒数第二时刻的点的距离  ，取最小值
//以此类推，一直到第一时刻。在所有第一时刻里取最小值即可。 
#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	int position[21][11];	//n个时刻k只地鼠 
	int dp[21][11];	//记录能量 
	int n, k;
	int min;
	while(cin >> n >> k)
	{
		fill(dp[0], dp[0] + 21 * 11, 0); 
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= k; j++)
			{
				cin >> position[i][j]; 
			}
		}	
		
		for(int i = n - 1; i >= 1; i--)	//倒数第二个时刻开始往前计算 
		{
			for(int j = 1; j <= k; j++)
			{
				min = 1;
				for(int l = 2; l <= k; l++)
				{
					if(dp[i + 1][l] + abs(position[i][j] - position[i + 1][l]) < dp[i + 1][min] + abs(position[i][j] - position[i + 1][min]))
						min = l; 	
				}
				dp[i][j] = dp[i + 1][min] + abs(position[i][j] - position[i + 1][min]);
			}
		}
		
		min = dp[1][1]; 
		for(int j = 2; j <= k; j++)
		{
			if(dp[1][j] < min)
				min = dp[1][j];
		}
		
		cout << min << endl;
		
	} 
	
	 
	return 0;	
} 
