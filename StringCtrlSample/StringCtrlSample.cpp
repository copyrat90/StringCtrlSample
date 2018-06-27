// StringCtrlSample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyString.h"

void TestFunc(const CMyString &strParam)
{
	cout << strParam << endl;
}


int main(void)
{
	CMyString strData("Hello");

	::TestFunc(strData);
	::TestFunc(CMyString("World"));

	return 0;
}