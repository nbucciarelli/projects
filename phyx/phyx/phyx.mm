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
#include "managers/TimerManager.h"
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
	
	m_pEntityManager = new EntityManager();
	m_pStateManager = new StateManager();
	m_pTimerManager = new TimerManager();
	m_pEventManager = new EventManager();
	m_pLogger = new Logger();
	
	entities = m_pEntityManager;
}

void phyx::Shutdown()
{
	SAFE_DELETE(m_pEntityManager);
	SAFE_DELETE(m_pStateManager);
	SAFE_DELETE(m_pTimerManager);
	SAFE_DELETE(m_pEventManager);
	SAFE_DELETE(m_pLogger);
	entities = NULL;
}

void phyx::PreUpdate()
{
	m_currTime = CFAbsoluteTimeGetCurrent();
}

void phyx::Update()
{
	float delta = GetDelta();
	m_fTimeSinceLaunch += delta;
	
	m_pStateManager->Update( delta );
	m_pEntityManager->Update( delta );
	m_pTimerManager->Update( delta );
}

void phyx::PostUpdate()
{
	m_pEventManager->ProcessEvents();
	
	m_prevTime = m_currTime;
}

void phyx::PreRender()
{
	_pRenderer->Begin();
}

void phyx::Render()
{
	m_pStateManager->Render();
	m_pEntityManager->Render();
}

void phyx::PostRender()
{
	_pRenderer->End();
}

void phyx::RegisterEntity( PhyxObject* _entity )
{
	m_pEntityManager->RegisterEntity( _entity );
}

void phyx::RegisterClient(unsigned _id, BaseFunctor* _functor)
{
	m_pEventManager->RegisterClient( _id, _functor );
}

void phyx::UnregisterClient(PhyxObject* _object)
{
	m_pEventManager->UnregisterClient( _object );
}

void phyx::UnregisterClient(PhyxObject* _object, unsigned _id)
{
	m_pEventManager->UnregisterClient( _object, _id );
}

void phyx::SendEvent(unsigned _id, BaseEvent* _data, short _frameDelay)
{
	m_pEventManager->SendEvent(_id, _data, _frameDelay);
}

TimerHandle phyx::AddTimer( unsigned _event, BaseEvent* _data, float _firstTick, float _tickIncrement )
{
	return m_pTimerManager->AddTimer(_event, _data, _firstTick, _tickIncrement);
}

void phyx::RemoveTimer( Timer* _timer )
{
	m_pTimerManager->RemoveTimer( _timer );
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

void phyx::LogMsg( std::string& _msg )
{
	m_pLogger->LogMsg( _msg );
}

void phyx::Assert( bool _fail, std::string& _msg )
{
	m_pLogger->Assert( _fail, _msg );
}

void phyx::ClearLogFile()
{
	m_pLogger->ClearFile();
}
























