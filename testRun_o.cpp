#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
 
#define A_ENABLE_1 13
#define A_ENABLE_2 19
#define A_IN_1 23
#define A_IN_2 24
 
#define B_ENABLE_1 5
#define B_ENABLE_2 6
#define B_IN_1 21
#define B_IN_2 22
 
class Car
{
public:
    void back()
    {
        setup();
        digitalWrite(RightAhead_pin,1);
        digitalWrite(RightBack_pin,0);
        digitalWrite(LeftAhead_pin,1);
        digitalWrite(LeftBack_pin,0);
    }
    void right()
    {
        setup();
        digitalWrite(RightAhead_pin,0);
        digitalWrite(RightBack_pin,1);
        digitalWrite(LeftAhead_pin,1);
        digitalWrite(LeftBack_pin,0);
    }
    void front()
    {
        setup();
        digitalWrite(RightAhead_pin,0);
        digitalWrite(RightBack_pin,1);
        digitalWrite(LeftAhead_pin,0);
        digitalWrite(LeftBack_pin,1);
    }
    void stop()
    {
        setup();
        digitalWrite(RightAhead_pin,0);
        digitalWrite(RightBack_pin,0);
        digitalWrite(LeftAhead_pin,0);
        digitalWrite(LeftBack_pin,0);
    }
    void left()
    {
        setup();
        digitalWrite(RightAhead_pin,1);
        digitalWrite(RightBack_pin,0);
        digitalWrite(LeftAhead_pin,0);
        digitalWrite(LeftBack_pin,1);
    }
private:
    int enab_pin[4]={5,6,13,19};
    int inx_pin[4]={21,22,23,24};
    int RightAhead_pin = inx_pin[0];
    int RightBack_pin = inx_pin[1];
    int LeftAhead_pin = inx_pin[2];
    int LeftBack_pin = inx_pin[3];
    void setup()
    {
        wiringPiSetup();
        for(int i=0;i<4;i++) {
            pinMode(enab_pin[i], OUTPUT);
            digitalWrite(enab_pin[i],1);
        }
        for(int i=0;i<4;i++) {
            pinMode(inx_pin[i], OUTPUT);
            digitalWrite(inx_pin[i],0);

        }
    }
};

int main(){
    Car mc = new Car();
    firstCar.front();
    delay(50);
    firstCar.stop();
    firstCar.left();
    delay(50);
    firstCar.stop();
    firstCar.right();
    delay(50);
    firstCar.stop();
    firstCar.back();
    delay(50);
    firstCar.stop();
    return 0;
}