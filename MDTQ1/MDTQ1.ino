void setup()
{
    Serial.begin(9600);
    pinMode(2 , INPUT_PULLUP);
    for(int pin = 3 ; pin < 14 ; pin++)

    {
        pinMode(pin,OUTPUT);
    }

    tone (8 , 200 ,500 );
    delay(250);
    tone (8 , 400 ,100 );
}

int time = 100;
int n = 0;    //ตัวแปรที่เก็บค่าจำนวนครั้งที่กด
void loop()
{  
    for(int i = 3 ; i < 14 ; i++ ) 
    {
        if(i == 8)

        {
            digitalWrite(i,0);
            continue;
        }

        digitalWrite(i, HIGH);
        while (digitalRead(2) == 0)  //คำสั่งกดให้Pin 2 ดับ (เชื่อมกับปุ่มเดียวคือ Button)
        { 
            if (digitalRead(2) == 1)
            {  
            time = time / 2 ;         
            n++; // ให้รู้ว่ากดครั้งต่อไป n ต้องเพิ่มทีละ 1 
            tone (8 , 400 ,100 );  
            Serial.println("Faster X 2 (Current Speed : X" + String(pow(2,n)) + ")"); //แสดงค่าเป็นตัวหนังสือ และค่าที่เพิ่มที่ละ 2n           
            }            
        } delay(time); // เปิดไฟตามเวลาที่กำหนดของdelay

        digitalWrite(i, LOW);        
    }

    for(int i = 13 ; i > 2 ; i-- )
    {
        if(i == 8)

        {
            digitalWrite(i,0);
            continue;
        }
    
        digitalWrite(i, HIGH);
        while (digitalRead(2) == 0)  //คำสั่งกดให้Pin 2 ดับ (เชื่อมกับปุ่มเดียวคือ Button)
        { 
            if (digitalRead(2) == 1)
            {  
            time = time / 2 ;         
            n++; // ให้รู้ว่ากดครั้งต่อไป n ต้องเพิ่มทีละ 1 
            tone (8 , 400 ,100 );  
            Serial.println("Faster X 2 (Current Speed : X" + String(pow(2,n)) + ")"); //แสดงค่าเป็นตัวหนังสือ และค่าที่เพิ่มที่ละ 2n           
            }            
        } delay(time); // เปิดไฟตามเวลาที่กำหนดของdelay

        digitalWrite(i, LOW);        
    }
    
}