//==============================================================================
#include "../stdafx.h"
//==============================================================================
#pragma comment(lib, "User32.lib")	// for MessageBox
#include <Windows.h>

#include <fstream>
#include <iomanip>

#include <sstream>

#include "CFileConfig.h"
//==============================================================================
#pragma hdrstop
//==============================================================================


CFileConfig::CFileConfig() : m_strFile( "" )
{
	m_bChangeFlag = false;
	m_iWidth      = 0;
}
//---------------------------------------------------------------------------
CFileConfig::~CFileConfig()
{
	if( m_bChangeFlag )
	{
		m_strFile.empty() ? m_strFile = "CFileConfig.log" : m_strFile += ".log";
		Save();
	}
}
//---------------------------------------------------------------------------
void CFileConfig::TrimStr( std::string & rstr_ )
{
	const std::string delims( " \t" );

	std::string::size_type id = rstr_.find_first_not_of( delims );
	if( id == std::string::npos ){ rstr_ = ""; return; }

	std::string::size_type idx = rstr_.find_last_not_of( delims );
	if( idx != std::string::npos ){ ++idx -= id; }
	if( idx < rstr_.size() ){ rstr_ = rstr_.substr( id, idx ); }
}
//---------------------------------------------------------------------------
void CFileConfig::ClearData( void )
{
	m_bChangeFlag = false;
	m_iWidth      = 0;
	m_strFile     = "";

	m_sssMap.clear();

	m_istrstrm.clear();
	m_istrstrm.str( "" );
}
//---------------------------------------------------------------------------
void CFileConfig::Load( void )
{
	std::ifstream filein( m_strFile.c_str() );

	if( !filein )
	{ 
		std::string ErrMsg = "Can NOT Open <" + m_strFile + ".ini> File";
		//ErrMsg.c_str();
		//::MessageBox( NULL, TEXT( ErrMsg.c_str() ), 
///			TEXT( "Error" ), MB_OK | MB_ICONERROR );
		return; 
	}
	else
	{
		m_bChangeFlag = false;
		m_iWidth      = 0;
		m_sssMap.clear();

		m_istrstrm.clear();
		m_istrstrm.str( "" );

		std::string str, str_tmp, str_where, str_name, str_value;
		std::string::size_type id;

		while( !filein.eof() )
		{
			std::getline( filein, str_tmp );
			TrimStr( str_tmp );

			id = str_tmp.find( '=' );
			//-----------------------------------------------
			if( id == std::string::npos )
			{
				if( str == str_where ){ str = ""; }
				if( !str_tmp.empty() ){ ( str += str_tmp ).push_back( '\n' ); }
				continue;
			}
			str_value = str_tmp.substr( id + 1, std::string::npos );
			if( str_value.find( '=' ) != std::string::npos )
			{
				if( str == str_where ){ str = ""; }
				if( !str_tmp.empty() ){ ( str += str_tmp ).push_back( '\n' ); }
				continue;
			}
			//-----------------------------------------------

			if( !str.empty() ){ ( str_where = str ).erase(str.size()-1); str = ""; }

			str_name = str_tmp.substr( 0, id );
			TrimStr( str_name );
			TrimStr( str_value );

			m_sssMap[ str_where ][ str_name ] = str_value;
			if( m_iWidth < static_cast<int>( str_name.size() ) ){ m_iWidth = str_name.size(); }
		}
	}
}
//---------------------------------------------------------------------------
void CFileConfig::Load( const std::string & c_rstr_file_ )
{
	if( !c_rstr_file_.empty() && m_strFile != c_rstr_file_ ){ m_strFile = c_rstr_file_; }
	Load();
}
//---------------------------------------------------------------------------
void CFileConfig::Save( void )
{
	std::ofstream fileout( m_strFile.c_str() );
	if( !fileout )
	{
		return; 
	}
	else
	{
		ssmap_type::iterator sspos;
		sssmap_type::iterator ssspos;
		for( ssspos = m_sssMap.begin(); ssspos != m_sssMap.end(); ++ssspos )
		{
			if( !ssspos->first.empty() ){ fileout << ssspos->first << std::endl; }
			for( sspos = ( ssspos->second ).begin(); sspos != ( ssspos->second ).end(); ++sspos )
			{
				TrimStr( sspos->second );
				fileout << std::setw( m_iWidth ) << std::left << sspos->first
					<< " = " << sspos->second << std::endl;
			}
			fileout << std::endl;
		}
		m_bChangeFlag = false;
	}
}
//--------------------------------------------------------------------------
void CFileConfig::Save( const std::string & c_rstr_file_ )
{
	if( !c_rstr_file_.empty() && m_strFile != c_rstr_file_ ){ m_strFile = c_rstr_file_; }
	Save();
}

std::istringstream & CFileConfig::Get( const std::string & c_rstr_where_,const std::string & c_rstr_name_,	int defaultIntData )
{
	std::string &  c_rstr_def_ = UtilityTool::int2stdstring(defaultIntData);
	if( m_iWidth < static_cast<int>( c_rstr_name_.size() ) ){ m_iWidth = c_rstr_name_.size(); }

	m_istrstrm.clear();
	sssmap_type::iterator ssspos = m_sssMap.find( c_rstr_where_ );
	if( ssspos != m_sssMap.end() )
	{
		ssmap_type::iterator sspos = ssspos->second.find( c_rstr_name_ );
		if( sspos != ssspos->second.end() )
		{
			m_istrstrm.str( sspos->second );
			return m_istrstrm;
		}
	}

	m_sssMap[ c_rstr_where_ ][ c_rstr_name_ ] = c_rstr_def_;
	m_bChangeFlag = true;
	m_istrstrm.str( c_rstr_def_ );

	return m_istrstrm;
}

