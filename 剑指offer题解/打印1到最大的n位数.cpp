/************************************************************* 
 * ������12����ӡ1������nλ��
 * ��������n����˳���ӡ����1������nλʮ����������������3��
 * ���ӡ1��2��3...999.
 *************************************************************/ 

/* �ǵݹ�д�� */
void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0) return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
		PrintNumber(number);

	delete []number;
}

bool Increment(char *number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	++number[nLength - 1];
	for (int i = nLength - 1; i >= 0; --i) {
		int nSum = number[i] - '0' + nTakeOver;
		
		if (nSum > 9) {
			if (i == 0) isOverflow = true;
			else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		} else break;
	}

	return isOverflow;
}

void PrintNumber(char *number) 
{
	int head = 0;

	while (number[head] == '0') ++head;
	puts(number + head);
}

/* �ݹ�д�� */
void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0) return;

	char *number = new char[n + 1];
	number[n] = '\0';

	Print1ToMaxOfNDigitsRecursively(number, 0, n);

	delete []number;
}

void Print1ToMaxOfNDigitsRecursively(char *number, int index, int n)
{
	if (index == n) {
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i) {
		number[i] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, index + 1, n);
	}
}
