#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int Num[20], NumMax, OperatorLength, NumCount; //Num数组存放算数，NumMax为算数最大值，OperatorLength为算式的长度	
	int  n, z = 0;
	int OperatorNum;//运算符个数
	int IntIndex1, IntIndex2;  //int型算数的位置
	int  FloatIndex1, FloatIndex2; //Float型算数的位置
	char Operator[6], OperatorTerm;//b[]为运算符存储数组
	float FloatNum1, FloatNum2;
	int FileFlag = 2, FloatFlag;
	printf("请输入你要定制的题目数量:\n");
	scanf_s("%d", &NumCount);
	printf("请输入运算数的运算范围:\n");
	scanf_s("%d", &NumMax);
	printf("请输入你所需要的运算符个数:\n");
	scanf_s("%d", &OperatorNum);
	printf("请输入你要输入的运算符:\n");
	for (int OperatorI = 0; OperatorI < OperatorNum; OperatorI++) {
		cin >> Operator[OperatorI];
	}
	srand((unsigned)time(NULL));
	printf("如果使用小数请输入1，否则输入2\n");
	scanf_s("%d", &FloatFlag);
	printf("请选择是否将结果存入到文档中（1代表是，2代表否）\n");
	scanf_s("%d", &FileFlag);
	if (FileFlag == 1) {
		printf("存入文档的地址为: D:\\C.txt\n");
	}
	FILE *fp = fopen("D:\\C.txt", "a+");
	for (int t = 0; t < NumCount; t++)
	{
		char buffer[50];
		z = 0;
		OperatorLength = rand() % 7;//每条算式的长度
		if (OperatorLength <= 2)
			OperatorLength = 3;

		for (int i = 0; i <= OperatorLength; i++)
		{

			Num[i] = rand() % NumMax + 1;
		}
		int j = 0;
		IntIndex1 = rand() % OperatorLength; if (IntIndex1 >= OperatorLength - 2)IntIndex1 = IntIndex1 - 2; if (IntIndex1 < 0)IntIndex1 = 0;
		IntIndex2 = rand() % OperatorLength; if (IntIndex2 <= IntIndex1 + 2)IntIndex2 = IntIndex1 + 2;
		if (IntIndex1 == 0 && IntIndex2 >= OperatorLength - 1)
			IntIndex1 = IntIndex1 + 1;
		FloatNum1 = (float)rand() / RAND_MAX * NumMax;
		FloatNum2 = (float)rand() / RAND_MAX * NumMax;
		FloatIndex1 = rand() % OperatorLength - 1;
		FloatIndex2 = rand() % OperatorLength - 1;
		for (int i = 0; i < OperatorLength - 1; i++)
		{
			if (i == IntIndex1) {
				printf("(");
				fprintf(fp, "%c", '(');
			}
			if (i == IntIndex2)
			{
				printf("%d", Num[i]);
				fprintf(fp, "%d", Num[i]);
				printf(")");
				fprintf(fp, "%c", ')');
				printf("%c", Operator[j]);
				fprintf(fp, "%c", Operator[j]);
				z = 1;
				i++;
				j++;
				if (j == OperatorNum)j = 0;
			}
			if (FloatFlag == 1 && i == FloatIndex1)
			{
				printf("%.2f%c", FloatNum1, Operator[j]);
				fprintf(fp, "%.2f", FloatNum1);
				fprintf(fp, "%c", Operator[j]);
				j++;
				if (j == OperatorNum)j = 0;
				i++;
				if (i == IntIndex1) {
					printf("(");
					fprintf(fp, "%c", '(');
				}
				if (IntIndex2 == i)
				{
					printf("%d", Num[i]);
					fprintf(fp, "%d", Num[i]);
					printf(")");
					fprintf(fp, "%c", ')');
					printf("%c", Operator[j]);
					fprintf(fp, "%c", Operator[j]);
					z = 1;
					i++;
					j++;
					if (j == OperatorNum)j = 0;
				}
			}

			if (FloatFlag == 1 && i == FloatIndex2)
			{
				printf("%.2f%c", FloatNum2, Operator[j]);
				fprintf(fp, "%.2f", FloatNum2);
				fprintf(fp, "%c", Operator[j]);
				j++;
				if (j == OperatorNum)j = 0;
				i++;
				if (i == IntIndex1) {
					printf("(");
					fprintf(fp, "%c", '(');
				}
				if (IntIndex2 == i)
				{
					printf("%d", Num[i]);
					fprintf(fp, "%d", Num[i]);
					printf(")");
					fprintf(fp, "%c", ')');
					printf("%c", Operator[j]);
					fprintf(fp, "%c", Operator[j]);
					z = 1;
					i++;
					j++;
					if (j == OperatorNum)j = 1;
				}
			}
			printf("%d%c", Num[i], Operator[j]);
			fprintf(fp, "%d", Num[i]);
			fprintf(fp, "%c", Operator[j]);
			j++;
			if (j == OperatorNum)j = 0;
		}

		if (z == 0 && IntIndex2 >= OperatorLength - 1) {
			printf("%d)=\n", Num[OperatorLength]);
			fprintf(fp, "%d", Num[OperatorLength]);
			fprintf(fp, "%c", ')');
			fprintf(fp, "%c", '=');
		}
		else {
			printf("%d=\n", Num[OperatorLength]);
			fprintf(fp, "%d", Num[OperatorLength]);
			fprintf(fp, "%c", '=');
		}
		n = rand() % OperatorNum;
		OperatorTerm = Operator[n];
		Operator[n] = Operator[1];
		Operator[1] = OperatorTerm;

		fprintf(fp, "\n");
	}
	fclose(fp);

	return 0;
}