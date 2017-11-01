//---------------------------------------------------------------------------

#ifndef SelectNumberFormH
#define SelectNumberFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TSelectNumber : public TForm
{
__published:	// IDE-managed Components
	TImage *imgBG;
	TImage *imgMazu;
	TCalloutRectangle *rctg1;
	TText *txt1;
	TComboBox *cbbNumber;
	TButton *btnOK;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSelectNumber(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSelectNumber *SelectNumber;
//---------------------------------------------------------------------------
#endif
