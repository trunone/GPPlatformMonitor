/***************************************************************************
 *   File Name: CDefaultValue.h                                            *
 *  Class Name: CDefaultValue                                              *
 *    Function: 提供 class CFileConfig 的 Get() 與 Set() 之間的溝通橋樑    *
 *     Purpose: 補足 class CFileConfig 在 Get() 與 Set() 之間, 在相互配合  *
 *              上的不方便, 使程式較容易撰寫                               *
 *     Include: <System.hpp>, <sstream>, <string>                          *
 *     Version: 測試版 for BCB                                             *
 *      Update: 2006/04/30                Writer: An-Cheng Cheng           *
 *                                        E-mail: ancheng0802@hotmail.com  *
 ***************************************************************************
 * [Note] 1. 使用說明見 CFileConfig.doc, 使用範例見 CFileConfig.h 下方
 *        2. Console 程式須用 Console wizard 產生並勾選 Use VCL 選項
 *
 ***************************************************************************/
//---------------------------------------------------------------------------

#if !defined(CDefaultConfigH)
#define CDefaultConfigH
//---------------------------------------------------------------------------
#if defined(_NO_VCL)
#error Non-vcl version problem.
#endif // #if defined(_NO_VCL)

//---------------------------------------------------------------------------
#include <sstream>
#include <string.h>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CDefaultConfigBase
{
public:       // User declarations

    CDefaultConfigBase()
        : m_strWhere(""), m_strName(""), m_strDef("") {};
        
    ~CDefaultConfigBase() {};

    bool Init( const std::string & c_rstrWhere_,     // 區塊完整名稱 ( "st r" 與 "st  r" 視為相異 )
               const std::string & c_rstrName_,      // 變數完整名稱 ( "st r" 與 "st  r" 視為相異 )
               const std::string & c_rstrDef_ )      // 預設值字串
    {
        if( c_rstrName_.find( '=' ) != std::string::npos ){ return false; } // 變數名稱不能有等號

        //std::string strdef = c_ranstrDef_.Trim().c_str();
		std::string strdef = c_rstrDef_;
		fnStdStringTrim(strdef);
		
        if( strdef.find( '=' ) != std::string::npos ){ return false; }      // 預設值字串不能有等號
        
        std::string::size_type id;
        if( ( id = c_rstrWhere_.find( '=' ) ) != std::string::npos )        // 區塊名稱不能唯一等號
        {
            if( c_rstrWhere_.substr( 0, id ).find( '=' ) == std::string::npos &&
                c_rstrWhere_.substr( id + 1, std::string::npos ).find( '=' ) == std::string::npos )
            {
                return false;
            }
        }

        m_strWhere = c_rstrWhere_;
        m_strName  = c_rstrName_;
        m_strDef   = strdef;
        return true;
    };

    const std::string & Where() const { return m_strWhere; };   // 取得區塊名稱
    const std::string & Name()  const { return m_strName; };    // 取得變數名稱
    const std::string & Def()   const { return m_strDef; };     // 取得預設值字串

    // friend function
    friend std::ostream & operator << ( std::ostream & os_,
                                        const CDefaultConfigBase & c_rDefConfigBs_ )
    {
        return os_ << c_rDefConfigBs_.Where() << "::"
                   << c_rDefConfigBs_.Name() << " = " << c_rDefConfigBs_.Def();
    };

protected:    // User declarations

    void UpdateDef( const std::string & c_rstrDef_ ){ m_strDef = c_rstrDef_; };

private:      // User declarations

    std::string m_strWhere;    // 區塊名稱
    std::string m_strName;     // 變數名稱
    std::string m_strDef;      // 預設值字串

	std::string fnStdStringTrim(std::string& str)
	{
		std::string::size_type pos = str.find_last_not_of("");
		if(pos != std::string::npos)
		{
			str.erase(pos + 1);
			pos = str.find_first_not_of("");
			if(pos != std::string::npos) str.erase(0, pos);
		}
		else str.erase(str.begin(), str.end());
		return str;
	}

};
//---------------------------------------------------------------------------
template<typename T>
class CDefaultConfig : public CDefaultConfigBase
{
public:       // User declarations

    CDefaultConfig<T> & Update( void )
        { UpdateDef( value ); return *this; };

    T value;               // 變數值

protected:    // User declarations
private:      // User declarations

};
//---------------------------------------------------------------------------
#endif // #if !defined(CDefaultConfigH)

//---------------------------------------------------------------------------
/***************************************************************************
 * 
 ***************************************************************************/

