/************************************************************* 
 * ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�
 * Edit by changmu
 *************************************************************/ 

void PrintMatrixInCircle(int **numbers, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	// �����Ҵ�ӡһ��
	for (int i = start; i <= endX; ++i) {
		int number = numbers[start][i];
		printNumber(number);
	}

	// ���ϵ��´�ӡ
	if (start < endY) {
		for (int i = start; i <= endY; ++i)
			printNumber(numbers[i][endX]);
	}

	// ���ҵ���
	if (endX > start && endY > start) {
		for (int i = endX - 1; i >= start; --i)
			printNumber(numbers[endY][i]);
	}

	// ��������
	if (endX > start && endY > start + 1) {
		for (int i = endY - 1; i > start; --i)
			printNumber(numbers[i][start]);
	}
}
