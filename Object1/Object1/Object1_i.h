

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Oct 20 13:55:35 2014
 */
/* Compiler settings for Object1.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Object1_i_h__
#define __Object1_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFunc_FWD_DEFINED__
#define __IFunc_FWD_DEFINED__
typedef interface IFunc IFunc;

#endif 	/* __IFunc_FWD_DEFINED__ */


#ifndef __Func_FWD_DEFINED__
#define __Func_FWD_DEFINED__

#ifdef __cplusplus
typedef class Func Func;
#else
typedef struct Func Func;
#endif /* __cplusplus */

#endif 	/* __Func_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFunc_INTERFACE_DEFINED__
#define __IFunc_INTERFACE_DEFINED__

/* interface IFunc */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IFunc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("46670255-36AD-40D7-88AB-0F34F4D4EC39")
    IFunc : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ LONG a,
            /* [in] */ LONG b,
            /* [out] */ LONG *pC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CatString( 
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            /* [out] */ BSTR *retval) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFuncVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFunc * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFunc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFunc * This);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IFunc * This,
            /* [in] */ LONG a,
            /* [in] */ LONG b,
            /* [out] */ LONG *pC);
        
        HRESULT ( STDMETHODCALLTYPE *CatString )( 
            IFunc * This,
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            /* [out] */ BSTR *retval);
        
        END_INTERFACE
    } IFuncVtbl;

    interface IFunc
    {
        CONST_VTBL struct IFuncVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFunc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFunc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFunc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFunc_Add(This,a,b,pC)	\
    ( (This)->lpVtbl -> Add(This,a,b,pC) ) 

#define IFunc_CatString(This,str1,str2,retval)	\
    ( (This)->lpVtbl -> CatString(This,str1,str2,retval) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFunc_INTERFACE_DEFINED__ */



#ifndef __Object1Lib_LIBRARY_DEFINED__
#define __Object1Lib_LIBRARY_DEFINED__

/* library Object1Lib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_Object1Lib;

EXTERN_C const CLSID CLSID_Func;

#ifdef __cplusplus

class DECLSPEC_UUID("12498F74-DA7A-41FC-A6B7-D0CEA3933779")
Func;
#endif
#endif /* __Object1Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


