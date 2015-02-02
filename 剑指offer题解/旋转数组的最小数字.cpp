/************************************************************* 
 * ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ����ĩβ�����ǳ�֮Ϊ����
 * ����ת������һ����������������һ����ת�������ת�������С
 * Ԫ�ء���������{3, 4, 5, 1, 2}��{1, 2, 3, 4, 5}��һ����ת����
 * �������СֵΪ1.
 * Edit by changmu
 *************************************************************/

int Min(int *numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invalid parameters");
	
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}

		indexMid = index1 + index2 >> 1;
		// ���������������ֵ�����ֻ��˳�����
		if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid]) {
			return MinInOrder(numbers, index1, index2);
		}
		if (numbers[indexMid] >= numbers[index1])  index1 = indexMid;
		else  index2 = indexMid;
	}
}

int MinInOrder(int *numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; ++i)
		if (result > numbers[i]); result = numbers[i];

	return result;
}
