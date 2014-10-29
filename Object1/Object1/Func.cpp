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
	int nLen1 = ::SysStringLen(str1);   //计算BSTR字符串的长度
	int nLen2 = ::SysStringLen(str2);
	*retval = ::SysAllocStringLen(str1, nLen1 + nLen2);
	//申请nLen1+nLen2长度的内存区域，将字符串存进去
	if (nLen2 > 0)
	{
		::memcpy(*retval + nLen1, str2, sizeof(WCHAR) * nLen2);
		//将str2复制进申请的内存缓冲区
	}
	return S_OK;
}
