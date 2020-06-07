/*
Copyright 2017 iBibb Team

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
void EnvoyerDonneesBluetooth()
{
  //FORME : POMPE | LED | TEMPERATURESONDE | TEMPERATURE | HUMIDITÉ | PH | ULTRASON
  // Variable string -> Bluetooth
  
  //Relais
  if (RelaisPompeOn = true)
  {
    Bluetooth += "1";
  }
  else
  {
    Bluetooth += "0";
  }
  if (RelaisLedOn = true)
  {
    Bluetooth += "1";
  }
  else
  {
    Bluetooth += "0";
  }
  //Température de la sonde
  temperatureSonde = temperatureSonde * 100.0;
  int BtemperatureSonde = (int)temperatureSonde; //Conversion forcée en Int
  Bluetooth+=String(BtemperatureSonde, HEX);
  
  //Température 
  Bluetooth+=String(DHTTemperature, HEX);
  
  //Humidité
  int bDHTHumidite = (int)DHTHumidite;
  Bluetooth+=String(bDHTHumidite, HEX);
  //PH
  PHValeur = PHValeur * 100.0;
  int bPH = (int)PHValeur;
   Bluetooth+= String(bPH, HEX);
   //Ultrason
   if (distanceUltrason > 99)
   {
    distanceUltrason = 255;
   }
  Bluetooth+=String(distanceUltrason, HEX); 
  //Ajouter un séparateur
  Bluetooth+=";";
  //Envoyer au module
  Serial1.println(Bluetooth); //Envoi au module

  //Debug
  Serial.print("Le module bluetooth a envoye << ");
  Serial.print(Bluetooth);
  Serial.println(" >>!");
  //Vider la chaine
  Bluetooth = "";
}

