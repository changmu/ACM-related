/************************************************************* 
 * ʵ�ֺ���ComplexListNode *Clone(ComplexListNode *pHead);����
 * һ����������ÿ���ڵ������һ��m_pNextָ��ָ����һ���ڵ���
 * ����һ��m_pSiblingָ�������е�����ڵ����NULL��
 * Edit by changmu
 *************************************************************/ 
struct ComplexListNode {
	int m_nValue;
	ComplexListNode *m_pNext;
	ComplexListNode *m_pSibling;
};

void CloneNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode *pClone = new ComplexListNode();
		pClone->m_nValue = pNode->m_nValue;
		pClone->m_pNext = pNode->m_pNext;
		pClone->m_pSibling = NULL;

		pNode->m_pNext = pClone;
		pNode = pClone->m_pNext;
	}
}

void ConnectionSiblingNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode *pClone = pNode->m_pNext;
		if (pNode->m_pSibling != NULL)
			pClone.m_pSibling = pNode->m_pSibling->m_pNext;
		pNode = pClone->m_pNext;
	}
}

ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	ComplexListNode *pCloneHead = NULL;
	ComplexListNode *pCloneNode = NULL;

	if (pNode != NULL) {
		pCloneNode = pCloneHead = pNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode != NULL) {
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pCloneHead;
}

ComplexListNode *Clone(ComplexListNode *pHead)
{
	if (pHead == NULL) return NULL;

	CloneNodes(pHead);
	ConnectionSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}
