//Aim: print "insert SQL"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "CCustEdit.h"

//////////����CCustEdit��ʵ��
CCustEdit::CCustEdit()
{
	memset(m_FieldName,0,MAXSIZE_FIELDNAME);
}
CCustEdit::CCustEdit(const char* FieldName)
{
//�β�FieldName���ڳ�ʼ��m_FieldName
// memset : to initial m_FieldName with 0
		memset(m_FieldName,0,MAXSIZE_FIELDNAME);
	  if(NULL==FieldName)
		return;
	 if(strlen(FieldName)>=MAXSIZE_FIELDNAME)
	  {  printf("the field name %s is too long,truncated it",FieldName);
	     strncpy(m_FieldName,FieldName,MAXSIZE_FIELDNAME-1);
	  }
	  else
		  strcpy(m_FieldName,FieldName);
}

void CCustEdit::BuildValues(char * Statement)
{
	  printf("insert statement is %s\n",Statement);
}

void CCustEdit::BuildFields(char * Statement)
{
		//���������ֶ��б���	�������ֶ���m_FieldName��һ��','�ַ�׷�ӵ�ʵ��Statement��
  		if(NULL==Statement)
        return;
		if(strlen(Statement)>MAXSIZE_SQL_FIELDS-strlen(m_FieldName)-2)
			printf("out of buffer when build statement with fields \n");
		else
	     sprintf(Statement+strlen(Statement),"%s,",m_FieldName);
}
void CCustEdit::SetFieldName(const char * FieldName)
{
	//�β�FieldName��������m_FieldName
	  if(NULL==FieldName)
		return;
	  memset(m_FieldName,0,MAXSIZE_FIELDNAME);
	  if(strlen(FieldName)>=MAXSIZE_FIELDNAME)
	  {  printf("the field name %s is too long,truncated it",FieldName);
	     strncpy(m_FieldName,FieldName,MAXSIZE_FIELDNAME-1);
	  }
	  else
		  strcpy(m_FieldName,FieldName);

}

////////////////����CIntEdit��ʵ��
CIntEdit::CIntEdit(const char * FieldName,int number):CCustEdit(FieldName)
{
	m_data=number;
}
CIntEdit& CIntEdit::operator =(int iValue)
{
	  m_data=iValue;
	  return *this;
}
void CIntEdit::SetValue(int iValue)
{
		  *this=iValue;
}
int CIntEdit::GetValue()const
{
	return m_data;
}
void CIntEdit::BuildValues(char * Statement)
{
	//��������ֵ�б��֣�����m_data��һ��','�ַ�׷�ӵ�ʵ��Statement��
  		if(NULL==Statement)
		return;
		char sTemp[20];
		_itoa(m_data,sTemp,10);
		if(strlen(Statement)>MAXSIZE_SQL_VALUES-strlen(sTemp)-2)
			printf("out of buffer when build statement with values\n");
		else
	     sprintf(Statement+strlen(Statement),"%d,",m_data);
}

//////////////////////////����CFoatEdit��ʵ��
CFloatEdit::CFloatEdit()
{
	m_data=0;
}
CFloatEdit::CFloatEdit(const char* FieldName,float number):CCustEdit(FieldName)
{
	m_data=number;
}
CFloatEdit& CFloatEdit::operator =(float fValue)
{
	  m_data=fValue;
	  return *this;
}
void CFloatEdit::SetValue(float fValue)
{
		  *this=fValue;
}
float CFloatEdit::GetValue()const
{
	return m_data;
}
void CFloatEdit::BuildValues(char * Statement)
	{
	//��������ֵ�б��֣�����m_data��һ��','�ַ�׷�ӵ�ʵ��Statement��
		if(NULL==Statement)
		return;
		if(strlen(Statement)>MAXSIZE_SQL_VALUES-14)
			printf("out of buffer when build statement with values\n");
		else
	     sprintf(Statement+strlen(Statement),"%8.3f,",m_data);
	}

