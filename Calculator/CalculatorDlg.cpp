
// CalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include"math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCalculatorDlg 对话框



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

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)//在这儿初始化时候就会和ID相关
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


// CCalculatorDlg 消息处理程序

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

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*double CCalculatorDlg::BtnDownNum( )
{
	double temp,sum=0;
	if (dot_flag)//dot为1时就把后面的小数点后的.几//后面都得变
	{
		do
		{
			
			//持续输入把数变成0.几
		} while (!str_flag || !equal_flag);
		//非0.几
	else//按照正常的做
		do 
		{
		
		}while(!str_flag || !equal_flag)
			
		if (str_flag)
			{
				有说明是第二个数
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
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedBtn2()
{
	UpdateData(TRUE);
	m_Str += L"2";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedBtn3()
{
	UpdateData(TRUE);
	m_Str += L"3";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedBtn4()
{
	UpdateData(TRUE);
	m_Str += L"4";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedBtn5()
{
	UpdateData(TRUE);
	m_Str += L"5";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedBtn6()
{
	UpdateData(TRUE);
	m_Str += L"6";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedBtn7()
{
	UpdateData(TRUE);
	m_Str += L"7";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedBtn8()
{
	UpdateData(TRUE);
	m_Str += L"8";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedBtn9()
{
	UpdateData(TRUE);
	m_Str += L"9";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedBtn0()
{
	UpdateData(TRUE);
	m_Str += L"0";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}

//enum Calculator_Operator { Plus, Subtract, Multiply, Divide }//Optr
//enum Optr { Plus, Subtract, Multiply, Divide };
void CCalculatorDlg::OnBnClickedplus()
{	
	SaveFirstValue();
	Optr = Plus;
	// TODO: 在此添加控件通知处理程序代码
}



void CCalculatorDlg::OnBnClickedsubtract()
{
	SaveFirstValue();
	Optr = Subtract;
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedmultiply()
{
	SaveFirstValue();
	Optr = Multiply;
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickeddivide()
{
	SaveFirstValue();
	Optr = Divide;
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::OnBnClickedpoint()
{
	UpdateData(TRUE);
	//如果没有小数点，则加上一个小数点，如果已有小数点就忽略此次的小数点，保证最多只有1个  
	if (-1 == m_Str.Find(L'.'))
	{
		m_Str += L".";
	}
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}

void CCalculatorDlg::SaveFirstValue()
{
	UpdateData(TRUE);
	m_Num1 = _wtof(m_Str);
	m_Str = L"";				//mStr置空
	UpdateData(FALSE);
}
//清空还没写呢QAQ

void CCalculatorDlg::OnBnClickedclear()
{
		UpdateData(TRUE);
		m_Str = L"";
		m_Num1 = 0.0f;
		m_Num2 = 0.0f;
		Optr = Plus;
		UpdateData(FALSE);
	}

	// TODO: 在此添加控件通知处理程序代码

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
	// TODO: 在此添加控件通知处理程序代码
}
void CCalculatorDlg::Calculator()
{
	UpdateData(TRUE);
	m_Num2 = _wtof(m_Str);					//转换
	double result = 0.0f;
	switch (Optr)
	{
	case Plus:								//加  
		result = m_Num1 + m_Num2;
		break;
	case Subtract:							//减 
		result = m_Num1 - m_Num2;
		break;
	case Multiply:							//乘  
		result = m_Num1 * m_Num2;
		break;
	case Divide:							//除  
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
		m_Str.Format(L"%f", result);//直接通过值来输出///***Format函数//
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




