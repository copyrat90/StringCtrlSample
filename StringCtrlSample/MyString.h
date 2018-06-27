#pragma once

class CMyString
{
public:
	CMyString();
	// ���� ������
	CMyString(const CMyString &rhs);
	~CMyString();

private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;

public:
	int SetString(const char *pszParam);
	const char* GetString(void) const;

	void Release(void);
	CMyString& operator=(const CMyString &rhs);
};

