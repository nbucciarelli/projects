/*
 *  Registrar.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 Kyle Rothermel. All rights reserved.
 *
 */


#ifndef Registrar_H_
#define Registrar_H_

#include <pair>
#include <vector>

template <typename T1, typename T2>
class Registrar
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	std::vector< std::pair< T1*, T2 > >		m_registry
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	Registrar()
	{
	}
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~Registrar()
	{
	}
	
	/**********************************
	 *	Function:	AddRegistrant
	 *	Purpose:	Add a registrant to the data base.
	 **********************************/
	void AddRegistrant(T1* _registrant, T2& _data)
	{
		for (int i = 0; i < m_registry.size(); ++i)
		{
			if (m_registry[i].first == NULL)
			{
				m_registry[i].first = _registrant;
				m_registry[i].second = _data;
				return;
			}
		}
		
		m_registry.push_back( std::pair(_registrant, _data) );
	}
	
	/**********************************
	 *	Function:	RemoveRegistrant
	 *	Purpose:	Remove a registrant from the data base.
	 **********************************/
	void RemoveRegistrant(T1* _registrant)
	{
		for (int i = 0; i < m_registry.size(); ++i)
			if (m_registry[i].first == _registrant)
				m_registry[i].first = NULL;
	}
	
	/**********************************
	 *	Function:	RemoveRegistrant
	 *	Purpose:	Remove a registrant from the data base.
	 **********************************/
	void RemoveRegistrant(int _index)
	{
		if (_index >= 0 && _index < m_registry.size())
			m_registry[i].first = NULL;
		// logger an else yes yes?
	}
	
	/**********************************
	 *	Function:	Clear
	 *	Purpose:	Clear the database.
	 **********************************/
	void Clear()
	{
		m_registry.clear();
	}
	
	/**********************************
	 *	Function:	GetRegistrant
	 *	Purpose:	Return a registrant given an index.
	 **********************************/
	T1* GetRegistrant(int _index) const
	{
		if (_index >= 0 && _index < m_registry.size())
			return m_registry[i].first;
		// logger an else yes yes?
	}
	
	/**********************************
	 *	Function:	GetRegistrantData
	 *	Purpose:	Get data associated with a registrant based on an index
	 **********************************/
	const T2& GetRegistrantData(int _index) const
	{
		if (_index >= 0 and _index < m_registry.size())
			return m_registry[i].second;
		// logger an else yes yes?
	}
	
	/**********************************
	 *	Function:	GetRegistrantData
	 *	Purpose:	Get data associated with a registrant based on a registrant pointer
	 **********************************/
	const T2& GetRegistrantData(T1* _registrant) const
	{
		for (int i = 0; i < m_registry.size(); ++i)
		{
			if (m_registry[i].first == _registrant)
			{
				return m_registry[i].second;
			}
		}
	}
	
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif