#pragma once

#include "StandAloneDlg.h"

#define MSG_PROGRESSDLG_UPDATE_UI	(WM_USER+121)
// CProgressDlg dialog
#define MSG_PROGRESSDLG_START 0
#define MSG_PROGRESSDLG_RUN   50
#define MSG_PROGRESSDLG_END   110
#define MSG_PROGRESSDLG_FAILED 111

class CProgressDlg : public CResizableStandAloneDialog
{
	DECLARE_DYNAMIC(CProgressDlg)

public:
	CProgressDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CProgressDlg();
	virtual BOOL OnInitDialog();
// Dialog Data
	enum { IDD = IDD_GITPROGRESS };
	CString m_GitCmd;
	std::vector<CString> m_GitCmdList;
	bool m_bAutoCloseOnSuccess;
	CString m_changeAbortButtonOnSuccessTo;

	CString m_LogFile;

	CProgressCtrl m_Progress;
	
	CEdit		  m_Log;
	CString m_Title;
	CAnimateCtrl  m_Animate;
	CStatic		  m_CurrentWork;
	CWinThread*				m_pThread;	
	volatile LONG			m_bThreadRunning;
	DWORD			  m_GitStatus;
	BOOL		  m_bShowCommand;	// whether to display the command in the log window (default true)
	CString		  m_PreText;		// optional text to show in log window before running command
	CString		  m_LogText;

	bool			m_bAbort;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	static UINT ProgressThreadEntry(LPVOID pVoid);
	UINT		ProgressThread();

	void		ParserCmdOutput(TCHAR ch);
	int			FindPercentage(CString &log);
	void        RemoveLastLine(CString &str);

	LRESULT CProgressDlg::OnProgressUpdateUI(WPARAM wParam,LPARAM lParam);

	void		OnCancel();

	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
