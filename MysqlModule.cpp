//---------------------------------------------------------------------------


#pragma hdrstop

#include "MysqlModule.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "FMX.Controls.TControl"
#pragma resource "*.dfm"
TModule *Module;
//---------------------------------------------------------------------------
__fastcall TModule::TModule(TComponent* Owner)
	: TDataModule(Owner)
{
	GodConnection->Connected = true;
}
//---------------------------------------------------------------------------
void __fastcall TModule::filter(int nID)
{
	if (GodConnection->Connected == false) {
		GodConnection->Open();
	}

	if (DataTable->Active == false) {
		DataTable->Active = true;
	}

	DataTable->Filtered = false;
	DataTable->Filter = L"id = " + IntToStr(nID);
    DataTable->Filtered = true;
}
//---------------------------------------------------------------------------
int __fastcall TModule::addUser(int nGender, int nAge, int nEducation, int nReligion, int nCountry, int nExperience)
{
	int nUserId;

	nUserId = 0;
	if (GodConnection->Connected == false) {
		GodConnection->Connected = true;
	}

	if (UserTable->Active == false) {
		UserTable->Active = True;
	}

	try {
		UserTable->Append();
			UserTablegender->Value = nGender;
			UserTableage->Value = nAge;
			UserTableeducation->Value = nEducation;
			UserTablereligion->Value = nReligion;
			UserTablecountry->Value = nCountry;
			UserTableexperience->Value = nExperience;
		UserTable->Post();
		nUserId = UserTableid->AsInteger;
		UserTable->Close();
	} catch (...) {
		//ShowMessage(L"儲存用戶資訊資料表時發生錯誤!");
	}
	return nUserId;
}
void __fastcall TModule::GodConnectionBeforeConnect(TObject *Sender)
{
#ifdef __WIN32__
	FDPhysMySQLDriverLink1->VendorHome = GetCurrentDir() + L"\\lib\\win32";
#endif

#ifdef _WIN64
	FDPhysMySQLDriverLink1->VendorHome = GetCurrentDir()+ L"\\lib\\win64";
#endif
	FDPhysMySQLDriverLink1->VendorLib = L"\\libmysql.dll";
	GodConnection->Params->Values[L"Database"] = L"god";
	GodConnection->Params->Values[L"User_Name"] = L"wuming";
	GodConnection->Params->Values[L"Password"] = L"22451010";
//	DaoConnection->Params->Values[L"User_Name"] = L"root";
//	DaoConnection->Params->Values[L"Password"] = L"";
	GodConnection->Params->Values[L"Server"] = L"redmine.jetfire.com.tw";
}
//---------------------------------------------------------------------------

