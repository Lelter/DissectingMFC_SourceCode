// MFCexp8_1.h : main header file for the MFCEXP8_1 application
//

#if !defined(AFX_MFCEXP8_1_H__63C52B90_0B03_48B1_946F_DF852449C0EB__INCLUDED_)
#define AFX_MFCEXP8_1_H__63C52B90_0B03_48B1_946F_DF852449C0EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCexp8_1App:
// See MFCexp8_1.cpp for the implementation of this class
//

class CMFCexp8_1App : public CWinApp
{
public:
	CMFCexp8_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCexp8_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCexp8_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXP8_1_H__63C52B90_0B03_48B1_946F_DF852449C0EB__INCLUDED_)
