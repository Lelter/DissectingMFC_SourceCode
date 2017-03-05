//////////////////////////C141.CPP
#include "stdio.h"
#include "VarQueue.h"
//������ģ���ʵ��
template <class POINT_TYPE,int MAX_POINTS>
       unsigned int VarQueue<POINT_TYPE,MAX_POINTS>::PopPoint(POINT_TYPE *Point)
{
	unsigned int i=0;
  if(m_Count>0)
  {
	  if(NULL!=Point)
		  *Point=m_Queue[0];
	  for(i=1;i<m_Count;i++)
	  {
	     m_Queue[i-1]=m_Queue[i];
	  }
	  m_Count--;
  }
	  return m_Count;
}

template <class POINT_TYPE,int MAX_POINTS>
		unsigned int VarQueue<POINT_TYPE,MAX_POINTS>::AppendPoint(const POINT_TYPE &Point)
	{
		if(m_Count<m_MaxCount)
	         m_Queue[m_Count++]=Point;

	  return m_Count;
	}

template <class POINT_TYPE,int MAX_POINTS>
		bool VarQueue<POINT_TYPE, MAX_POINTS>::GetPoint(POINT_TYPE *Point,unsigned int Position)const
	{
	  if(Position<m_Count && NULL!=Point)
	  {	  *Point=m_Queue[Position];
	    return true;
	  }
	  else return false;
	}

template <class POINT_TYPE,int MAX_POINTS>
		inline unsigned int  VarQueue<POINT_TYPE,MAX_POINTS>::GetCount()const
{
  return m_Count;
}

template <class POINT_TYPE,int MAX_POINTS>
		void VarQueue<POINT_TYPE,MAX_POINTS>::ClearQueue()
	{ m_Count=0;
	}
//////////////////////////////

int main(int argc, char* argv[])
{
	/*��ģ��ʵ����Ϊ�������50��Ԫ�ص����Ͷ���,����ΪVarQueue<int,50>,
	�ɸ���ʵ�����Ķ�����ΪiQueue */
	VarQueue<int,50> iQueue(20);
	/*��ģ��ʵ����Ϊ�������50��Ԫ�ص�CElement�Ͷ���,����ΪVarQueue <CElement,30>,
	�ɸ���ʵ�����Ķ�����ΪfQueue */
  VarQueue<CElement,30> fQueue(10);
	int ival=0;
	unsigned count=0;;
  CElement fval=1.0;

	for(unsigned int i=0;i<4;i++)
	iQueue.AppendPoint(i);

	count=iQueue.GetCount();
	for(unsigned int i=0;i<count;i++)
	{
		iQueue.PopPoint(&ival);
		fQueue.AppendPoint((float)ival);
	}
	for(unsigned int i=0;i<fQueue.GetCount();i++)
	{
	fQueue.GetPoint(&fval,i);
	printf("%4.2f\n",fval.GetValue());
	}
	iQueue.ClearQueue();
  fQueue.ClearQueue();
	return 0;
}
