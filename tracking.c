/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         tracking.c
* @author       Danny
* @version      V1.0
* @date         2017.08.16
* @brief        Ѳ��ʵ��
* @details
* @par History  ������˵��
*
*/
#include <wiringPi.h>
#include <softPwm.h>

//��������
int Left_motor_go = 23;       //����ǰ��AIN2����Raspberry��wiringPi����28��
int Left_motor_back = 24;     //��������AIN1����Raspberry��wiringPi����29��

int Right_motor_go = 21;      //�ҵ��ǰ��BIN2����Raspberry��wiringPi����24��
int Right_motor_back = 22;    //�ҵ������BIN1����Raspberry��wiringPi����25��

int Left_motor_pwm = 13;      //��������PWMA����Raspberry��wiringPi����27��
int Left_motor_pwm_2 = 19;
int Right_motor_pwm = 5;     //�ҵ������PWMB����Raspberry��wiringPi����23��
int Right_motor_pwm_2 = 6;

int key = 10;                 //���尴��ΪRaspberry��wiringPi����10��

//ѭ���������Ŷ���
//TrackSensorLeftPin1 TrackSensorLeftPin2 TrackSensorRightPin1 TrackSensorRightPin2
//      9                 21                  7                   1
const int TrackSensorLeftPin1  =  9;   //������ߵ�һ��ѭ�����⴫��������ΪwiringPi����9��
const int TrackSensorLeftPin2  =  2;  //������ߵڶ���ѭ�����⴫��������ΪwiringPi����21��
const int TrackSensorRightPin1 =  7;   //�����ұߵ�һ��ѭ�����⴫��������ΪwiringPi����7��
const int TrackSensorRightPin2 =  1;   //�����ұߵڶ���ѭ�����⴫��������ΪwiringPi����1��

//�������ѭ���������Ųɼ������ݵı���
int TrackSensorLeftValue1;
int TrackSensorLeftValue2;
int TrackSensorRightValue1;
int TrackSensorRightValue2;

/**
* Function       run
* @author        Danny
* @date          2017.08.16
* @brief         С��ǰ��
* @param[in1]    left_speed:�����ٶ�
* @param[in2]    right_speed:�����ٶ�
* @param[out]    void
* @retval        void
* @par History   ��
*/
void run(int left_speed, int right_speed)
{
  //����ǰ��
  digitalWrite(Left_motor_go, HIGH);   //����ǰ��ʹ��
  digitalWrite(Left_motor_back, LOW);  //�������˽�ֹ
  softPwmWrite(Left_motor_pwm, left_speed );
  softPwmWrite(Left_motor_pwm_2, left_speed );

  //�ҵ��ǰ��
  digitalWrite(Right_motor_go, HIGH);  //�ҵ��ǰ��ʹ��
  digitalWrite(Right_motor_back, LOW); //�ҵ�����˽�ֹ
  softPwmWrite(Right_motor_pwm, right_speed);
  softPwmWrite(Right_motor_pwm_2, right_speed);
}

/**
* Function       brake
* @author        Danny
* @date          2017.08.16
* @brief         С��ɲ��
* @param[in]     time:��ʱʱ��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void brake(int time)
{
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Left_motor_back, LOW);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, LOW);

  delay(time * 100);
}

/**
* Function       left
* @author        Danny
* @date          2017.08.16
* @brief         С����ת(���ֲ���������ǰ��)
* @param[in1]    left_speed:�����ٶ�
* @param[in2]    right_speed:�����ٶ�
* @param[out]    void
* @retval        void
* @par History   ��
*/
void left(int left_speed, int right_speed)
{
  //����ֹͣ
  digitalWrite(Left_motor_go, LOW);    //����ǰ����ֹ
  digitalWrite(Left_motor_back, LOW);  //�������˽�ֹ
  softPwmWrite(Left_motor_pwm, left_speed);
  softPwmWrite(Left_motor_pwm_2, left_speed );

  //�ҵ��ǰ��
  digitalWrite(Right_motor_go, HIGH);  //�ҵ��ǰ��ʹ��
  digitalWrite(Right_motor_back, LOW); //�ҵ�����˽�ֹ
  softPwmWrite(Right_motor_pwm, right_speed);
  softPwmWrite(Right_motor_pwm_2, right_speed);
}

