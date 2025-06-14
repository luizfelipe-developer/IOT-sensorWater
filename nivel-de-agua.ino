const int trigPin = 7 ;
const int echoPin = 5;

const float velocidadeSom = 0.0343;

const float comprimentoRecipiente= 20.0;
const float larguraRecipiente = 15.0;

const float alturaRecipienteVazio= 23.33; // Exemplo: 23.33 cm (para 7L em 20x15cm)


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH);

 
  float distanciaSensorAgua = duracao * velocidadeSom / 2;

  if (distanciaSensorAgua > alturaRecipienteVazio || distanciaSensorAgua < 0) {
    Serial.println("Leitura fora do alcance ou erro. Verifique o sensor ou o recipiente.");
    delay(1000);
    return;
  }

  float alturaAgua = alturaRecipienteVazio - distanciaSensorAgua;

 
  if (alturaAgua < 0) {
    alturaAgua = 0;
  }

  float volumeAgua3 = comprimentoRecipiente* larguraRecipiente * alturaAgua;

  float volumeAgua_litros = volumeAgua3 / 1000.0;

  Serial.print("Distancia do sensor a agua: ");
  Serial.print(distanciaSensorAgua);
  Serial.println(" cm");

  Serial.print("Altura da agua: ");
  Serial.print(alturaAgua);
  Serial.println(" cm");

  Serial.print("Volume de agua: ");
  Serial.print(volumeAgua_litros);
  Serial.println(" Litros");

  Serial.println("--------------------");

  delay(2000);
}