
#include <SoftwareSerial.h> //TX RX Software Library for Bluetooth

#include <Servo.h>
Servo myservo;

int bluetoothTX = 10;//BluetoothTX hc05 pin 10
int bluetoothRX = 11;//BluetoothRX hc05 pin 11

SoftwareSerial bluetooth{bluetoothTX, bluetoothRX};



void setup() 
{
  myservo.attach(9);//attach servo to pin 9
  //Setup usb serial connection to computer
  Serial.begin(9600);
//Setup bluetooth connection to android
  bluetooth.begin(9600);
}

void loop() 
{
 //Read from bluetooth and write to usb serial
 if(bluetooth.available()>0)//recieve number from bluetooth
 {
  int servopos = bluetooth.read();
  Serial.println(servopos);
  myservo.write(servopos); 
 }

}
