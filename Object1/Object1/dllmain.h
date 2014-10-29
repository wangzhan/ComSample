// dllmain.h : Declaration of module class.

class CObject1Module : public ATL::CAtlDllModuleT< CObject1Module >
{
public :
	DECLARE_LIBID(LIBID_Object1Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OBJECT1, "{E0E0070E-5FCD-4F9A-806D-78B498CC5F1B}")
};

extern class CObject1Module _AtlModule;
