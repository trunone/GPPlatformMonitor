/***************************************************************************
 *   File Name: CDefaultValue.h                                            *
 *  Class Name: CDefaultValue                                              *
 *    Function: ���� class CFileConfig �� Get() �P Set() ���������q����    *
 *     Purpose: �ɨ� class CFileConfig �b Get() �P Set() ����, �b�ۤ��t�X  *
 *              �W������K, �ϵ{�����e�����g                               *
 *     Include: <System.hpp>, <sstream>, <string>                          *
 *     Version: ���ժ� for BCB                                             *
 *      Update: 2006/04/30                Writer: An-Cheng Cheng           *
 *                                        E-mail: ancheng0802@hotmail.com  *
 ***************************************************************************
 * [Note] 1. �ϥλ����� CFileConfig.doc, �ϥνd�Ҩ� CFileConfig.h �U��
 *        2. Console �{������ Console wizard ���ͨäĿ� Use VCL �ﶵ
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

    bool Init( const std::string & c_rstrWhere_,     // �϶�����W�� ( "st r" �P "st  r" �����۲� )
               const std::string & c_rstrName_,      // �ܼƧ���W�� ( "st r" �P "st  r" �����۲� )
               const std::string & c_rstrDef_ )      // �w�]�Ȧr��
    {
        if( c_rstrName_.find( '=' ) != std::string::npos ){ return false; } // �ܼƦW�٤��঳����

        //std::string strdef = c_ranstrDef_.Trim().c_str();
		std::string strdef = c_rstrDef_;
		fnStdStringTrim(strdef);
		
        if( strdef.find( '=' ) != std::string::npos ){ return false; }      // �w�]�Ȧr�ꤣ�঳����
        
        std::string::size_type id;
        if( ( id = c_rstrWhere_.find( '=' ) ) != std::string::npos )        // �϶��W�٤���ߤ@����
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

    const std::string & Where() const { return m_strWhere; };   // ���o�϶��W��
    const std::string & Name()  const { return m_strName; };    // ���o�ܼƦW��
    const std::string & Def()   const { return m_strDef; };     // ���o�w�]�Ȧr��

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

    std::string m_strWhere;    // �϶��W��
    std::string m_strName;     // �ܼƦW��
    std::string m_strDef;      // �w�]�Ȧr��

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

    T value;               // �ܼƭ�

protected:    // User declarations
private:      // User declarations

};
//---------------------------------------------------------------------------
#endif // #if !defined(CDefaultConfigH)

//---------------------------------------------------------------------------
/***************************************************************************
 * 
 ***************************************************************************/

