#include "includes.h" 

void Board_Init(void)
{
	LED_Init();
}

int main(void)
{
	taskENTER_CRITICAL();		//�����ٽ���
	
	Board_Init();
		
	//������ʼ����
	//������ �������� �����ջ��С ������� �������ȼ� ������
	xTaskCreate((TaskFunction_t )Start_Task,            //������
							(const char*    )"Start_Task",          //��������
							(uint16_t       )START_STK_SIZE,        //�����ջ��С
							(void*          )NULL,                  //���ݸ��������Ĳ���
							(UBaseType_t    )START_TASK_PRIO,       //�������ȼ�
							(TaskHandle_t*  )&Start_Task_Handler);	//������  

	taskEXIT_CRITICAL();		//�˳��ٽ���	
  vTaskStartScheduler();	//�����������			
	while(1);
}


