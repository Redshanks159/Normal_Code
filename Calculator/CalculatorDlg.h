
// CalculatorDlg.h : ͷ�ļ�
//

#pragma once
enum Calculator_Operator { Plus, Subtract, Multiply, Divide };

// CCalculatorDlg �Ի���
class CCalculatorDlg : public CDialogEx
{
// ����
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
							//һ����������								/********************************/	
							//��¼��ǰ���ļ����
	double result;			//num1,num2,result
	double m_Num1;
	double m_Num2;
	/*BOOL str_flag;			//��¼�Ƿ��¼����
	BOOL continue_flag;		//��¼�Ƿ������������֣���û�а��¼����������£�
	BOOL dot_flag;			//С�����־
	BOOL equal_flag;		//�Ⱥű�־
	int count;				//�����õ�
	*/
	Calculator_Operator Optr;
	void SaveFirstValue();        //�����һ������ֵ
	void Calculator();  
	//����
	//�������Զ���ı���
	
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
	//���������ĺ���
	afx_msg void OnBnClickedEqual();
	CString m_Str;
	afx_msg void OnBnClickedpoint();
	afx_msg void OnBnClickedclear();
};
