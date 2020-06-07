/*
Copyright 2017 iBibb Team, Adafruit Industries and Seeed Technology Inc

Permission is hereby granted, free of charge, to any person obtaining a 
copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, including without limitation 
the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the 
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall 
be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE.
 */

void LireSondeEtanche()
{
  if(LireTemperature(&temperatureSonde, true) != READ_OK) {
    Serial.println(F("Le capteur n'est pas accessible"));
    return;
  }
  Serial.print(F("Temperature de la sonde etanche : "));
  Serial.print(temperatureSonde, 2);
  Serial.write(176); // Caractère degré
  Serial.write('C');
  Serial.println();
}

//Capteur de température et d'humidité
void LireTemperatureHumid()
{
  DHTTemperature = SondeTempHumid.readTemperature();
  DHTHumidite = SondeTempHumid.readHumidity();
  
  if (isnan(DHTTemperature) || isnan(DHTHumidite)) {
    Serial.println("Erreur lors de la lecture du capteur DHT11!");
  } else {
    Serial.print("Humidite DHT: ");
    Serial.print(DHTHumidite);
    Serial.print(" %\t");
    Serial.print("Temperature DHT: ");
    Serial.print(DHTTemperature);
    Serial.println(" *C");
  }
  
}

