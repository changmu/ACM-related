/************************************************************* 
 * ���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ���
 * ������A~~KΪ1~~13����С����Ϊ0.
 *************************************************************/ 
bool IsContinuous(int *numbers, int length)
{
	if (numbers == NULL || length != 5)
		return false;

	int hashTable[14] = {0};
	int maxNum = 0;
	int minNum = 13;

	for (int i = 0; i < length; ++i) {
		if (numbers[i] != 0 && ++hashTable[numbers[i]] == 2)
			return false;
		else if (numbers[i] > maxNum)
			maxNum = numbers[i];
		else if (numbers[i] != 0 && numbers[i] < minNum)
			minNum = numbers[i];

		if (maxNum - minNum > 4) return false;
	}

	return true;
}
