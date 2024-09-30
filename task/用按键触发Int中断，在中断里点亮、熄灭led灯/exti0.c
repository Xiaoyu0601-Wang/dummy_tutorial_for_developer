#include <REGX52.H>
/*
* 函 数 名       : exti0_init
* 函数功能		 : 外部中断0配置函数
* 输    入       : 无
* 输    出    	 : 无
*/
void exti0_init(void)
{
	IT0=1;//跳变沿触发方式（下降沿）
	EX0=1;//打开INT0的中断允许
	EA=1;//打开总中断
}