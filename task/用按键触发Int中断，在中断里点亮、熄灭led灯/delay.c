/*
* ��������		 : ��ʱ������ten_us=1ʱ����Լ��ʱ10us
* ��    ��       : ten_us
* ��    ��    	 : ��
*/
typedef unsigned int u16;
void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}