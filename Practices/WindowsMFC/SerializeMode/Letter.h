// Letter.h: interface for the CLetter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LETTER_H__C859FCFA_8450_45ED_9F76_240CAE6CE770__INCLUDED_)
#define AFX_LETTER_H__C859FCFA_8450_45ED_9F76_240CAE6CE770__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLetter : public CObject  
{
public:
private:
	char m_sLetter;					//�ַ���Ա����
public:
	CLetter( );
	virtual void Serialize(CArchive& ar);	//�������л�����
public:
	void SetLetter(char ch);			//Ϊ�ַ�������ֵ�ĺ���
	char GetLetter( );				//����ַ������ĺ���
	virtual ~CLetter( );
};

#endif // !defined(AFX_LETTER_H__C859FCFA_8450_45ED_9F76_240CAE6CE770__INCLUDED_)
