#include "stdio.h"
#include "string.h"
class Ca
{
public:
	Ca(){m_Style=0;}
Ca(int style){m_Style=style;}
//����������
	virtual ~Ca(){ printf("~ca() called\n");}
//�����麯��
	virtual void OutputStyle()
	{
	 printf("%d\n",m_Style);
	}
//���麯��
	virtual void OutputTitle()=0;
protected:
	int m_Style;
};
class Cb:public Ca
{
public:
	Cb(){ m_pTitle=NULL;}
	Cb(const char* Title,int Style=0);
	~Cb()
	{
		if(NULL!=m_pTitle)
		delete[] m_pTitle;
        printf("~cb() called\n");
	}
 	virtual void OutputStyle()
	{
	 printf("%d\n",~m_Style);
	}
	virtual void OutputTitle()
	{
		if(NULL!=m_pTitle)
		printf("%s\n",m_pTitle);
	}
private:
  char *m_pTitle;
};

Cb::Cb(const char* Title,int Style):Ca(Style)
{
	if(NULL==Title)
		m_pTitle=NULL;
	else
	{ m_pTitle=new char[strlen(Title)+1];
	  strcpy(m_pTitle,Title);
	}
}
int main(int argc, char* argv[])
{
	Ca* pa=new Cb("Fairy");
 //���û��ඨ��ĳ����麯��
//���ڳ�����಻��ʵ��������ֻ��ͨ�������޶��ķ����������ĳ����麯��
	pa->Ca::OutputStyle();
//�������������ص��麯��
	pa->OutputStyle();
	pa->OutputTitle();
//�ͷŶ��е���������󣬽����ȵ������������������
	delete pa;
	return 0;
}
