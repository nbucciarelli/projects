/*
 *  Logger.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef Logger_H_
#define Logger_H_

#include <string>
#include <fstream>

enum SEVERITY { INFO = 0, WARNING, ERROR };

class Logger
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	std::string		m_szFilePath;
	std::ofstream*	m_fout;
	
	
	// Instance of main engine object
	static Logger		sm_Instance;
	
public:
	/*	Public Functions		*/
	
	static Logger* GetInstance() { return &sm_Instance; }
	
	/**********************************
	 *	Function:	log
	 *	Purpose:	log a message to open file.
	 **********************************/
	void log( char* _str, SEVERITY _severity );
	
	/**********************************
	 *	Function:	log
	 *	Purpose:	log a msg if !_fail.
	 **********************************/
	void log( bool _fail, char* _str, SEVERITY _severity );
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	void ValidateStream();
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	Logger();
	Logger(const Logger&);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~Logger();
	
	/**********************************
	 *	Function:	ClearFile
	 **********************************/
	void ClearFile();
	
	/**********************************
	 *	Function:	Mutators
	 **********************************/
	void SetFilePath( std::string& _filePath );

};

static Logger * const logger = Logger::GetInstance();

#endif