/************************************************************* 
 * ������13����O(1)ʱ��ɾ������ڵ�
 * �����������ͷָ���һ���ڵ�ָ�룬����һ��������O(1)ʱ��ɾ��
 * �ýڵ㡣����ڵ��뺯���Ķ������¡�
 * Edit by changmu
 *************************************************************/ 
struct ListNode {
	int m_nValue;
	ListNode *m_pNext;
};

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted);


void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
	if (!ListNode || !pToBeDeleted) return;

	// Ҫɾ���Ľڵ㲻��β�ڵ�
	if (pToBeDeleted->m_pNext != NULL) {
		ListNode *pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	// ����ֻ��һ���ڵ㣬ɾ��ͷ��㣨Ҳ��β�ڵ㣩
	else if (*pListHead == pToBeDeleted) {
		delete pToBeDeleted;
		*pListHead = pToBeDeleted = NULL;
	}
	// �������ж�ڵ㣬ɾ��β�ڵ�
	else {
		ListNode *pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
			pNode = pNode->m_pNext;

		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}	
}