/**
* Function       right
* @author        Danny
* @date          2017.08.16
* @brief         С����ת(���ֲ���������ǰ��)
* @param[in1]    left_speed:�����ٶ�
* @param[in2]    right_speed:�����ٶ�
* @param[out]    void
* @retval        void
* @par History   ��
*/
void right(int left_speed, int right_speed)
{
  //����ǰ��
  digitalWrite(Left_motor_go, HIGH);   //����ǰ��ʹ��
  digitalWrite(Left_motor_back, LOW);  //�������˽�ֹ
  softPwmWrite(Left_motor_pwm, left_speed);
  softPwmWrite(Left_motor_pwm_2, left_speed );

  //�ҵ��ֹͣ
  digitalWrite(Right_motor_go, LOW);   //�ҵ��ǰ����ֹ
  digitalWrite(Right_motor_back, LOW); //�ҵ�����˽�ֹ
  softPwmWrite(Right_motor_pwm, right_speed);
  softPwmWrite(Right_motor_pwm_2, right_speed);
}

/**
* Function       spin_left
* @author        Danny
* @date          2017.08.16
* @brief         С��ԭ����ת(���ֺ��ˣ�����ǰ��)
* @param[in1]    left_speed:�����ٶ�
* @param[in2]    right_speed:�����ٶ�
* @param[out]    void
* @retval        void
* @par History   ��
*/
void spin_left(int left_speed, int right_speed)
{
  //��������
  digitalWrite(Left_motor_go, LOW);     //����ǰ����ֹ
  digitalWrite(Left_motor_back, HIGH);  //��������ʹ��
  softPwmWrite(Left_motor_pwm, left_speed);
  softPwmWrite(Left_motor_pwm_2, left_speed );

  //�ҵ��ǰ��
  digitalWrite(Right_motor_go, HIGH);  //�ҵ��ǰ��ʹ��
  digitalWrite(Right_motor_back, LOW); //�ҵ�����˽�ֹ
  softPwmWrite(Right_motor_pwm, right_speed);
  softPwmWrite(Right_motor_pwm_2, right_speed);
}

/**
* Function       spin_right
* @author        Danny
* @date          2017.08.16
* @brief         С��ԭ����ת(���ֺ��ˣ�����ǰ��)
* @param[in1]    left_speed:�����ٶ�
* @param[in2]    right_speed:�����ٶ�
* @param[out]    void
* @retval        void
* @par History   ��
*/
void spin_right(int left_speed, int right_speed)
{
  //����ǰ��
  digitalWrite(Left_motor_go, HIGH);    //����ǰ��ʹ��
  digitalWrite(Left_motor_back, LOW);   //�������˽�ֹ
  softPwmWrite(Left_motor_pwm, left_speed);
  softPwmWrite(Left_motor_pwm_2, left_speed );

  //�ҵ������
  digitalWrite(Right_motor_go, LOW);    //�ҵ��ǰ����ֹ
  digitalWrite(Right_motor_back, HIGH); //�ҵ������ʹ��
  softPwmWrite(Right_motor_pwm, right_speed);
  softPwmWrite(Right_motor_pwm_2, right_speed);
}

