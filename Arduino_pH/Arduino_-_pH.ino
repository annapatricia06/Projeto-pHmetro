float sinalAnalogico;                        //Corresponde ao sinal analógico
float tensao;                                //Corresponde a tensão elétrica
float sensorpH;                              //Corresponde ao pH
float milivolt;                              //Corresponde aos milivolts de pH

void setup() {
  Serial.begin(9600);                        //Inicia o monitor serial
  
}

void loop() {
  sinalAnalogico = analogRead(A0);           //Efetua a leitura do sinal analógico
  tensao = (sinalAnalogico/1023)*5;          //Realiza a conversão do sinal analógico para tensão elétrica
  
  Serial.print("Tensão = ");
  Serial.println(tensao);                    //Mostra no monitor serial o valor correspondente da tensão elétrica
  sensorpH = (tensao-4.9984)/-0.1887;        //Equação resultante da validação de soluções
  Serial.print("pH = ");                   
  Serial.println(sensorpH);                  //Mostra no monitor serial o valor correspondente ao pH

  milivolt = (-59.16*sensorpH)+414.12;
  Serial.print("mV = ");                   
  Serial.println(milivolt);                  //Mostra no monitor serial o valor correspondente aos milivolts
  
  delay(600);                                //Aguarda seiscentos milisegundos para retorno ao void loop
}
