// **********************************************************************
//
// Copyright (c) 2003-2017 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.6.4
//
// <auto-generated>
//
// Generated from file `TDU100GeneralCmd.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <TDU100GeneralCmd.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/BasicStream.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/PopDisableWarnings.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 306
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 4
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

const ::std::string __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__TDU100GeneralCmdRoute_name = "TDU100GeneralCmdRoute";

const ::std::string __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__updateProtocolParam_name = "updateProtocolParam";

const ::std::string __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse__TDU100GeneralCmdReply_name = "TDU100GeneralCmdReply";

}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::TDU100GeneralCmd::upCast(::IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest* p) { return p; }

void
::IceProxy::TDU100GeneralCmd::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::TDU100GeneralCmdRoute(const ::TDU100GeneralCmd::tduReqSeq& __p_reqSeq, const ::Ice::Context* __ctx)
{
    ::IceInternal::Outgoing __og(this, __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__TDU100GeneralCmdRoute_name, ::Ice::Normal, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_reqSeq);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    __invoke(__og);
}

::Ice::AsyncResultPtr
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::begin_TDU100GeneralCmdRoute(const ::TDU100GeneralCmd::tduReqSeq& __p_reqSeq, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__TDU100GeneralCmdRoute_name, __del, __cookie);
    try
    {
        __result->prepare(__TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__TDU100GeneralCmdRoute_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_reqSeq);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

void
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::end_TDU100GeneralCmdRoute(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__TDU100GeneralCmdRoute_name);
}

void
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::updateProtocolParam(const ::TDU100GeneralCmd::protocolMsgSeq& __p_protocolSeq, const ::Ice::Context* __ctx)
{
    ::IceInternal::Outgoing __og(this, __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__updateProtocolParam_name, ::Ice::Normal, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_protocolSeq);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    __invoke(__og);
}

::Ice::AsyncResultPtr
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::begin_updateProtocolParam(const ::TDU100GeneralCmd::protocolMsgSeq& __p_protocolSeq, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__updateProtocolParam_name, __del, __cookie);
    try
    {
        __result->prepare(__TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__updateProtocolParam_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_protocolSeq);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

void
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::end_updateProtocolParam(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest__updateProtocolParam_name);
}

const ::std::string&
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::ice_staticId()
{
    return ::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::ice_staticId();
}

::IceProxy::Ice::Object*
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::__newInstance() const
{
    return new TDU100GeneralCmdManagerRequest;
}
::IceProxy::Ice::Object* ::IceProxy::TDU100GeneralCmd::upCast(::IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse* p) { return p; }

void
::IceProxy::TDU100GeneralCmd::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::TDU100GeneralCmdReply(const ::TDU100GeneralCmd::replyMsgSeq& __p_replySeq, const ::Ice::Context* __ctx)
{
    ::IceInternal::Outgoing __og(this, __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse__TDU100GeneralCmdReply_name, ::Ice::Normal, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_replySeq);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    __invoke(__og);
}

::Ice::AsyncResultPtr
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::begin_TDU100GeneralCmdReply(const ::TDU100GeneralCmd::replyMsgSeq& __p_replySeq, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse__TDU100GeneralCmdReply_name, __del, __cookie);
    try
    {
        __result->prepare(__TDU100GeneralCmd__TDU100GeneralCmdManagerResponse__TDU100GeneralCmdReply_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_replySeq);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

void
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::end_TDU100GeneralCmdReply(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse__TDU100GeneralCmdReply_name);
}

const ::std::string&
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::ice_staticId()
{
    return ::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::ice_staticId();
}

::IceProxy::Ice::Object*
IceProxy::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::__newInstance() const
{
    return new TDU100GeneralCmdManagerResponse;
}

::Ice::Object* TDU100GeneralCmd::upCast(::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest* p) { return p; }

namespace
{
const ::std::string __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_ids[2] =
{
    "::Ice::Object",
    "::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest"
};

}

bool
TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_ids, __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_ids + 2, _s);
}

::std::vector< ::std::string>
TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_ids[0], &__TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_ids[2]);
}

const ::std::string&
TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::ice_id(const ::Ice::Current&) const
{
    return __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_ids[1];
}

const ::std::string&
TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest";
    return typeId;
#else
    return __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_ids[1];
#endif
}

::Ice::DispatchStatus
TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::___TDU100GeneralCmdRoute(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::TDU100GeneralCmd::tduReqSeq __p_reqSeq;
    __is->read(__p_reqSeq);
    __inS.endReadParams();
    TDU100GeneralCmdRoute(__p_reqSeq, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::___updateProtocolParam(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::TDU100GeneralCmd::protocolMsgSeq __p_protocolSeq;
    __is->read(__p_protocolSeq);
    __inS.endReadParams();
    updateProtocolParam(__p_protocolSeq, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_all[] =
{
    "TDU100GeneralCmdRoute",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "updateProtocolParam"
};

}

::Ice::DispatchStatus
TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_all, __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __TDU100GeneralCmd__TDU100GeneralCmdManagerRequest_all)
    {
        case 0:
        {
            return ___TDU100GeneralCmdRoute(in, current);
        }
        case 1:
        {
            return ___ice_id(in, current);
        }
        case 2:
        {
            return ___ice_ids(in, current);
        }
        case 3:
        {
            return ___ice_isA(in, current);
        }
        case 4:
        {
            return ___ice_ping(in, current);
        }
        case 5:
        {
            return ___updateProtocolParam(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
TDU100GeneralCmd::__patch(TDU100GeneralCmdManagerRequestPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::TDU100GeneralCmd::TDU100GeneralCmdManagerRequestPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::TDU100GeneralCmd::TDU100GeneralCmdManagerRequest::ice_staticId(), v);
    }
}

::Ice::Object* TDU100GeneralCmd::upCast(::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse* p) { return p; }

namespace
{
const ::std::string __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_ids[2] =
{
    "::Ice::Object",
    "::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse"
};

}

bool
TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_ids, __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_ids + 2, _s);
}

::std::vector< ::std::string>
TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_ids[0], &__TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_ids[2]);
}

const ::std::string&
TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::ice_id(const ::Ice::Current&) const
{
    return __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_ids[1];
}

const ::std::string&
TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse";
    return typeId;
#else
    return __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_ids[1];
#endif
}

::Ice::DispatchStatus
TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::___TDU100GeneralCmdReply(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::TDU100GeneralCmd::replyMsgSeq __p_replySeq;
    __is->read(__p_replySeq);
    __inS.endReadParams();
    TDU100GeneralCmdReply(__p_replySeq, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_all[] =
{
    "TDU100GeneralCmdReply",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

}

::Ice::DispatchStatus
TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_all, __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __TDU100GeneralCmd__TDU100GeneralCmdManagerResponse_all)
    {
        case 0:
        {
            return ___TDU100GeneralCmdReply(in, current);
        }
        case 1:
        {
            return ___ice_id(in, current);
        }
        case 2:
        {
            return ___ice_ids(in, current);
        }
        case 3:
        {
            return ___ice_isA(in, current);
        }
        case 4:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
TDU100GeneralCmd::__patch(TDU100GeneralCmdManagerResponsePtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::TDU100GeneralCmd::TDU100GeneralCmdManagerResponsePtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::TDU100GeneralCmd::TDU100GeneralCmdManagerResponse::ice_staticId(), v);
    }
}