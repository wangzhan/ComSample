// DFun.cpp : Implementation of CDFun

#include "stdafx.h"
#include "DFun.h"


// CDFun



STDMETHODIMP CDFun::Add(VARIANT v1, VARIANT v2, VARIANT* pVal)
{
	// TODO: Add your implementation code here
	::VariantInit(pVal);
	CComVariant v_1(v1);
	CComVariant v_2(v2);
	if ((v1.vt & VT_I4) && (v2.vt & VT_I4)) // 如果都是整数类型
	{
		v_1.ChangeType(VT_I4);   // 转换为整数
		v_2.ChangeType(VT_I4);   // 转换为整数
		pVal->vt = VT_I4;
		pVal->lVal = v_1.lVal + v_2.lVal; // 加法
	}
	else
	{
		v_1.ChangeType(VT_BSTR);   // 转换为字符串
		v_2.ChangeType(VT_BSTR);   // 转换为字符串
		CComBSTR bstr(v_1.bstrVal);
		bstr.AppendBSTR(v_2.bstrVal); // 字符串连接
		pVal->vt = VT_BSTR;
		pVal->bstrVal = bstr.Detach();
	}
	return S_OK;
}


STDMETHODIMP CDFun::Lower(BSTR bstr, BSTR* pVal)
{
	// TODO: Add your implementation code here
	*pVal = NULL;
	CComBSTR s(bstr);
	s.ToLower(); // 转换为小写
	*pVal = s.Copy();
	return S_OK;
}
