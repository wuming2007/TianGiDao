//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MindsetListForm.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMindsetList *MindsetList;
//---------------------------------------------------------------------------
__fastcall TMindsetList::TMindsetList(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMindsetList::FormShow(TObject *Sender)
{
    m_nSelected = 0;
}
//---------------------------------------------------------------------------
