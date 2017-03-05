#include "stdio.h"
class Contain
{
public:
	//����һ������Ϊ���г�Ա
	class Embed
	{
	public:
		Embed(){}
		Embed(int flag){m_flag=flag;}
		int GetValue()const
		{return m_flag;}
		Embed& operator=(const Embed& bed);
		void ShowLink(Contain* pCon);
	private:
		int m_flag;
	}m_bed ;//ͬʱ����һ�������͵ĳ�Ա������Ҳ�ǹ��г�Ա

 //����Ƕ�ඨ��Ϊ���������
	friend class Embed;
public:
	Contain(){}
	Contain(int flag,unsigned char cLink):m_bed(flag)
	{ m_link=cLink;}

	//�����п�������Ӧ���Զ�������ͳ�Ա
	Embed GetEmbedMember()const
	{ return m_bed;}

protected:
	unsigned char m_link;
 };
//���ⲿ������Ƕ��ĳ�Ա������Ҫ��˫��ʶ���޶���Χ
Contain::Embed& Contain::Embed::operator=(const Embed& bed)
		{
			m_flag=bed.m_flag;
			return *this;
		}
void Contain::Embed::ShowLink(Contain* pCon)
		{
		  if(m_flag)
			  printf("%d\n",pCon->m_link);
		  else
	  printf("%c\n",pCon->m_link);
		}
int main(int argc, char* argv[])
{
	Contain::Embed bed;
  Contain con(73,'A');
	con.m_bed.ShowLink(&con);
	bed=con.m_bed;
	printf("%d\n",bed.GetValue());
	return 0;
}
