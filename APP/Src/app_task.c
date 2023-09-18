#define APP_TASK_GLOBALS	 //����ȫ�ֱ���˽�к꣬������.c�ļ�û�ж���ú�
#include "includes.h" 

void Start_Task(void *pvParameters)
{
	taskENTER_CRITICAL();           //�����ٽ���

	xTaskCreate((TaskFunction_t )Cammand_Task,            	//������
							(const char*    )"Cammand_Task",          	//��������
							(uint16_t       )CAMMAND_STK_SIZE,        	//�����ջ��С
							(void*          )NULL,                			//���ݸ��������Ĳ���
							(UBaseType_t    )CAMMAND_TASK_PRIO,       	//�������ȼ�
							(TaskHandle_t*  )&Cammand_Task_Handler);		//������  				
										 
	xTaskCreate((TaskFunction_t )Err_Handle_Task,           //������
							(const char*    )"Err_Handle_Task",         //��������
							(uint16_t       )ERR_STK_SIZE,        			//�����ջ��С
							(void*          )NULL,                			//���ݸ��������Ĳ���
							(UBaseType_t    )ERR_TASK_PRIO,       			//�������ȼ�
							(TaskHandle_t*  )&Err_Task_Handler);				//������  		

	xTaskCreate((TaskFunction_t )Test_Task,            			//������
							(const char*    )"Test_Task",          			//��������
							(uint16_t       )TEST_STK_SIZE,        			//�����ջ��С
							(void*          )NULL,                			//���ݸ��������Ĳ���
							(UBaseType_t    )TEST_TASK_PRIO,       			//�������ȼ�
							(TaskHandle_t*  )&Test_Task_Handler);				//������  

							
	xTaskCreate((TaskFunction_t )LED_Task,            			//������
							(const char*    )"LED_Task",          			//��������
							(uint16_t       )LED_STK_SIZE,        			//�����ջ��С
							(void*          )NULL,                			//���ݸ��������Ĳ���
							(UBaseType_t    )LED_TASK_PRIO,       			//�������ȼ�
							(TaskHandle_t*  )&Led_Task_Handler);				//������
							
	vTaskDelete(Start_Task_Handler);	//ɾ����ʼ����
	taskEXIT_CRITICAL();            	//�˳��ٽ���
}

/************************************************/
//�������ܣ��쳣����������
//���������
//����ֵ��
//��ע��
/************************************************/
void Err_Handle_Task(void *p_arg)
{
	while(1)
	{		
	
		vTaskDelay(500);
	}
}


/************************************************/
//�������ܣ����������
//���������
//����ֵ��
//��ע��
/************************************************/
void Cammand_Task(void *p_arg)
{
	while(1)
	{		
	
		vTaskDelay(500);
	}
}


/************************************************/
//�������ܣ���������
//���������
//����ֵ��
//��ע��
/************************************************/
void Test_Task(void *p_arg)
{
	while(1)
	{		
	
		vTaskDelay(500);
	}
}


/************************************************/
//�������ܣ�led��������
//���������
//����ֵ��
//��ע��
/************************************************/
void LED_Task(void *p_arg)
{
	while(1)
	{
		LED_TOGGLE;
		vTaskDelay(500);
	}  
}

