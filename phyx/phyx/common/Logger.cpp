/*
 *  Logger.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Logger.h"

#include "TargetConditionals.h"


Logger::Logger()
{
	m_fout = NULL;
	m_szFilePath = "logFile.txt";
}

Logger::~Logger()
{
	if ( m_fout != NULL )
	{
		m_fout->close();
		delete m_fout;
	}
}

#if (TARGET_IPHONE_SIMULATOR)
	void Logger::LogMsg( std::string& _str )
	{
		ValidateStream();
		(*m_fout) << _str;
	}

	void Logger::Assert( bool _fail, std::string& _str )
	{
		if ( !_fail )
		{
			ValidateStream();
			(*m_fout) << _str;
		}
	}
#else
	void Logger::LogMsg( std::sting& _str )
	{
	}

	void Logger::Assert( bool _fail, std::string& _str )
	{
	}
#endif

void Logger::ValidateStream()
{
	if ( m_fout = NULL )
	{
		m_fout = new std::ofstream();
		m_fout->open( m_szFilePath.c_str() );
	}
}

void Logger::ClearFile()
{
	if ( m_fout != NULL )
	{
		m_fout->close();
		m_fout->open( m_szFilePath.c_str() );
	}
}
				
void Logger::SetFilePath( std::string& _filePath )
{
	if ( m_fout != NULL )
	{
		m_fout->close();
		delete m_fout;
		m_fout = NULL;
	}
	m_szFilePath = _filePath;
}

