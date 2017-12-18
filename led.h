#ifndef LED_H
#define LED_H
#define LED2 2

#define LED3 3

#define LEDboth 4
#define ButtonS1 1
#define ButtonS2 2
#define ButtonS3 3
 
 int configLight(int LEDx);
 int delightLed();

 int dimLed();
 int configButton();
 int readButtonValue();
 

#endif
