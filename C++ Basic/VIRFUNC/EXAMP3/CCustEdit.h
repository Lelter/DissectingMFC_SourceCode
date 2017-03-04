#ifndef CCUSTEDIT_H_INCLUDED
#define CCUSTEDIT_H_INCLUDED

//insert����ֶ��б���ǰ�ĳ���
#define MAXSIZE_SQL_FIELDS 200
//insert���ֵ�б��Ժ�ĳ���
#define MAXSIZE_SQL_VALUES 200
//name�ֶε���󳤶�
#define MAXSIZE_NAME_FIELD  20
//�ֶ�������󳤶�
#define MAXSIZE_FIELDNAME  20
//���������ֶ���
#define MAX_FIELDSCOUNT 50

//����CCustEdit�Ķ���
class CCustEdit
{
public:
	CCustEdit();
	CCustEdit(const char* FieldName);
	virtual ~CCustEdit(){};
public:
	void BuildFields(char * Statement);
 // ���ඨ���麯����Ϊ�����ṩ���ص���ʽ��
	void virtual BuildValues(char * Statement);
	void SetFieldName(const char * FieldName);

protected:
  //���ڴ洢�ؼ��������ֶ�����
	char m_FieldName[MAXSIZE_FIELDNAME];
};

//����CIntEdit�Ķ���
class CIntEdit:public CCustEdit
{
public:
	CIntEdit();
	CIntEdit(const char * FieldName,int number);
	virtual ~CIntEdit(){};

public:
	void virtual BuildValues(char * Statement);
	CIntEdit& operator =(int iValue);
	void SetValue(int iValue);
	int GetValue()const;

private:
//���ڷ�װ�����ֶ�ֵ:
	int m_data;
};

//����CFoatEdit�Ķ���
class CFloatEdit:public CCustEdit
{
public:
	CFloatEdit();
	CFloatEdit(const char* FieldName,float number);
	virtual ~CFloatEdit(){};
public:
	void virtual BuildValues(char * Statement);
	CFloatEdit& operator =(float fValue);
	void SetValue(float fValue);
	float GetValue()const;

private:
//���ڷ�װ�������ֶ�ֵ
float m_data;
};

//����CVcharEdit�Ķ���
class CVcharEdit:public CCustEdit
{
public:
	CVcharEdit();
	CVcharEdit(const char * FieldName,const char * str);
	virtual ~CVcharEdit(){};
public:
	void virtual BuildValues(char * Statement);
	CVcharEdit& operator =(const char* sValue);
	void SetValue(const char * sValue);
	void GetValue(char * sValue,unsigned int MaxCount)const;

private:
 //���ڷ�װ�ַ������ֶ�ֵ
	char m_data[MAXSIZE_NAME_FIELD];
};



#endif // CCUSTEDIT_H_INCLUDED
