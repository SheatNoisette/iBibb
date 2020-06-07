/*
Copyright 2017 iBibb Team and SeeedStudio

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

 //Ultrason
void MesurerDistance ()
{
  distanceUltrason = moduleUltrason.MeasureInCentimeters();
  Serial.print("Module ultrason distance relevee: ");
  Serial.print(distanceUltrason);
  Serial.println(" cm");
}

//Flow sensor - int VitesseEau,InterruptionFlow;
void InitialisationFlow()
{
  pinMode(FLOWSENSOR, INPUT); //Définition du GPIO utilisé
  attachInterrupt(0, InterruptionFlow, RISING); //Attacher le système d'interruption à la fonction "VitesseFlow"
}
void vitesseFlow()
{
  InterruptionFlow++; //Calculer le nombre de fermeture du circuit
}
void calculFlow()
{
  InterruptionFlow = 0;   //Set NbTops to 0 ready for calculations
  sei();      //Enables interrupts
  delay (1000);   //Attendre une seconde pour lancer les calculs
  cli();      //Déactiver les interruptions
  VitesseEau = (InterruptionFlow * 60 / 73); //(Pulsation x 60) / 73Q, = Vitesse en L/H

  Serial.print("Vitesse de l'eau en L/H: ");
  Serial.println(VitesseEau,DEC);
}

