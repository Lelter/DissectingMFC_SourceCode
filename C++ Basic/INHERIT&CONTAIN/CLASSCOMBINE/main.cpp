
#include "stdio.h"
#include "string.h"

typedef enum _SEX
{
    UNKNOWN = -1,
    MALE,
    FEMALE
}ENU_SEX;

class CPerson
{
public:
    CPerson()
    {
        age = 0;
        sex = UNKNOWN;
        stature = 0.0;
        pAddress = NULL;
    }
    CPerson(int a)
    {
        age = a;
        sex = UNKNOWN;
        stature = 0.0;
        pAddress = NULL;
    }
    CPerson(int a, ENU_SEX s, float h,const char* addr)
    {
        age = a;
        sex = s;
        stature = h;
        if(NULL != addr)
        {
            pAddress = new char[strlen(addr)+1];
            strcpy(pAddress,addr);
        }
    }
    ~CPerson()
    {
        if(NULL!=pAddress)
            delete []pAddress;
    }

    //�����ж�����ָ���Աʱ��һ��Ҫ���ء�=�������
    CPerson& operator= (const CPerson& sb)
    {
        age = sb.age;
        sex = sb.sex;
        stature = sb.stature;
        //�ж�ָ��
        if(NULL != pAddress)
        {
            delete []pAddress;
            pAddress = NULL;
        }
        if(NULL!=sb.pAddress)
        {
            pAddress = new char[strlen(sb.pAddress)+1];
            strcpy(pAddress,sb.pAddress);
        }
        return *this;
    }
private:
    int age;
    ENU_SEX sex;
    float stature;
    char* pAddress;
};

//��ĺϳɣ�һ�����а�����һ����Ķ�����Ϊ���ݳ�Ա
class Contain
{
public:
    //ע�⣺ʹ�ϳ�������й��캯�����б����õĻ���

    Contain(){};
    //����CPerson(int a)
    Contain(int a):person(a)
    {
        printf("Person construct through 'CPerson(int a)'\n");
    }

    //����CPerson(int a, ENU_SEX s, float h,const char* addr)
    Contain(int a, ENU_SEX s, float h,const char* addr):person(a,s,h,addr)
    {
        printf("Person construct through 'CPerson(int a, ENU_SEX s, float h,const char* addr)'\n");
    }
private:
    CPerson person;
};

int main()
{
//    char* add1 = 'CHENGDU';
    CPerson a(12,MALE,2.0,"CHENGDU");
    Contain com(22);
    Contain con(24,FEMALE,19.0,"SHANGHAI");
    return 0;
}
