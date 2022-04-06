int buttonarray[] = {12, 11, 10, 9, 8}; // [E2, A2, D3, G3, B3, E4]
//int buttonarray[] = {8, 9, 10, 11, 12};
// each pin represents a guitar stringk
// next we create and array with frequencies matching each of the strings above
// such that when 13 is selected the freq matching the note e is selected).
float freqarray[] = {82.41, 110.00, 146.83, 196.00, 246.94, 329.63};//sll in Hz

 

int lowerLed = 7;
int higherLed = 6;
int justRight = 5;

 

#define LENGTH 512

 

byte rawData[LENGTH];
int count = 0;

 

// Sample Frequency in kHz
const float sample_freq = 8919;
int len = sizeof(rawData);
int i,k;
long sum, sum_old;
int thresh = 0;
float freq_per = 0;
byte pd_state = 0;
int value;

 

void setup(){
  for (int i=0; i<5; i++)
  {
    pinMode(buttonarray[i], INPUT);
  }
  
  pinMode(lowerLed, OUTPUT);
  pinMode(higherLed, OUTPUT);
  pinMode(justRight, OUTPUT);
  
  Serial.begin(9600);
}
void loop(){
  
   if (count < LENGTH) 
  {
    count++;
    rawData[count] = analogRead(A0)>>1;
  }
  else {
    sum = 0;
    pd_state = 0;
    int period = 0;
    for(i=0; i < len; i++)
    {
      // Autocorrelation
      sum_old = sum;
      sum = 0;
      for(k=0; k < len-i; k++) sum += (rawData[k]-127)*(rawData[k+i]-127)/256;
      // Serial.println(sum);
      
      // Peak Detect State Machine
      if (pd_state == 2 && (sum-sum_old) <=0) 
      {
        period = i;
        pd_state = 3;
      }
      if (pd_state == 1 && (sum > thresh) && (sum-sum_old) > 0) pd_state = 2;
      if (!i) {
        thresh = sum * 0.5;
        pd_state = 1;
      }
    }

 


    if (thresh >100) {
      freq_per = sample_freq/period;
      Serial.println(freq_per);
    
    //freq_per= 112;
    
        for ( int s=0; s<5 ; s++)
      {  
        value = digitalRead(buttonarray[s]);
        Serial.println(value);

        digitalWrite(lowerLed, LOW);
        digitalWrite(justRight, LOW);
        digitalWrite(higherLed, LOW);
        
        if (value == HIGH)
        {
          //Serial.println("I'm HEREEEEEE");
          Serial.println("");
          
          if (freq_per - freqarray[s] < 0)
          {
            Serial.println("strange");
            Serial.println(freq_per);
            Serial.println(freqarray[s]);
            digitalWrite(lowerLed, HIGH);
            digitalWrite(justRight, LOW);
            digitalWrite(higherLed, LOW);
          }
          else if(freq_per - freqarray[s] > 10)
          {
            Serial.println("lasaa");
            Serial.println(freq_per);
            Serial.println(freqarray[s]);
            digitalWrite(higherLed, HIGH);
            digitalWrite(lowerLed, LOW);
            digitalWrite(justRight, LOW);
          }

          else

          {
            Serial.println("bines");
            Serial.println(freq_per);
            Serial.println(freqarray[s]);
            digitalWrite(justRight, HIGH);
            digitalWrite(higherLed, LOW);
            digitalWrite(lowerLed, LOW);
          }
         
        }

       
      }
    }
        count = 0;
    }

 

    }
  
