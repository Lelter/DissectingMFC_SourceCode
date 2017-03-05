#ifndef VARQUEUE_H_INCLUDED
#define VARQUEUE_H_INCLUDED

///////////////////////////
//������ģ�嶨��
template <class POINT_TYPE,int MAX_POINTS> class VarQueue
{
public:
	VarQueue()
	{
		m_MaxCount=MAX_POINTS;
		m_Count=0;
	}
	VarQueue(unsigned int MaxCount)
	{
		if(MaxCount>MAX_POINTS)
			m_MaxCount=MAX_POINTS;
        else
	     m_MaxCount=MaxCount;
		m_Count=0;
	}
public:
	//���Ӵ����Ƚ��ȳ�
	unsigned int PopPoint(POINT_TYPE *Point);
	//��Ӵ���׷���ڶӵ�ĩβ
	unsigned int AppendPoint(const POINT_TYPE &Point);
	//ȡ��ĳ����ֵ
bool GetPoint(POINT_TYPE *Point,unsigned int Position)const;
//ȡ�ý����
unsigned int GetCount()const;
	//��ն���
	void ClearQueue();
private:
	//���е��������
	unsigned int m_MaxCount;
	//���е�ʵ�ʽ����
	unsigned int m_Count;
	//�����������
	POINT_TYPE m_Queue[MAX_POINTS];
};
/////////////////����Ԫ���ඨ��
class CElement
{
public:
	CElement(){fValue=0.0;}
	CElement(float value){fValue=value;}

	CElement& operator =(int value)
	{
	  fValue=(float)value;
	  return *this;
	}
	CElement& operator =(float value)
	{
	  fValue=value;
	  return *this;
	}
	CElement& operator =(CElement elem)
	{
	  fValue=elem.fValue;
	  return *this;
	}
	operator float()
	{return fValue;	}
	float GetValue()const
	{ return fValue;}
private:
	float fValue;
};



#endif // VARQUEUE_H_INCLUDED
