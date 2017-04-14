// Letter.h: interface for the CLetter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LETTER_H__26EE6B10_8BE6_44E1_9474_6A67C4A62036__INCLUDED_)
#define AFX_LETTER_H__26EE6B10_8BE6_44E1_9474_6A67C4A62036__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLetter : public CObject  
{
	DECLARE_SERIAL(CLetter)
public:
	char m_sLetter;					//�ַ���Ա����
	int m_X,m_Y;
public:
	CLetter( );
	CLetter(char ch,int x,int y);
	virtual void Serialize(CArchive& ar);	//�������л�����
public:
	virtual ~CLetter( );
};

#endif // !defined(AFX_LETTER_H__26EE6B10_8BE6_44E1_9474_6A67C4A62036__INCLUDED_)
