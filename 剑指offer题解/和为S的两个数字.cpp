/************************************************************* 
 * ����һ����������������һ������S���������в�����������ʹ��
 * ���ǵĺ�������S��������ж�ԣ��������һ�Լ��ɡ�
 *************************************************************/ 
bool FindNumbersWithSum(int data[], int length, int sum, int *num1, int *num2)
{
	if (data == NULL || length < 2) return false;
	
	bool found = false;
	int *pHead = data;
	int *pTail = data + length - 1;
	while (pHead < pTail) {
		int currentSum = *pHead + *pTail;
		if (currentSum == sum) {
			*num1 = *pHead;
			*num2 = *pTail;
			found = true;
			break;
		} else if (currentSum < sum) ++pHead;
		else --pTail;
	}

	return found;
}
