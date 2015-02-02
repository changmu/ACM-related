/************************************************************* 
 * ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������
 * ������򷵻�true�����򷵻�false�������������ظ�Ԫ�ء�
 * Edit by changmu
 *************************************************************/ 

bool VerifySquenceOfBST(int *sequence, int length)
{
	if (sequence == NULL || length <= 0)
		return false;

	int root = sequence[length - 1];
	
	int i = 0;
	for ( ; i < length - 1; ++i)
		if (sequence[i] > sequence[root])
			break;

	int j = i;
	for ( ; j < length - 1; ++j)
		if (sequence[j] < root) return false;

	bool left = true;
	if (i) left = VerifySquenceOfBST(sequence, i);

	bool right = true;
	if (length - 1 > i)
		right = VerifySquenceOfBST(sequence + i, length - i - 1);

	return left && right;
}
