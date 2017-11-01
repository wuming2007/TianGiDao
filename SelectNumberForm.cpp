//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "SelectNumberForm.h"
#include "MainForm.h"
#include "MysqlModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TSelectNumber *SelectNumber;
//---------------------------------------------------------------------------
__fastcall TSelectNumber::TSelectNumber(TComponent* Owner)
	: TForm(Owner)
{
	cbbNumber->Items->Add(L"½Ð¿ï¾Ü...");
	if (Module->GodConnection->Connected == false) {
		Module->GodConnection->Connected = True;
	}
	if (Module->DataTable->Active == false) {
		Module->DataTable->Active = true;
	}
	Module->DataTable->First();
	while (!Module->DataTable->Eof) {
		cbbNumber->Items->Add(Module->DataTablename->Value);
		Module->DataTable->Next();
	}
	for (int i = 0; i < cbbNumber->Items->Count; i++) {
        cbbNumber->ListBox->ListItems[i]->TextSettings->Font->Size = 32;
	}
}
//---------------------------------------------------------------------------
void __fastcall TSelectNumber::FormShow(TObject *Sender)
{
    cbbNumber->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSelectNumber::btnOKClick(TObject *Sender)
{
	Main->m_nNumber = cbbNumber->ItemIndex;
	Main->m_nGotoReport = 0;
	Main->tbcTianGi->ActiveTab = Main->tbtmResult;
	this->Close();
}
//---------------------------------------------------------------------------
