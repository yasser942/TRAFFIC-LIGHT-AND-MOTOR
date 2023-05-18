int light_sensor = 0;
int LED_WAIT_DURATION_MIN = 2000;
int LED_WAIT_DURATION_MAX = 6000;

int LED_ON_DURATION_MIN = 2000;
int LED_ON_DURATION_MAX = 6000;

int LIGHT_SENSOR_OUTPUT_INTERVAL = 1000;
int enA = 11;

int random_wait = -1;
int random_on = -1;
int ms=0;


void setup()
{
  pinMode(A2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(A0,OUTPUT); 
  pinMode(A1,OUTPUT); 
  Serial.begin(9600);
  motor_cntrl(1);

}

void motor_cntrl(int a){
  if(a==1){
  	digitalWrite(A0,HIGH);
    digitalWrite(A1, LOW);
    analogWrite(enA, 255);
  }
  else{
  	digitalWrite(A0,LOW);
    digitalWrite(A1, LOW);
  }
}

void sensor_to_motor(){
  delay(100);
	light_sensor = analogRead(A2);
  if (light_sensor < 290) {
  	motor_cntrl(1);
  } else {
  	motor_cntrl(0);
  }
  
}
void loop()
{
  	
  random_wait = random(LED_WAIT_DURATION_MIN, LED_WAIT_DURATION_MAX);
  
  Serial.print("LED is turned OFF for ");
  Serial.print(random_wait);
  Serial.println(" milliseconds.");  
  
  ms =0;  
  while(ms <= random_wait){
    if(ms%LIGHT_SENSOR_OUTPUT_INTERVAL == 0){
      Serial.print("Light sensor output is ");
      Serial.println(analogRead(A2));

    } 
  	ms++;
    delay(1);
  }
  
  digitalWrite(3, HIGH);

  sensor_to_motor();

  random_on = random(LED_ON_DURATION_MIN, LED_ON_DURATION_MAX);
 
  Serial.print("LED is turned ON for ");
  Serial.print(random_on);
  Serial.println(" milliseconds.");
  
  ms =0;
  while(ms<= random_on){
    if(ms%LIGHT_SENSOR_OUTPUT_INTERVAL == 0){
      Serial.print("Light sensor output is ");
      Serial.println(analogRead(A2));
    } 
  	ms++;
    delay(1);

  }
  digitalWrite(3, LOW);

  sensor_to_motor();
  

  
}