/**
* Function       back
* @author        Danny
* @date          2017.08.16
* @brief         С������
* @param[in]     time����ʱʱ��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void back(int time)
{
  //��������
  digitalWrite(Left_motor_go, LOW);     //����ǰ����ֹ
  digitalWrite(Left_motor_back, HIGH);  //��������ʹ��
  softPwmWrite(Left_motor_pwm, 40);
  softPwmWrite(Left_motor_pwm_2, 40);

  //�ҵ������
  digitalWrite(Right_motor_go, LOW);    //�ҵ��ǰ����ֹ
  digitalWrite(Right_motor_back, HIGH); //�ҵ������ʹ��
  softPwmWrite(Right_motor_pwm, 40);
  softPwmWrite(Right_motor_pwm_2, 40);

  delay(time );
}

/**
* Function       key_scan
* @author        Danny
* @date          2017.08.16
* @brief         �������(������������ȥ��)
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void key_scan()
{
  while (digitalRead(key));       //������û�б�����һֱѭ��
  while (!digitalRead(key))       //������������ʱ
  {
    delay(10);	                  //��ʱ10ms
    if (digitalRead(key)  ==  LOW)//�ڶ����жϰ����Ƿ񱻰���
    {
      delay(100);
      while (!digitalRead(key));  //�жϰ����Ƿ��ɿ�
    }
  }
}

/**
* Function       main
* @author        Danny
* @date          2017.08.16
* @brief         �ȵ���setup��ʼ����������İ���ɨ�躯����
*                ѭ��ģʽ����
* @param[in]     void
* @retval        void
* @par History   ��
*/
void main()
{
  //wiringPi��ʼ��
  wiringPiSetup();
	
  //��ʼ���������IO��Ϊ�����ʽ
  pinMode(Left_motor_go, OUTPUT);
  pinMode(Left_motor_back, OUTPUT);
  pinMode(Right_motor_go, OUTPUT);
  pinMode(Right_motor_back, OUTPUT);

  //���������������Ƶ�PWM��
  softPwmCreate(Left_motor_pwm,0,255); 
  softPwmCreate(Right_motor_pwm,0,255);
  
  //���尴���ӿ�Ϊ����ӿ�
  pinMode(key, INPUT);

  //������·ѭ�����⴫����Ϊ����ӿ�
  pinMode(TrackSensorLeftPin1, INPUT);
  pinMode(TrackSensorLeftPin2, INPUT);
  pinMode(TrackSensorRightPin1, INPUT);
  pinMode(TrackSensorRightPin2, INPUT);

  //���ð���ɨ�躯��
  key_scan();
  
  while(1)
  {
   //��⵽����ʱѭ��ģ����Ӧ��ָʾ�������˿ڵ�ƽΪLOW
   //δ��⵽����ʱѭ��ģ����Ӧ��ָʾ���𣬶˿ڵ�ƽΪHIGH
   TrackSensorLeftValue1  = digitalRead(TrackSensorLeftPin1);
   TrackSensorLeftValue2  = digitalRead(TrackSensorLeftPin2);
   TrackSensorRightValue1 = digitalRead(TrackSensorRightPin1);
   TrackSensorRightValue2 = digitalRead(TrackSensorRightPin2);

   //��·ѭ�����ŵ�ƽ״̬
   // 0 0 X 0
   // 1 0 X 0
   // 0 1 X 0
   //����6�ֵ�ƽ״̬ʱС��ԭ����ת���ٶ�Ϊ250,��ʱ80ms
   //��������Ǻ���ֱ�ǵ�ת��
   if ( (TrackSensorLeftValue1 == LOW || TrackSensorLeftValue2 == LOW) &&  TrackSensorRightValue2 == LOW)
   {
     spin_right(250, 250);
     delay(80);
   }
   //��·ѭ�����ŵ�ƽ״̬
   // 0 X 0 0       
   // 0 X 0 1 
   // 0 X 1 0       
   //��������Ǻ���ֱ�ǵ�ת��
   else if ( TrackSensorLeftValue1 == LOW && (TrackSensorRightValue1 == LOW ||  TrackSensorRightValue2 == LOW))
   {
     spin_left(250, 250);
     delay(80);
   }
   // 0 X X X
   //����߼�⵽
   else if ( TrackSensorLeftValue1 == LOW)
   {
     spin_left(150, 150);
     //delay(10);
   }
   // X X X 0
   //���ұ߼�⵽
   else if ( TrackSensorRightValue2 == LOW )
   {
     spin_right(150, 150);
     //delay(10);
   }
   //��·ѭ�����ŵ�ƽ״̬
   // X 0 1 X
   //������С��
   else if ( TrackSensorLeftValue2 == LOW && TrackSensorRightValue1 == HIGH)
   {
     left(0, 220);
   }
   //��·ѭ�����ŵ�ƽ״̬
   // X 1 0 X  
   //������С��
   else if (TrackSensorLeftValue2 == HIGH && TrackSensorRightValue1 == LOW)
   {
     right(220, 0);
   }
   //��·ѭ�����ŵ�ƽ״̬
   // X 0 0 X
   //����ֱ��
   else if (TrackSensorLeftValue2 == LOW && TrackSensorRightValue1 == LOW)
   {
     run(255, 255);
   }
   //��Ϊ1 1 1 1ʱС��������һ��С������״̬
 }
 return;
}


