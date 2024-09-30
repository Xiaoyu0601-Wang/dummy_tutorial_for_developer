/*
* 函数功能		 : 延时函数，ten_us=1时，大约延时10us
* 输    入       : ten_us
* 输    出    	 : 无
*/
typedef unsigned int u16;
void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}