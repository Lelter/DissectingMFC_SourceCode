///////////////
#include "stdio.h"
#include "string.h"
class Ca
{
public:
	Ca(){m_Style=0;}
    Ca(int style){m_Style=style;}

	//���д�������������Ϊ�����⺯���������ڴ�й©����
//	~Ca(){}
	virtual ~Ca(){}
	virtual void OutputValue()
	{
	 printf("%d\n",m_Style);
	}
private:
	int m_Style;
};

class Cb:public Ca
{
public:
	Cb(){ m_pTitle=NULL;}
	Cb(const char* Title);
	~Cb()
	{
	if(NULL!=m_pTitle)
			delete[] m_pTitle;
	}
    virtual void OutputValue()
	{
		if(NULL!=m_pTitle)
		printf("%s\n",m_pTitle);
	}
private:
  char *m_pTitle;
};

Cb::Cb(const char* Title)
{
	if(NULL==Title)
		m_pTitle=NULL;
	else
	{ m_pTitle=new char[strlen(Title)+1];
	  strcpy(m_pTitle,Title);
	}
}

//���������ɻ���ָ��ָ��ʱ��ʹ��deleteҪע��
int main(int argc, char* argv[])
{
	//�ڶ��й�������������ɻ���ָ������
	Ca* pa=new Cb("bill_server");
	pa->OutputValue();

	/*ɾ�����еĶ����ͷ��ڴ档�����������������û�б����ã�
	���е��ͷ��ڴ����Ҳ���޷���ɣ���Cb::m_pTitleû�еõ��ͷš�*/

	delete pa;  //��Ȼ���Ը�дΪdelete (Cb*)pa; ������Ԥ��֪��ת��������
return 0;
}
