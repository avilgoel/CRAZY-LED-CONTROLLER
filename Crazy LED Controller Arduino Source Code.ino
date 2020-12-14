#include <FastLED.h>
#define NUM_LEDS  60
#define LED_PIN   2
uint8_t hue=0;
int pattern=0;
CRGB leds[NUM_LEDS];
void colour()
{
  for(int i=0;i<60;i++)
  {
    if(pattern%3==0)
    {
      if(i%3==0)
      {
        leds[i]=CRGB::Red;
      }
      if(i%3==1)
      {
        leds[i]=CRGB::Green;
      }
      if(i%3==2)
      {
        leds[i]=CRGB::Blue;
      }
    }
    if(pattern%3==1)
    {
      if(i%3==0)
      {
        leds[i]=CRGB::Green;
      }
      if(i%3==1)
      {
        leds[i]=CRGB::Blue;
      }
      if(i%3==2)
      {
        leds[i]=CRGB::Red;
      }
    }
    if(pattern%3==2)
    {
      if(i%3==0)
      {
        leds[i]=CRGB::Blue;
      }
      if(i%3==1)
      {
        leds[i]=CRGB::Red;
      }
      if(i%3==2)
      {
        leds[i]=CRGB::Green;
      }
    }
  }
  FastLED.show();
  pattern++;
  delay(200);
}
void cold()
{
  EVERY_N_MILLISECONDS(50)
  {
    for(int i=NUM_LEDS-1;i>0;i--)
    {
      leds[i]=leds[i-1];
    }
    leds[0]=CHSV(160,random8(),random8(100,255));
  }
  FastLED.show();
}
void hot()
{
  EVERY_N_MILLISECONDS(50)
  {
    for(int i=NUM_LEDS-1;i>0;i--)
    {
      leds[i]=leds[i-1];
    }
    leds[0]=CHSV(7,random8(200,255),random8(100,255));
  }
  FastLED.show();
}
void rainbow()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
    leds[i]=CHSV(hue+(i*15),255,255);
  }
  EVERY_N_MILLISECONDS(5)
  {
    hue++;
  }
  FastLED.show();
}
void racing_()// This is not used in final presentation
{
  pattern=0;
  while(pattern<5000)
  {
    if(pattern>180)
    {
       pattern=0;
    }
    if(pattern<=60)
    {
      leds[0]=CRGB::Red;
      for(int i=NUM_LEDS-1;i>0;i--)
      {
        leds[i]=leds[i-1];
      }
    }
    else if(pattern<=120)
    {
      leds[0]=CRGB::Blue;
      for(int i=NUM_LEDS-1;i>0;i--)
      {
        leds[i]=leds[i-1];
      }
    }
    else if(pattern<=180)
    {
      leds[0]=CRGB::Green;
      for(int i=NUM_LEDS-1;i>0;i--)
      {
        leds[i]=leds[i-1];
      }
    }
    delay(50);
    FastLED.show();
    pattern++;
  }
}
void racing()
{
  if(pattern>60)
  {
     pattern=0;
     hue+=50;
  }
  if(pattern<=60)
  {
    leds[0]=CHSV(hue,255,255);
    for(int i=NUM_LEDS-1;i>0;i--)
    {
      leds[i]=leds[i-1];
    }
  }
//  else if(pattern<=120)// change a bit
//  {
//    leds[0]=CHSV(hue,255,255);
//    for(int i=NUM_LEDS-1;i>0;i--)
//    {
//      leds[i]=leds[i-1];
//    }
//  }
//  else if(pattern<=180)
//  {
//    leds[0]=CHSV(hue,255,255);
//    for(int i=NUM_LEDS-1;i>0;i--)
//    {
//      leds[i]=leds[i-1];
//    }
//  }
  delay(20);
  FastLED.show();
  pattern++;
}
void disco()
{
  EVERY_N_MILLISECONDS(50)
  {
    for(int i=NUM_LEDS-1;i>0;i--)
    {
      leds[i]=leds[i-1];
    }
    leds[0]=CHSV(random8(),random8(100,255),random8());
  }
  FastLED.show();
}
void fun(int intensity)
{
  for(int j=0;j<255;j+=5)
  {
    leds[0]=CHSV(intensity,j,255);//given color
    for(int i=1;i<NUM_LEDS;i++)
    {
      leds[i]=leds[i-1];
    }
    FastLED.show();
    delay(100);
  }
  leds[0]=CHSV(0,0,0);//given color
  for(int i=1;i<NUM_LEDS;i++)
  {
    leds[i]=leds[i-1];
  }
  FastLED.show();
  delay(70);
}
void twinkle()
{
  fun(20);
  if(Serial.available()>0)
  {
    return;
  }
  fun(60);
  if(Serial.available()>0)
  {
    return;
  }
  fun(100);
  if(Serial.available()>0)
  {
    return;
  }
  fun(140);
  if(Serial.available()>0)
  {
    return;
  }
  fun(180);
  if(Serial.available()>0)
  {
    return;
  }
  fun(220);
  if(Serial.available()>0)
  {
    return;
  }
  fun(250);
}
void soft()
{
  for(int f=210;f<255;f++)
  {
    for(int m=190;m<=255;m+=5)
    {
      leds[0]=CHSV(f,m,255);//give color
      for(int i=1;i<NUM_LEDS;i++)
      {
        leds[i]=leds[i-1];
      }
      int random_size=random8(1,3);
      for(int l=0;l<random_size;l++)
      {
        int random_led_num=random8();
        random_led_num=(random_led_num)%60;
        uint8_t col_h=f+5;
        uint8_t col_v=(m+150)%256;
        leds[random_led_num]=CHSV(col_h,col_v,255);
      }
      FastLED.show(); 
      delay(50); 
      if(Serial.available()>0)
      {
        return;
      }
    }
  }
}
void off()
{
  leds[0]=CHSV(0,0,0);//given color
  for(int i=1;i<NUM_LEDS;i++)
  {
    leds[i]=leds[i-1];
  }
  FastLED.show();
}
void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);//0-255
  Serial.begin(9600);
}
void loop() 
{
  if(Serial.available()>0)
  {
    char data=Serial.read();
    switch(data)
    {
      case '0': 
      {
        off();
        break;
      }
      case '1': 
      {
        Serial.println(data);
        while(Serial.available()<=0)
        {
          rainbow();
        }
        break;
      }
      case '2': 
      {
        while(Serial.available()<=0)
        {
          cold();
        }
        break;
      }
      case '3': 
      {
        while(Serial.available()<=0)
        {
          hot();
        }
        break;
      }
      case '4': 
      {
        while(Serial.available()<=0)
        {
          disco();
        }
        break;
      }
      case '5': 
      {
        while(Serial.available()<=0)
        {
          twinkle();
        }
        break;
      }
      case '6': 
      {
        pattern=0;
        while(Serial.available()<=0)
        {
          racing();
        }
        break;
      }
      case '7': 
      {
        while(Serial.available()<=0)
        {
          soft();
        }
        break;
      }
      case '8': 
      {
        pattern=0;
        while(Serial.available()<=0)
        {  
          colour();
        }
        break;
      }
      default:
      {
        off();
      }
    }
    Serial.println(data);
  }
}
