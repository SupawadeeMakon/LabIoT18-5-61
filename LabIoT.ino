//Add Library
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Explicit ประกาศตัวแปร
int myOutput = D7;
int myDelay=1000;//ค่าของเวลาจะมีหน่วยเป็น มิลลิวินาที
//int intIndex=0;
int intSwitch=0;



//การกำหนดค่าคงที
#define wifiSSID "Kik"    //String wifiSSID="";
#define wifiPassword "12345678"
//-------------------------------------------------
//การทำงานบนfirebase
#define firebaseHost "loginbyfirebase9-5-61.firebaseio.com"//"supawadeenodemcu.firebaseio.com"
#define firebaseKey  "OmFZxkzLllwvfQ7gcPnisIa82reht58UDO4sKYQt"
//-------------------------------------------------





void setup() {

  //  ส่วนที่กำหนดการส่งสัญญาณ digital Out จากขาของ Node
  pinMode(myOutput, OUTPUT);
  
//  การกำหนดช่องทางในการ monitor
  Serial.begin(9600);
//-------------------------------------------------
//  การกำหนดข้อมูลเกี่ยวกับการเชื่อมต่อ wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifiSSID, wifiPassword);
  Serial.println("Start Find WiFi");  

  while(WiFi.status() != WL_CONNECTED) 
  {
    //ถ้า Condition Ture จะทำงานที่นี้
    Serial.print("=");
    delay(1000);
    
    }

//    ถ้ามาทำงานตรงนี้คือ Connected WiFi ได้แล้ว
  Serial.println();
  Serial.println("Success Connected WiFi");
  Serial.println(WiFi.localIP());

//------------------------------------------------------
//  ส่วนของการเชื่อมต่อ Firebase 

  Firebase.begin(firebaseHost, firebaseKey);

}//setup

void loop() {

  
//  Serial.println("Hello Supawadee");
//  delay(2000);

//Check Connected Firebase
  //Firebase.setInt("led", intIndex);
  
  if (Firebase.failed()) {

    //    เมื่อไรก็ตามที่ไม่สามารถเข้า Firebase
    Serial.print("Connot Connected Firebase :...");
    Serial.println(Firebase.error());
    return;
    
    }

    Serial.print("Success Connected Firebase Times ==>");
    //Serial.println(Firebase.getInt("led"));

    //intIndex = Firebase.getInt("led");

    //intIndex++;

    intSwitch = Firebase.getInt("Switch");

  if(intSwitch==0){
    //  for myOutput
      digitalWrite(myOutput, LOW);   // turn the LED on (HIGH is the voltage level) 
  }
  else{
      digitalWrite(myOutput, HIGH);  
    
    }

  
    delay(myDelay);


  
}//Loop


