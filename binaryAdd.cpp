//////////////////////////////////////////////////////////////////////////////
//
//  8. ���������������أ��٣����أ��ٻ�Ϊ����������Ȼ����������������������
//   �Ƽӷ����㣬�ٽ������Ϊʮ�����������
//////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

//��ʮ������ת��Ϊ��������
int* DecimalToBinary(int num)
{
  int* result=new int[10];
  //���������ݳ�ʼ��
  for(int i=0;i<10;i++)
    result[i]=0;
  int index=9;
  do
  {
    result[index]=num%2;
    num=(num/2);
    index--;
  }while(num>=2);
  result[index]=num%2;
  return result;
}

//�����Ƽӷ�
int *BinaryAdd(int* num1,int* num2)
{
  int carry=0;
  for(int i=9;i>=0;i--)
  {
    if(num1[i]+num2[i]+carry>=2)
    {
      num1[i]=(num1[i]+num2[i]+carry)%2;
      carry=1;
    }
    else
    {
      num1[i]=(num1[i]+num2[i]+carry)%2;
      carry=0;
    }
  }
  return num1;
}

void PrintArray(int* data,int length)
{
  for(int i=0;i<length;i++)
    cout<<data[i];
  cout<<endl;
}

//����������ת��Ϊʮ������
int BinaryToDecimal(int *num)
{
  int result=0;
  for(int i=0;i<9;i++)
  {
    result+=num[i];
    result*=2;
  }
  result+=num[9];
  return result;
}

int main()
{
  int num1=65,num2=135;
  int *operand1=DecimalToBinary(num1);
  int *operand2=DecimalToBinary(num2);
  BinaryAdd(operand1,operand2);
  cout<<BinaryToDecimal(operand1)<<endl;
  return 0;
}

