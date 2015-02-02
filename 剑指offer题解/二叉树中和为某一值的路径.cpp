/************************************************************* 
 * ����һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������
 * ��·���������ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��
 * ·����
 * Edit by changmu
 *************************************************************/ 
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void FindPath(BinaryTreeNode *pRoot, int expectedSum)
{
	if (pRoot == NULL) return;

	std::vector<int> path;
	int currentSum = 0;

	FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode *pRoot, int expectedSum, 
		std::vector<int>& path, int currentSum)
{
	if (pRoot == NULL) return;

	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
	if (currentSum == expectedSum && isLeaf) {
		cout << "A path is found: ";
		std::vector<int>::iterator iter = path.begin();
		for ( ; iter != path.end(); ++iter)
			printf("%d\t", *iter);
		printf("\n");
	}

	FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

	path.pop_back();
}
