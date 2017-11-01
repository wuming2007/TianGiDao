//---------------------------------------------------------------------------

#ifndef MisunderstandFormH
#define MisunderstandFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TMisunderstand : public TForm
{
__published:	// IDE-managed Components
	TImage *imgBG;
	TImage *imgMazu;
	TCalloutRectangle *rctg1;
	TText *txt1;
	TButton *btnOK;
private:	// User declarations
public:		// User declarations
	__fastcall TMisunderstand(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMisunderstand *Misunderstand;
//---------------------------------------------------------------------------
#endif
