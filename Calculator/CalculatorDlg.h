
// CalculatorDlg.h : 头文件
//

#pragma once
enum Calculator_Operator { Plus, Subtract, Multiply, Divide };

// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
							//一会儿把它改喽								/********************************/	
							//记录当前按的计算符
	double result;			//num1,num2,result
	double m_Num1;
	double m_Num2;
	/*BOOL str_flag;			//记录是否按下计算符
	BOOL continue_flag;		//记录是否连续按下数字（在没有按下计算符的情况下）
	BOOL dot_flag;			//小数点标志
	BOOL equal_flag;		//等号标志
	int count;				//计数用的
	*/
	Calculator_Operator Optr;
	void SaveFirstValue();        //保存第一个输入值
	void Calculator();  
	//计算
	//以上是自定义的变量
	
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedplus();
	afx_msg void OnBnClickedsubtract();
	afx_msg void OnBnClickedmultiply();
	afx_msg void OnBnClickeddivide();
	//按键触发的函数
	afx_msg void OnBnClickedEqual();
	CString m_Str;
	afx_msg void OnBnClickedpoint();
	afx_msg void OnBnClickedclear();
};
