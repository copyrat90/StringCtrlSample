#pragma once

class CMyString
{
public:
	CMyString();
	// 복사 생성자
	CMyString(const CMyString &rhs);
	~CMyString();

private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;

public:
	int SetString(const char *pszParam);
	const char* GetString(void) const;

	void Release(void);
	CMyString& operator=(const CMyString &rhs);
};

