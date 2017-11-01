//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <System.Bluetooth.Components.hpp>
#include <System.Bluetooth.hpp>
#include <System.Win.Registry.hpp>
#include <FMX.DialogService.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMXTee.Chart.hpp>
#include <FMXTee.Engine.hpp>
#include <FMXTee.Procs.hpp>
#include <FMXTee.Series.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Edit.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include <vector>
#include <System.SysUtils.hpp>

#define	REQ_PREGNANT		0
#define REQ_FORTUNE			1
#define	REQ_MARRIAGE		2
#define	REQ_FAME			3
#define	REQ_FAMILY_FORTUNE	4
#define	REQ_WEALTH			5
#define	REQ_BUSINESS        6
#define REQ_HEALTH          7

class TMindwaveConnectionTH;
//---------------------------------------------------------------------------
class TMain : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tbcTianGi;
	TTabItem *tbtmMain;
	TTabItem *tbtmUserData;
	TTabItem *tbtmInstruction;
	TTabItem *tbtmBrainwaveComm;
	TTabItem *tbtmResult;
	TTabItem *tbtmSettings;
	TImage *imgBGMain;
	TGridPanelLayout *lytFunction;
	TButton *btnPregnant;
	TImage *imgPregnant;
	TButton *btnFortune;
	TImage *imgFortune;
	TButton *btnMarriage;
	TImage *imgMarriage;
	TButton *btnFame;
	TImage *imgFame;
	TButton *btnFamilyFortune;
	TImage *imgFamilyFortune;
	TButton *btnWealth;
	TImage *imgWealth;
	TButton *btnBusiness;
	TImage *imgBusiness;
	TButton *btnHealth;
	TImage *imgHealth;
	TImage *imgGod;
	TText *txtInstruction;
	TLabel *lblGender;
	TRadioButton *rbGenderFemale;
	TRadioButton *rbGenderMale;
	TLabel *lblAge;
	TRadioButton *rbAge20;
	TRadioButton *rbAge21to30;
	TRadioButton *rbAge31to59;
	TRadioButton *rbAge60;
	TLabel *lblEducation;
	TRadioButton *rbEduElemantary;
	TRadioButton *rbEduHighSchool;
	TRadioButton *rbEduCollege;
	TRadioButton *rbEduGraduate;
	TLabel *lblReligion;
	TRadioButton *rbReligionNone;
	TRadioButton *rbReligionDao;
	TRadioButton *rbReligionBudda;
	TRadioButton *rbReligionCatholicism;
	TRadioButton *rbReligionChristian;
	TRadioButton *rbReligionElse;
	TLabel *lblCountry;
	TRadioButton *rbCountryROC;
	TRadioButton *rbCountryChina;
	TRadioButton *rbCountryJapan;
	TRadioButton *rbCountryKorea;
	TRadioButton *rbCountrySoutheastAsia;
	TRadioButton *rbCountryWestern;
	TRadioButton *rbCountryElse;
	TLabel *lblExperience;
	TRadioButton *rbExpYes;
	TRadioButton *rbExpNone;
	TButton *btnNext;
	TImage *imgBGUser;
	TImage *imgBGInstruction;
	TImage *imgGod1;
	TCalloutRectangle *rctgDialog;
	TText *txtInstruction1;
	TButton *btnComm;
	TImage *imgBGComm;
	TMemo *mmo1;
	TButton *btn1;
	TChart *chtWave;
	TBarSeries *tsBrainwave;
	TTimer *tmrRandom;
	TTimer *tmrConnect;
	TImage *imgStatus;
	TImage *imgBGResult;
	TImage *imgBGSettings;
	TTabItem *tbtmReport;
	TImage *imgBGReport;
	TLabel *lbl1;
	TLabel *lbl2;
	TComboBox *cmbType;
	TLabel *lbl3;
	TEdit *edtFreq;
	TButton *btnRandom;
	TImage *imgRandom;
	TLabel *lblRandom;
	TButton *btnSave;
	TImage *imgSave;
	TLabel *lblSave;
	TImage *img1;
	TText *txtSummary;
	TText *txtContent;
	TMemo *mmoExplanation;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkControlToField *LinkControlToField1;
	TLinkPropertyToField *LinkPropertyToFieldText;
	TButton *btnReport;
	TButton *btnHome;
	TEdit *edtFreq1;
	TText *txtThans;
	TGridPanelLayout *lytReport;
	TText *txt1;
	TText *txt2;
	TText *txt3;
	TText *txt4;
	TText *txt5;
	TText *txt6;
	TText *txt7;
	TRadioButton *rb1101;
	TRadioButton *rb1102;
	TRadioButton *rb1103;
	TRadioButton *rb1104;
	TRadioButton *rb1105;
	TRadioButton *rb1201;
	TRadioButton *rb1202;
	TRadioButton *rb1203;
	TRadioButton *rb1204;
	TRadioButton *rb1205;
	TText *txt9;
	TRadioButton *rb1301;
	TRadioButton *rb1302;
	TRadioButton *rb1303;
	TRadioButton *rb1304;
	TRadioButton *rb1305;
	TText *txt10;
	TRadioButton *rb2101;
	TRadioButton *rb2102;
	TRadioButton *rb2103;
	TRadioButton *rb2104;
	TRadioButton *rb2105;
	TText *txt11;
	TRadioButton *rb2201;
	TRadioButton *rb2202;
	TRadioButton *rb2203;
	TRadioButton *rb2204;
	TRadioButton *rb2205;
	TText *txt12;
	TRadioButton *rb2301;
	TRadioButton *rb2302;
	TRadioButton *rb2303;
	TRadioButton *rb2304;
	TRadioButton *rb2305;
	TText *txt13;
	TRadioButton *rb2401;
	TRadioButton *rb2402;
	TRadioButton *rb2403;
	TRadioButton *rb2404;
	TRadioButton *rb2405;
	TText *txt14;
	TRadioButton *rb3101;
	TRadioButton *rb3102;
	TRadioButton *rb3103;
	TRadioButton *rb3104;
	TRadioButton *rb3105;
	TText *txt15;
	TRadioButton *rb3201;
	TRadioButton *rb3202;
	TRadioButton *rb3203;
	TRadioButton *rb3204;
	TRadioButton *rb3205;
	TText *txt16;
	TRadioButton *rb3301;
	TRadioButton *rb3302;
	TRadioButton *rb3303;
	TRadioButton *rb3304;
	TRadioButton *rb3305;
	TText *txt17;
	TRadioButton *rb3401;
	TRadioButton *rb3402;
	TRadioButton *rb3403;
	TRadioButton *rb3404;
	TRadioButton *rb3405;
	TImage *imgSettings;
	TButton *btnSelectNumber;
	TImage *imgSelectNumber;
	TTimer *tmrParseData;
	TImageList *ilConnectStatus;
	TImage *Image1;
	TLine *Line1;
	TText *txt8;
	TLine *Line2;
	TLine *Line3;
	TLine *Line4;
	TLine *Line5;
	TLine *Line6;
	TLine *Line7;
	TLine *Line8;
	TLine *Line9;
	TLine *Line10;
	TLine *Line11;
	void __fastcall btnPregnantClick(TObject *Sender);
	void __fastcall btnFortuneClick(TObject *Sender);
	void __fastcall btnMarriageClick(TObject *Sender);
	void __fastcall imgFameClick(TObject *Sender);
	void __fastcall btnFamilyFortuneClick(TObject *Sender);
	void __fastcall btnWealthClick(TObject *Sender);
	void __fastcall btnBusinessClick(TObject *Sender);
	void __fastcall imgHealthClick(TObject *Sender);
	void __fastcall btnFameClick(TObject *Sender);
	void __fastcall btnHealthClick(TObject *Sender);
	void __fastcall imgPregnantClick(TObject *Sender);
	void __fastcall imgFortuneClick(TObject *Sender);
	void __fastcall imgMarriageClick(TObject *Sender);
	void __fastcall imgFamilyFortuneClick(TObject *Sender);
	void __fastcall imgWealthClick(TObject *Sender);
	void __fastcall imgBusinessClick(TObject *Sender);
	void __fastcall tbcTianGiChange(TObject *Sender);
	void __fastcall btnNextClick(TObject *Sender);
	void __fastcall btnCommClick(TObject *Sender);
	void __fastcall btn1Click(TObject *Sender);
	void __fastcall tmrRandomTimer(TObject *Sender);
	void __fastcall tmrConnectTimer(TObject *Sender);
	void __fastcall imgRandomClick(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall imgSaveClick(TObject *Sender);
	void __fastcall lblSaveClick(TObject *Sender);
	void __fastcall btnReportClick(TObject *Sender);
	void __fastcall btnHomeClick(TObject *Sender);
	void __fastcall rb1101Change(TObject *Sender);
	void __fastcall rb1102Change(TObject *Sender);
	void __fastcall rb1103Change(TObject *Sender);
	void __fastcall rb1104Change(TObject *Sender);
	void __fastcall rb1105Change(TObject *Sender);
	void __fastcall rb1201Change(TObject *Sender);
	void __fastcall rb1202Change(TObject *Sender);
	void __fastcall rb1203Change(TObject *Sender);
	void __fastcall rb1204Change(TObject *Sender);
	void __fastcall rb1205Change(TObject *Sender);
	void __fastcall rb1301Change(TObject *Sender);
	void __fastcall rb1302Change(TObject *Sender);
	void __fastcall rb1303Change(TObject *Sender);
	void __fastcall rb1304Change(TObject *Sender);
	void __fastcall rb1305Change(TObject *Sender);
	void __fastcall rb2101Change(TObject *Sender);
	void __fastcall rb2102Change(TObject *Sender);
	void __fastcall rb2103Change(TObject *Sender);
	void __fastcall rb2104Change(TObject *Sender);
	void __fastcall rb2105Change(TObject *Sender);
	void __fastcall rb2201Change(TObject *Sender);
	void __fastcall rb2202Change(TObject *Sender);
	void __fastcall rb2203Change(TObject *Sender);
	void __fastcall rb2204Change(TObject *Sender);
	void __fastcall rb2205Change(TObject *Sender);
	void __fastcall rb2301Change(TObject *Sender);
	void __fastcall rb2302Change(TObject *Sender);
	void __fastcall rb2303Change(TObject *Sender);
	void __fastcall rb2304Change(TObject *Sender);
	void __fastcall rb2305Change(TObject *Sender);
	void __fastcall rb2401Change(TObject *Sender);
	void __fastcall rb2402Change(TObject *Sender);
	void __fastcall rb2403Change(TObject *Sender);
	void __fastcall rb2404Change(TObject *Sender);
	void __fastcall rb2405Change(TObject *Sender);
	void __fastcall rb3101Change(TObject *Sender);
	void __fastcall rb3102Change(TObject *Sender);
	void __fastcall rb3103Change(TObject *Sender);
	void __fastcall rb3104Change(TObject *Sender);
	void __fastcall rb3105Change(TObject *Sender);
	void __fastcall rb3201Change(TObject *Sender);
	void __fastcall rb3202Change(TObject *Sender);
	void __fastcall rb3203Change(TObject *Sender);
	void __fastcall rb3204Change(TObject *Sender);
	void __fastcall rb3205Change(TObject *Sender);
	void __fastcall rb3301Change(TObject *Sender);
	void __fastcall rb3302Change(TObject *Sender);
	void __fastcall rb3303Change(TObject *Sender);
	void __fastcall rb3304Change(TObject *Sender);
	void __fastcall rb3305Change(TObject *Sender);
	void __fastcall rb3401Change(TObject *Sender);
	void __fastcall rb3402Change(TObject *Sender);
	void __fastcall rb3403Change(TObject *Sender);
	void __fastcall rb3404Change(TObject *Sender);
	void __fastcall rb3405Change(TObject *Sender);
	void __fastcall imgSettingsDblClick(TObject *Sender);
	void __fastcall btnSelectNumberClick(TObject *Sender);
	void __fastcall tmrParseDataTimer(TObject *Sender);
	void __fastcall rbGenderFemaleClick(TObject *Sender);
	void __fastcall rbGenderMaleClick(TObject *Sender);
	void __fastcall rbAge20Click(TObject *Sender);
	void __fastcall rbAge21to30Click(TObject *Sender);
	void __fastcall rbAge31to59Click(TObject *Sender);
	void __fastcall rbAge60Click(TObject *Sender);
	void __fastcall rbEduElemantaryClick(TObject *Sender);
	void __fastcall rbEduHighSchoolClick(TObject *Sender);
	void __fastcall rbEduCollegeClick(TObject *Sender);
	void __fastcall rbEduGraduateClick(TObject *Sender);
	void __fastcall rbReligionNoneClick(TObject *Sender);
	void __fastcall rbReligionDaoClick(TObject *Sender);
	void __fastcall rbReligionBuddaClick(TObject *Sender);
	void __fastcall rbReligionCatholicismClick(TObject *Sender);
	void __fastcall rbReligionChristianClick(TObject *Sender);
	void __fastcall rbReligionElseClick(TObject *Sender);
	void __fastcall rbCountryROCClick(TObject *Sender);
	void __fastcall rbCountryChinaClick(TObject *Sender);
	void __fastcall rbCountryJapanClick(TObject *Sender);
	void __fastcall rbCountryKoreaClick(TObject *Sender);
	void __fastcall rbCountrySoutheastAsiaClick(TObject *Sender);
	void __fastcall rbCountryWesternClick(TObject *Sender);
	void __fastcall rbCountryElseClick(TObject *Sender);
	void __fastcall rbExpYesClick(TObject *Sender);
	void __fastcall rbExpNoneClick(TObject *Sender);
private:	// User declarations
    bool    m_bUserInit;
	int		m_bGender;		// 0: �k��, 1: �k��
	int    	m_nAge;			// 0: 20�H�U, 1:20-30, 2: 31-59, 3: 60�H�W
	int     m_nEducation;   // 0: �p��, 1:�갪��, 2:�j�M, 3: ��s��
	int 	m_nReligion;    // 0: �L�H��, 1: �D��, 2:���, 3:�ѥD��, 4:�����, 5:��L
	int     m_nCountry;     // 0: ���إ���, 1:����, 2:�饻, 3:����, 4:�F�n��, 5:�ڬ�, 6:��L
	int     m_nExperiece;   // 0: �L�g��, 1: ���g��
	int     m_nFunction;    // 0: ����, 1: �B��, 2:�ýt, 3:�\�W, 4:�a�B, 5:�]�B, 6:�g��, 7:���d
	int     m_nResult;      // �D�Ҧ��\���ѡC0:����, 1:���\
	int     m_nData11;      // �ݨ�1-1, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData12;      // �ݨ�1-2, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData13;      // �ݨ�1-3, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData21;      // �ݨ�2-1, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData22;      // �ݨ�2-2, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData23;      // �ݨ�2-3, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData24;      // �ݨ�2-4, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData31;      // �ݨ�3-1, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData32;      // �ݨ�3-2, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData33;      // �ݨ�3-3, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nData34;      // �ݨ�3-4, 1-5�N��D�`���{�P-�D�`�{�P
	int     m_nUserId;      // �b�s�W���Τ�򥻸�ưݨ���, �O���ӥΤ᪺ ID

	TBluetoothManager * FBluetoothManager;
	TBluetoothDeviceList *FDiscoverDevices;
	TBluetoothAdapter * FAdapter;

	void __fastcall initTabMain();              // ��l�� main �������@�� UI ��
	void __fastcall initTabUserData();          // ��l�� UserData �������@�� UI ��
	void __fastcall initTabInstruction();       // ��l�� Instruction �������@�� UI ��
	void __fastcall initTabBrainwaveComm();     // ��l�� BrainwaveComm �������@�� UI ��
	void __fastcall initTabResult();            // ��l�� Result �������@�� UI ��
	void __fastcall initTabSetting();           // ��l�� Setting �������@�� UI ��
	void __fastcall initTabReport();            // ��l�� Setting(�ݨ�) �������@�� UI ��
	void __fastcall findMindwave();             // �s��EEG
	TMindwaveConnectionTH *MindwaveConnectionTH;
	void __fastcall parseMessage(void);         // �ѪR�ʥ]�T��
	void __fastcall updateUI(void);             // ��sUI
	void __fastcall checkStatus(void);          // �ˬd�O�_�F��q�F����

	void __fastcall resetReportBtn(void);       // �N�ݨ��������Ҧ��� radio button �ҳ]�� uncheck.
public:		// User declarations
	__fastcall TMain(TComponent* Owner);
	TBluetoothDeviceList * FPairedDevices;  	// �O���w�t�諸�Ť��˸m
	TBluetoothDevice *FMindwaveDevice;
	TBluetoothSocket *FSocket;
	TBytes FData;
	UnicodeString m_szConnectedImg;
	UnicodeString m_szPoorSignal1Img;
	UnicodeString m_szPoorSignal2Img;
	UnicodeString m_szPoorSignal3Img;
	UnicodeString m_szDisconnectImg;
	int  m_nType;                               // �O���q�F�W�D
	int  m_nFreq;                               // �O���q�F��q1
	int  m_nFreq1;                              // �O���q�F��q2
	int  m_nFreq2;                              // �O���q�F��q
	BOOL m_bIsEnableTimer;                      // �O�� timer �O�_�w�Ұ�. 0: ���Ұ�, 1: �w�Ұ�
	int  m_nGotoReport;  						// �O�_�n��ݨ��լd����. 0: ����, 1:�n. �Y�O�d���Ҹ�,�N���n�i�ݨ��լd
	int  m_nNumber;      						// �O���Ҽ�
	void __fastcall stopMindwave(void);         // ���������

	Byte        u8PoolSignal;
	Byte        u8Attention;
	Byte        u8Meditation;
	Byte        u8EyeBlink;
	UINT        u32Delta;
	UINT        u32Theta;
	UINT        u32Alpha1;
	UINT        u32Alpha2;
	UINT        u32Beta1;
	UINT    	u32Beta2;
	UINT        u32Gamma1;
	UINT        u32Gamma2;
	UnicodeString m_szHomePath;

};
//---------------------------------------------------------------------------
// �إߤ@�� Thread �M��Ū Mindwave �����
class TMindwaveConnectionTH : public TThread
{
	friend TMain;
private:
	TBluetoothSocket *FSocket;
	TBytes FData;
	void __fastcall TThreadMethod(void);            // �B�z�D�e���� UI
	void __fastcall TThreadMethodException(void);   // �o�ͷN�~����ܪ��T��
	void __fastcall ParseMessage(void);             // �N TGAM ���T���ѪR
	void __fastcall commStart(void);                // �ˬd�O�_�i�H�}�l�q�F�F.

protected:
	void __fastcall Execute(void);
	void __fastcall UpdateUI();
public:
	__fastcall TMindwaveConnectionTH(bool ACreateSuspended) : TThread(ACreateSuspended) { }
	__fastcall ~TMindwaveConnectionTH(void);
	void __fastcall GentleStop(void);

	Byte        u8PoolSignal;
	Byte        u8Attention;
	Byte        u8Meditation;
	Byte        u8EyeBlink;
	UINT        u32Delta;
	UINT        u32Theta;
	UINT        u32Alpha1;
	UINT        u32Alpha2;
	UINT        u32Beta1;
	UINT    	u32Beta2;
	UINT        u32Gamma1;
	UINT        u32Gamma2;

	BYTE        u8Type;                         // �O���q�F���\�����i����, 0: Delta, 1: Theta......�H������
	UINT        u32Data;                        // �O���q�F���\�ɪ����i��q��
};
//---------------------------------------------------------------------------
extern PACKAGE TMain *Main;
//---------------------------------------------------------------------------
#endif
