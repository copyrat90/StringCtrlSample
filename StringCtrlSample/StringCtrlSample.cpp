// StringCtrlSample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyString.h"

int main()
{
	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	// 복사 생성
	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	// 단순 대입 연산자 호출
	strNewData = strTest;
	cout << strNewData.GetString() << endl;

	return 0;
}