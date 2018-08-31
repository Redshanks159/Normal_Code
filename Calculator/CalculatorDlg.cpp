
// CalculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include"math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg �Ի���



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	
	, m_Str(_T(""))
{
	result = 0.0;
	m_Str = "";
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT3, m_Str);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)//�������ʼ��ʱ��ͻ��ID���
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Num_BTN1, &CCalculatorDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(Num_BTN4, &CCalculatorDlg::OnBnClickedBtn4)
	ON_BN_CLICKED(Num_BTN3, &CCalculatorDlg::OnBnClickedBtn3)
	ON_BN_CLICKED(Num_BTN6, &CCalculatorDlg::OnBnClickedBtn6)
	ON_BN_CLICKED(Num_BTN2, &CCalculatorDlg::OnBnClickedBtn2)
	ON_BN_CLICKED(Num_BTN5, &CCalculatorDlg::OnBnClickedBtn5)
	ON_BN_CLICKED(Num_BTN7, &CCalculatorDlg::OnBnClickedBtn7)
	ON_BN_CLICKED(Num_BTN8, &CCalculatorDlg::OnBnClickedBtn8)
	ON_BN_CLICKED(Num_BTN9, &CCalculatorDlg::OnBnClickedBtn9)
	ON_BN_CLICKED(Num_BTN0, &CCalculatorDlg::OnBnClickedBtn0)
	ON_BN_CLICKED(Operator_plus, &CCalculatorDlg::OnBnClickedplus)
	ON_BN_CLICKED(Operator_subtract, &CCalculatorDlg::OnBnClickedsubtract)
	ON_BN_CLICKED(Operator_multiply, &CCalculatorDlg::OnBnClickedmultiply)
	ON_BN_CLICKED(Operator_divide, &CCalculatorDlg::OnBnClickeddivide)
	ON_BN_CLICKED(Operator_Equal, &CCalculatorDlg::OnBnClickedEqual)
	ON_BN_CLICKED(Decimal_point, &CCalculatorDlg::OnBnClickedpoint)
	ON_BN_CLICKED(Btn_clear, &CCalculatorDlg::OnBnClickedclear)
END_MESSAGE_MAP()


// CCalculatorDlg ��Ϣ�������

BOOL CCalculatorDlg::OnInitDialog()
{
	/*CDialogEx::OnInitDialog();
	CEdit *pEdit = (CEdit *)this->GetDlgItem(IDC_EDIT3);
	pEdit->SetLimitText(6);*/
	//SetLimitText(6);
	/*CDialogEx::OnInitDialog()
	{
		mStr.SetLimitText(6);
	}*/

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*double CCalculatorDlg::BtnDownNum( )
{
	double temp,sum=0;
	if (dot_flag)//dotΪ1ʱ�ͰѺ����С������.��//���涼�ñ�
	{
		do
		{
			
			//��������������0.��
		} while (!str_flag || !equal_flag);
		//��0.��
	else//������������
		do 
		{
		
		}while(!str_flag || !equal_flag)
			
		if (str_flag)
			{
				��˵���ǵڶ�����
			}
	
		//input number and judge whether continue is true;
	}	
}
*/

void CCalculatorDlg::OnBnClickedBtn1()
{
	UpdateData(TRUE);
	m_Str += L"1";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedBtn2()
{
	UpdateData(TRUE);
	m_Str += L"2";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedBtn3()
{
	UpdateData(TRUE);
	m_Str += L"3";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedBtn4()
{
	UpdateData(TRUE);
	m_Str += L"4";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedBtn5()
{
	UpdateData(TRUE);
	m_Str += L"5";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedBtn6()
{
	UpdateData(TRUE);
	m_Str += L"6";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedBtn7()
{
	UpdateData(TRUE);
	m_Str += L"7";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedBtn8()
{
	UpdateData(TRUE);
	m_Str += L"8";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedBtn9()
{
	UpdateData(TRUE);
	m_Str += L"9";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedBtn0()
{
	UpdateData(TRUE);
	m_Str += L"0";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//enum Calculator_Operator { Plus, Subtract, Multiply, Divide }//Optr
//enum Optr { Plus, Subtract, Multiply, Divide };
void CCalculatorDlg::OnBnClickedplus()
{	
	SaveFirstValue();
	Optr = Plus;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



void CCalculatorDlg::OnBnClickedsubtract()
{
	SaveFirstValue();
	Optr = Subtract;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCalculatorDlg::OnBnClickedmultiply()
{
	SaveFirstValue();
	Optr = Multiply;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCalculatorDlg::OnBnClickeddivide()
{
	SaveFirstValue();
	Optr = Divide;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::OnBnClickedpoint()
{
	UpdateData(TRUE);
	//���û��С���㣬�����һ��С���㣬�������С����ͺ��Դ˴ε�С���㣬��֤���ֻ��1��  
	if (-1 == m_Str.Find(L'.'))
	{
		m_Str += L".";
	}
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CCalculatorDlg::SaveFirstValue()
{
	UpdateData(TRUE);
	m_Num1 = _wtof(m_Str);
	m_Str = L"";				//mStr�ÿ�
	UpdateData(FALSE);
}
//��ջ�ûд��QAQ

void CCalculatorDlg::OnBnClickedclear()
{
		UpdateData(TRUE);
		m_Str = L"";
		m_Num1 = 0.0f;
		m_Num2 = 0.0f;
		Optr = Plus;
		UpdateData(FALSE);
	}

	// TODO: �ڴ���ӿؼ�֪ͨ����������

/*	void CCalculatorDlg::OnButtonClear()
	{
		UpdateData(TRUE);
		mStr = L"";
		m_Num1 = 0.0f;
		m_Num2 = 0.0f;
		mFlag = FLAG_JIA;//WHY
		UpdateData(FALSE);
	}
*/
void CCalculatorDlg::OnBnClickedEqual()
{
	Calculator();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCalculatorDlg::Calculator()
{
	UpdateData(TRUE);
	m_Num2 = _wtof(m_Str);					//ת��
	double result = 0.0f;
	switch (Optr)
	{
	case Plus:								//��  
		result = m_Num1 + m_Num2;
		break;
	case Subtract:							//�� 
		result = m_Num1 - m_Num2;
		break;
	case Multiply:							//��  
		result = m_Num1 * m_Num2;
		break;
	case Divide:							//��  
		if (m_Num2 == 0.0f)
		{
			//result = m_Num1;
			m_Str = L"Error";
		}
		else
		{
			result = m_Num1 / m_Num2;
		}
		break;
	}
	if (m_Num2 != 0.0f)
	{
		int n, count = 0; CString m_rStr; CString index; double m_Result;
		m_Str.Format(L"%f", result);//ֱ��ͨ��ֵ�����///***Format����//
		n = m_Str.Find(L".");
		m_rStr=m_Str.Left(n+1);
		if (m_rStr.GetLength() > 6)
		{
			m_Result = _wtof(m_rStr);
			do
			{
				m_Result = m_Result / 10.0;
				count++;
			} while (m_Result>=10.0);
			index.Format(L"%d", count);
			m_rStr.Format(L"%f", m_Result);
			m_rStr += L"e";
			m_Str = m_rStr + index;	
		}
	}	
	UpdateData(false);
	m_Num1 = result;
	m_Num2 = 0.0f;
}




