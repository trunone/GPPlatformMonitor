/***************************************************************************
 *   File Name: CFileConfig.h                                              *
 *  Class Name: CFileConfig                                                *
 *    Function: ���J�]�w��, ���o�S�w�ܼƪ���l��                           *
 *     Purpose: ���Ѥ@��²���K���ɭ��Ӧs���ɮת���l�ȳ]�w               *
 *     Include: <map>, "./CDefaultConfig.h"                                *
 *     Version: ���ժ� for BCB                                             *
 *      Update: 2006/05/04                Writer: An-Cheng Cheng           *
 *                                        E-mail: ancheng0802@hotmail.com  *
 ***************************************************************************
 * [Note] 1. �ԲӮ榡�����P��z��������( CFileConfig.doc ), �ϥνd�Ҩ��U��
 *        2. Console �{������ Console wizard ���ͨäĿ� Use VCL �ﶵ
 *        3. �ϥ� Get() ��n���o����r��, �� std::string str = Get().str();
 *
 ***************************************************************************/
//---------------------------------------------------------------------------

#ifndef CFileConfigH
#define CFileConfigH

//---------------------------------------------------------------------------
#include <map>
//---------------------------------------------------------------------------

#include "./CDefaultConfig.h"

//#include "../stdafx.h"
#include "UtilityTool.h"
//---------------------------------------------------------------------------
class CFileConfig
{
public:		// User declarations

    CFileConfig();
    ~CFileConfig();

    bool DataChanged( void ) const { return m_bChangeFlag; };        // ���o��T�ܧ󪬪p
    std::string CurrFileName( void ) const { return m_strFile; };    // ���o�ثe���ɮ׸��|��T

    void ClearData( void );                             // �M�� ( ��Ȥ� ) �����ܼƸ��

    void Load( void );                                  // Ū�� ( �ϥΥثe���ɮ׸��|��T )
    void Load( const std::string & );                   // Ū�� ( ���ɮ׸��|��T, �ثe���|�Q��s )

    void Save( void );                                  // �s�� ( �ϥΥثe���ɮ׸��|��T )
    void Save( const std::string & );                   // �s�� ( ���ɮ׸��|��T, �ثe���|�Q��s )


	
	//�P�U����ƬۦP�A�ȲĤT�ӿ�J��int
	std::istringstream & Get( const std::string &,      // �϶�����W�� ( "st r" �P "st  r" �����۲� )
							  const std::string &,      // �ܼƧ���W�� ( "st r" �P "st  r" �����۲� )
							  const int );    // �Y���o���Ѫ��w�]��
	//�P�U����ƬۦP�A�ȲĤT�ӿ�J��float
	std::istringstream & Get( const std::string &,      // �϶�����W�� ( "st r" �P "st  r" �����۲� )
		const std::string &,      // �ܼƧ���W�� ( "st r" �P "st  r" �����۲� )
		const float );    // �Y���o���Ѫ��w�]��
	

    std::istringstream & Get( const std::string &,      // �϶�����W�� ( "st r" �P "st  r" �����۲� )
                              const std::string &,      // �ܼƧ���W�� ( "st r" �P "st  r" �����۲� )
                              const std::string & );    // �Y���o���Ѫ��w�]��

    std::istringstream & Get( const std::string &,      // �ܼƧ���W�� ( "st r" �P "st  r" �����۲� )
                              const std::string & );    // �Y���o���Ѫ��w�]��
	

	bool Set( const std::string &,     // �϶�����W�� ( "st r" �P "st  r" �����۲� )
		const std::string &,     // �ܼƧ���W�� ( "st r" �P "st  r" �����۲� )
		const int inInt );   // �]���s���w���w�]��int

    bool Set( const std::string &,     // �϶�����W�� ( "st r" �P "st  r" �����۲� )
              const std::string &,     // �ܼƧ���W�� ( "st r" �P "st  r" �����۲� )
              const float inFloat );   // �]���s���w���w�]��float
	
	bool Set( const std::string &,     // �϶�����W�� ( "st r" �P "st  r" �����۲� )
		const std::string &,     // �ܼƧ���W�� ( "st r" �P "st  r" �����۲� )
		const std::string & );   // �]���s���w���w�]��


    inline std::istringstream & Get( const CDefaultConfigBase & c_rDefConfigBs_ )
    {
        return Get( c_rDefConfigBs_.Where(), c_rDefConfigBs_.Name(), c_rDefConfigBs_.Def() );
    };

    inline bool Set( const CDefaultConfigBase & c_rDefConfigBs_ )
    {
        return Set( c_rDefConfigBs_.Where(), c_rDefConfigBs_.Name(), c_rDefConfigBs_.Def() );
    };


protected:	// User declarations

