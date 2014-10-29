// ProcOut.cpp : Implementation of WinMain


#include "stdafx.h"
#include "resource.h"
#include "ProcOut_i.h"


using namespace ATL;


class CProcOutModule : public ATL::CAtlExeModuleT< CProcOutModule >
{
public :
	DECLARE_LIBID(LIBID_ProcOutLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_PROCOUT, "{5AAC87E7-E0DE-45CB-A7AD-DD0E1A1CF109}")
	};

CProcOutModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

