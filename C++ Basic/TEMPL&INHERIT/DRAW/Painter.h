#ifndef PAINTER_H_INCLUDED
#define PAINTER_H_INCLUDED

//����ͼ��ߴ�
#define MAX_PIC_HEIGHT 600
#define MAX_PIC_WIDTH  800
//��ͼ��������
typedef enum ENUM_TOOL_TYPE
{
BRUSH=0,
CIRCLE,
BEELINE,
RECTANGLE,
RUBBER
}ENUM_TOOL;
//���߷��
typedef enum ENUM_TOOL_STYLE
{
SL_NULL=0,
//for Circle
CR_SOLID,
CR_DOT,
//for brush
BS_SOLID,
BS_HATCHED,
//for beeline
BL_SOLID,
BL_DOT,
BL_DASH,
//for rectangle
RT_SOLID,
RT_DOT,
RT_DASH,
//for rubber
RB_MINI,
RB_MID,
RB_MAX
}ENUM_STYLE;
//�����ͼ���ߵĳ������
class DrawingTool
{
public:
	DrawingTool()
	{
	 m_Width=0;
	 m_Style=SL_NULL;
	 };
	virtual void Draw(int left,int top,int right,int bottom,
					int Coordinates_x,int Coordinates_y,unsigned long **DrawingBuffer)=0;
	virtual void SetStyle(ENUM_STYLE style)=0;
     //����ѡ��Ĺ������ù��
	virtual void SetToolCursor()=0;

	inline void SetWidth(unsigned long width)
	{
		m_Width=width;
	}

public:
	unsigned long m_Width;
	ENUM_STYLE m_Style;
	//���徲̬��Ա���浱ǰ��ѡ����ɫ
	static unsigned long m_SelectedColor;
};

unsigned long DrawingTool::m_SelectedColor=0;
//����滭��
class Painter
{
public:
	Painter()
	{
		//��ʼ������������
	 SetDrawingArea(0,0,0,0);
	 m_pTool=NULL;

	 //��ʼ��������������ֵ0Ϊ��ɫ
	 memset((char*)m_DrawingBuffer,0,
		 MAX_PIC_HEIGHT*MAX_PIC_WIDTH*sizeof(unsigned long));
	}
	Painter(int left,int top,int right,int bottom)
	{
		//���û���������
	 SetDrawingArea(left,top,right,bottom);
	 m_pTool=NULL;
	 memset((char*)m_DrawingBuffer,0,
		 MAX_PIC_HEIGHT*MAX_PIC_WIDTH*sizeof(unsigned long));
	}
	//��ʾͼƬ�ļ�
	bool ReadFromFile(char * FilePath);
	//�洢�������ļ�
	bool SaveToFile(char *FilePath);
	//��ת����
	void Rotate(unsigned int degree);
	//���Ŵ���
	void Zoom(float rate);
    //��ɫ����
	void Invert(void);
public:
	//�ɻ�ͼ��Ϣ���øú������л�ͼ
	void OnDraw(int Coordinates_x,int Coordinates_y);
	//���õ�ǰ��ͼ���ߵ�����
	void SetToolCharacteristic(unsigned long width,ENUM_STYLE style);
	//ѡ���ͼ����
	void SelectTool(ENUM_TOOL ToolType);
	//���û�ͼ����
	void SetDrawingArea(int left,int top,int right,int bottom);
	//ѡ��ǰʹ����ɫ
	inline void SetSelectedColor(unsigned long color)
	{
		printf("select color value %lu\n",color);
		DrawingTool::m_SelectedColor=color;
	}
private:
	void ShowDrawing(int Coordinates_x,int Coordinates_y);

private:
//�ó�Ա���ڴ��ͼ�����ݣ�������ռ�ô����ڴ棬���ʺϴ洢�ڶ����У����Զ���Ϊ��̬��Ա��
	static unsigned long m_DrawingBuffer[MAX_PIC_HEIGHT][MAX_PIC_WIDTH];
	int m_PicLeft;
	int m_PicTop;
	int m_PicRight;
	int m_PicBottom;

    //�����ͼ���߳�������ָ���Ա����������ָ��ͬ�Ĺ��ߣ����л�ͼ��
	DrawingTool *m_pTool;

	//����ˢ��Բ�Ρ�ֱ�ߡ����Ρ���Ƥ�Ȼ�ͼ������Ϊ��Ƕ�࣬�������£�
private:
	//���廭ˢ
	class Brush:public DrawingTool
	{
	public:
		Brush(){}
		Brush(ENUM_STYLE style,unsigned long width)
		{
		  m_Style=style;
		  m_Width=width;
		}
		void Draw(int left,int top,int right,int bottom,
				int Coordinates_x,int Coordinates_y,unsigned long **DrawingBuffer);
		void SetStyle(ENUM_STYLE style);
		void SetToolCursor();
	}m_Brush;

    //����Բ�ι���
	class Circle:public DrawingTool
	{
	public:
		Circle(){}
		Circle(ENUM_STYLE style,unsigned long width)
		{
		  m_Style=style;
		  m_Width=width;
		}
	    void Draw(int left,int top,int right,int bottom,
				int Coordinates_x,int Coordinates_y,unsigned long **DrawingBuffer);
		void SetStyle(ENUM_STYLE style);
		void SetToolCursor();
	}m_Circle;

	//����ֱ�߹���
	class Beeline:public DrawingTool
	{
	public:
		Beeline(){}
		Beeline(ENUM_STYLE style,unsigned long width)
		{
		  m_Style=style;
		  m_Width=width;
		}
		void Draw(int left,int top,int right,int bottom,
				int Coordinates_x,int Coordinates_y,unsigned long **DrawingBuffer);
		void SetStyle(ENUM_STYLE style);
		void SetToolCursor();
	}m_Beeline;

	//������ι���
	class Rectangle:public DrawingTool
	{
	public:
		Rectangle(){}
		Rectangle(ENUM_STYLE style,unsigned long width)
		{
		  m_Style=style;
		  m_Width=width;
		}
		void Draw(int left,int top,int right,int bottom,
				int Coordinates_x,int Coordinates_y,unsigned long **DrawingBuffer);
		void SetStyle(ENUM_STYLE style);
		void SetToolCursor();
	}m_Rectangle;

	//������Ƥ����
	class Rubber:public DrawingTool
	{
	public:
		Rubber(){}
		Rubber(ENUM_STYLE style,unsigned long width)
		{
		  m_Style=style;
		  m_Width=width;
		}
		void Draw(int left,int top,int right,int bottom,
				int Coordinates_x,int Coordinates_y,unsigned long **DrawingBuffer);
		void SetStyle(ENUM_STYLE style);
		void SetToolCursor();
	}m_Rubber;
};


#endif // PAINTER_H_INCLUDED