    typedef std::map<std::string,std::string> ssmap_type;
    typedef std::map<std::string,ssmap_type> sssmap_type;

    std::istringstream m_istrstrm;     // �ܼƪ�l�Ȧr���y���Ȧs�ܼ�
    std::string m_strFile;             // �ثe���ɮ׸��|��T
    sssmap_type m_sssMap;              // �ܼƪ�l�Ȫ�

    bool m_bChangeFlag;                // ��T�ܧ󪬪p
    int  m_iWidth;                     // �ܼƦW�٦s�ɮ榡�Ƽe��

    void TrimStr( std::string & );     // �����@���r��e�᪺�ťզr���P Tab �r��



private:	// User declarations

};
//---------------------------------------------------------------------------
#endif // #ifndef CFileConfigH
/***************************************************************************
 * - �ϥνd�� - 2006/04/10 update
 *--------------------------------------------------------------------------
 * ...test.txt...( �G�N����� )
 *
 *  testInt   = 98
 *
 *     [Mine]
 *
 *   myChar  =  C
 *
 *     testInt   = 321
 *
 *--------------------------------------------------------------------------
 * #include <iostream>
 * using namespace std;
 *
 * #include "./CFileConfig/CFileConfig.h"
 *
 * int main()
 * {
 *     char testChar, myChar;
 *     int testInt;
 *     float testFloat;
 *     string testStr;
 *
 *     CFileConfig fc;                                 ////////////////////////////////////////////
 *     fc.Load( "test.txt" );                          // ( Load file )
 *
 *
 *     CDefaultConfig<int> idef;
 *     CDefaultConfig<float> fdef;
 *     CDefaultConfig<string> strdef;
 *                                                     ////////////////////////////////////////////
 *     idef.Init( "[2006-04-10 update]",               // Init wherestr,
 *                "int default", 137 );                //      namestr, and defaultstr of idef
 *                                                     //
 *     fdef.Init( "[2006-04-10 update]",               // Init wherestr,
 *                "float default", -6.7 );             //      namestr, and defaultstr of fdef
 *                                                     //
 *     strdef.Init( "[2006-04-10 update]",             // Init wherestr,
 *                  "string default", "string" );      //      namestr, and defaultstr of strdef
 *                                                     //
 *     cout << "<idef> " << idef << endl;              // [Output] <idef> [2006-04-10 update]::int default = 137
 *     cout << "<fdef> " << fdef << endl;              // [Output] <fdef> [2006-04-10 update]::float default = -6.7
 *     cout << "<strdef> " << strdef << endl;          // [Output] <strdef> [2006-04-10 update]::string default = string
 *                                                     //
 *     fc.Get( idef ) >> idef.value;                   // idef.value   = 137 (default)
 *     fc.Get( fdef ) >> fdef.value;                   // fdef.value   = -6.7 (default)
 *     fc.Get( strdef ) >> strdef.value;               // strdef.value = string (default)
 *                                                     //
 *     cout << "idef.value = " << idef.value << endl;  // [Output] idef.value = 137
 *     cout << "fdef.value = " << fdef.value << endl;  // [Output] fdef.value = -6.7
 *     cout << "strdef.value = " << strdef.value       // [Output] strdef.value = string
 *          << endl;                                   //
 *                                                     //
 *     idef.value += 10;                               // idef.value = 147
 *     fdef.value *= 2;                                // fdef.value = -13.4
 *
 *                                                     ////////////////////////////////////////////
 *     fc.Get( "testChar", "A" ) >> testChar;          // testChar  = 'A' (default)
 *     fc.Get( "testInt", "123" ) >> testInt;          // testInt   = 98
 *     fc.Get( "testFloat", "-3.6" ) >> testFloat;     // testFloat = -3.6 (default)
 *                                                     //
 *     cout << "testChar = " << testChar << endl;      // [Output] testChar = A
 *     cout << "testInt = "  << testInt << endl;       // [Output] testInt = 98
 *     cout << "testFloat = "  << testFloat << endl;   // [Output] testFloat = -3.6
 *
 *                                                     ////////////////////////////////////////////
 *     fc.Get( "", "testInt", "0" ) >> testInt;        // testInt = 98
 *     cout << "::testInt = " << testInt << endl;      // [Output] ::testInt = 98
 *                                                     //
 *     fc.Get( "[Mine]", "myChar", "0" ) >> myChar;    // myChar = 'C'
 *     cout << "[Mine]::myChar = " << myChar << endl;  // [Output] [Mine]::myChar = C
 *                                                     //
 *     fc.Get( "[Mine]", "myInt", "-45" ) >> testInt;  // testInt = -45 (default)
 *     cout << "[Mine]::myInt = " << testInt << endl;  // [Output] [Mine]::myInt = -45
 *                                                     //
 *     fc.Get( "[Mine]", "testInt", "0" ) >> testInt;  // testInt = 321
 *     cout << "[Mine]::testInt = "                    // [Output] [Mine]::testInt = 321
 *          << testInt << endl;                        //
 *                                                     //
 *     fc.Get( "[Added]", "Int", "555" ) >> testInt;   // testInt = 555 (default)
 *     cout << "[Added]::Int = " << testInt << endl;   // [Output] [Added]::Int = 555
 *
 *                                                     ////////////////////////////////////////////
 *     fc.Get( "Char + Int", "Z  50" )                 // testChar = 'Z' (default)
 *         >> testChar >> testInt;                     // testInt = 50   (default)
 *                                                     //
 *     cout << "Char + Int = "                         // [Output] Char + Int = [ch]Z[ch], [int]50[int]
 *          << "[ch]" << testChar << "[ch], "          //
 *          << "[int]" << testInt << "[int]" << endl;  //
 *                                                     //
 *     fc.Get( "Char + Int", "X  99" )                 // testChar = 'Z'
 *         >> testChar >> testInt;                     // testInt = 50
 *                                                     //
 *     cout << "Char + Int = "                         // [Output] Char + Int = [ch]Z[ch], [int]50[int]
 *          << "[ch]" << testChar << "[ch], "          //
 *          << "[int]" << testInt << "[int]" << endl;  //
 *
 *                                                     ////////////////////////////////////////////
 *     fc.Get( "testStr", "My test ..." ) >> testStr;  // testStr = "My"
 *     cout << "testStr = " << testStr << endl;        // [Output] testStr = My
 *                                                     //
 *     testStr = fc.Get( "testStr", "string" ).str();  // testStr = "My test ..."
 *     cout << "testStr = " << testStr << endl;        // [Output] testStr = My test ...
 *
 *                                                     ////////////////////////////////////////////
 *     fc.Save( "newtest.txt" );                       // Save all settings to a new file
 *
 *                                                     ////////////////////////////////////////////
 *     if( fc.Set( "[Added]", "Int", "345" ) )         // change [Added]::Int from 555 to 345
 *     {                                               //
 *         cout << "change [Added]::Int to 345"        // [Output] Set [Added]::Int = 345
 *              << endl;                               //
 *     }                                               //
 *     else                                            // change [Added]::Int from 555 to 345
 *     {                                               //
 *         cout << " * Can't find [Added]::Int"        // [Won't Output]  * Can't find [Added]::Int
 *              << endl;                               //
 *     }                                               //
 *
 *                                                     ////////////////////////////////////////////
 *     fc.Set( idef.Update() );                        // [2006-04-10 update]::int default = 147
 *     fc.Set( fdef.Update() );                        // [2006-04-10 update]::float default = -13.4
 *     fc.Set( strdef.Update() );                      // [2006-04-10 update]::string default = string
 *                                                     //
 *     cout << "<idef> " << idef << endl;              // [Output] <idef> [2006-04-10 update]::int default = 147
 *     cout << "<fdef> " << fdef << endl;              // [Output] <fdef> [2006-04-10 update]::float default = -13.3999996185303
 *     cout << "<strdef> " << strdef << endl;          // [Output] <strdef> [2006-04-10 update]::string default = string
 *
 *                                                     ////////////////////////////////////////////
 *     fc.Save( "newtest(changed).txt" );              // Save all settings to a new file
 *
 *                                                     ////////////////////////////////////////////
 *     cin.get();                                      // Hold window
 *
 *     return 0;
 * }
 *
 *--------------------------------------------------------------------------
 * ( �۰ʱƧǰ϶��P�϶����ѼƳ]�w��, �è㦳�ۦP��������m )
 *--------------------------------------------------------------------------
 * ...newtest.txt...
 * Char + Int     = Z  50
 * testChar       = A
 * testFloat      = -3.6
 * testInt        = 123
 * testStr        = My test ...
 *
 * [2006-04-10 update]
 * float default  = -6.7
 * int default    = 137
 * string default = string
 *
 * [Added]
 * Int            = 555
 *
 * [Mine]
 * myChar         = C
 * myInt          = -45
 * testInt        = 321
 *
 *
 *--------------------------------------------------------------------------
 * ...newtest(changed).txt...( �Y�ǳ]�w�w��� )
 * Char + Int     = Z  50
 * testChar       = A
 * testFloat      = -3.6
 * testInt        = 123
 * testStr        = My test ...
 *
 * [2006-04-10 update]
 * float default  = -13.3999996185303
 * int default    = 147
 * string default = string
 *
 * [Added]
 * Int            = 345
 *
 * [Mine]
 * myChar         = C
 * myInt          = -45
 * testInt        = 321
 *
 *
 ***************************************************************************/
 
