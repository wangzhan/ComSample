// Func.h : Declaration of the CFunc

#pragma once
#include "resource.h"       // main symbols



#include "Object1_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CFunc

class ATL_NO_VTABLE CFunc :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFunc, &CLSID_Func>,
	public IFunc
{
public:
	CFunc()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FUNC)


BEGIN_COM_MAP(CFunc)
	COM_INTERFACE_ENTRY(IFunc)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(Add)(LONG a, LONG b, LONG* retval);
	STDMETHOD(CatString)(BSTR str1, BSTR str2, BSTR* retval);
};

OBJECT_ENTRY_AUTO(__uuidof(Func), CFunc)
