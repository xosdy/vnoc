#pragma once
#include "IRefCountImpl.h"

// 尽管有引用计数，不过尽量避免使用
interface IModule : public IRefCountImpl
{
public:
	// UpperFrame提供了上层的接口，比如子模块会收到Frame模块的接口。请使用QueryInterface
	STDMETHOD( Initialize(IModule* UpperFrame=NULL) = 0 );
	STDMETHOD( UnInitialize() = 0 );
	// 通知模块初始化，模块内部可以使用独立线程，保证接口的线程安全即可。
	STDMETHOD( Run() = 0 );
	// 通知退出
	STDMETHOD( Terminate() = 0 );
};

template<class retType>
void GetiModule(IModule* pBase,retType** pRet)
{
	if (pRet && pBase)
	{
		*pRet = dynamic_cast<retType*>(pBase);
	}
}