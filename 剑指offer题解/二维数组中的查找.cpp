/*
** ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/

/*
** ˼·���Ӿ������Ͻ�Ԫ��x���֣���������ֵy��xС����ôx�����оͿ����ų�������y��x����ôx�����оͿ����ų�������x==y���ҵ��ˡ�
*/

bool Find(int *matrix, int rows, int columns, int number) {
	bool found = false;

	if (matrix != NULL && rows && columns) {
		int row = 0, cloumn = columns - 1;

		while (row < rows && column >= 0) {
			if (matrix[row * cloumns + column] == number) {
				found = true; break;
			} else if (matrix[row * columns + column] > number)
				--column;
			else ++row;
		}
	}

	return found;
}

// via:changmu
