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

Logger Logger::sm_Instance;

Logger::Logger()
{
	m_fout = NULL;
	m_szFilePath = "logFile.txt";
	
	// Clear file on launch.
	std::ofstream fout;
	fout.open( m_szFilePath.c_str() );
	fout.close();
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
	void Logger::log( char* _str, SEVERITY _severity )
	{
		//ValidateStream();
		std::ofstream fout( m_szFilePath.c_str(), std::ios::app );
		std::string severity;
		switch ( _severity ) 
		{
			case INFO:
				severity = "INFO";
				break;
			case WARNING:
				severity = "WARNING";
				break;
			case ERROR:
				severity = "ERROR";
				break;
		}
		fout << _str << "\t\tSeverity: " << severity << '\n';
		fout.close();
	}

	void Logger::log( bool _fail, char* _str, SEVERITY _severity )
	{
		if ( !_fail )
		{
			//ValidateStream();
			std::ofstream fout( m_szFilePath.c_str(), std::ios::app );
			std::string severity;
			switch ( _severity ) 
			{
				case INFO:
					severity = "INFO";
					break;
				case WARNING:
					severity = "WARNING";
					break;
				case ERROR:
					severity = "ERROR";
					break;
			}
			fout << _str << "Severity: " << severity;
			fout.close();
		}
	}
#else
	void Logger::log( char* _str, SEVERITY _severity )
	{
	}

	void Logger::log( bool _fail, char* _str, SEVERITY _severity )
	{
	}
#endif

void Logger::ValidateStream()
{
	if ( m_fout == NULL )
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

