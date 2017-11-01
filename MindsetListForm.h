//---------------------------------------------------------------------------

#ifndef MindsetListFormH
#define MindsetListFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMindsetList : public TForm
{
__published:	// IDE-managed Components
	TListBox *lstMindwave;
	TButton *btnOK;
	TButton *btnCancel;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    int     m_nSelected;
	__fastcall TMindsetList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMindsetList *MindsetList;
//---------------------------------------------------------------------------
#endif
