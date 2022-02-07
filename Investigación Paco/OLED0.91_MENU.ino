#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <splash.h>
#include <SPI.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3c
#define ARRIBA 4
#define ABAJO 5
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int arr;
int aba;
int color = 3;
void setup() {
 Serial.begin(9600);
 display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
 pinMode(ARRIBA, INPUT);
 pinMode(ABAJO, INPUT);
  }

void loop() {
  arr = digitalRead(ARRIBA);
  aba = digitalRead(ABAJO);
 if(arr == HIGH){
  Serial.println(color);
  color++;
  Serial.println(color);
  delay(250);
 }
 if(aba == HIGH){
  Serial.println(color);
  color--;
  Serial.println(color);
  delay(250);
 }
if (color == 3){
display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Opcion A");
  display.setTextColor(SSD1306_WHITE);
  display.println("Opcion B");
  display.setTextColor(SSD1306_WHITE);
  display.println("Opcion C");
  display.display();
}

if (color == 2){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Opcion A");
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display.println("Opcion B");
  display.setTextColor(SSD1306_WHITE);
  display.println("Opcion C");
  display.display();
}

if (color == 1){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Opcion A");
  display.setTextColor(SSD1306_WHITE);
  display.println("Opcion B");
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display.println("Opcion C");
  display.display();
}
if (color < 1){
  color= 3;
}
if(color > 3){
  color = 1;
}
 
 }
