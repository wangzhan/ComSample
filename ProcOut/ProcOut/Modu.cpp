// Modu.cpp : Implementation of CModu

#include "stdafx.h"
#include "Modu.h"


// CModu



STDMETHODIMP CModu::Produce(LONG nProduce)
{
	// TODO: Add your implementation code here
	m_lNum += nProduce;
	return S_OK;
}


STDMETHODIMP CModu::Customer(LONG nCustomer)
{
	// TODO: Add your implementation code here
	m_lNum -= nCustomer;
	if (m_lNum < 0)
	{
		MessageBox(NULL, L"消耗没了", L"提示", MB_OK);
		m_lNum = 0;
	}
	return S_OK;
}


STDMETHODIMP CModu::get_CurrentNum(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_lNum;
	return S_OK;
}


STDMETHODIMP CModu::put_CurrentNum(LONG newVal)
{
	// TODO: Add your implementation code here
	m_lNum = newVal;
	return S_OK;
}
