#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>


unsigned char KeyNum,LEDMode;

void main ()
{
	P2=0xFE;//1111 1110
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			if(KeyNum==1);
			{
				LEDMode++;
				if(LEDMode>=2)LEDMode=0;
				
			}
			if(KeyNum==2)P2_2=~P2_2;
			if(KeyNum==3)P2_3=~P2_3;
			if(KeyNum==4)P2_4=~P2_4;
		}
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count; //静态变量函数结束后保留赋值
	TH0=64536/256;//设置定时初值
	TL0=64536%256;//设置定时初值
	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
		if(LEDMode==0)
			P2=_crol_(P2,1);//循环左移
		if(LEDMode==1)
			P2=_cror_(P2,1);//循环右移
	}
}