#include <REGX52.H>

void Timer0_Init()
{
	TMOD=0x01; //0000 0001
	TF0=0;
	TR0=1;
	TH0=64536/256;//��8λ��ʾΪ���ٸ��Ͱ�λ
	TL0=64536%256;//��8λ����
	ET0=1;
	EA=1;
	PT0=0;
	
}
/*��ʱ���ж�ģ��
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count; //��̬������������������ֵ
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
