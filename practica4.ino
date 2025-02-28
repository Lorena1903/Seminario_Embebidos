//Resolución = unidad menor que un dispositivo puede medir.
//Nuestro microcontrolador puede procesar 12bits, lo que es 2^12, lo que seria igual 4096
//(3.3V-0V)/4096 = 0.81mV, es la minima unidad que puede medir el procesador, osea su Resolución
const int pinPot = 15;  // Pin del potenciómetro
const int LED = 13;      // Pin del LED

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT); 
}

void loop() {
    int valorADC = analogRead(pinPot); // Leer el valor del potenciómetro
    valorADC = (valorADC * 0.7) + (analogRead(pinPot) * 0.3); 
    int brillo = map(valorADC, 0, 4095, 0, 255); // Convierte ADC a brillo (0-255)
    int angulo = map(valorADC, 0, 4095, 0, 360); // Convierte ADC a ángulo

    analogWrite(LED, brillo); // Ajusta el brillo del LED

    Serial.print("Valor ADC: ");
    Serial.print(valorADC);
    Serial.print("  -  Brillo: ");
    Serial.print(brillo);
    Serial.print("  -  Ángulo: ");
    Serial.println(angulo);

//    delay(200); // 
}










//const int pinPot = 15;
//const int LED = 5;
//const int canalPWM = 0;


//void setup() {
//  Serial.begin(115200);
//  ledSetup(canalPWM, 5000, 8);
//  ledcAttachPin(LED, canalPWM);
//}

//void loop() {
//  int valorADC = analogRead(pinPot);
//  float brillo = map(valorADC, 0, 4095, 0, 255);

//  ledcWrite(canalPWM, brillo);

//  Serial.print("Valor ADC: ");
//  Serial.print(valorADC);
//  Serial.print("  -  brillo: ");
//  Serial.print(brillo);

//  delay(500);

//}
