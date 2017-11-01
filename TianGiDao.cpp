//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("MysqlModule.cpp", Module); /* TDataModule: File Type */
USEFORM("MainForm.cpp", Main);
USEFORM("MindsetListForm.cpp", MindsetList);
USEFORM("MisunderstandForm.cpp", Misunderstand);
USEFORM("SelectNumberForm.cpp", SelectNumber);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMain), &Main);
		Application->CreateForm(__classid(TModule), &Module);
		Application->CreateForm(__classid(TMindsetList), &MindsetList);
		Application->CreateForm(__classid(TMisunderstand), &Misunderstand);
		Application->CreateForm(__classid(TSelectNumber), &SelectNumber);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
