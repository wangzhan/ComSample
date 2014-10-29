// Func.cpp : Implementation of CFunc

#include "stdafx.h"
#include "Func.h"


// CFunc



STDMETHODIMP CFunc::Add(LONG a, LONG b, LONG* retval)
{
	// TODO: Add your implementation code here
	*retval = a + b;
	return S_OK;
}


STDMETHODIMP CFunc::CatString(BSTR str1, BSTR str2, BSTR* retval)
{
	// TODO: Add your implementation code here
	int nLen1 = ::SysStringLen(str1);   //����BSTR�ַ����ĳ���
	int nLen2 = ::SysStringLen(str2);
	*retval = ::SysAllocStringLen(str1, nLen1 + nLen2);
	//����nLen1+nLen2���ȵ��ڴ����򣬽��ַ������ȥ
	if (nLen2 > 0)
	{
		::memcpy(*retval + nLen1, str2, sizeof(WCHAR) * nLen2);
		//��str2���ƽ�������ڴ滺����
	}
	return S_OK;
}
