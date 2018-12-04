/*
优选法调普通PID Kp,Ki,Kd参数，调模糊PID模糊值域

*/


#include <stdio.h>

#define      YES               1
#define      NO                1
#define      back_ratio        0.618     
#define      head_ratio        0.382





int main()
{
	float range[2] =      { 0.0f,0.0f };       //调参的范围
	float scale[2] =      { 0.0f,0.0f };       //两个比例值
	float Last_scale[2] = { 0.0f,0.0f };       //上一次的两个比例值
	float Result[4] =     { 0.0f,0.0f,0.0f,0.0f };
	printf("输入调试范围\n");
	printf("range[0] = ");
	scanf_s("%f", &range[0]);
	printf(",range[1] = ");
	scanf_s("%f", &range[1]);
	printf("\n");
	while (1)
	{




	}





}



