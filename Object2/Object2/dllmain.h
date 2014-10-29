// dllmain.h : Declaration of module class.

class CObject2Module : public ATL::CAtlDllModuleT< CObject2Module >
{
public :
	DECLARE_LIBID(LIBID_Object2Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OBJECT2, "{D3A2BA1D-BFE1-45C9-A161-09FF8A3D13E7}")
};

extern class CObject2Module _AtlModule;
