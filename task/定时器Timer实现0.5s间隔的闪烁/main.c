#include <REGX52.H>
#include "Timer0.h"

void main ()
{
	Timer0_Init();
	while(1)
	{
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count; //静态变量函数结束后保留赋值
	TH0=64536/256;
	TL0=64536%256;
	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
		P2_0=~P2_0;
	}
}