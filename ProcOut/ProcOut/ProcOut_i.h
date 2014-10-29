

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Oct 20 16:59:38 2014
 */
/* Compiler settings for ProcOut.idl:
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

#ifndef __ProcOut_i_h__
#define __ProcOut_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IModu_FWD_DEFINED__
#define __IModu_FWD_DEFINED__
typedef interface IModu IModu;

#endif 	/* __IModu_FWD_DEFINED__ */


#ifndef __Modu_FWD_DEFINED__
#define __Modu_FWD_DEFINED__

#ifdef __cplusplus
typedef class Modu Modu;
#else
typedef struct Modu Modu;
#endif /* __cplusplus */

#endif 	/* __Modu_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IModu_INTERFACE_DEFINED__
#define __IModu_INTERFACE_DEFINED__

/* interface IModu */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IModu;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("56AB6043-23ED-4BA0-87F4-9380E6EE8B65")
    IModu : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Produce( 
            /* [in] */ LONG nProduce) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Customer( 
            /* [in] */ LONG nCustomer) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentNum( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentNum( 
            /* [in] */ LONG newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IModuVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IModu * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IModu * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IModu * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IModu * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IModu * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IModu * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IModu * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Produce )( 
            IModu * This,
            /* [in] */ LONG nProduce);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Customer )( 
            IModu * This,
            /* [in] */ LONG nCustomer);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentNum )( 
            IModu * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentNum )( 
            IModu * This,
            /* [in] */ LONG newVal);
        
        END_INTERFACE
    } IModuVtbl;

    interface IModu
    {
        CONST_VTBL struct IModuVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IModu_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IModu_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IModu_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IModu_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IModu_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IModu_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IModu_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IModu_Produce(This,nProduce)	\
    ( (This)->lpVtbl -> Produce(This,nProduce) ) 

#define IModu_Customer(This,nCustomer)	\
    ( (This)->lpVtbl -> Customer(This,nCustomer) ) 

#define IModu_get_CurrentNum(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentNum(This,pVal) ) 

#define IModu_put_CurrentNum(This,newVal)	\
    ( (This)->lpVtbl -> put_CurrentNum(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IModu_INTERFACE_DEFINED__ */



#ifndef __ProcOutLib_LIBRARY_DEFINED__
#define __ProcOutLib_LIBRARY_DEFINED__

/* library ProcOutLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ProcOutLib;

EXTERN_C const CLSID CLSID_Modu;

#ifdef __cplusplus

class DECLSPEC_UUID("64E440AF-52E5-4149-970A-656074910DFE")
Modu;
#endif
#endif /* __ProcOutLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


