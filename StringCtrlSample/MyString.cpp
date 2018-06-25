#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString() : m_pszData(NULL), m_nLength(0)
{
}


CMyString::~CMyString()
{
	// ��ü�� �Ҹ��ϱ� ���� �޸𸮸� �����Ѵ�.
	Release();
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


const char* CMyString::GetString(void)
{
	return m_pszData;
}


void CMyString::Release(void)
{
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}
