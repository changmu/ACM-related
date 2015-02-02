/************************************************************* 
 * ������16����ת����
 * ����һ������������һ�������ͷ��㣬��ת�����������ת��
 * �����ͷ��㡣
 * Edit by changmu
 *************************************************************/ 
struct ListNode {
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *ReverseList(ListNode *pHead)
{
	if (pHead == NULL) return NULL;

	ListNode *pReversedHead = NULL;
	ListNode *pNode = pHead;
	ListNode *pPrev = NULL;
	while (pNode != NULL) {
		ListNode *pNext = pNode->m_pNext;
		if (pNext == NULL) pReversedHead = pNode;
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}

// ���������ݹ�ʵ��
ListNode *ReverseList(ListNode *pHead)
{
	if (pHead == NULL) return NULL;
	return ReverseListCore(NULL, pHead);
}

ListNode *ReverseListCore(ListNode *pPrev, ListNode *pNode)
{
	if (pNode == NULL) return pPrev;
	ListNode *pReversedHead = ReverseList(pNode, pNode->m_pNext);
	pNode->m_pNext = pPrev;
	return pReversedHead;
}
