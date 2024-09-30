#include <REGX52.H>

void Timer0_Init()
{
	TMOD=0x01; //0000 0001
	TF0=0;
	TR0=1;
	TH0=64536/256;//高8位表示为多少个低八位
	TL0=64536%256;//低8位求余
	ET0=1;
	EA=1;
	PT0=0;
	
}
/*定时器中断模板
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
*/
