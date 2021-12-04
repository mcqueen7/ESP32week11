#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("mcqueen");//請改名
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(26,OUTPUT);
}
 int b=0;
    int r=0;
void loop() {
  // put your main code here, to run repeatedly:

  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
     
   
    //顯示在序列視窗
    Serial.println(BTdata);
      Serial.print("r:");
    Serial.println(r);
    Serial.print("b:");
    Serial.println(b);
    Serial.println("---");
    if(BTdata=="BW"){
        b++;
        if(b==3)b=0;
      }
    else if(BTdata=="RW") {
      r++;
      if(r==3)r=0;
      }
  if(b==1) digitalWrite(12,HIGH);
      else if(b==2)digitalWrite(14,HIGH);
      else if(b==0){
        digitalWrite(12,LOW);
        digitalWrite(14,LOW);
        } 
        
       if(r==1) digitalWrite(26,HIGH);
      else if(r==2)digitalWrite(27,HIGH);
      else if(r==0){
        digitalWrite(26,LOW);
        digitalWrite(27,LOW);
        } 
     
    Serial.print("r:");
    Serial.println(r);
    Serial.print("b:");
    Serial.println(b);
  }
  
 
  delay(1);
}
