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
 
void init(void)
{
    wiringPiSetup();
    pinMode(A_ENABLE_1, OUTPUT);
    pinMode(A_ENABLE_2, OUTPUT);
    pinMode(A_IN_1, OUTPUT);
    pinMode(A_IN_2, OUTPUT);
    pinMode(B_ENABLE_1, OUTPUT);
    pinMode(B_ENABLE_2, OUTPUT);
    pinMode(B_IN_1, OUTPUT);
    pinMode(B_IN_2, OUTPUT);
}
 
void reset(void)
{
    digitalWrite(A_ENABLE_1, HIGH);
    digitalWrite(A_ENABLE_2, HIGH);
    digitalWrite(A_IN_1, LOW);
    digitalWrite(A_IN_2, LOW);
    digitalWrite(B_ENABLE_1, HIGH);
    digitalWrite(B_ENABLE_2, HIGH);
    digitalWrite(B_IN_1, LOW);
    digitalWrite(B_IN_2, LOW);
}
 
void forward(void)
{
    digitalWrite(A_IN_1, LOW);
    digitalWrite(A_IN_2, HIGH);
    digitalWrite(B_IN_1, LOW);
    digitalWrite(B_IN_2, HIGH);
}
 
void backward(void)
{
    digitalWrite(A_IN_1, HIGH);
    digitalWrite(A_IN_2, LOW);
    digitalWrite(B_IN_1, HIGH);
    digitalWrite(B_IN_2, LOW);
}
 
void left(void)
{
    digitalWrite(A_IN_1, HIGH);
    digitalWrite(A_IN_2, LOW);
    digitalWrite(B_IN_1, LOW);
    digitalWrite(B_IN_2, HIGH);
}
 
void right(void)
{
    digitalWrite(A_IN_1, LOW);
    digitalWrite(A_IN_2, HIGH);
    digitalWrite(B_IN_1, HIGH);
    digitalWrite(B_IN_2, LOW);
}
 
void stop(void)
{
    digitalWrite(A_IN_1, LOW);
    digitalWrite(A_IN_2, LOW);
    digitalWrite(B_IN_1, LOW);
    digitalWrite(B_IN_2, LOW);
}

void main(void)
{
    init();
    forward();
    sleep(2);
    stop();
    left();
    sleep(2);
    stop();
    right();
    sleep(2);
    stop();
}