///////////////////////////����CVcharEdit��ʵ��
CVcharEdit::CVcharEdit()
{
	memset(m_data,0,MAXSIZE_NAME_FIELD);
}
CVcharEdit::CVcharEdit(const char * FieldName,const char * str):CCustEdit(FieldName)
{
	 //�β�str���ڳ�ʼ��m_data
		memset(m_data,0,MAXSIZE_NAME_FIELD);
		if(NULL==str)
		return;
		if(strlen(str)<MAXSIZE_NAME_FIELD)
			strcpy(m_data,str);
		else
			strncpy(m_data,str,MAXSIZE_NAME_FIELD-1);
}
void CVcharEdit::BuildValues(char * Statement)
{
//��������ֵ�б��֣�����m_data��һ��','�ַ�׷�ӵ�ʵ��Statement��
 		if(NULL==Statement)
		return;
		if(strlen(Statement)>MAXSIZE_SQL_VALUES-strlen(m_data)-4)
			printf("out of buffer when build statement with values\n");
		else
	     sprintf(Statement+strlen(Statement),"\'%s\',",m_data);
}
CVcharEdit& CVcharEdit::operator =(const char* sValue)
{
	//�β�str��������m_data
		if(NULL==sValue)
		return *this;
		memset(m_data,0,MAXSIZE_NAME_FIELD);
		if(strlen(sValue)<MAXSIZE_NAME_FIELD)
			strcpy(m_data,sValue);
		else
			strncpy(m_data,sValue,MAXSIZE_NAME_FIELD-1);

return *this;
}
void CVcharEdit::SetValue(const char * sValue)
	{
		  *this=sValue;
	}
void CVcharEdit::GetValue(char * sValue,unsigned int MaxCount)const
{
	  if(NULL==sValue)
		  return ;
		if(strlen(m_data)>=MaxCount)
			strncpy(sValue,m_data,MaxCount-1);
		else strcpy(sValue,m_data);
}
/******************************************************************************
ȫ�ֵĹ���SQL������������
EditList	��װ�ֶ������ֶ�ֵ�Ŀؼ����б������ﲻ�ع���ÿ���ؼ������ͣ�����ÿ��
�ؼ����麯�������Է���ع����SQL��䡣
InsStaFields	���ڱ���insert����ֶ��б���ǰ����
InsStaValues���ڱ���insert���ֵ�б��Ժ󲿷�
********************************************************************/
void gBuildHelper(CCustEdit** EditList,char*InsStaFields,char * InsStaValues)
{
   for(int i=0;i<MAX_FIELDSCOUNT&&EditList[i]!=NULL;i++)
   {
	   EditList[i]->BuildFields(InsStaFields);
	   EditList[i]->BuildValues(InsStaValues);
   }
}

int main(int argc, char* argv[])
{
	char InsertStatement[MAXSIZE_SQL_FIELDS+MAXSIZE_SQL_VALUES+2];
	char InsStaFields[MAXSIZE_SQL_FIELDS];
	char InsStaValues[MAXSIZE_SQL_VALUES];

	CVcharEdit Name("name","XinChangAn");
	CIntEdit Age("age",27);
	CFloatEdit Stature("stature",(float)1.65);
	CFloatEdit Weight("weight",(float)125.22);
  CCustEdit **EditList;

	EditList=new CCustEdit*[5];

	EditList[0]=&Name;
	EditList[1]=&Age;
	EditList[2]=&Stature;
	EditList[3]=&Weight;
	EditList[4]=NULL;

	strcpy(InsStaFields,"insert into user_database(");
	strcpy(InsStaValues,"values(");
    //ʹ�ÿؼ��б���SQL���
	gBuildHelper(EditList, InsStaFields,InsStaValues);

	//�����һ���ַ�','��Ϊ')'
	InsStaFields[strlen(InsStaFields)-1]=')';
	InsStaValues[strlen(InsStaValues)-1]=')';

	//����������䵽InsertStatement��
	strcpy(InsertStatement,InsStaFields);
	strcat(InsertStatement,InsStaValues);
	//���������SQL���
	printf("%s\n",InsertStatement);
	 delete[] EditList;
	return 0;
}
