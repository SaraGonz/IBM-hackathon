#define UpperThreshold 550
#define LowerThreshold 500

float temperatureC;
int pinT = A1;                     // Cable de señal del sensor de temperatura al pin de entrada 1
int BPM = A3;                      // Cable de señal del sensor de pulso al pin de entrada 3


bool BPMTiming    = false;        
bool BeatComplete = false;
int LastTime      = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);                // Velocidad en baudios de lectura
analogReference(INTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:
temperatureC = analogRead(pinT);
float temperatureCTransform = ((temperatureC * 0.48828) - 50);


BPM = analogRead(BPM);

if (BPM > UpperThreshold)   {
      if (BeatComplete) {
          BPM = millis()-LastTime;
          BPM = int(60/(float(BPM)/1000));
          BPMTiming =false;
          BeatComplete =false;
      }
      if (BPMTiming == false) {
          BPMTiming = true;
          LastTime  = millis();
      }
  }

  if (BPM < LowerThreshold & BPMTiming) {
      BeatComplete = true;
      // output bpm to serial monitor
      Serial.print(BPM);
      Serial.println(" BPM");
}
  


Serial.println("DATA");
Serial.println("pintT: " + pinT);
Serial.print("La temperatura del paciente es: ");
Serial.println(temperatureCTransform);

if (temperatureC>=38){
  Serial.print("WARNING: La temperatura es más alta de los valores normales");
}

Serial.println("pinP: " + BPM);
Serial.print("El pulso del paciente es: ");
Serial.println(BPM);
if (BPM >= 550){
  Serial.print("WARNING: El pulso es más acelerado que los valores normales");
  Serial.print("Se recomienda realizar un control médico");
}
Serial.println("-------------------");

delay(1000);
}
