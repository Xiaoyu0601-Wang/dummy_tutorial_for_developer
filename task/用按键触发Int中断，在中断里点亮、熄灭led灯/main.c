#include <REGX52.H>
#include "delay.h"
#include "exti0.h"

typedef unsigned int u16;	//��ϵͳĬ���������ͽ����ض���
typedef unsigned char u8;

//����LED1�ܽ�
sbit LED1=P2^0;

//�����������K3���ƽ�
sbit KEY3=P3^2;

/*
* �� �� ��       : main
* ��������		 : ������
* ��    ��       : ��
* ��    ��    	 : ��
*/
void main()
{	
	exti0_init();//�ⲿ�ж�0����

	while(1)
	{			
							
	}		
}

void exti0() interrupt 0 //�ⲿ�ж�0�жϺ���
{
	delay_10us(1000);//������������ͨ�ź��ȶ�����ִ��
	if(KEY3==0)//�ٴ��ж�K3���Ƿ���
		LED1=!LED1;//LED1״̬��ת					
}