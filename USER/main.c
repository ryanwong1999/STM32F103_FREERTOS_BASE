#include "includes.h" 


int main(void)
{
	taskENTER_CRITICAL();		//进入临界区
		
	//创建开始任务
	//任务函数 任务名称 任务堆栈大小 任务参数 任务优先级 任务句柄
	xTaskCreate((TaskFunction_t )Start_Task,            //任务函数
							(const char*    )"Start_Task",          //任务名称
							(uint16_t       )START_STK_SIZE,        //任务堆栈大小
							(void*          )NULL,                  //传递给任务函数的参数
							(UBaseType_t    )START_TASK_PRIO,       //任务优先级
							(TaskHandle_t*  )&Start_Task_Handler);	//任务句柄  

	taskEXIT_CRITICAL();		//退出临界区	
  vTaskStartScheduler();	//开启任务调度			
	while(1);
}


