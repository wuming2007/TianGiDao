//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "MindsetListForm.h"
#include "MysqlModule.h"
#include "SelectNumberForm.h"
#include "MisunderstandForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)

TMain *Main;

String Msg = "";
const String ServiceName = _D("Serial Port Profile");
const String ServiceGUI = "{00001101-0000-1000-8000-00805F9B34FB}";

//---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner)
	: TForm(Owner)
{
#ifdef _Windows
	TRegistry *pTianGi;
	try {
		pTianGi = new TRegistry(KEY_READ | KEY_WRITE);
		pTianGi->RootKey = HKEY_CURRENT_USER;
		if (pTianGi->KeyExists(L"\\SOFTWARE\\jetfire\\God")) {
			pTianGi->OpenKey(L"\\SOFTWARE\\jetfire\\God", KEY_WRITE);
			m_nType = pTianGi->ReadInteger("type");
			m_nFreq = pTianGi->ReadInteger("Freq");
		}
	} catch (...) {
	}
	delete pTianGi;
	pTianGi = NULL;
#endif
	tbcTianGi->Width = this->ClientWidth;
	tbcTianGi->Height = this->ClientHeight;
	tbcTianGi->ActiveTab = tbtmMain;
	tbcTianGi->TabPosition = TTabPosition::None;
	tsBrainwave->Clear();
	tsBrainwave->AddXY(0,0,L"Delta", claRed);
	tsBrainwave->AddXY(1,0,L"Theta", claYellow);
	tsBrainwave->AddXY(2,0,L"LoAlpha",claGreen);
	tsBrainwave->AddXY(3,0,L"HiAlpha", claLime);
	tsBrainwave->AddXY(4,0,L"LoBeta", claAqua);
	tsBrainwave->AddXY(5,0,L"HiBeta", claBlue);
	tsBrainwave->AddXY(6,0,L"LoGamma", claOlive);
	tsBrainwave->AddXY(7,0,L"MidGamma", claPurple);

	m_szConnectedImg = ExtractFilePath(ParamStr(0)) + L"img\\connected_v1.png";
	m_szDisconnectImg = ExtractFilePath(ParamStr(0)) + L"img\\nosignal_v1.png";
	m_szPoorSignal1Img = ExtractFilePath(ParamStr(0)) + L"img\\connecting1_v1.png";
	m_szPoorSignal2Img = ExtractFilePath(ParamStr(0)) + L"img\\connecting2_v1.png";
	m_szPoorSignal3Img = ExtractFilePath(ParamStr(0)) + L"img\\connecting3_v1.png";

	m_bIsEnableTimer = false;
	m_nNumber = 1;
	m_nFunction = 0;
	m_nResult = 0;
	m_nUserId = 0;
	// 初始化問卷數據
	m_nData11 = 3;
	m_nData12 = 3;
	m_nData13 = 3;
	m_nData21 = 3;
	m_nData22 = 3;
	m_nData23 = 3;
	m_nData24 = 3;
	m_nData31 = 3;
	m_nData32 = 3;
	m_nData33 = 3;
	m_nData34 = 3;

//	m_szHomePath =  ExtractFilePath(Application->ExeName);
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnPregnantClick(TObject *Sender)
{
	m_nFunction = 0;
	tbcTianGi->ActiveTab = tbtmUserData;
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnFortuneClick(TObject *Sender)
{
	m_nFunction = 1;
	tbcTianGi->ActiveTab = tbtmUserData;
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnMarriageClick(TObject *Sender)
{
	m_nFunction = 2;
	tbcTianGi->ActiveTab = tbtmUserData;
}
//---------------------------------------------------------------------------
void __fastcall TMain::imgFameClick(TObject *Sender)
{
	btnFameClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnFamilyFortuneClick(TObject *Sender)
{
	m_nFunction = 4;
	tbcTianGi->ActiveTab = tbtmUserData;
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnWealthClick(TObject *Sender)
{
	m_nFunction = 5;
	tbcTianGi->ActiveTab = tbtmUserData;
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnBusinessClick(TObject *Sender)
{
	m_nFunction = 6;
	tbcTianGi->ActiveTab = tbtmUserData;
}
//---------------------------------------------------------------------------
void __fastcall TMain::imgHealthClick(TObject *Sender)
{
	btnHealthClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnFameClick(TObject *Sender)
{
	m_nFunction = 3;
	tbcTianGi->ActiveTab = tbtmUserData;

}
//---------------------------------------------------------------------------
void __fastcall TMain::btnHealthClick(TObject *Sender)
{
	m_nFunction = 7;
	tbcTianGi->ActiveTab = tbtmUserData;
}
//---------------------------------------------------------------------------
void __fastcall TMain::imgPregnantClick(TObject *Sender)
{
	btnPregnantClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMain::imgFortuneClick(TObject *Sender)
{
    btnFortuneClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMain::imgMarriageClick(TObject *Sender)
{
	btnMarriageClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMain::imgFamilyFortuneClick(TObject *Sender)
{
	btnFamilyFortuneClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMain::imgWealthClick(TObject *Sender)
{
	btnWealthClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMain::imgBusinessClick(TObject *Sender)
{
	btnBusinessClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMain::tbcTianGiChange(TObject *Sender)
{
	if (tbcTianGi->ActiveTab == tbtmMain) {
		initTabMain();
	}

	if (tbcTianGi->ActiveTab == tbtmUserData) {
		initTabUserData();
	}

	if (tbcTianGi->ActiveTab == tbtmInstruction) {
		initTabInstruction();
	}

	if (tbcTianGi->ActiveTab == tbtmBrainwaveComm) {
		initTabBrainwaveComm();
	}

	if (tbcTianGi->ActiveTab == tbtmResult) {
		initTabResult();
	}

	if (tbcTianGi->ActiveTab == tbtmSettings){
		initTabSetting();
	}

	if (tbcTianGi->ActiveTab == tbtmReport) {
		initTabReport();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnNextClick(TObject *Sender)
{
	m_nUserId = Module->addUser(m_bGender, m_nAge, m_nEducation, m_nReligion, m_nCountry, m_nExperiece);
	tbcTianGi->ActiveTab = tbtmInstruction;
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnCommClick(TObject *Sender)
{
	tbcTianGi->ActiveTab = tbtmBrainwaveComm;
}
//---------------------------------------------------------------------------
void __fastcall TMain::initTabMain()              // 初始化 main 頁面的一些 UI 值
{
	// 主功能畫面.
	m_nFunction = -1;
	// 檢查執行緒是否屬於半死狀態.
	if (MindwaveConnectionTH != NULL) {
		if (MindwaveConnectionTH->Terminated == true) {
			delete MindwaveConnectionTH;
            MindwaveConnectionTH = NULL;
		}
	}

	for (int i = 0; i < lytFunction->RowCollection->Count; i++) {
		lytFunction->RowCollection->Items[i]->Value = 150;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain::initTabUserData()          // 初始化 UserData 頁面的一些 UI 值
{
	// 蒐集用戶資訊
	m_bGender = -1;
	m_nAge = -1;
	m_nEducation = -1;
	m_nReligion = -1;
	m_nCountry = -1;
	m_nExperiece = -1;

	rbGenderMale->IsChecked = false;
	rbGenderFemale->IsChecked = false;
	rbAge20->IsChecked = false;
	rbAge21to30->IsChecked = false;
	rbAge31to59->IsChecked = false;
	rbAge60->IsChecked = false;
	rbEduElemantary->IsChecked = false;
	rbEduHighSchool->IsChecked = false;
	rbEduCollege->IsChecked = false;
	rbEduGraduate->IsChecked =false;
	rbReligionNone->IsChecked = false;
	rbReligionDao->IsChecked = false;
	rbReligionBudda->IsChecked = false;
	rbReligionCatholicism->IsChecked = false;
	rbReligionChristian->IsChecked = false;
	rbReligionElse->IsChecked = false;
	rbCountryROC->IsChecked = false;
	rbCountryChina->IsChecked = false;
	rbCountryJapan->IsChecked = false;
	rbCountryKorea->IsChecked = false;
	rbCountrySoutheastAsia->IsChecked = false;
	rbCountryWestern->IsChecked = false;
	rbCountryElse->IsChecked = false;
	rbExpNone->IsChecked = false;
	rbExpYes->IsChecked = false;

	btnNext->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMain::initTabInstruction()       // 初始化 Instruction 頁面的一些 UI 值
{
	// 做一些腦波儀的簡單說明
	UnicodeString szInstruction;
	if (m_bGender == 1) {
		szInstruction = L"施主您好，";
	} else {
		if (m_nAge == 0 || m_nAge == 1) {
			szInstruction = L"姑娘您好，";
		} else {
			szInstruction = L"仙姑您好，";
		}
	}

	szInstruction += L"您想詢問有關 ";
	switch (m_nFunction) {
		case 0:
			szInstruction += L"懷孕生子 ";
			break;
		case 1:
			szInstruction += L"個人運勢 ";
			break;
		case 2:
			szInstruction += L"婚姻愛情 ";
			break;
		case 3:
			szInstruction += L"考試功名 ";
			break;
		case 4:
			szInstruction += L"家庭運勢 ";
			break;
		case 5:
			szInstruction += L"財運加薪 ";
			break;
		case 6:
			szInstruction += L"創業經商 ";
			break;
		case 7:
			szInstruction += L"健康疾病 ";
			break;
	}
	szInstruction += L"方面的問題，請參照下方相片方式配戴好腦波儀，準備接入我的客服中心，與諸神通靈。";
	txtInstruction1->Text = szInstruction;
}
//---------------------------------------------------------------------------
void __fastcall TMain::initTabBrainwaveComm()     // 初始化 BrainwaveComm 頁面的一些 UI 值
{
	u8PoolSignal = 200;
	tmrRandom->Enabled = true;
	imgRandomClick(this);
	mmo1->ClearContent();
    mmo1->Lines->Clear();
	mmo1->Lines->Add(L"type:" + IntToStr(m_nType));
	mmo1->Lines->Add(L"freq:" + IntToStr(m_nFreq) + L"-" + IntToStr(m_nFreq1));

	if (FMindwaveDevice == NULL) {
		findMindwave();
	}

	if (FMindwaveDevice != NULL) {
		if (FSocket == NULL) {
			FSocket = FMindwaveDevice->CreateClientSocket(System::Sysutils::StringToGUID(ServiceGUI), false);
		}
		FData.Length = 4132;
		if (FSocket->Connected == false) {
			FSocket->Connect();
			tmrParseData->Enabled = true;
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TMain::initTabResult()            // 初始化 Result 頁面的一些 UI 值
{
	UnicodeString strSummary;

	Module->filter(m_nNumber);

	strSummary = Module->DataTable->FieldByName(L"name")->AsString + L"  " + Module->DataTable->FieldByName(L"ganzhi")->AsString + L"籤  卦象:" + Module->DataTable->FieldByName(L"gua")->AsString + L"  ";

	switch (m_nFunction) {
	case REQ_PREGNANT:
	strSummary = strSummary + L"六甲:" + Module->DataTable->FieldByName(L"pregnant")->AsString;
	break;
	case REQ_FORTUNE:
	strSummary = strSummary + L"運勢:" + Module->DataTable->FieldByName(L"fortune")->AsString;
	break;
	case REQ_MARRIAGE:
	strSummary = strSummary + L"婚姻:" + Module->DataTable->FieldByName(L"marriage")->AsString;
	break;
	case REQ_FAME:
	strSummary = strSummary + L"功名:" + Module->DataTable->FieldByName(L"fame")->AsString;
	break;
	case REQ_FAMILY_FORTUNE:
	strSummary = strSummary + L"家運:" + Module->DataTable->FieldByName(L"family_fortune")->AsString;
	break;
	case REQ_WEALTH:
	strSummary = strSummary + L"財運:" + Module->DataTable->FieldByName(L"wealth")->AsString;
	break;
	case REQ_BUSINESS:
	strSummary = strSummary + L"生意:" + Module->DataTable->FieldByName(L"business")->AsString;
	break;
	case REQ_HEALTH:
	strSummary = strSummary + L"健康:" + Module->DataTable->FieldByName(L"sick")->AsString;
	break;
	}

	txtSummary->Text = strSummary;
	m_nResult = 1;

}
//---------------------------------------------------------------------------
void __fastcall TMain::initTabSetting()           // 初始化 Setting 頁面的一些 UI 值
{

}
//---------------------------------------------------------------------------
void __fastcall TMain::initTabReport()           // 初始化 Report 頁面的一些 UI 值
{
    resetReportBtn();
}
//---------------------------------------------------------------------------
// 處理 Mindwave 連線的 Exception
void __fastcall TMindwaveConnectionTH::TThreadMethodException(void)
{
	// TODO: 處理執行緒的例外狀況
	Main->mmo1->Lines->Add("Mindwave socket closed: " + Msg);
}
//---------------------------------------------------------------------------
// 處理讀到的 Mindwave 資料, 就是要 parsing 資料啦~
void __fastcall TMindwaveConnectionTH::TThreadMethod(void)
{
	// TODO:
#if 0
	Main->mmo1->Lines->Add(L"信號品質:" + IntToStr(u8PoolSignal));
	Main->mmo1->Lines->Add(L"專注度:" + IntToStr(u8Attention));
	Main->mmo1->Lines->Add(L"禪定度:" + IntToStr(u8Meditation));
	Main->mmo1->Lines->Add(L"眨眼強度:" + IntToStr(u8EyeBlink));
	Main->mmo1->Lines->Add(L"Delta:" + IntToStr((int)u32Delta));
	Main->mmo1->Lines->Add(L"Theta:" + IntToStr((int)u32Theta));
	Main->mmo1->Lines->Add(L"Low Alpha:" + IntToStr((int)u32Alpha1));
	Main->mmo1->Lines->Add(L"High Alpha:" + IntToStr((int)u32Alpha2));
	Main->mmo1->Lines->Add(L"Low Beta:" + IntToStr((int)u32Beta1));
	Main->mmo1->Lines->Add(L"High Beta:" + IntToStr((int)u32Beta2));
	Main->mmo1->Lines->Add(L"Low Gamma:" + IntToStr((int)u32Gamma1));
	Main->mmo1->Lines->Add(L"Middle Gamma:" + IntToStr((int)u32Gamma2));
	Main->mmo1->GoToTextEnd();
#endif
	if (u8PoolSignal >= 200) {
		Main->tsBrainwave->YValue[0] = 0;
		Main->tsBrainwave->YValue[1] = 0;
		Main->tsBrainwave->YValue[2] = 0;
		Main->tsBrainwave->YValue[3] = 0;
		Main->tsBrainwave->YValue[4] = 0;
		Main->tsBrainwave->YValue[5] = 0;
		Main->tsBrainwave->YValue[6] = 0;
		Main->tsBrainwave->YValue[7] = 0;
		Main->imgStatus->Bitmap->LoadFromFile(Main->m_szDisconnectImg);
	} else {
		if (u8PoolSignal > 60 && u8PoolSignal < 200) {
			Main->imgStatus->Bitmap->LoadFromFile(Main->m_szPoorSignal1Img);
		} else if (u8PoolSignal > 30 && u8PoolSignal < 60) {
			Main->imgStatus->Bitmap->LoadFromFile(Main->m_szPoorSignal2Img);
		} else if (u8PoolSignal > 15 && u8PoolSignal < 30) {
			Main->imgStatus->Bitmap->LoadFromFile(Main->m_szPoorSignal3Img);
		} else {
			Main->imgStatus->Bitmap->LoadFromFile(Main->m_szConnectedImg);
		}
		Main->tsBrainwave->YValue[0] = u32Delta % 65535;
		Main->tsBrainwave->YValue[1] = u32Theta % 65535;
		Main->tsBrainwave->YValue[2] = u32Alpha1 % 65535;
		Main->tsBrainwave->YValue[3] = u32Alpha2 % 65535;
		Main->tsBrainwave->YValue[4] = u32Beta1 % 65535;
		Main->tsBrainwave->YValue[5] = u32Beta2 % 65535;
		Main->tsBrainwave->YValue[6] = u32Gamma1 % 65535;
		Main->tsBrainwave->YValue[7] = u32Gamma2 % 65535;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMindwaveConnectionTH::Execute(void)
{
	ReturnValue = -1;
	while (!Terminated) {
		try {
			if ((!Terminated) && (FSocket == NULL)) {
				TBluetoothDevice * LDevice = Main->FMindwaveDevice;
				FSocket = LDevice->CreateClientSocket(System::Sysutils::StringToGUID(ServiceGUI), false);
			}
			ReturnValue = 0;
			if (FSocket != NULL) {
				while(!Terminated) {
					if (FSocket->Connected == false) {
						FSocket->Connect();
					}
					FData = FSocket->ReceiveData();
					ParseMessage();
					Synchronize(commStart);
					Sleep(500);
					FData.Length = 0;
				}
			}
		} catch (Exception &e) {
			Msg = e.Message;
			Synchronize(TThreadMethodException);
		} catch (DynArrayException &e) {
			Msg = L"記憶體操作錯誤!";
			FData.Length = 0;
			Synchronize(TThreadMethodException);
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TMindwaveConnectionTH::GentleStop()
{
	this->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TMindwaveConnectionTH::UpdateUI()
{
	// TODO: 更新主畫面的 UI 資訊
	// 馬上判斷是否達到通靈條件
	switch (Main->m_nType) {
	case 0:
		if (Main->m_bIsEnableTimer) {
			if (u32Delta >= Main->m_nFreq && u32Delta < Main->m_nFreq1) {
				Main->tmrRandom->Enabled = false;
				Main->tmrConnect->Enabled = false;
				Main->m_nFreq2 = u32Delta;
				Main->tbcTianGi->ActiveTab = Main->tbtmResult;
				Main->m_nGotoReport = 1;
			}
		}
		break;
	case 1:
		if (Main->m_bIsEnableTimer == false) {
			return;
		}
		if (u32Theta >= Main->m_nFreq && u32Theta < Main->m_nFreq1) {
			Main->tmrRandom->Enabled = false;
			Main->tmrConnect->Enabled = false;
			Main->m_nFreq2 = u32Theta;
			Main->tbcTianGi->ActiveTab = Main->tbtmResult;
			Main->m_nGotoReport = 1;
			this->GentleStop();
		}
		break;
	case 2:
		if (Main->m_bIsEnableTimer == false) {
			return;
		}
		if (u32Alpha1 >= Main->m_nFreq && u32Alpha1 < Main->m_nFreq1) {
			Main->tmrRandom->Enabled = false;
			Main->tmrConnect->Enabled = false;
			Main->m_nFreq2 = u32Alpha1;
			Main->m_nGotoReport = 1;
			Main->tbcTianGi->ActiveTab = Main->tbtmResult;
		}
		break;
	case 3:
		if (Main->m_bIsEnableTimer == false) {
			return;
		}
		if (u32Alpha2 >= Main->m_nFreq && u32Alpha2 < Main->m_nFreq1) {
			Main->tmrRandom->Enabled = false;
			Main->tmrConnect->Enabled = false;
			Main->m_nFreq2 = u32Alpha2;
			Main->m_nGotoReport = 1;
			Main->tbcTianGi->ActiveTab = Main->tbtmResult;
		}
		break;
	case 4:
		if (Main->m_bIsEnableTimer == false) {
			return;
		}
		if (u32Beta1 >= Main->m_nFreq && u32Beta1 < Main->m_nFreq1) {
			Main->tmrRandom->Enabled = false;
			Main->tmrConnect->Enabled = false;
			Main->m_nFreq2 = u32Beta1;
			Main->m_nGotoReport = 1;
			Main->tbcTianGi->ActiveTab = Main->tbtmResult;
		}
		break;
	case 5:
		if (Main->m_bIsEnableTimer == false) {
			return;
		}
		if (u32Beta2 >= Main->m_nFreq && u32Beta2 < Main->m_nFreq1) {
			Main->tmrRandom->Enabled = false;
			Main->tmrConnect->Enabled = false;
			Main->m_nFreq2 = u32Beta2;
			Main->m_nGotoReport = 1;
			Main->tbcTianGi->ActiveTab = Main->tbtmResult;
		}
		break;
	case 6:
		if (Main->m_bIsEnableTimer == false) {
			return;
		}
		if (u32Gamma1 >= Main->m_nFreq && u32Gamma1 < Main->m_nFreq1) {
			Main->tmrRandom->Enabled = false;
			Main->tmrConnect->Enabled = false;
			Main->m_nFreq2 = u32Gamma1;
			Main->m_nGotoReport = 1;
			Main->tbcTianGi->ActiveTab = Main->tbtmResult;
		}
		break;
	case 7:
		if (Main->m_bIsEnableTimer == false) {
			return;
		}
		if (u32Gamma2 >= Main->m_nFreq && u32Gamma2 < Main->m_nFreq1) {
			Main->tmrRandom->Enabled = false;
			Main->tmrConnect->Enabled = false;
			Main->m_nFreq2 = u32Gamma2;
			Main->tbcTianGi->ActiveTab = Main->tbtmResult;
		}
		break;
	}
}
//---------------------------------------------------------------------------
__fastcall TMindwaveConnectionTH::~TMindwaveConnectionTH(void)
{
	FSocket->Free();
}

//---------------------------------------------------------------------------
void __fastcall TMindwaveConnectionTH::ParseMessage(void)
{
	BYTE u8PLength;
	WORD u16Checksum = 0;
	BYTE *pPayload;
	BYTE u8BytesParsed = 0;
	BYTE u8Length;
	int  u16Position = 0;
	BYTE u8Data;
	__int16 i16RawData;

	u16Position = 0;
	int nCount = FData.get_length();
	while (u16Position < nCount) {
Head:	u8Data = FData[u16Position++];
		if (u8Data != 0xAA) {
			continue;
		}
		u8Data = FData[u16Position++];
		if (u8Data != 0xAA) {
			continue;
		}
		u8PLength = FData[u16Position++];
		if (u8PLength != 0x04) {
			if (u8PLength != 0x20) {
				continue;
			}
		}
		if (u8PLength == 0x04) {
			u16Position+=5;
			continue;
		}
		pPayload = new BYTE[u8PLength];
		memset(pPayload, 0, u8PLength);
		u16Checksum = 0;
		for (int i = 0; i < u8PLength; i++) {
			pPayload[i] = FData[u16Position++];
			u16Checksum += pPayload[i];
		}
		u16Checksum &= 0xFF;
		u16Checksum = ~u16Checksum & 0xFF;
		u8Data = FData[u16Position++];
		if (u8Data != u16Checksum) {
			continue;
		}
		u8BytesParsed = 0;
		while (u8BytesParsed < u8PLength) {
			u8Data = pPayload[u8BytesParsed++];
			if(u8Data == 0x80 || u8Data == 0x83)
				u8Length = pPayload[u8BytesParsed++];
			else
				u8Length = 1;

			switch (u8Data) {
				case 0x02:  // Pool signal
					u8PoolSignal = pPayload[u8BytesParsed++];
					break;
				case 0x04:  // Attention
					u8Attention = pPayload[u8BytesParsed++];
					break;
				case 0x05:  // Meditation
					u8Meditation = pPayload[u8BytesParsed++];
					break;
				case 0x16:  // Eye blink strength
					u8EyeBlink = pPayload[u8BytesParsed++];
					break;
				case 0x80:  // Raw data
					i16RawData = pPayload[u8BytesParsed] << 8 | pPayload[u8BytesParsed+1];
					if (i16RawData > 32767)
						i16RawData -= 65536;
					u8BytesParsed += u8Length;
					break;
				case 0x83:  // EEG Power spectrum
					u32Delta = pPayload[u8BytesParsed] << 16 | pPayload[u8BytesParsed+1] << 8 | pPayload[u8BytesParsed+2];
					u32Theta = pPayload[u8BytesParsed+3] << 16 | pPayload[u8BytesParsed+4] << 8 | pPayload[u8BytesParsed+5];
					u32Alpha1 = pPayload[u8BytesParsed+6] << 16 | pPayload[u8BytesParsed+7] << 8 | pPayload[u8BytesParsed+8];
					u32Alpha2 = pPayload[u8BytesParsed+9] << 16 | pPayload[u8BytesParsed+10] << 8 | pPayload[u8BytesParsed+11];
					u32Beta1 = pPayload[u8BytesParsed+12] << 16 | pPayload[u8BytesParsed+13] << 8 | pPayload[u8BytesParsed+14];
					u32Beta2 = pPayload[u8BytesParsed+15] << 16 | pPayload[u8BytesParsed+16] << 8 | pPayload[u8BytesParsed+17];
					u32Gamma1 = pPayload[u8BytesParsed+18] << 16 | pPayload[u8BytesParsed+19] << 8 | pPayload[u8BytesParsed+20];
					u32Gamma2 = pPayload[u8BytesParsed+21] << 16 | pPayload[u8BytesParsed+22] << 8 | pPayload[u8BytesParsed+23];
					u8BytesParsed += u8Length;
					break;
			}
		}
		delete [] pPayload;
		pPayload = NULL;
		Synchronize(UpdateUI);
		Synchronize(TThreadMethod);
	}
}
//---------------------------------------------------------------------------
/*
	我們以 PoolSignal 是否為 0 及 attention 或 meditation 的值大於0 時開始通靈
	此時 tmrRandom 及 tmrConnect 皆開始計時, connect 持續 20 秒, 20秒內若達到通
	靈條件即停止.
*/
void __fastcall TMindwaveConnectionTH::commStart(void)                // 檢查是否可以開始通靈了.
{
	if (Main->m_bIsEnableTimer) {
		return;
	}
	if (u8PoolSignal == 0) {
		if (u8Attention > 0 || u8Meditation > 0) {
			Main->tmrRandom->Enabled = true;
			Main->tmrConnect->Enabled = true;
			Main->m_bIsEnableTimer = true;
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TMain::btn1Click(TObject *Sender)
{
	initTabBrainwaveComm();
}
//---------------------------------------------------------------------------
void __fastcall TMain::tmrRandomTimer(TObject *Sender)
{
	srand(time(NULL));
	m_nNumber = rand() % 61;
}
//---------------------------------------------------------------------------

void __fastcall TMain::tmrConnectTimer(TObject *Sender)
{

	tmrConnect->Enabled = false;
	tmrParseData->Enabled = false;
    tmrRandom->Enabled = false;
//	ShowMessage(L"I cannot understand what you said!");
	Misunderstand->ShowModal();
    FSocket->Close();
	tbcTianGi->ActiveTab = tbtmReport;
	stopMindwave();
	m_bIsEnableTimer = false;
	m_nResult = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMain::imgRandomClick(TObject *Sender)
{
	int nTemp;
	srand(time(NULL));
	cmbType->ItemIndex = (rand() % 64) % 8;
	edtFreq->Text = rand() % 65535;
	edtFreq1->Text = rand() % 65535;
	m_nType = cmbType->ItemIndex;
	m_nFreq = edtFreq->Text.ToInt();
	m_nFreq1 = edtFreq1->Text.ToInt();
	if (m_nFreq > m_nFreq1) {
		nTemp = m_nFreq;
		m_nFreq = m_nFreq1;
		m_nFreq1 = nTemp;
	}
}
//---------------------------------------------------------------------------


void __fastcall TMain::btnSaveClick(TObject *Sender)
{
#ifdef _Windows
	TRegistry *pTianGi;
	try {
		pTianGi = new TRegistry(KEY_READ | KEY_WRITE);
		pTianGi->RootKey = HKEY_CURRENT_USER;
		if (pTianGi->KeyExists(L"\\SOFTWARE\\jetfire\\God")) {
			pTianGi->OpenKey(L"\\SOFTWARE\\jetfire\\God", KEY_WRITE);
			pTianGi->WriteInteger(L"type", cmbType->ItemIndex);
			pTianGi->WriteInteger(L"Freq", m_nFreq);
			pTianGi->WriteInteger(L"Freq1", m_nFreq1);
		}
	} catch (...) {
	}
	delete pTianGi;
	pTianGi = NULL;
#endif

	ShowMessage(L"設定保存完成!");
	tbcTianGi->ActiveTab = tbtmMain;
}
//---------------------------------------------------------------------------

void __fastcall TMain::imgSaveClick(TObject *Sender)
{
	btnSaveClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMain::lblSaveClick(TObject *Sender)
{
	btnSaveClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMain::stopMindwave(void)		 // 結束執行緒
{
	if (MindwaveConnectionTH != NULL) {
		MindwaveConnectionTH->Terminate();
		MindwaveConnectionTH->WaitFor();
		delete MindwaveConnectionTH;
		MindwaveConnectionTH = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain::btnReportClick(TObject *Sender)
{
	if (m_nGotoReport == 1) {
		tbcTianGi->ActiveTab = tbtmReport;
		if (MindwaveConnectionTH != NULL) {
			delete MindwaveConnectionTH;
            MindwaveConnectionTH = NULL;
		}
	} else {
		tbcTianGi->ActiveTab = tbtmMain;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain::btnHomeClick(TObject *Sender)
{
	// TODO:將問卷結果記到資料庫中
	try {
		if (Module->GodConnection->Connected == false) {
			Module->GodConnection->Connected = true;
		}
		if (Module->ResultTable->Active == false) {
			Module->ResultTable->Active = true;
		}

		Module->ResultTable->Append();
			Module->ResultTable->FieldByName(L"user_id")->Value = m_nUserId;
			Module->ResultTable->FieldByName(L"result")->Value = m_nResult;
			if (m_nResult == 1) {
				Module->ResultTable->FieldByName(L"result1")->Value = m_nNumber;
				Module->ResultTable->FieldByName(L"band")->Value = m_nType;
                Module->ResultTable->FieldByName(L"freq")->Value = m_nFreq2;
			}
			Module->ResultTable->FieldByName(L"type")->Value = m_nFunction;
			Module->ResultTable->FieldByName(L"data1-1")->Value = m_nData11;
			Module->ResultTable->FieldByName(L"data1-2")->Value = m_nData12;
			Module->ResultTable->FieldByName(L"data1-3")->Value = m_nData13;
			Module->ResultTable->FieldByName(L"data2-1")->Value = m_nData21;
			Module->ResultTable->FieldByName(L"data2-2")->Value = m_nData22;
			Module->ResultTable->FieldByName(L"data2-3")->Value = m_nData23;
			Module->ResultTable->FieldByName(L"data2-4")->Value = m_nData24;
			Module->ResultTable->FieldByName(L"data3-1")->Value = m_nData31;
			Module->ResultTable->FieldByName(L"data3-2")->Value = m_nData32;
			Module->ResultTable->FieldByName(L"data3-3")->Value = m_nData33;
			Module->ResultTable->FieldByName(L"data3-4")->Value = m_nData34;
		Module->ResultTable->Post();
	} catch (...) {
	}
	// 返回主頁面
	tbcTianGi->ActiveTab = tbtmMain;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1101Change(TObject *Sender)
{
    m_nData11 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1102Change(TObject *Sender)
{
    m_nData11 = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1103Change(TObject *Sender)
{
	m_nData11 = 3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1104Change(TObject *Sender)
{
	m_nData11 = 4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1105Change(TObject *Sender)
{
    m_nData11=5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1201Change(TObject *Sender)
{
    m_nData12=1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1202Change(TObject *Sender)
{
	m_nData12=2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1203Change(TObject *Sender)
{
	m_nData12=3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1204Change(TObject *Sender)
{
    m_nData12=4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1205Change(TObject *Sender)
{
    m_nData12=5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1301Change(TObject *Sender)
{
    m_nData13=1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1302Change(TObject *Sender)
{
    m_nData13=2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1303Change(TObject *Sender)
{
    m_nData13=3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1304Change(TObject *Sender)
{
    m_nData13=4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb1305Change(TObject *Sender)
{
    m_nData13=5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2101Change(TObject *Sender)
{
    m_nData21=1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2102Change(TObject *Sender)
{
    m_nData21=2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2103Change(TObject *Sender)
{
    m_nData21=3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2104Change(TObject *Sender)
{
    m_nData21=4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2105Change(TObject *Sender)
{
    m_nData21=5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2201Change(TObject *Sender)
{
    m_nData22 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2202Change(TObject *Sender)
{
    m_nData22 = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2203Change(TObject *Sender)
{
    m_nData22 = 3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2204Change(TObject *Sender)
{
    m_nData22 = 4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2205Change(TObject *Sender)
{
    m_nData22 = 5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2301Change(TObject *Sender)
{
    m_nData23 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2302Change(TObject *Sender)
{
    m_nData23 = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2303Change(TObject *Sender)
{
    m_nData23 = 3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2304Change(TObject *Sender)
{
    m_nData23 = 4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2305Change(TObject *Sender)
{
    m_nData23 = 5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2401Change(TObject *Sender)
{
    m_nData24 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2402Change(TObject *Sender)
{
    m_nData24 = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2403Change(TObject *Sender)
{
    m_nData24 = 3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2404Change(TObject *Sender)
{
    m_nData24 = 4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb2405Change(TObject *Sender)
{
    m_nData24 = 5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3101Change(TObject *Sender)
{
    m_nData31 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3102Change(TObject *Sender)
{
    m_nData31 = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3103Change(TObject *Sender)
{
    m_nData31 = 3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3104Change(TObject *Sender)
{
    m_nData31 = 4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3105Change(TObject *Sender)
{
    m_nData31 = 5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3201Change(TObject *Sender)
{
    m_nData32 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3202Change(TObject *Sender)
{
    m_nData32 = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3203Change(TObject *Sender)
{
    m_nData32 = 3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3204Change(TObject *Sender)
{
    m_nData32 = 4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3205Change(TObject *Sender)
{
    m_nData32 = 5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3301Change(TObject *Sender)
{
    m_nData33 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3302Change(TObject *Sender)
{
    m_nData33 = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3303Change(TObject *Sender)
{
    m_nData33 = 3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3304Change(TObject *Sender)
{
    m_nData33 = 4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3305Change(TObject *Sender)
{
    m_nData33 = 5;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3401Change(TObject *Sender)
{
    m_nData34 = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3402Change(TObject *Sender)
{
	m_nData34 = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3403Change(TObject *Sender)
{
    m_nData34 = 3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3404Change(TObject *Sender)
{
    m_nData34 = 4;
}
//---------------------------------------------------------------------------

void __fastcall TMain::rb3405Change(TObject *Sender)
{
	m_nData34 = 5;
}
//---------------------------------------------------------------------------
void __fastcall TMain::resetReportBtn(void)       // 將問卷頁面內所有的 radio button 皆設為 uncheck.
{
	rb1101->IsChecked = false;
	rb1102->IsChecked = false;
	rb1103->IsChecked = false;
	rb1104->IsChecked = false;
	rb1105->IsChecked = false;
	rb1201->IsChecked = false;
	rb1202->IsChecked = false;
	rb1203->IsChecked = false;
	rb1204->IsChecked = false;
	rb1205->IsChecked = false;
	rb1301->IsChecked = false;
	rb1302->IsChecked = false;
	rb1303->IsChecked = false;
	rb1304->IsChecked = false;
	rb1305->IsChecked = false;
	rb2101->IsChecked = false;
	rb2102->IsChecked = false;
	rb2103->IsChecked = false;
	rb2104->IsChecked = false;
	rb2105->IsChecked = false;
	rb2201->IsChecked = false;
	rb2202->IsChecked = false;
	rb2203->IsChecked = false;
	rb2204->IsChecked = false;
	rb2205->IsChecked = false;
	rb2301->IsChecked = false;
	rb2302->IsChecked = false;
	rb2303->IsChecked = false;
	rb2304->IsChecked = false;
	rb2305->IsChecked = false;
	rb2401->IsChecked = false;
	rb2402->IsChecked = false;
	rb2403->IsChecked = false;
	rb2404->IsChecked = false;
	rb2405->IsChecked = false;
	rb3101->IsChecked = false;
	rb3102->IsChecked = false;
	rb3103->IsChecked = false;
	rb3104->IsChecked = false;
	rb3105->IsChecked = false;
	rb3201->IsChecked = false;
	rb3202->IsChecked = false;
	rb3203->IsChecked = false;
	rb3204->IsChecked = false;
	rb3205->IsChecked = false;
	rb3301->IsChecked = false;
	rb3302->IsChecked = false;
	rb3303->IsChecked = false;
	rb3304->IsChecked = false;
	rb3305->IsChecked = false;
	rb3401->IsChecked = false;
	rb3402->IsChecked = false;
	rb3403->IsChecked = false;
	rb3404->IsChecked = false;
	rb3405->IsChecked = false;
}

void __fastcall TMain::imgSettingsDblClick(TObject *Sender)
{
    tbcTianGi->ActiveTab = tbtmSettings;
}
//---------------------------------------------------------------------------

void __fastcall TMain::btnSelectNumberClick(TObject *Sender)
{
    SelectNumber->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMain::findMindwave()
{
	try {   // 要連接神念的腦波儀前，需先完成配對，且本程式僅處理一支腦波儀。
		FBluetoothManager = TBluetoothManager::Current;
		FAdapter = FBluetoothManager->CurrentAdapter;
		if (FBluetoothManager->ConnectionState == TBluetoothConnectionState::Connected) {
			FPairedDevices = FBluetoothManager->GetPairedDevices();
			if (FPairedDevices->Count > 0) {    // 找神念腦波儀
				for (int i = 0; i < FPairedDevices->Count; i++) {
					if (FPairedDevices->Items[i]->DeviceName == L"MindWave Mobile") {
						FMindwaveDevice = FPairedDevices->Items[i];
						break;
					}
				}
				mmo1->Lines->Add("We got the mindwave set~");
			} else {
				throw L"Canot find the paired eeg device，please check if it is already paired!";
			}
		} else {
			throw L"We cannot find any bluetooth device!";
		}
	} catch (Exception &e) {
		ShowMessage(e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain::tmrParseDataTimer(TObject *Sender)
{
	try {
		FData = FSocket->ReceiveData();
		parseMessage();
		updateUI();
		checkStatus();
	} catch (...) {
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain::parseMessage()
{
	BYTE u8PLength;
	WORD u16Checksum;
	BYTE pPayload[255];
	BYTE u8BytesParsed;
	BYTE u8Length;
	int  u16Position;
	BYTE u8Data;
	__int16 i16RawData;
	BYTE *pu8Data;

	try {
		u16Position = 0;
		u16Checksum = 0;
		u8BytesParsed = 0;
        u16Position = 0;
		int nCount = FData.get_length();
		pu8Data = new BYTE[nCount+1];
		for (int i= 0; i < FData.Length; i++) {
			pu8Data[i] = FData[i];
		}
		while (u16Position < nCount) {
		u8Data = pu8Data[u16Position++];
	Head:	if (u8Data != 0xAA) {
				continue;
			}
			u8Data = pu8Data[u16Position++];
			if (u8Data != 0xAA) {
				continue;
			}
			u8PLength = pu8Data[u16Position++];
			if (u8PLength != 0x04) {
				if (u8PLength != 0x20) {
					continue;
				}
			}
			if (u8PLength == 0x04) {
				u16Position+=5;
//				goto Head;
				continue;
			}

	//		pPayload = new BYTE[32];
			memset(pPayload, 0, 255);
			u16Checksum = 0;
			for (int i = 0; i < u8PLength; i++) {
				pPayload[i] = pu8Data[u16Position++];
				u16Checksum += pPayload[i];
			}
			u16Checksum &= 0xFF;
			u16Checksum = ~u16Checksum & 0xFF;
			u8Data = pu8Data[u16Position++];
			if (u8Data != u16Checksum) {
				continue;
			}
			u8BytesParsed = 0;
			while (u8BytesParsed < u8PLength) {
				u8Data = pPayload[u8BytesParsed++];
				if(u8Data == 0x80 || u8Data == 0x83)
					u8Length = pPayload[u8BytesParsed++];
				else
					u8Length = 1;
				switch (u8Data) {
					case 0x02:  // Pool signal
						u8PoolSignal = pPayload[u8BytesParsed++];
						break;
					case 0x04:  // Attention
						u8Attention = pPayload[u8BytesParsed++];
						break;
					case 0x05:  // Meditation
						u8Meditation = pPayload[u8BytesParsed++];
						break;
					case 0x16:  // Eye blink strength
						u8EyeBlink = pPayload[u8BytesParsed++];
						break;
					case 0x80:  // Raw data
						i16RawData = pPayload[u8BytesParsed] << 8 | pPayload[u8BytesParsed+1];
						if (i16RawData >= 32767)
							i16RawData -= 65536;
						u8BytesParsed += u8Length;
						break;
					case 0x83:  // EEG Power spectrum
						u32Delta = pPayload[u8BytesParsed] << 16 | pPayload[u8BytesParsed+1] << 8 | pPayload[u8BytesParsed+2];
						u32Theta = pPayload[u8BytesParsed+3] << 16 | pPayload[u8BytesParsed+4] << 8 | pPayload[u8BytesParsed+5];
						u32Alpha1 = pPayload[u8BytesParsed+6] << 16 | pPayload[u8BytesParsed+7] << 8 | pPayload[u8BytesParsed+8];
						u32Alpha2 = pPayload[u8BytesParsed+9] << 16 | pPayload[u8BytesParsed+10] << 8 | pPayload[u8BytesParsed+11];
						u32Beta1 = pPayload[u8BytesParsed+12] << 16 | pPayload[u8BytesParsed+13] << 8 | pPayload[u8BytesParsed+14];
						u32Beta2 = pPayload[u8BytesParsed+15] << 16 | pPayload[u8BytesParsed+16] << 8 | pPayload[u8BytesParsed+17];
						u32Gamma1 = pPayload[u8BytesParsed+18] << 16 | pPayload[u8BytesParsed+19] << 8 | pPayload[u8BytesParsed+20];
						u32Gamma2 = pPayload[u8BytesParsed+21] << 16 | pPayload[u8BytesParsed+22] << 8 | pPayload[u8BytesParsed+23];
						u8BytesParsed += u8Length;
						break;
				}

			}
		}
	} catch (EExternalException  &e) {
		ShowMessage(e.Message);
	} catch (DynArrayOutOfRange &e) {
		UnicodeString strMessage;
		strMessage = "index=" + IntToStr(e.m_Index) + L",count=" + IntToStr(e.m_Count);
		ShowMessage(strMessage);
		FData.Length = 0;
	} catch (...) {
#ifdef _DEBUG
		ShowMessage("unknown error!");
#endif
	}
	delete [] pu8Data;
}

//---------------------------------------------------------------------------
void __fastcall TMain::updateUI(void)
{
		// 處理UI
		if (u8PoolSignal >= 200) {
			tsBrainwave->YValue[0] = 0;
			tsBrainwave->YValue[1] = 0;
			tsBrainwave->YValue[2] = 0;
			tsBrainwave->YValue[3] = 0;
			tsBrainwave->YValue[4] = 0;
			tsBrainwave->YValue[5] = 0;
			tsBrainwave->YValue[6] = 0;
			tsBrainwave->YValue[7] = 0;
			imgStatus->Bitmap = ilConnectStatus->Source->Items[0]->MultiResBitmap->Items[0]->Bitmap;
		} else {
			if (u8PoolSignal > 60 && u8PoolSignal < 200) {
				imgStatus->Bitmap = ilConnectStatus->Source->Items[1]->MultiResBitmap->Items[0]->Bitmap;
			} else if (u8PoolSignal > 30 && u8PoolSignal < 60) {
				imgStatus->Bitmap = ilConnectStatus->Source->Items[2]->MultiResBitmap->Items[0]->Bitmap;
			} else if (u8PoolSignal > 15 && u8PoolSignal < 30) {
				imgStatus->Bitmap = ilConnectStatus->Source->Items[3]->MultiResBitmap->Items[0]->Bitmap;
			} else {
				imgStatus->Bitmap = ilConnectStatus->Source->Items[4]->MultiResBitmap->Items[0]->Bitmap;
			}
			tsBrainwave->YValue[0] = u32Delta % 65535;
			tsBrainwave->YValue[1] = u32Theta % 65535;
			tsBrainwave->YValue[2] = u32Alpha1 % 65535;
			tsBrainwave->YValue[3] = u32Alpha2 % 65535;
			tsBrainwave->YValue[4] = u32Beta1 % 65535;
			tsBrainwave->YValue[5] = u32Beta2 % 65535;
			tsBrainwave->YValue[6] = u32Gamma1 % 65535;
			tsBrainwave->YValue[7] = u32Gamma2 % 65535;
			if (u8PoolSignal == 0) {
				if (u8Attention > 0 || u8Meditation > 0) {
					tmrConnect->Enabled = true;
				}
			}
		}
}
//---------------------------------------------------------------------------
void __fastcall TMain::checkStatus(void)
{
	if (m_nType == 0) {
		if (u32Delta > m_nFreq && u32Delta < m_nFreq1) {
			tmrConnect->Enabled = false;
			tmrRandom->Enabled = false;
			tmrParseData->Enabled = false;
			tbcTianGi->ActiveTab = tbtmResult;
			FSocket->Close();
			FData.Length = 0;
			m_nGotoReport = 1;
			m_nFreq2 = u32Delta;
		}
	}

	if (m_nType == 1) {
		if (u32Theta > m_nFreq && u32Theta < m_nFreq1) {
			tmrConnect->Enabled = false;
			tmrRandom->Enabled = false;
			tmrParseData->Enabled = false;
			tbcTianGi->ActiveTab = tbtmResult;
			FSocket->Close();
			FData.Length = 0;
			m_nGotoReport = 1;
			m_nFreq2 = u32Theta;
		}
	}

	if (m_nType == 2) {
		if (u32Alpha1 > m_nFreq && u32Theta < u32Alpha1) {
			tmrConnect->Enabled = false;
			tmrRandom->Enabled = false;
			tmrParseData->Enabled = false;
			tbcTianGi->ActiveTab = tbtmResult;
			FSocket->Close();
			FData.Length = 0;
			m_nGotoReport = 1;
			m_nFreq2 = u32Alpha1;
		}
	}

	if (m_nType == 3) {
		if (u32Alpha2 > m_nFreq && u32Theta < u32Alpha2) {
			tmrConnect->Enabled = false;
			tmrRandom->Enabled = false;
			tmrParseData->Enabled = false;
			tbcTianGi->ActiveTab = tbtmResult;
			FSocket->Close();
			FData.Length = 0;
			m_nGotoReport = 1;
			m_nFreq2 = u32Alpha2;
		}
	}

	if (m_nType == 4) {
		if (u32Beta1 > m_nFreq && u32Theta < u32Beta1) {
			tmrConnect->Enabled = false;
			tmrRandom->Enabled = false;
			tmrParseData->Enabled = false;
			tbcTianGi->ActiveTab = tbtmResult;
			FSocket->Close();
			FData.Length = 0;
			m_nGotoReport = 1;
			m_nFreq2 = u32Beta1;
		}
	}

	if (m_nType == 5) {
		if (u32Beta2 > m_nFreq && u32Theta < u32Beta2) {
			tmrConnect->Enabled = false;
			tmrRandom->Enabled = false;
			tmrParseData->Enabled = false;
			tbcTianGi->ActiveTab = tbtmResult;
			FSocket->Close();
			FData.Length = 0;
			m_nGotoReport = 1;
			m_nFreq2 = u32Beta2;
		}
	}

	if (m_nType == 6) {
		if (u32Gamma1 > m_nFreq && u32Theta < u32Gamma1) {
			tmrConnect->Enabled = false;
			tmrRandom->Enabled = false;
			tmrParseData->Enabled = false;
			tbcTianGi->ActiveTab = tbtmResult;
			FSocket->Close();
			FData.Length = 0;
			m_nGotoReport = 1;
			m_nFreq2 = u32Gamma1;
		}
	}

	if (m_nType == 7) {
		if (u32Gamma2 > m_nFreq && u32Theta < u32Gamma2) {
			tmrConnect->Enabled = false;
			tmrRandom->Enabled = false;
			tmrParseData->Enabled = false;
			tbcTianGi->ActiveTab = tbtmResult;
			FSocket->Close();
			FData.Length = 0;
			m_nGotoReport = 1;
			m_nFreq2 = u32Gamma2;
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TMain::rbGenderFemaleClick(TObject *Sender)
{
	m_bGender = 0;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain::rbGenderMaleClick(TObject *Sender)
{
	m_bGender = 1;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbAge20Click(TObject *Sender)
{
	m_nAge = 0;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbAge21to30Click(TObject *Sender)
{
	m_nAge = 1;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain::rbAge31to59Click(TObject *Sender)
{
	m_nAge = 2;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbAge60Click(TObject *Sender)
{
	m_nAge = 3;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbEduElemantaryClick(TObject *Sender)
{
	m_nEducation  = 0;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbEduHighSchoolClick(TObject *Sender)
{
	m_nEducation = 1;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain::rbEduCollegeClick(TObject *Sender)
{
	m_nEducation = 2;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbEduGraduateClick(TObject *Sender)
{
	m_nEducation = 3;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbReligionNoneClick(TObject *Sender)
{
	m_nReligion = 0;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbReligionDaoClick(TObject *Sender)
{
	m_nReligion = 1;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbReligionBuddaClick(TObject *Sender)
{
	m_nReligion = 2;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbReligionCatholicismClick(TObject *Sender)
{
	m_nReligion = 3;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbReligionChristianClick(TObject *Sender)
{
	m_nReligion = 4;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbReligionElseClick(TObject *Sender)
{
	m_nReligion = 5;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbCountryROCClick(TObject *Sender)
{
	m_nCountry = 0;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbCountryChinaClick(TObject *Sender)
{
	m_nCountry = 1;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbCountryJapanClick(TObject *Sender)
{
	m_nCountry = 2;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbCountryKoreaClick(TObject *Sender)
{
	m_nCountry = 3;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbCountrySoutheastAsiaClick(TObject *Sender)
{
	m_nCountry = 4;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbCountryWesternClick(TObject *Sender)
{
	m_nCountry = 5;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbCountryElseClick(TObject *Sender)
{
	m_nCountry = 6;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbExpYesClick(TObject *Sender)
{
	m_nExperiece = 1;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TMain::rbExpNoneClick(TObject *Sender)
{
	m_nExperiece = 0;
	if ((m_bGender >= 0) && (m_nAge>=0) && (m_nEducation >= 0) && (m_nReligion >= 0) && (m_nCountry >= 0) && (m_nExperiece >= 0)) {
		btnNext->Enabled = true;
	} else {
		btnNext->Enabled = false;
	}
}
//---------------------------------------------------------------------------

