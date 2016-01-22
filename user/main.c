#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "led.h" 		 	 
#include "oled.h"
#include "rtc.h" 
int main(void)
{					   
 		    
	u8 w=0;
 	Stm32_Clock_Init(9);	//系统时钟设置
	delay_init(72);	   	 	//延时初始化
	uart_init(72,115200);	//串口初始化 
	LED_Init();		  		//初始化与LED连接的硬件接口 
	OLED_Init();			//初始化OLED
//  	OLED_ShowString(0,0,"Panda Joe",24);  
	OLED_ShowString(0,24, "Fuck somebody",16);  
 	OLED_ShowString(24,40,"/",12);  
	OLED_ShowString(42,40,"/",12); 
	OLED_ShowString(24,0,":",24);
	OLED_ShowString(60,0,":",24);	
 	OLED_ShowString(0,52,"www.pandaroll.cn Joe",12);  

	OLED_Refresh_Gram();	//更新显示到OLED	 
	RTC_Init();
	
	while(1) 
	{		
//		OLED_ShowChar(36,52,t,12,1);//显示ASCII字符	
//		OLED_ShowNum(94,52,t,3,12);	//显示ASCII字符的码值    
//		OLED_Refresh_Gram();//更新显示到OLED
//		t++;
//		//if(t>'~')t=' ';  
//		delay_ms(500);
//		//LED0=!LED0;
		
		
		if(w!=calendar.sec){
			w = calendar.sec;
			OLED_ShowNum(0,40,calendar.w_year,4,12);
			if(calendar.w_month < 10){
				OLED_ShowNum(30,40,calendar.w_month,2,12);
				OLED_ShowString(30,40,"0",12);
			}else{
				OLED_ShowNum(30,40,calendar.w_month,2,12);
			}
			if(calendar.w_date < 10){
				OLED_ShowNum(48,40,calendar.w_date,2,12);
				OLED_ShowString(48,40,"0",12);
			}else{
				OLED_ShowNum(48,40,calendar.w_date,2,12);
			}
			
			switch(calendar.week)
			{
				case 0:
					OLED_ShowString(66,40,"Sunday   ",12);
					break;
				case 1:
					OLED_ShowString(66,40,"Monday   ",12);
					break;
				case 2:
					OLED_ShowString(66,40,"Tuesday  ",12);
					break;
				case 3:
					OLED_ShowString(66,40,"Wednesday",12);
					break;
				case 4:
					OLED_ShowString(66,40,"Thursday ",12);
					break;
				case 5:
					OLED_ShowString(66,40,"Friday   ",12);
					break;
				case 6:
					OLED_ShowString(66,40,"Saturday ",12);
					break;  
			}
			
			OLED_ShowNum(0,0,calendar.hour,2,24);
			
			if(calendar.min < 10){
				OLED_ShowNum(36,0,calendar.min,2,24);
				OLED_ShowString(36,0,"0",24);
			}else{
				OLED_ShowNum(36,0,calendar.min,2,24);
			}
			
			if(calendar.sec < 10){
				OLED_ShowNum(72,0,calendar.sec,2,24);
				OLED_ShowString(72,0,"0",24);
			}else{
				OLED_ShowNum(72,0,calendar.sec,2,24);
			}
			
			OLED_Refresh_Gram();
		}
		delay_ms(10);
	}	
}


