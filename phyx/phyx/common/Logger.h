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

class Logger
{
	friend class phyx;
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	std::string		m_szFilePath;
	std::ofstream*	m_fout;
	
public:
	/*	Public Functions		*/
	
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
	 *	Function:	LogMsg
	 *	Purpose:	mog a message to open file.
	 **********************************/
	void LogMsg( std::string& _str );
	
	/**********************************
	 *	Function:	LogMsg
	 *	Purpose:	mog a message to open file.
	 **********************************/
	void Assert( bool _fail, std::string& _str );
	
	/**********************************
	 *	Function:	ClearFile
	 **********************************/
	void ClearFile();
	
	/**********************************
	 *	Function:	Mutators
	 **********************************/
	void SetFilePath( std::string& _filePath );

};

#endif