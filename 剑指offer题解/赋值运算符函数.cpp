/*
** ��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������
class CMyString {
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

private:
	char *m_pData;
};
*/

/*
** ˼·����Ҫ����4�㣺
** 1���Ƿ�ѷ���ֵ��������Ϊ�����͵����ã����ں�������ǰ����ʵ����������ü�*this������������ֵ�������塣
** 2���Ƿ�Ѵ���Ĳ�������������Ϊ�������á��������Ĳ����������ö���ʵ������ô���βε�ʵ�λ����һ�θ��ƹ��캯�����Ѳ�������Ϊ���ÿ��Ա�����������ν���ģ���ߴ���Ч�ʣ�ͬʱ���ڲ��ı�ʵ��״̬����ô���βμ���const�ؼ��֡�
** 3���Ƿ��ͷ�ʵ���������е��ڴ档������������ڷ������ڴ�֮ǰ�ͷ��������еĿռ䣬���򽫳����ڴ�й¶��
** 4���жϴ���Ĳ����͵�ǰ��ʵ��(*this)�ǲ���ͬһ��ʵ����������Ȳ��жϾͽ��и�ֵ����ô���ͷ�ʵ��������ڴ�ʱ�ͻᵼ�����ص����⣺�Ҳ�����Ҫ��ֵ�������ˡ�
*/

// ����ⷨ�����ż�����Ա
CMyString& CMyString::operator = (const CMyString& str) {
	if (this == &str) return *this;

	delete[] m_pData;
	m_pData = NULL;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

/*
** ����ⷨ��ȱ�ݣ�new���ܻ��׳��쳣��Υ�����쳣��ȫ��ԭ�������ֽ��������1����new����ɹ������ͷ����е����ݣ�2��������ʱʵ����������ʱʵ����ԭ��ʵ�������ݡ�
*/

// �߼��ⷨ���߼�����Ա
CMyString& CMyString::operator = (const CMyString& str) {
	if (this == &str) return *this;

	CMystring tmp(str);
	char *ptmp = tmp.m_pData;
	tmp.m_pData = m_pData;
	m_pData = ptmp;

	return *this;
}

// via:changmu
