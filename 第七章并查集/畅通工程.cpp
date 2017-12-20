/************************************************************************************************************************************
Problem Description
某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。
省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。
问最少还需要建设多少条道路？
Input
测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；
随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 
注意:两个城市之间可以有多条道路相通,也就是说3 3 1 2 1 2 2 1 这种输入也是合法的 当N为0时，输入结束，该用例不被处理。 
Output
对每个测试用例，在1行里输出最少还需要建设的道路数目。
Sample Input
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
Sample Output
1
0
2
998
****************************************************************************************************************************************/
//简单并查集。通过合并后，判断总共有几个集合，需要的就是集合数 - 1。 总共有几个集合可以通过父节点是自己的节点数来判断。 
#include <iostream>
#define MAX 1001
using namespace std;

int set[MAX];

void initSet(int n)					// 初始化并查集，初始时每个元素的根节点都是自己，n为元素个数 
{
	for(int i = 1;i <= n; i++)
		set[i] = i;
}

int findSet(int index)				//寻找一个集合的根节点，一直循环到父节点为自己为止 
{
	while(set[index] != index)
		index = set[index];
	
	return index;	
}

void mergeSet(int a, int b)			//合并集合，如果两个集合的根节点不是同一个，则将其中一个集合的根节点设为另一个，完成合并 
{
	int fa = findSet(a);
	int fb = findSet(b);
	if(fa != fb)
		set[fa] = fb;
}

using namespace std;
int main()
{
	int n, m, count, a, b;
	cin >> n;
	while(n != 0)
	{
		count = -1;		//count以-1初始化，因为结果为集合数 - 1 
		initSet(n);		//初始化集合 
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			cin >> a >> b;
			mergeSet(a, b);		//合并a, b 
		}
		
		for(int i = 1; i <= n; i++)
		{
			if(set[i] == i)			//如果父节点是自己，则是一个集合 
				count++;
		}
		
		cout << count << endl;
		cin >> n;
	}
	return 0;
}
