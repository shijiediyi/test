#include <stdio.h>
#include <iostream>


/*Kp模糊子集*/
float Code_KpRule[4] = { 0.0f,-2.0f,-4.0f,-6.0f };

float Postive_Fuzzy_Kp(float e, float ec,int change)
{
	//输出值
	float Kp_out = 0.0;
	int num = 0, pe = 0, pec = 0;
	//误差e的模糊论域
	float eRule[7] = { 24.0f,20.0f,16.0f,12.0f,8.0f,4.0f,0.0f };;
	//误差ec的模糊论域
	float ecRule[7] = { 3.6f,2.4f,1.2f,0.0f,-1.2f,-2.4f,-3.6f };
	//误差e的隶属度程度
	float eFuzzy[2] = { 0.0f,0.0f };
	//误差ec的隶属度程度
	float ecFuzzy[2] = { 0.0f,0.0f };
	//Kp隶属度程度
	float KpFuzzy[4] = { 0.0f,0.0f,0.0f,0.0f };
	/********误差e隶属度描述********/
	if (e >= eRule[0])
	{
		eFuzzy[0] = 1.0f;
		pe = 0;
	}
	else if (eRule[0] > e && e >= eRule[1])
	{
		eFuzzy[0] = (eRule[0] - e) / (eRule[0] - eRule[1]);
		pe = 0;
	}
	else if (eRule[1] > e && e >= eRule[2])
	{
		eFuzzy[0] = (eRule[1] - e) / (eRule[1] - eRule[2]);
		pe = 1;
	}
	else if (eRule[2] > e && e >= eRule[3])
	{
		eFuzzy[0] = (eRule[2] - e) / (eRule[2] - eRule[3]);
		pe = 2;
	}
	else if (eRule[3] > e && e >= eRule[4])
	{
		eFuzzy[0] = (eRule[3] - e) / (eRule[3] - eRule[4]);
		pe = 3;
	}
	else if (eRule[4] > e && e >= eRule[5])
	{
		eFuzzy[0] = (eRule[4] - e) / (eRule[4] - eRule[5]);
		pe = 4;
	}
	else if (eRule[5] > e && e >= eRule[6])
	{
		eFuzzy[0] = (eRule[5] - e) / (eRule[5] - eRule[6]);
		pe = 5;
	}
	eFuzzy[1] = 1 - eFuzzy[0];

	/********误差变化率ec隶属度描述********/

	if (ec > ecRule[0])
	{
		ecFuzzy[0] = 1.0f;
		pec = 0;
	}
	else if (ecRule[0] > ec && ec > ecRule[1])
	{
		ecFuzzy[0] = (ecRule[0] - ec) / (ecRule[0] - ecRule[1]);
		pec = 0;
	}
	else if (ecRule[1] > ec && ec > ecRule[2])
	{
		ecFuzzy[0] = (ecRule[1] - ec) / (ecRule[1] - ecRule[2]);
		pec = 1;
	}
	else if (ecRule[2] > ec && ec > ecRule[3])
	{
		ecFuzzy[0] = (ecRule[2] - ec) / (ecRule[2] - ecRule[3]);
		pec = 2;
	}
	else if (ecRule[3] > ec && ec > ecRule[4])
	{
		ecFuzzy[0] = (ecRule[3] - ec) / (ecRule[3] - ecRule[4]);
		pec = 3;
	}
	else if (ecRule[4] > ec && ec > ecRule[5])
	{
		ecFuzzy[0] = (ecRule[4] - ec) / (ecRule[4] - ecRule[5]);
		pec = 4;
	}
	else if (ecRule[5] > ec && ec > ecRule[6])
	{
		ecFuzzy[0] = (ecRule[5] - ec) / (ecRule[5] - ecRule[6]);
		pec = 5;
	}
	ecFuzzy[1] = 1 - ecFuzzy[0];
	/*
	int KpRule[7][7] =
	{
		3,3,3,3,3,3,3,
		2,2,2,2,1,2,2,
		1,1,1,1,1,1,1,
		1,1,0,1,0,1,1,
		0,0,1,0,0,1,0,
		0,1,0,1,0,0,2,
		3,3,3,3,3,3,3
	};
	*/
	int KpRule[7][7] =
	{
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,
		0,0,0,1,0,0,0,
		0,0,2,2,2,0,0,
		0,3,3,3,3,3,0,

	};
	/********   查询模糊规则表   ********/
	if (change == 1)
	{
		printf("pe = %d,pec = %d\n", pe, pec);
		printf("eFuzzy[0] = %f, eFuzzy[1] = %f,ecFuzzy[0] = %f,ecFuzzy[1] = %f\n", eFuzzy[0], eFuzzy[1], ecFuzzy[0], ecFuzzy[1]);
	}
	num = KpRule[pe][pec];
	if (change == 1)
	printf("num = %d,", num);
	KpFuzzy[num] += ecFuzzy[0] * eFuzzy[0];
	if (change == 1)
	num = KpRule[pe][pec + 1];
	if (change == 1)
	printf("num = %d,", num);
	KpFuzzy[num] += ecFuzzy[0] * eFuzzy[1];
	num = KpRule[pe + 1][pec];
	if (change == 1)
	printf("num = %d,", num);
	KpFuzzy[num] += ecFuzzy[1] * eFuzzy[0];
	num = KpRule[pe + 1][pec + 1];
	if (change == 1)
	printf("num = %d\n", num);
	KpFuzzy[num] += ecFuzzy[1] * eFuzzy[1];
	if (change == 1)
	printf("KpFuzzy[0] = %f, KpFuzzy[1] = %f,KpFuzzy[2] = %f,KpFuzzy[3] = %f\n", KpFuzzy[0], KpFuzzy[1], KpFuzzy[2], KpFuzzy[3]);


	/**********  加权平均数解模糊  ********/
	Kp_out = Code_KpRule[0] * KpFuzzy[0] + Code_KpRule[1] * KpFuzzy[1] + Code_KpRule[2] * KpFuzzy[2] + Code_KpRule[3] * KpFuzzy[3];

	return Kp_out;
}

