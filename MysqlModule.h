//---------------------------------------------------------------------------

#ifndef MysqlModuleH
#define MysqlModuleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <System.IOUtils.hpp>

//---------------------------------------------------------------------------
class TModule : public TDataModule
{
__published:	// IDE-managed Components
	TFDConnection *GodConnection;
	TFDQuery *DataTable;
	TFDQuery *ResultTable;
	TFDQuery *UserTable;
	TWideStringField *DataTablecontent;
	TWideStringField *DataTableexplanation;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	TWideStringField *DataTablename;
	TShortintField *DataTableid;
	TWideStringField *DataTableganzhi;
	TWideStringField *DataTablegua;
	TWideStringField *DataTablepregnant;
	TWideStringField *DataTablefortune;
	TWideStringField *DataTablemarriage;
	TWideStringField *DataTablefame;
	TWideStringField *DataTablefamily_fortune;
	TWideStringField *DataTablewealth;
	TWideStringField *DataTablebusiness;
	TWideStringField *DataTablesick;
	TShortintField *UserTablegender;
	TShortintField *UserTableage;
	TShortintField *UserTableeducation;
	TShortintField *UserTablereligion;
	TShortintField *UserTablecountry;
	TShortintField *UserTableexperience;
	TFDAutoIncField *UserTableid;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	void __fastcall GodConnectionBeforeConnect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TModule(TComponent* Owner);
	void __fastcall filter(int nID);    // ±N≈“∏÷ß‰•X®”~
	int __fastcall addUser(int nGender, int nAge, int nEducation, int nReligion, int nCountry, int nExperience);
};
//---------------------------------------------------------------------------
extern PACKAGE TModule *Module;
//---------------------------------------------------------------------------
#endif
