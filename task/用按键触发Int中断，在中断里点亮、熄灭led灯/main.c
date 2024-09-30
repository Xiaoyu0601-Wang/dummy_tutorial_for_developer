#include <REGX52.H>
#include "delay.h"
#include "exti0.h"

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;

//定义LED1管脚
sbit LED1=P2^0;

//定义独立按键K3控制脚
sbit KEY3=P3^2;

/*
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*/
void main()
{	
	exti0_init();//外部中断0配置

	while(1)
	{			
							
	}		
}

void exti0() interrupt 0 //外部中断0中断函数
{
	delay_10us(1000);//消抖，按键接通信号稳定后再执行
	if(KEY3==0)//再次判断K3键是否按下
		LED1=!LED1;//LED1状态翻转					
}