std::istringstream & CFileConfig::Get( const std::string & c_rstr_where_,const std::string & c_rstr_name_,	float defaultFloatData )
{
	std::string &  c_rstr_def_ = UtilityTool::float2stdstring(defaultFloatData);
	if( m_iWidth < static_cast<int>( c_rstr_name_.size() ) ){ m_iWidth = c_rstr_name_.size(); }

	m_istrstrm.clear();
	sssmap_type::iterator ssspos = m_sssMap.find( c_rstr_where_ );
	if( ssspos != m_sssMap.end() )
	{
		ssmap_type::iterator sspos = ssspos->second.find( c_rstr_name_ );
		if( sspos != ssspos->second.end() )
		{
			m_istrstrm.str( sspos->second );
			return m_istrstrm;
		}
	}

	m_sssMap[ c_rstr_where_ ][ c_rstr_name_ ] = c_rstr_def_;
	m_bChangeFlag = true;
	m_istrstrm.str( c_rstr_def_ );

	return m_istrstrm;
}
//---------------------------------------------------------------------------
std::istringstream & CFileConfig::Get( const std::string & c_rstr_where_,
	const std::string & c_rstr_name_,
	const std::string & c_rstr_def_ )
{
	if( m_iWidth < static_cast<int>( c_rstr_name_.size() ) ){ m_iWidth = c_rstr_name_.size(); }

	m_istrstrm.clear();
	sssmap_type::iterator ssspos = m_sssMap.find( c_rstr_where_ );
	if( ssspos != m_sssMap.end() )
	{
		ssmap_type::iterator sspos = ssspos->second.find( c_rstr_name_ );
		if( sspos != ssspos->second.end() )
		{
			m_istrstrm.str( sspos->second );
			return m_istrstrm;
		}
	}

	m_sssMap[ c_rstr_where_ ][ c_rstr_name_ ] = c_rstr_def_;
	m_bChangeFlag = true;
	m_istrstrm.str( c_rstr_def_ );

	return m_istrstrm;
}
//---------------------------------------------------------------------------
std::istringstream & CFileConfig::Get( const std::string & c_rstr_name_,
	const std::string & c_rstr_def_ )
{
	if( m_iWidth < static_cast<int>( c_rstr_name_.size() ) ){ m_iWidth = c_rstr_name_.size(); }

	m_istrstrm.clear();
	ssmap_type::iterator sspos;
	sssmap_type::iterator ssspos;
	for( ssspos = m_sssMap.begin(); ssspos != m_sssMap.end(); ++ssspos )
	{
		sspos = ssspos->second.find( c_rstr_name_ );
		if( sspos != ssspos->second.end() )
		{
			m_istrstrm.str( sspos->second );
			return m_istrstrm;
		}
	}

	m_sssMap[ "" ][ c_rstr_name_ ] = c_rstr_def_;
	m_bChangeFlag = true;
	m_istrstrm.str( c_rstr_def_ );

	return m_istrstrm;
}
//---------------------------------------------------------------------------

bool CFileConfig::Set( const std::string & c_rstr_where_,	const std::string & c_rstr_name_,	int  defaultIntData){
	std::string & c_rstr_def_  = UtilityTool::int2stdstring(defaultIntData);

	sssmap_type::iterator ssspos = m_sssMap.find( c_rstr_where_ );
	if( ssspos != m_sssMap.end() )
	{
		ssmap_type::iterator sspos = ssspos->second.find( c_rstr_name_ );
		if( sspos != ssspos->second.end() )
		{
			if( sspos->second != c_rstr_def_ )
			{
				sspos->second = c_rstr_def_;
				m_bChangeFlag = true;
			}
			return true;    // set successfully
		}
	}
	return false;           // fail to set
}

bool CFileConfig::Set( const std::string & c_rstr_where_,	const std::string & c_rstr_name_, const	float  defaultFloatData ){
	std::string & c_rstr_def_  = UtilityTool::float2stdstring(defaultFloatData);
	
	sssmap_type::iterator ssspos = m_sssMap.find( c_rstr_where_ );
	if( ssspos != m_sssMap.end() )
	{
		ssmap_type::iterator sspos = ssspos->second.find( c_rstr_name_ );
		if( sspos != ssspos->second.end() )
		{
			if( sspos->second != c_rstr_def_ )
			{
				sspos->second = c_rstr_def_;
				m_bChangeFlag = true;
			}
			return true;    // set successfully
		}
	}
	return false;           // fail to set
}

bool CFileConfig::Set( const std::string & c_rstr_where_,
	const std::string & c_rstr_name_,
	const std::string & c_rstr_def_ )
{
	sssmap_type::iterator ssspos = m_sssMap.find( c_rstr_where_ );
	if( ssspos != m_sssMap.end() )
	{
		ssmap_type::iterator sspos = ssspos->second.find( c_rstr_name_ );
		if( sspos != ssspos->second.end() )
		{
			if( sspos->second != c_rstr_def_ )
			{
				sspos->second = c_rstr_def_;
				m_bChangeFlag = true;
			}
			return true;    // set successfully
		}
	}
	return false;           // fail to set
}

//---------------------------------------------------------------------------

