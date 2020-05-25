//Déclaration des variables pour les capteurs//
int unc = 1;
int deuxc = 2;
int cinqc = 3;
int dixc = 4;
int vingtc = 5;
int cinquantec = 6;
int une = 7;
int deuxe = 8;

int somme = 0;// Déclaration de la variable pour la somme d'argent

// Déclaration des valeurs de la somme
int chiffdizaine = 0;
int chiffunite = 0;
int chiffdizieme = 0;
int chiffcentieme = 0;
// Déclaration des valeurs à envoyer à l'afficheur 4x7 segments
int affdizaine = 0;
int affunite = 0;
int affdizieme = 0;
int affcentieme = 0;


// Déclaration des variables de l'état des capteurs
int etatunc = 0;
int etatdeuxc = 0;
int etatcinqc = 0;
int etatdixc = 0;
int etatvingtc = 0;
int etatcinquantec = 0;
int etatune = 0;
int etatdeuxe = 0;


// utilisation d'un afficheur 4 x 7 segments

// brancher la borne RX de l'afficheur 4x7 segments sur la broche 11 de Arduino

//importer la bibliotheque liaison serie 
#include <SoftwareSerial.h>

// definir les bornes digitales correspondant à Rx et Tx
# define txPin 11
# define rxPin 10

// créer un port serie avec les bornes digitales
SoftwareSerial PortSerie1 =SoftwareSerial(rxPin,txPin); 

// Initialisation des entrées et sorties
void setup ()
{
  pinMode (unc,INPUT);
  pinMode (deuxc,INPUT);
  pinMode (cinqc,INPUT);
  pinMode (dixc,INPUT);
  pinMode (vingtc,INPUT);
  pinMode (cinquantec,INPUT);
  pinMode (une,INPUT);
  pinMode (deuxe,INPUT);
  pinMode (txPin,OUTPUT);
  pinMode (rxPin,INPUT);
  
  PortSerie1.begin(9600);
  initialiseAfficheur(224);
}

//--------------------------------------------------------------
// fonction pour initialiser l'afficheur
void initialiseAfficheur(byte adresse){
    PortSerie1.write(adresse);
    PortSerie1.write(164);
}
//--------------------------------------------------------------
// fonction pour afficher un caractere
//-- 
void afficheCaractere(byte adresse,byte place, byte caractere){
    PortSerie1.write(adresse);
    PortSerie1.write(place);
    PortSerie1.write(caractere);
}
//--------------------------------------------------------------
// fonction pour afficher un point
//-- 
void affichePoint(byte adresse,byte place){
    PortSerie1.write(adresse);
    PortSerie1.write(place);
}

//--------------------------------------------------------------
// fonction pour afficher un caractere
//-- 
void afficheValeurVariable(byte adresse,byte octet1, byte octet2){
    PortSerie1.write(adresse);
    PortSerie1.write(250);
    PortSerie1.write(octet1);
    PortSerie1.write(octet2);
}

// fonction pour afficher le nombre

void affiche4caracteres(byte dizaineLocale,byte uniteLocale,byte diziemeLocale,byte centiemeLocale){
afficheCaractere(224,1,dizaineLocale);
afficheCaractere(224,2,uniteLocale);
afficheCaractere(224,3,diziemeLocale);
afficheCaractere(224,4,centiemeLocale);
affichePoint(224,210);
}

//--------------------------------------------------------------
void loop ()
{
  etatunc=digitalRead(unc);// lecture de l'état du capteur de pièce de 1c
  if(etatunc==HIGH)// si capteur activé
  {
    somme = somme+1;// ajouter 1 à la somme
  }
  etatunc = 0;// on remet la variable etat à 0
  
  
  etatdeuxc=digitalRead(deuxc);// lecture de l'état du capteur de pièce de 2c
  if(etatdeuxc==HIGH)// si capteur activé
  {
    somme = somme+2;// ajouter 2 à la somme
  }
  etatdeuxc = 0;// on remet la variable etat à 0
  
  
  etatcinqc=digitalRead(cinqc);// lecture de l'état du capteur de pièce de 5c
  if(etatcinqc==HIGH)// si capteur activé
  {
    somme = somme+5;// ajouter 5 à la somme
  }
  etatcinqc = 0;// on remet la variable etat à 0
  
  
  etatdixc=digitalRead(dixc);// lecture de l'état du capteur de pièce de 10c
  if(etatdixc==HIGH)// si capteur activé
  {
    somme = somme+10;// ajouter 10 à la somme
  }
  etatdixc = 0;// on remet la variable etat à 0
  
  
  etatvingtc=digitalRead(vingtc);// lecture de l'état du capteur de pièce de 20c
  if(etatvingtc==HIGH)// si capteur activé
  {
    somme = somme+20;// ajouter 20 à la somme
  }
  etatvingtc = 0;// on remet la variable etat à 0
  
  
  etatcinquantec=digitalRead(cinquantec);// lecture de l'état du capteur de pièce de 50c
  if(etatcinquantec==HIGH)// si capteur activé
  {
    somme = somme+50;// ajouter 50 à la somme
  }
  etatcinquantec = 0;// on remet la variable etat à 0
  
  
  etatune=digitalRead(une);// lecture de l'état du capteur de pièce de 1€
  if(etatune==HIGH)// si capteur activé
  {
    somme = somme+100;// ajouter 100 à la somme
  }
  etatune = 0;// on remet la variable etat à 0
  
  
  etatdeuxe=digitalRead(deuxe);// lecture de l'état du capteur de pièce de 2€
  if(etatdeuxe==HIGH)// si capteur activé
  {
    somme = somme+200;// ajouter 200 à la somme
  }
  etatdeuxe = 0;// on remet la variable etat à 0
  
  
  
  chiffdizaine = somme/1000;
  somme = somme-chiffdizaine*1000;
  chiffunite = somme/100;
  somme = somme-chiffunite*100;
  chiffdizieme = somme/10;
  somme = somme-chiffdizieme*10;
  chiffcentieme = somme;
  
  affdizaine = 48+chiffdizaine;
  affunite = 48+chiffunite;
  affdizieme = 48+chiffdizieme;
  affcentieme = 48+chiffcentieme;

  
  affiche4caracteres(affdizaine,affunite,affdizieme,affcentieme);
}





