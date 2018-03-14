#include<stdio.h>
#include<stdlib.h>
//保存选项信息
int judge_two[] = { 2,3,0,1 };
int judge_three[] = { 3,6,2,4 };
int judge_four[][2] = { 1,5,2,7,1,9,6,10 };
int judge_five[] = { 8,4,9,7 };
int judge_six[][2] = { 2,4,1,6,3,10,5,9};
int judge_seven[] = { 2,1,0,3};
int judge_eight[] = { 7,5,2,10 };
int judge_nine[] = { 6,10,2,9 };
int judge_ten[] = { 3,2,4,1 };
bool solve(int s[])
{
	int num[4];
	for (int i = 0; i < 4; i++)
		num[i] = 0;
	//2
	if (s[5] != judge_two[s[2]])
	{
		return false;
	}
	//3
	int temp;
	int cnt = 0;
	for (int i = 0; i <= 3; i++)
	{
		if (s[3] != i)
		{
			cnt++;
			if (cnt == 1)
				temp = s[judge_three[i]];
			if (temp == s[judge_three[i]])
				continue;
			else
				return false;
		}
	}
	//4
	if (s[judge_four[s[4]][0]] != s[judge_four[s[4]][1]])
		return false;
	//5
	if (s[judge_five[s[5]]] != s[5])
		return false;
	//6
	if (!(s[judge_six[s[6]][0]] == s[8] && s[judge_six[s[6]][1]] == s[8]))
		return false;
	//7
	int min = 11, max = 0;//记录选项最少、最多分别出现的次数
	int node_min, node_max;//记录相对应的选项
	for (int i = 1; i <= 10; i++)
	{
		num[s[i]]++;
		if (num[s[i]] > max)
		{
			node_max = s[i];
			max = num[s[i]];
		}
	}
	min = 11;
	for(int i=0;i<4;i++)
		if (num[i] < min)
		{
			min = num[i];
			node_min = i;
		}
	if (node_min != judge_seven[s[7]])
		return false;
	//8
	if (abs(s[1] - s[judge_eight[s[8]]]) == 1)
		return false;
	//9
	if (s[1] == s[6] && s[judge_nine[s[9]]] == s[5] || s[1] != s[6] && s[judge_nine[s[9]]] != s[5])
		return false;
	//10
	if (judge_ten[s[10]] != max - min)
		return false;
	return true;
}
int main()
{
	/*
	 *  0-A
	 *  1-B
	 *  2-C
	 *  3-D
	 */
	int flag = 0;
	//回溯
	for(int i1=0;i1<=3;i1++)
		for (int i2 = 0; i2 <= 3; i2++)
			for (int i3 = 0; i3 <= 3; i3++)
				for (int i4 = 0; i4 <= 3; i4++)
					for (int i5 = 0; i5 <= 3; i5++)
					    for (int i6 = 0; i6 <= 3; i6++)
						    for (int i7 = 0; i7 <= 3; i7++)
							    for (int i8 = 0; i8 <= 3; i8++)
									for (int i9 = 0; i9 <= 3; i9++)
										for (int i0 = 0; i0 <= 3; i0++)
										{
											int answer[11] = { 0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i0 };
											if (solve(answer))//输出所有结果
											{
												for (int i = 1; i <= 10; i++)
												{
													printf("第%d题：%c\n", i, 'A' + answer[i]);
													flag = 1;
												}
											}
										}
	if (!flag)//无解
		printf("No Solution");
	return 0;
}