/*
 *  phyx.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 4/17/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "phyx.h"

#include "wrappers/Renderer.h"

#include "managers/EntityManager.h"
#include "managers/StateManager.h"
#include "managers/EventManager.h"
#include "common/Logger.h"

#define SAFE_DELETE(obj) delete (obj); obj = NULL

phyx phyx::sm_Instance;

phyx::phyx()
{
}

phyx::~phyx()
{
}

void phyx::Initialize()
{
	m_fTimeSinceLaunch = 0.0f;
	m_prevTime = m_currTime = CFAbsoluteTimeGetCurrent();
	
	m_pEntityManager = new EntityManager();
	m_pStateManager = new StateManager();
	m_pEventManager = new EventManager();
	m_pAttributeManager = new AttributeManager();
	
	entities = m_pEntityManager;
}

void phyx::Shutdown()
{
	SAFE_DELETE(m_pEntityManager);
	SAFE_DELETE(m_pStateManager);
	SAFE_DELETE(m_pEventManager);
	SAFE_DELETE(m_pAttributeManager);
	entities = NULL;
}

void phyx::PreUpdate()
{
	m_prevTime = m_currTime;
	m_currTime = CFAbsoluteTimeGetCurrent();
}

void phyx::Update()
{
	float delta = GetDelta();
	m_fTimeSinceLaunch += delta;
	
	m_pStateManager->Update( delta );
	m_pEntityManager->Update( delta );
}

void phyx::PostUpdate()
{
	m_pEventManager->ProcessEvents();
}

void phyx::PreRender()
{
	_pRenderer->Begin();
}

void phyx::Render()
{
	m_pStateManager->Render();
	m_pEntityManager->Render( GetDelta() );
}

void phyx::PostRender()
{
	_pRenderer->End();
}

void phyx::Add( PhyxObject* _object, unsigned _priority )
{
	m_pEntityManager->RegisterEntity( _object, _priority );
}

void phyx::Remove(PhyxObject* _object)
{
	m_pEntityManager->RemoveEntity( _object );
}

void phyx::RegisterForEvent(unsigned _id, BaseFunctor* _functor, EVENT_PRIORITY _priority)
{
	m_pEventManager->RegisterClient( _id, _functor, _priority );
}

void phyx::UnregisterForEvent(PhyxObject* _object)
{
	m_pEventManager->UnregisterClient( _object );
}

void phyx::UnregisterForEvent(PhyxObject* _object, unsigned _id)
{
	m_pEventManager->UnregisterClient( _object, _id );
}

void phyx::SendEvent(unsigned _id, BaseEvent* _data, short _frameDelay)
{
	m_pEventManager->SendEvent(_id, _data, _frameDelay);
}

void phyx::SendSynchronousEvent(unsigned _id, BaseEvent* _data)
{
	m_pEventManager->SendEvent(_id, _data, -1);
}

void phyx::ChangeState(BaseState* _state)
{
	m_pStateManager->ChangeState( _state );
}

void phyx::PushState(BaseState* _state)
{
	m_pStateManager->PushState( _state );
}

void phyx::PopState()
{
	m_pStateManager->PopState();
}

void phyx::ClearStates()
{
	m_pStateManager->Clear();
}

bool phyx::DelAttr(PhyxObject* _obj, std::string& _attrName)
{
	return m_pAttributeManager->DelAttr( _obj, _attrName );
}

bool phyx::ClearObjAttrs(PhyxObject* _obj)
{
	return m_pAttributeManager->ClearObjAttrs( _obj );
}





















