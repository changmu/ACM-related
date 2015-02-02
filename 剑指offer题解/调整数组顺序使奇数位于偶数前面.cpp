/************************************************************* 
 * ������14����������˳��ʹ����λ��ż��ǰ��
 * ����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ��
 * ��������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
 * Edit by changmu
 *************************************************************/ 

void ReorderOddEven(int *pData, int length)
{
	Reorder(pData, length, isOdd);
}

void Reorder(int *pData, int length, bool (*fun)(int))
{
	if (pData == NULL || length <= 0) return;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd) {
		while (pBegin < pEnd && func(*pBegin)) ++pBegin;
		while (pBegin < pEnd && !func(*pEnd)) --pEnd;

		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isOdd(int n)
{
	return n & 0x1;
}
