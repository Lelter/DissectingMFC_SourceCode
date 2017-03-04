#include "stdio.h"
class Rectangle
{
public:
	Rectangle(){ m_cx=0;m_cy=0;};
	Rectangle(float cx,float cy)
	{
	m_cx=cx;
	m_cy=cy;
	}
//����Ϊ������Ϊ�˸�����̳С�
protected:
//m_cx��ˮƽ��ȣ�m_cy�Ǵ�ֱ�߶ȡ�
	float m_cx;
	float m_cy;
public:
//��const�ؼ��֣��ú�������ֱ�ӻ��Ӹ������Ա��
//�ڼ򵥲���ʹ���ʸߵĳ�Ա����ǰ��inline�ؼ��֣��������Ч�ʡ�
	inline float GetCx() const
	{return m_cx;}

	inline float GetCy() const
	{return m_cy;}

	inline void SetCx(float cx)
	{ m_cx=cx;}

	inline void SetCy(float cy)
	{ m_cy=cy;}

	void DispRectInfo();
protected:
  //��Ϊ���麯��ֻ������ڲ�ʹ�ã���������Ϊ�������ڱ�����Ҳ��������Ϊ˽�С�
	virtual float CalculateArea();
};
void Rectangle::DispRectInfo()
{
  printf("the cx=%f\n",GetCx());
  printf("the cy=%f\n",GetCy());
  printf("the area=%f\n",CalculateArea());
}
float Rectangle::CalculateArea()
{	//���麯�����ڼ���������
	return m_cx*m_cy;
}

//print the rectangle
/*
int main(float argc, char* argv[])
{
	Rectangle rect(20,30);
	rect.DispRectInfo();
	return 0;
}
*/

class Parallelogram:public Rectangle
{
public:
	Parallelogram(float cx, float cy,float height):Rectangle(cx,cy)
	{
		m_height = height;
	}
	Parallelogram(){m_height = 0;}
protected:
	float m_height;
public:
	inline float GetHeight() const{return m_height;}
	inline void SetHeight(float height){m_height = height;}

	void DispParalleInfo();

protected:
	//overriding virtual function
	float CalculateArea();
};

void Parallelogram::DispParalleInfo()
{
	printf("the height=%f\n",GetHeight());

	DispRectInfo();
}

float Parallelogram::CalculateArea()
{
	return m_cx*m_height;
}

int main()
{
	Rectangle rect(20,30);
	rect.DispRectInfo();

	Parallelogram para(20,30,10);
	para.DispParalleInfo();
	return 0;
}

