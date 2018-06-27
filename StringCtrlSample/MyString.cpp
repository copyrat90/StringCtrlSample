#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString() : m_pszData(NULL), m_nLength(0)
{
}

CMyString::CMyString(const char *pszParam)
	: m_pszData(NULL), m_nLength(0)
{
	this->SetString(pszParam);
}

// ���� ������
CMyString::CMyString(const CMyString &rhs)
	: m_pszData(NULL), m_nLength(0)
{
	this->SetString(rhs.GetString());
}

CMyString::~CMyString()
{
	// ��ü�� �Ҹ��ϱ� ���� �޸𸮸� �����Ѵ�.
	Release();
}

CMyString::operator char *(void) const
{
	return m_pszData;
}

int CMyString::SetString(const char *pszParam)
{
	Release();

	if (pszParam == NULL)
		return 0;

	m_nLength = strlen(pszParam);
	if (m_nLength == 0)
		return 0;
	
	m_pszData = new char[m_nLength + 1];

	strcpy_s(m_pszData, sizeof(char)*(m_nLength + 1), pszParam);

	return m_nLength;
}


const char* CMyString::GetString(void) const
{
	return m_pszData;
}


void CMyString::Release(void)
{
	if (m_pszData != NULL)
		delete[] m_pszData;

	// Release �����Ƿ� �ֿ� ��� �ʱ�ȭ
	m_pszData = NULL;
	m_nLength = 0;
}


CMyString& CMyString::operator=(const CMyString &rhs)
{
	// �ڱ� �ڽſ� ���� �����̸� �ƹ��͵� ���� �ʴ´�.
	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}