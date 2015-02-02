/************************************************************* 
 * ���������������У���һ�����б�ʾջ��ѹ�����У����жϵڶ���
 * �����Ƿ�Ϊ��ջ�ĵ������С�����ѹ��ջ���������ֶ�����ȡ�
 * ����12345��ѹջ���У�45321��һ���Ϸ��������У�43512ȴ���ǡ�
 * Edit by changmu
 *************************************************************/ 

bool IsPopOrder(const int *pPush, const int *pPop, int nLength)
{
	if (pPop == NULL || pPush == NULL || nLength <= 0)
		return false;

	bool result = false;
	const int *pNextPush = pPush;
	const int *pNextPop = pPop;
	stack<int> stackData;

	while (pNextPop - pPop < nLength) {
		while (stackData.empty() || stackData.top() != *pNextPop) {
			if (pNextPop - pPop == nLength) break;
			stackData.push(*pNextPush++);
		}

		if (stackData.top() != *pNextPop) break;
		stackData.pop();
		++pNextPop;
	}

	return stackData.empty();
}
