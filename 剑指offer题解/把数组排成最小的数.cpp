/************************************************************* 
 * ����һ�����������飬����������������ƴ�������ų�һ��������ӡ
 * ��ƴ�ӳ���������������С��һ����
 * Via: changmu
 *************************************************************/ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int g_MaxNumberLength = 10;
char *g_String1 = new char[g_MaxNumberLength << 1 | 1];
char *g_String2 = new char[g_MaxNumberLength << 1 | 1];

void PrintMinNumber(int *numbers, int length)
{
	if (numbers == NULL || length <= 0)
		return;

	char **strNumbers = (char **)(new int[length]); // ����һ��װָ�������
	for (int i = 0; i < length; ++i) {
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}
	int compare(const void *, const void *);
	qsort(strNumbers, length, sizeof(char *), compare);

	for (int i = 0; i < length; ++i) {
		printf("%s", strNumbers[i]);
		delete[] strNumbers[i];
	}
	printf("\n");
	
	delete[] strNumbers;
}

int compare(const void *string1, const void *string2)
{
	strcpy(g_String1, *(char **)string1);
	strcat(g_String1, *(char **)string2);

	strcpy(g_String2, *(char **)string2);
	strcat(g_String2, *(char **)string1);

	return strcmp(g_String1, g_String2);
}

int main()
{
	int a[] = {3, 32, 321};
	PrintMinNumber(a, 3);
	return 0;
}
