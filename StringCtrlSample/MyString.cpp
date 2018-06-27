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

// 복사 생성자
CMyString::CMyString(const CMyString &rhs)
	: m_pszData(NULL), m_nLength(0)
{
	this->SetString(rhs.GetString());
}

CMyString::~CMyString()
{
	// 객체가 소멸하기 전에 메모리를 해제한다.
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

	// Release 했으므로 주요 멤버 초기화
	m_pszData = NULL;
	m_nLength = 0;
}


CMyString& CMyString::operator=(const CMyString &rhs)
{
	// 자기 자신에 대한 대입이면 아무것도 하지 않는다.
	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}