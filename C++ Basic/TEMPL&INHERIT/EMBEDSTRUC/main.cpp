//����ȫ�ֽṹ����
#include "stdio.h"
#include "memory.h"
struct EmbedStruct
{
	//�ڽṹ����Ĭ��Ϊ���г�Ա
	 int flag;
	 float result;
};
class ContainType
{
public:
//������ڲ�����һ���ṹ������Ϊ���г�Ա
	struct EmbedStruct
	{
//�ڽṹ����Ĭ��Ϊ���г�Ա
	 int flag;
	 float result;
	};
public:
	ContainType(){}
	ContainType(unsigned char cLink)
	{ m_link=cLink;}

private:
	unsigned char m_link;
};
int main(int argc, char* argv[])
{
  //ʹ��ȫ�����ͱ�ʶ��
	:: EmbedStruct gEm;
//ͨ��������ʶʹ��ContainType����Ĺ�������
 	ContainType:: EmbedStruct Emb;
	Emb.flag=82;
	Emb.result=52.00;
    memcpy(&gEm,&Emb,sizeof(gEm));
	printf("%d %8.2f\n",gEm.flag,gEm.result);
	return 0;
}