float Negative_Fuzzy_Kp(float e, float ec,int change)
{
	//输出值
	float Kp_out = 0.0;
	int num = 0, pe = 0, pec = 0;
	//误差e的模糊论域
	float eRule[7] = { -24.0f,-20.0f,-16.0f,-12.0f,-8.0f,-4.0f,0.0f };
	//误差ec的模糊论域
	float ecRule[7] = { 3.0f,2.0f,1.0f,0.0f,-1.0f,-2.0f,-3.0f };
	//误差e的隶属度程度
	float eFuzzy[2] = { 0.0f,0.0f };
	//误差ec的隶属度程度
	float ecFuzzy[2] = { 0.0f,0.0f };
	//Kp隶属度程度
	float KpFuzzy[4] = { 0.0f,0.0f,0.0f,0.0f };
	/********误差e隶属度描述********/
	if (e <= eRule[0])
	{
		eFuzzy[0] = 1.0f;
		pe = 0;
	}
	else if (eRule[0] < e && e <= eRule[1])
	{
		eFuzzy[0] = (eRule[0] - e) / (eRule[0] - eRule[1]);
		pe = 0;
	}
	else if (eRule[1] < e && e <= eRule[2])
	{
		eFuzzy[0] = (eRule[1] - e) / (eRule[1] - eRule[2]);
		pe = 1;
	}
	else if (eRule[2] < e && e <= eRule[3])
	{
		eFuzzy[0] = (eRule[2] - e) / (eRule[2] - eRule[3]);
		pe = 2;
	}
	else if (eRule[3] < e && e <= eRule[4])
	{
		eFuzzy[0] = (eRule[3] - e) / (eRule[3] - eRule[4]);
		pe = 3;
	}
	else if (eRule[4] < e && e <= eRule[5])
	{
		eFuzzy[0] = (eRule[4] - e) / (eRule[4] - eRule[5]);
		pe = 4;
	}
	else if (eRule[5] < e && e <= eRule[6])
	{
		eFuzzy[0] = (eRule[5] - e) / (eRule[5] - eRule[6]);
		pe = 5;
	}
	eFuzzy[1] = 1 - eFuzzy[0];



	/********误差变化率ec隶属度描述********/
	if (ec >= ecRule[0])
	{
		ecFuzzy[0] = 1.0f;
		pec = 0;
	}
	else if (ecRule[0] > ec && ec >= ecRule[1])
	{
		ecFuzzy[0] = (ecRule[0] - ec) / (ecRule[0] - ecRule[1]);
		pec = 0;
	}
	else if (ecRule[1] > ec && ec >= ecRule[2])
	{
		ecFuzzy[0] = (ecRule[1] - ec) / (ecRule[1] - ecRule[2]);
		pec = 1;
	}
	else if (ecRule[2] > ec && ec >= ecRule[3])
	{
		ecFuzzy[0] = (ecRule[2] - ec) / (ecRule[2] - ecRule[3]);
		pec = 2;
	}
	else if (ecRule[3] > ec && ec >= ecRule[4])
	{
		ecFuzzy[0] = (ecRule[3] - ec) / (ecRule[3] - ecRule[4]);
		pec = 3;
	}
	else if (ecRule[4] > ec && ec >= ecRule[5])
	{
		ecFuzzy[0] = (ecRule[4] - ec) / (ecRule[4] - ecRule[5]);
		pec = 4;
	}
	else if (ecRule[5] > ec && ec >= ecRule[6])
	{
		ecFuzzy[0] = (ecRule[5] - ec) / (ecRule[5] - ecRule[6]);
		pec = 5;
	}
	else
	{
		ecFuzzy[0] = 0.0f;
		pec = 5;
	}
	ecFuzzy[1] = 1 - ecFuzzy[0];

	/*int KpRule[7][7] =
	{
		3,3,3,3,3,3,3,
		2,2,3,3,3,2,2,
		2,2,2,3,2,2,2,
		2,2,2,2,2,2,2,
		0,0,1,2,1,0,0,
		1,1,2,1,2,1,1,
		3,2,3,2,3,2,3
	};
	*/
	int KpRule[7][7] =
	{
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,
		0,0,0,1,0,0,0,
		0,0,2,2,2,0,0,
		0,3,3,3,3,3,0,
	};

	/********   查询模糊规则表   ********/
	if (change == 1)
	{
		printf("pe = %d,pec = %d\n", pe, pec);
		printf("eFuzzy[0] = %f, eFuzzy[1] = %f,ecFuzzy[0] = %f,ecFuzzy[1] = %f\n", eFuzzy[0], eFuzzy[1], ecFuzzy[0], ecFuzzy[1]);
	}
	num = KpRule[pe][pec];
	if(change == 1)
	printf("num = %d,", num);
	KpFuzzy[num] += ecFuzzy[0] * eFuzzy[0];
	num = KpRule[pe][pec + 1];
	if (change == 1)
	printf("num = %d,", num);
	KpFuzzy[num] += ecFuzzy[0] * eFuzzy[1];
	num = KpRule[pe + 1][pec];
	if (change == 1)
	printf("num = %d,", num);
	KpFuzzy[num] += ecFuzzy[1] * eFuzzy[0];
	num = KpRule[pe + 1][pec + 1];
	if (change == 1)
	printf("num = %d\n", num);
	KpFuzzy[num] += ecFuzzy[1] * eFuzzy[1];
	if (change == 1)
	printf("KpFuzzy[0] = %f, KpFuzzy[1] = %f,KpFuzzy[2] = %f,KpFuzzy[3] = %f\n", KpFuzzy[0], KpFuzzy[1], KpFuzzy[2], KpFuzzy[3]);


	/**********  加权平均数解模糊  ********/
	Kp_out = Code_KpRule[0] * KpFuzzy[0] + Code_KpRule[1] * KpFuzzy[1] + Code_KpRule[2] * KpFuzzy[2] + Code_KpRule[3] * KpFuzzy[3];

	return Kp_out;
}



float e = 24, ec = 0.0f;
float Out = 0.0f;
int main()
{

	int change;
	printf("是否查看全部数据：");
	scanf_s("%d", &change);
	while (1)
	{
		printf("e = %f  ,   ec = %f\n", e, ec);
		if (e > 0)
		{
			Out = Postive_Fuzzy_Kp(e, ec,change);
		}
		if (e < 0)
		{
			Out = Negative_Fuzzy_Kp(e, ec,change);
		}

		printf("Kp = %f\n", Out);
		if (e == -24)
			break;
		e -= 1;
	}
	system("pause");
	return 0;
}
