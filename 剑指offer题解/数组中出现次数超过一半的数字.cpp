/************************************************************* 
 * ��Ŀ����������һ�������ֵĴ����������鳤�ȵ�һ�룬���ҳ����
 * ���֡�
 *************************************************************/ 

bool g_InputInvalid = false;

int MoreThanHalfNum(int *numbers, int length)
{
	if (numbers == NULL && length <= 0) {
		g_InputInvalid = true;
		return 0;
	}

	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; ++i) {
		if (times == 0) {
			result = numbers[i];
			++times;
		} else if (numbers[i] == result)
			++times;
		else --times;
	}

	if (!CheckMoreThanHalf(numbers, length, result))
		return 0;

	return result;
}

bool CheckMoreThanHalf(int *numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
		if (numbers[i] == number) ++times;

	return times * 2 > length;
}
