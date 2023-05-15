#include "myClass_DrawOnTheScreen.h" // Adafruit_ST7735 compri
#include "myFunctions_WriteAndReadToSDCard.h"
#include "DHT.h"
#include <Wire.h>
#include "Adafruit_VL6180X.h"

                                     //CS  A0  MOSI  CLK RST
Adafruit_ST7735 tft = Adafruit_ST7735(12, 5, 13,   14, 0);

Adafruit_VL6180X vl = Adafruit_VL6180X();

//Customs Images
int hexFan_width = 32;
int hexFan_height = 32;
String hexFan0 = "1FF800003FFC0000700C0000600600006006000060060000600C0000601C00007038001C3031F87F3837FEE39C7F07C1FE7C03C0FFF803C01FF003C0066003C0066003C00FF803C01FFF03C03E7F83E0FE39C77FEC1CFE3F8C0C38001C0E00003806000030060000600600006006000060060000300E00003FFC00001FF800"; //IDLE
String hexFan1 = "1FFC00003FFF00007001C004600660086006101060020830600C0020601C00607038005C3031F8DB3837FEC39C7F07C1FE7C03C0FFF803C01FF003C0066003C0066003C00FF803C01FFF03C03E7F83E0FE39C37FEC1CDB3F8C0C3A001C0E06003806040030060C10400608086006100660062003800E0000FFFC00003FF800"; //frame 1
String hexFan2 = "7FE00001F0780003C38600070180000E0183F00C008FF80C039E1C0C03380C0C0338062E0370072603E0034781E00343C1C001C1F3C001C07FE7C5BE3E7FDDBBFE7C7DA3E7FE038003CF83800383C2C00781E2C007C064E00EC074601CC030701CC0303879C0301FF100300FC18070000180E00061C3C0001E0F800007FE00"; //frame 2
String hexFan3 = "7C000018FF0000E1C78003C181C0074380E00E6300701C53003838130018701B000C601B007CE01B0024C01F0FC2C00F3E02C00FF800E007FFF078067FFC3FFE601E0FFFE006001FF003407CF00343F0F8032400D8073E00D8063000C80E3800C81C1C00CA380E00C6700701C2E0038183C001E3870000FF1800003E0000"; //frame 3
PixelImage Pixelfan(tft);
int speedometer_width = 15;
int speedometer_height = 15;
String speedometer ="7C03260A0A2002602D0086020E083";
PixelImage Speedometer(tft);

int buttons_width = 32;
int buttons_height = 11;
String backButton0 = "FFFFFFFF8000000180040001800C0001801FF001800C08018004080180000801800FF00180000001FFFFFFFF";
String backButton1 = "3FFFFFFC200000042002000420060004200FE0042006100420021004200010042007E004200000043FFFFFFC";
PixelImage BackButton(tft);
String leftButton0 = "FFFFFFFF80000001800000018008000180180001803FFC0180180001800800018000000180000001FFFFFFFF";
String leftButton1 = "3FFFFFFC200000042000000420040004200C0004201FF804200C00042004000420000004200000043FFFFFFC";
PixelImage LeftButton(tft);
String rightButton0 = "FFFFFFFF80000001800000018000100180001801803FFC0180001801800010018000000180000001FFFFFFFF";
String rightButton1 = "3FFFFFFC20000004200000042000200420003004201FF804200030042000200420000004200000043FFFFFFC";
PixelImage RightButton(tft);
String okButton0 = "FFFFFFFF80000001800E44018011480180115001801160018011500180114801800E440180000001FFFFFFFF";
String okButton1 = "3FFFFFFC2000000420064804200950042009600420094004200960042009500420064804200000043FFFFFFC";
PixelImage OkButton(tft);

int sensors_width = 11;
int sensors_height = 16;
String waterDrop = "40140280881104108220240500600C01404808C6070";
PixelImage WaterDrop(tft);
String thermometer = "E022C4408A11022C540AA150491392FA5F49C8820F8";
PixelImage Thermometer(tft);
String leaf = "E064308822048090244490921284508460B0200400";
PixelImage Leaf(tft);

int runStopButtons_width = 32;
int runStopButtons_height = 11;
String runButton0 = "FFFFFFFF8000000180F22881808A2881808A2C8180F22A8180A22981809228818089C88180000001FFFFFFFF"; //waiting
String runButton1 = "E00000078000000180F22881008A2880008A2C8000F22A8000A22980009228808089C88180000001E0000007";//up
String runButton2 = "3FFFFFFC2000000420722904204A2904204A2D0420722B0420522B04204A29042049C904200000043FFFFFFC"; //click
PixelImage RunButton(tft);
String stopButton0 = "FFFFFFFF80000001839F39E18455451184044511838445E180444501844445018384390180000001FFFFFFFF"; //waiting
String stopButton1 = "E000000780000001839F39E10455451004044510038445E000444500044445008384390180000001E0000007"; //up
String stopButton2 = "3FFFFFFC20000004219F39C42255452422044524218445C4204445042244450421843904200000043FFFFFFC"; //click
PixelImage StopButton(tft);

int speedCursor_width = 12;
int speedCursor_height = 12;
String speedCursor0 = "F03FC7FE7FEFFFFFFFFFFFF7FE7FE3FC0F0";
String speedCursor1 = "0xF030C40240280180180180140240230C0F0";
PixelImage SpeedCursor(tft);
int arrowsCursor_width = 12;
int arrowsCursor_height = 5;
String arrowsCursor0 = "204606FFF606204";
String arrowsCursor1 = "0";
PixelImage ArrowsCursor(tft);

int menuCursor_width = 11;
int menuCursor_height = 7;
String menuCursor0 = "802808820880A00FFF";
String menuCursor1 = "0";
PixelImage MenuCursor(tft);

int optionCursor_width = 8;
int optionCursor_height = 11;
String optionCursor0 = "6050484442414244485060";
String optionCursor1 = "0";
PixelImage OptionCursor(tft);

int speaker_width = 17;
int speaker_height = 14;
String speaker = "C000A0809020888B842502918124C09260523C21211110481014100600";
PixelImage Speaker(tft);
int moon_width = 15;
int moon_height = 15;
String moon = "E0068012004800900220044008803080E082A0FA4004401060C03E0";
PixelImage Moon(tft);
int relayIcon_width = 15;
int relayIcon_height = 7;
String relayIcon = "7FF11FF41FF83FF07FD1FF1FFC";
PixelImage RelayIcon(tft);

long int counter; //compteur permettant aux animations de sélectionner leurs frame à afficher.
int frame; //image actuelle de l'animation en cours

// Variables boutons
const int escapeButton = 34;
const int leftButton = 35;
const int rightButton = 36;
const int okButton = 39;
int escapeButtonValue = 0;
int leftButtonValue = 0;
int rightButtonValue = 0;
int okButtonValue = 0;
int lastEscapeButtonValue = 0;
int lastLeftButtonValue = 0;
int lastRightButtonValue = 0;
int lastOkButtonValue = 0;

// Variables commande fan
const int PWMfanPin = 25;                                         // Pin PWM fan                                      // Précision binaire de la modulation de largeur d'impultion
const int fanMOSFET = 15;                                         // Pin relais

// Variables lecture fan [tr/min]
const int PinTachymetre = 4;                                      // PIN du tachymetre
volatile byte tours = 0;                                          // Nombre de tours comptés
unsigned long tempsPrecedent = 0;                                 // Temps du dernier tour
unsigned long temps = 0;                                          // Temps total écoulé depuis le démarrage
const int delai = 1800;                                           // Durée en millisecondes pour calculer les tours par minute (lecture toutes les "delai" ms) (0-10000RPM)
int toursParMinute = 0;

//Flags d'affichage fréquentiels
int myDislplayClock;                                              // Fréquence d'affichage/d'actualisation des données à afficher dans l'écran (toutes les 300ms)
int flagMyDislplayClock;                                          // Front montant de cette fréquence
int myOldDislplayClock;                                           // Front déscandant de cette fréquence

//Quelques capteurs et valeurs...
uint8_t tankFillLevel;          //niveau de remplissage du réservoir (0-71mm)
int maxTankFillLevel = 71;      //hauteur maximum que peuvent atteindre les déchets
#define DHTPIN 26
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int pinRelay = 2;
int pinMQ2 = 33;
int pinBuzzer = 27;
int humidity;                   //humidité (0-100%)
int temperature;                //température (0-50°C)
int airQuality;                 //Qualité d'air (0-4095)->(0-2048 = 0-100%)

//Flags des menus
int menuSetup = 0;                //flag mis à 1 une fois que le setup (affichages de widget) d'un menu est executé
int menuSelection;                // 0: DASHBOARD ; 1:LOGS ; 2: OPTION
int previousMenuSelection;        //...
int isInMenu;                     //flag permettant de savoir si l'opérateur est rentré dans un menu (dès qu'il a cliqué sur OK)
int okCount;                      //permet d'identifier à quel endroit nous sommes en ayant cliqué une ou plus de fois (sous-menu, sous-sous menu, ...)
int indexSelection;               //permet d'identifier à quel endroit nous sommes en ayant cliqué une ou plus de fois (sous-menu, sous-sous menu, ...) suite à okCount
int previousOkCount;              //...
int dacValueIsEnable;             //permet de savoir l'instant où on souhaite varier la vitesse (appui sur slider) afin de de lancer le DAC
int dacValue = 190;               //le slider sera à 50% au démarrage
int isRunning = 0;                //Flag permettant de savoir si le ventilateur tourne ou pas
int buzzerEnabled = 1;            //OPTION : flag permettant la sonorisation aprrès du buzzer. Si 1 il y a bip, si 0 (donc modifié depuis les OPTION) alors plus de bip
int relayEnabled = 0;             //OPTION : falg permettant d'allumer ou éteindre le relai depuis les OPTIONS
int afkModeEnabled = 0;           //OPTION : flag permettant d'activer ou non la mise en veille du système depuis les OPTIONS
int disableAFKCountdown = 1;      //OPTION : flag permettant de désactiver ou pas la mise en veille du système après 10min de mise en service de l'aspirateur
int previousAfkModeEnabled = 0;   //Après mise en veille, il ne faut plus répeter qu'il faut mettre en veille car il est déjà en veille, donc cette variable gère les front montant de ce procédé

//Liste des signaux affichés dans les LOGS
#define LIST_LENGTH 102                               //Liste de 100 données utiles lue toutes les 300ms
int logsValues_VL[LIST_LENGTH] = {-1};                //Liste des données du capteur de niveau de remplissage (par défaut rempli à -1, cela permet de ne pas confondre avec un 0 qui pourrait etre mesuré) (-1 pour dire que la l'emplacement de cette donnée est vide)
int previousLogsValues_VL[LIST_LENGTH] = {-1};        //Liste des données précédentes. Cela permet d'effacer les anciennes données pour laisser place aux nouvelles.
int logsValues_MQ2[LIST_LENGTH] = {-1};               //...Capteur de qualité d'air
int previousLogsValues_MQ2[LIST_LENGTH] = {-1};       //...
int logsValues_TACH[LIST_LENGTH] = {-1};              //...Capteur de vitesse
int previousLogsValues_TACH[LIST_LENGTH] = {-1};      //...
int logsValues_DHT_HUM[LIST_LENGTH] = {-1};           //...Capteur d'humidité
int previousLogsValues_DHT_HUM[LIST_LENGTH] = {-1};   //...
int logsValues_DHT_TEMP[LIST_LENGTH] = {-1};          //...Capteur de température
int previousLogsValues_DHT_TEMP[LIST_LENGTH] = {-1};  //...

void shiftLogsValues(int listValues[LIST_LENGTH]) {
  /* Permet de décaller les valeurs d'une liste vers la gauche d'une position.
   * Utilisé pour gerer l'affichage des pixels des courbes du menu LOGS
   */
  for (int i = 0; i < LIST_LENGTH-1; i++) {           // Décalage des valeurs d'une position vers la gauche
    listValues[i] = listValues[i+1];
  }
  listValues[LIST_LENGTH-1] = -1;                   
}

void allMinOneLogsValues(int listValues[LIST_LENGTH]) {
  /* Initialise les listes avec 102 fois -1 à chaque position. 
   * Permet de ne pas afficher de pixel inutiles si le menu LOGS a été ouvert pour la première fois.
   * Cela revient à ce que les courbes évolue dans le temps de droite vers gauche, sans qu'il y ai des signaux inutiles avant.
   */
  for (int i = 0; i < LIST_LENGTH-1; i++) { 
    listValues[i] = -1;
  }
  listValues[LIST_LENGTH-1] = -1; 
}

void menuDashboard(){
  /* Fonction executée dès que l'utilisateur a placé son curseur sur le menu DASHBOARD.
   * Affiche tous les widget en premier temps (icones, premières valeurs des capteurs, slider, boutons, ...), et ce 1 seule fois.
   * Actualise toutes les valeurs des capteurs en deuxième temps, et ce dans une boucle infinie.
   * Dans cette boucle se trouve aussi la gestion des flag pour localiser le curseur en fonction des appuis de l'utilisateur.
   * Dans le dashboard se trouve : 
   *    Icone de température + sa valeur (°C)
   *    Icone d'humudité + sa valeur (%)
   *    Icone de qualité d'air + sa valeur (%)
   *    Icone de vitesse + sa valeur (RPM)
   *    Icone du niveau de remplissage du réservoir + sa valeur (mm)
   *    Animation d'un ventilateur (tourne si c'est le cas, sinon est a l'arret)
   *    Bouton RUN/STOP auquel l'utilisateur peut y avoir accès pour démarrer le ventilateur
   *    Slider permettant de varier la vitesse auquel l'utilisateur peut y avoir accès pour varier la vitesse
   *    Valeur du slider (%)
   */
  int isOnRunStop;
  int isOnSlider;
  //setup  
  if(menuSetup == 0){
    //-------------------------------creations des icones-------------------------------
    //big fan icon
    Pixelfan.debug(false);
    Pixelfan.create(hexFan_width,hexFan_height, HexToBinImage(hexFan_width, hexFan_height, hexFan0));
    Pixelfan.addFrame(HexToBinImage(hexFan_width, hexFan_height, hexFan1));
    Pixelfan.addFrame(HexToBinImage(hexFan_width, hexFan_height, hexFan2));
    Pixelfan.addFrame(HexToBinImage(hexFan_width, hexFan_height, hexFan3));
    //sensor icons
    Speedometer.debug(false);
    Speedometer.create(speedometer_width,speedometer_height, HexToBinImage(speedometer_width, speedometer_width, speedometer));
    WaterDrop.debug(false);
    WaterDrop.create(sensors_width,sensors_height, HexToBinImage(sensors_width, sensors_height, waterDrop));
    Thermometer.debug(false);
    Thermometer.create(sensors_width,sensors_height, HexToBinImage(sensors_width, sensors_height, thermometer));
    Leaf.debug(false);
    Leaf.create(sensors_width,sensors_height, HexToBinImage(sensors_width, sensors_height, leaf));
    //speedfan icons
    SpeedCursor.debug(false);
    SpeedCursor.create(speedCursor_width,speedCursor_height, HexToBinImage(speedCursor_width, speedCursor_height, speedCursor0)); 
    SpeedCursor.addFrame(HexToBinImage(speedCursor_width, speedCursor_height, speedCursor1)); 
    ArrowsCursor.debug(false);
    ArrowsCursor.create(arrowsCursor_width,arrowsCursor_height, HexToBinImage(arrowsCursor_width, arrowsCursor_height, arrowsCursor0)); 
    ArrowsCursor.addFrame(HexToBinImage(arrowsCursor_width, arrowsCursor_height, arrowsCursor1)); 
    RunButton.debug(false);
    RunButton.create(runStopButtons_width,runStopButtons_height,HexToBinImage(runStopButtons_width, runStopButtons_height, runButton0));
    RunButton.addFrame(HexToBinImage(runStopButtons_width, runStopButtons_height, runButton1));
    RunButton.addFrame(HexToBinImage(runStopButtons_width, runStopButtons_height, runButton2));
    StopButton.debug(false);
    StopButton.create(runStopButtons_width,runStopButtons_height,HexToBinImage(runStopButtons_width, runStopButtons_height, stopButton0));
    StopButton.addFrame(HexToBinImage(runStopButtons_width, runStopButtons_height, stopButton1));
    StopButton.addFrame(HexToBinImage(runStopButtons_width, runStopButtons_height, stopButton2));
    //-------------------------------affichage des icones-------------------------------
    //sensors
    Thermometer.drawFrame(10, 25, 0, ST7735_ORANGE);
    WaterDrop.drawFrame(54, 25, 0, ST7735_BLUE);
    Leaf.drawFrame(99, 25, 0, ST7735_GREEN);
    Speedometer.drawFrame(10,47,0, ST7735_WHITE);
    //speedfan icons
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.setCursor(10,75);               
    tft.print("Set speed:");
    RunButton.drawFrame(10, 90, 0, ST7735_WHITE);
    tft.drawRect(50,94,79,6, 0xFFFF);
    tft.drawRect(52,96,map(dacValue,180,200,79-16,0)-1,2, ST77XX_MAGENTA);
    //SpeedCursor.drawFrame(52+map(dacValue,0,256,0,79-16), 90, 0);
    //tank
    tft.drawRect(116,50,35,35, 0xFFFF);
    tft.drawRect(117,51,33,33, 0xFFFF);
    for(int i=0; i < 35; i++){
      if (i%6 == 0){
      tft.drawLine(116+35+1,50+i,116+35+2,50+i, 0xFFFF);
      }
      else if (i%6 == 3){
      tft.drawLine(116+35+1,50+i,116+35+1,50+i, 0xFFFF);
      }   
    }
    tft.setCursor(119, 53);               
    tft.print("Tank:");
    //menu selection lines
    
    tft.drawLine(0,1,0,15, 0xFFFF); //x,y à x,y
    tft.drawLine(0,1,67,1, 0xFFFF);
    tft.drawLine(67,1,67,15, 0xFFFF);
    tft.drawLine(67,15,157,15, 0xFFFF);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);  
   
    menuSetup = 1;
    okCount = 0;
  }
  //-------------------------------loop of menuDashboard-------------------------------
  else { 
     tft.setTextColor(ST7735_RED, ST7735_BLACK);  
     tft.setTextSize(1);                 
     tft.setCursor(29, 55);
     String rpmString;
     if (toursParMinute>1000) rpmString = "rpm";   
     else if (toursParMinute>100) rpmString = "rpm ";   
     else if (toursParMinute>10) rpmString = "rpm  "; 
     if (not isRunning) toursParMinute = 0;
     if (toursParMinute==0) rpmString = "rpm   "; 
     tft.print(String(toursParMinute)+ rpmString);               
     tft.setCursor(119, 75);
     tft.print(String(maxTankFillLevel-tankFillLevel)+ "mm ");
     tft.setCursor(25, 31);
     tft.print(String(temperature)+"C ");
     tft.setCursor(69, 31);
     tft.print(String(humidity)+"% ");
     tft.setCursor(114, 31);
     tft.print(String(airQuality/10.24)+ "% ");  
     tft.setTextColor(ST77XX_MAGENTA, ST7735_BLACK);
     tft.setCursor(133, 93);     
     tft.print(String(map(dacValue, 180, 200, 99, 1))+"% ");  
     if (isRunning){
      frame = counter%3;
      Pixelfan.drawFrame(75, 50, frame+1, ST7735_WHITE);    
     }
     else{
      Pixelfan.drawFrame(75, 50, 0, ST7735_WHITE); 
     }
     
     if (okCount == 0){ //curseur sur le menu principale
      isInMenu = 0;
      frame = counter%2;
      MenuCursor.drawFrame(26, 15, frame, ST7735_WHITE);
      if(isRunning) StopButton.drawFrame(10, 90, 0, ST7735_WHITE);
      else if(not isRunning) RunButton.drawFrame(10, 90, 0, ST7735_WHITE);
      SpeedCursor.drawFrame(52+map(dacValue,180,200,79-16,0), 90, 0, ST7735_WHITE); 
      ArrowsCursor.drawFrame(52+map(dacValue,180,200,79-16,0), 103, 1, ST7735_WHITE); 
      
     }

     if (okCount == 1){ //curseur sur le premier bouton interactif
      isInMenu = 1;    
      previousOkCount = 1;  
      MenuCursor.drawFrame(26, 15, 1, ST7735_WHITE);
     }

     if (indexSelection == 0 and isInMenu){ //up run stop button
      SpeedCursor.drawFrame(52+map(dacValue,180,200,79-16,0), 90, 0, ST7735_WHITE);  
      if (not isRunning){ //click
        frame = counter%2;
        RunButton.drawFrame(10, 90, frame, ST7735_WHITE);
        digitalWrite(fanMOSFET, LOW);                               
        dacWrite(PWMfanPin, 255); 
      }
      else if (isRunning){ //click
        frame = counter%2;
        StopButton.drawFrame(10, 90, frame, ST7735_WHITE);
        digitalWrite(fanMOSFET, HIGH);                               
        dacWrite(PWMfanPin, dacValue); 
      }
      if (okCount > previousOkCount ){
        if(isRunning) isRunning = 0;
        else if(not isRunning) isRunning = 1;
      }
     }
     if (indexSelection > 0 and isInMenu){ //up slider
      indexSelection = 1;    
      
      tft.drawRect(52,96,map(dacValue,180,200,79-16,0)-1,2, ST77XX_MAGENTA);    
      if (okCount > previousOkCount){
        dacValueIsEnable = 1;
      }
 
      if (dacValueIsEnable == 1){//ici on varie la longeur du slider
          dacWrite(PWMfanPin, dacValue);       
        //nettoye
        //à gauche
        tft.drawLine(50,92,52+map(dacValue,180,200,79-16,0)-1,92, 0x0000);
        tft.drawLine(50,101,52+map(dacValue,180,200,79-16,0)-1,101, 0x0000);
        tft.drawLine(51,93,52+map(dacValue,180,200,79-16,0)-1,93, 0x0000);
        tft.drawLine(51,100,52+map(dacValue,180,200,79-16,0)-1,100, 0x0000);
        tft.drawLine(51,95,52+map(dacValue,180,200,79-16,0)-1,95, 0x0000);
        tft.drawLine(51,98,52+map(dacValue,180,200,79-16,0)-1,98, 0x0000);
        tft.drawLine(52+map(dacValue,180,200,79-16,0)-1,96,52+map(dacValue,180,200,79-16,0)-1,97, 0x0000);
        tft.fillRect(48+map(dacValue,180,200,79-16,0), 104, 4,5, 0x0000); //fleche contresens
        //à droite
        tft.drawLine(52+map(dacValue,180,200,79-16,0)+12,92,128,92, 0x0000);
        tft.drawLine(52+map(dacValue,180,200,79-16,0)+12,101,128,101, 0x0000);
        tft.drawLine(52+map(dacValue,180,200,79-16,0)+12,93,128,93, 0x0000);
        tft.drawLine(52+map(dacValue,180,200,79-16,0)+12,100,128,100, 0x0000);
        tft.drawLine(52+map(dacValue,180,200,79-16,0)+12,95,128,95, 0x0000);
        tft.drawLine(52+map(dacValue,180,200,79-16,0)+12,98,128,98, 0x0000);
        tft.drawLine(52+map(dacValue,180,200,79-16,0)+12,96,128,96, 0x0000);
        tft.drawLine(52+map(dacValue,180,200,79-16,0)+12,97,128,97, 0x0000);
        tft.fillRect(52+map(dacValue,180,200,79-16,0)+12, 104, 4,5, 0x0000); //fleche contresens
        //repli     
        tft.drawRect(50,94,79,6, 0xFFFF);
        ArrowsCursor.drawFrame(52+map(dacValue,180,200,79-16,0), 103, frame, ST7735_WHITE);
        SpeedCursor.drawFrame(52+map(dacValue,180,200,79-16,0), 90, 0,ST7735_WHITE);
        //Serial.println(dacValue);
      }
      else {  
        frame = counter%2;     
        SpeedCursor.drawFrame(52+map(dacValue,180,200,79-16,0), 90, frame, ST7735_WHITE);  
      }
      if(isRunning) StopButton.drawFrame(10, 90, 0, ST7735_WHITE);
      else if(not isRunning) RunButton.drawFrame(10, 90, 0, ST7735_WHITE);
     }
  }
  previousOkCount = okCount;
}

void displaySignal(int listValues[LIST_LENGTH], int previousListValue[LIST_LENGTH], float value, int  minValue, int maxValue, uint16_t color, int textPos, String text, String unity){
  /* Affiche pixel par pixel la valeur en temps réel d'un capteur de sorte à former un graphique de 100 valeurs historique défilant dans le temps toute les 300ms dans le menu LOGS.
   * Affiche aussi les légendes de ces valeurs avec leur unité et leur valeur
   */
    listValues[LIST_LENGTH-1] = value; // Ajout de la valeur au bout de la liste
    shiftLogsValues(listValues); // Décalage des valeurs
    //on nettoye les précédents points affichés
    for (int i = 0; i < LIST_LENGTH-1; i++) {      
      if (previousListValue[i] != listValues[i]){
        int y = map(previousListValue[i],minValue,maxValue,101,35);
        int x = i+10;
        tft.drawPixel(x,y, 0x0000);   
      }  
    }   
    //On affiche les nouveaux points lu 
    for (int i = 0; i < LIST_LENGTH-1; i++) {    
      if (listValues[i] >= 0){ //Si c'est là première fois qu'on rentre dans les logs, il ne faut pas afficher les valeurs par défauts dans la liste
        int y = map(listValues[i],minValue,maxValue,101,35); //de 110 à 20 pixel = 0 à 100%
        int x = i+10;
        tft.drawPixel(x,y, color);
      }     
    }
    //On stocke les précédents points affichés
    for (int i = 0; i < LIST_LENGTH-1; i++) {      
      previousListValue[i] = listValues[i];    
    }
    //On affiche les textes
   tft.setTextColor(color, ST7735_BLACK); 
   tft.setCursor(118, textPos*13+40);
   tft.print(text);   
   tft.setCursor(textPos*25+7 , 25);
   tft.print(String(listValues[LIST_LENGTH-2])+unity);
}

void menuLogs(){   
  /* Fonction executée dès que l'utilisateur a placé son curseur sur le menu LOGS.
   * Affiche tous les widget en premier temps (cadre du graphe, légendes des données), et ce 1 seule fois.
   * Actualise toutes les valeurs des capteurs dans les courbes en deuxième temps, et ce dans une boucle infinie.
   */
  if(menuSetup == 0){
    tft.drawLine(67,15,0,15, 0xFFFF); 
    tft.drawLine(67,1,67,15, 0xFFFF);
    tft.drawLine(67,1,104,1, 0xFFFF);
    tft.drawLine(104,1,104,15, 0xFFFF);
    tft.drawLine(104,15,157,15, 0xFFFF);      
    menuSetup = 1;
    okCount = 0;
    tft.drawRect(7,35,107,70, 0xFFFF);
  }
  else{
    okCount = 0;
    frame = counter%2;
    MenuCursor.drawFrame(81, 15, frame, ST7735_WHITE); 
    displaySignal(logsValues_VL,previousLogsValues_VL, maxTankFillLevel-tankFillLevel, 0, 80, ST7735_MAGENTA, 0, "Tank", "mm "); 
    displaySignal(logsValues_MQ2,previousLogsValues_MQ2, airQuality/10.24, 0, 100, ST7735_GREEN, 1, "Air", "% ");     
    displaySignal(logsValues_DHT_TEMP,previousLogsValues_DHT_TEMP, temperature, 0, 50, ST7735_ORANGE, 2, "Temp", "C ");
    displaySignal(logsValues_DHT_HUM,previousLogsValues_DHT_HUM, humidity, 0, 100, ST7735_BLUE, 3, "Hum", "% ");
    displaySignal(logsValues_TACH,previousLogsValues_TACH, toursParMinute, 0, 7000, ST7735_YELLOW, 4, "Speed", "rpm ");    
  }
}

void menuOptions(){ 
  /* Fonction executée dès que l'utilisateur a placé son curseur sur le menu OPTIONS.
   * Affiche tous les widget en premier temps (cadre du menu, icones, textes, ...), et ce 1 seule fois.
   * Pret à interragir avec l'utilisateur en deuxième temps, et ce dans une boucle infinie :
   *    Accès au bouton relay (allumer/éteindre le relai)
   *    Accès au bouton screen (forcer le mode veille de l'aspirateur)
   *    Accès au bouton buzzer (active/désactive le buzzer à chaque interraction)
   *    Accès ay bouton 10min AFK (Active/désactive la mise en veille du sisytème après 10min d'activité)
   * En parallele se trouve la durée à laquelle le système est mis en route depuis son lancement.
   * En parallele se trouve l'animation du curseur qui se balade dans chaque bouton.
   */  
  if(menuSetup == 0){ 
    tft.drawLine(104,15,0,15, 0xFFFF); 
    tft.drawLine(104,1,157,1, 0xFFFF); 
    tft.drawLine(104,1,104,15, 0xFFFF);
    tft.drawLine(157,1,157,15, 0xFFFF);
    
    menuSetup = 1;
    okCount = 0;
    
    OptionCursor.debug(false);
    OptionCursor.create(optionCursor_width,optionCursor_height, HexToBinImage(optionCursor_width, optionCursor_height, optionCursor0)); 
    OptionCursor.addFrame(HexToBinImage(optionCursor_width, optionCursor_height, optionCursor1));   

    Speaker.debug(false);
    Speaker.create(speaker_width,speaker_height, HexToBinImage(speaker_width, speaker_height, speaker)); 
    Moon.debug(false);
    Moon.create(moon_width,moon_height, HexToBinImage(moon_width, moon_height, moon)); 
    RelayIcon.debug(false);
    RelayIcon.create(relayIcon_width,relayIcon_height, HexToBinImage(relayIcon_width, relayIcon_height, relayIcon)); 

    RelayIcon.drawFrame(19,37, 0, ST7735_CYAN);
    Moon.drawFrame(90,34, 0, ST7735_YELLOW);
    Speaker.drawFrame(19,74, 0, ST7735_BLUE);
    Moon.drawFrame(90,74, 0, ST7735_YELLOW);
    
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);  
    tft.setTextSize(1);                 
    tft.setCursor(39, 32);               
    tft.print("Relay:");
    tft.setCursor(109, 32);               
    tft.print("Screen:");
    tft.setCursor(39, 72);               
    tft.print("Buzz.:");
    tft.setCursor(109, 72);
    tft.print("10m AFK:");
    
    tft.setTextColor(ST7735_RED, ST7735_BLACK);  
    tft.setTextSize(1); 
    if(buzzerEnabled){tft.setCursor(39, 86); tft.print("ON");}
    else{tft.setCursor(39, 86); tft.print("OFF");}
    if(relayEnabled){tft.setCursor(39, 46); tft.print("ON");}
    else{tft.setCursor(39, 46); tft.print("OFF");}
    if(afkModeEnabled){tft.setCursor(109, 46); tft.print("ON");}
    else{tft.setCursor(109, 46); tft.print("OFF");}
    if(disableAFKCountdown){tft.setCursor(109, 86); tft.print("ON");}
    else{tft.setCursor(109, 86); tft.print("OFF");}
  }
  else{
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.setCursor(64, 100);
    tft.print(String((millis()/1000)/3600)+":"+String(((millis()/1000)%3600)/60)+":"+String((millis()/1000)%60)+" ");
    tft.setTextColor(ST7735_RED, ST7735_BLACK);
    if (okCount == 0){ //curseur sur le menu principale
      isInMenu = 0;
      frame = counter%2;
      MenuCursor.drawFrame(125, 15, frame, ST7735_WHITE);  
      OptionCursor.drawFrame(4, 32, 1, ST7735_WHITE);
      OptionCursor.drawFrame(75, 32, 1, ST7735_WHITE);
      OptionCursor.drawFrame(4, 72, 1, ST7735_WHITE);  
      OptionCursor.drawFrame(75, 72, 1, ST7735_WHITE);        
    }
    if (okCount == 1){ //curseur sur le premier bouton interactif
      isInMenu = 1;    
      previousOkCount = 1;  
      MenuCursor.drawFrame(125, 15, 1, ST7735_WHITE); 
    }
    
    if (indexSelection == 0 and isInMenu){
      frame = counter%2;
      OptionCursor.drawFrame(4, 32, frame, ST7735_WHITE); 
      OptionCursor.drawFrame(75, 32, 1, ST7735_WHITE);
      OptionCursor.drawFrame(4, 72, 1, ST7735_WHITE);  
      OptionCursor.drawFrame(75, 72, 1, ST7735_WHITE);   
      if (okCount > previousOkCount){
        if(relayEnabled){relayEnabled=0; tft.setCursor(39, 46); tft.print("OFF");digitalWrite(pinRelay, LOW);}
        else{relayEnabled=1; tft.setCursor(39, 46); tft.print("ON ");digitalWrite(pinRelay, HIGH);}
      } 
      
    }
    if (indexSelection == 1 and isInMenu){
      frame = counter%2;
      OptionCursor.drawFrame(75, 32, frame, ST7735_WHITE);   
      OptionCursor.drawFrame(4, 32, 1, ST7735_WHITE);
      OptionCursor.drawFrame(4, 72, 1, ST7735_WHITE);  
      OptionCursor.drawFrame(75, 72, 1, ST7735_WHITE);   
      if (okCount > previousOkCount){
        if(afkModeEnabled){afkModeEnabled=0; tft.setCursor(109, 46); tft.print("OFF");}
        else{afkModeEnabled=1; tft.setCursor(109, 46); tft.print("ON ");}
      }
    }
    if (indexSelection == 2 and isInMenu){
      frame = counter%2;
      OptionCursor.drawFrame(4, 72, frame, ST7735_WHITE);  
      OptionCursor.drawFrame(4, 32, 1, ST7735_WHITE);
      OptionCursor.drawFrame(75, 32, 1, ST7735_WHITE);
      OptionCursor.drawFrame(75, 72, 1, ST7735_WHITE);  
      if (okCount > previousOkCount){
        if(buzzerEnabled){buzzerEnabled=0; tft.setCursor(39, 86); tft.print("OFF");}
        else{buzzerEnabled=1; tft.setCursor(39, 86); tft.print("ON ");}
      } 
    }
    if (indexSelection >= 3 and isInMenu){
      indexSelection = 3;
      frame = counter%2;
      OptionCursor.drawFrame(75, 72, frame, ST7735_WHITE);  
      OptionCursor.drawFrame(4, 32, 1, ST7735_WHITE);
      OptionCursor.drawFrame(75, 32, 1, ST7735_WHITE);
      OptionCursor.drawFrame(4, 72, 1, ST7735_WHITE);  
      if (okCount > previousOkCount){
        if(disableAFKCountdown){disableAFKCountdown=0; tft.setCursor(109, 86); tft.print("OFF");}
        else{disableAFKCountdown=1; tft.setCursor(109, 86); tft.print("ON ");}
      }   
    }     
  } 
  previousOkCount = okCount; 
}

String HexToBinImage(int width, int height, String hexa){
  /* Fonction executée lorsqu'il y a création des icones depuis leurs String (depuis le setup).
   * Converti la chaine hexadécimale des icones en chaine binaire. Et ceci dans le but de faciliter l'affichage de l'image sur l'écran pixel par pixel.
   * Là où il y a des 1 se trouve un pixel affiché. Là où il y a des 0 se trouve un pixel éteint, et ce en suivant les lignes et colonnes (width et height) de l'icone en question.
   * Renvoie donc la chaine de caractère binaire.
   */
  long int i = 0;
  String myHexToBin;
  while (hexa[i]){
    switch (hexa[i]){
      case '0': myHexToBin+=("0000");break;
      case '1': myHexToBin+=("0001");break;
      case '2': myHexToBin+=("0010");break;
      case '3': myHexToBin+=("0011");break;
      case '4': myHexToBin+=("0100");break;
      case '5': myHexToBin+=("0101");break;
      case '6': myHexToBin+=("0110");break;
      case '7': myHexToBin+=("0111");break;
      case '8': myHexToBin+=("1000");break;
      case '9': myHexToBin+=("1001");break;
      case 'A': case 'a': myHexToBin+=("1010");break;
      case 'B': case 'b': myHexToBin+=("1011");break;
      case 'C': case 'c': myHexToBin+=("1100");break;
      case 'D': case 'd': myHexToBin+=("1101");break;
      case 'E': case 'e': myHexToBin+=("1110");break;
      case 'F': case 'f': myHexToBin+=("1111");break;
      //default : Serial.println("ERROR");
    }
  i++;
  }
  // s'assurer que l'image respectera sa width*height et ne soit pas betement un multiple de 4 :
  int lengthBin = i * 4;
  while ((width * height) - lengthBin > 0){
    myHexToBin = '0' + myHexToBin; //on rajoute des 0 à l'avant
    lengthBin++;
  }
  return myHexToBin;
}

void setup() {
  /* Initialise tout le système :
   *    Le Serial à 115200 bauds
   *    Les l'éinMode des entrées sorties.
   *    Ecran, depuis le SPI
   *    Les images/icones (création des frames depuis leurs objets créés)
   *    Affichage des menu
   *    Les capteurs et de la carte SD
   */
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(PinTachymetre), compterTours, RISING);
  pinMode(escapeButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(okButton, INPUT);
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(pinBuzzer, LOW);
  
  //-------------------------------------TFT----------------------------------
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab 
  tft.fillScreen(ST77XX_BLACK);
  tft.setRotation(3); // mode paysage
    
  BackButton.debug(false);
  BackButton.create(buttons_width,buttons_height, HexToBinImage(buttons_width, buttons_height, backButton0));
  BackButton.addFrame(HexToBinImage(buttons_width, buttons_height, backButton1));

  LeftButton.debug(false);
  LeftButton.create(buttons_width,buttons_height, HexToBinImage(buttons_width, buttons_height, leftButton0));
  LeftButton.addFrame(HexToBinImage(buttons_width, buttons_height, leftButton1));

  RightButton.debug(false);
  RightButton.create(buttons_width,buttons_height, HexToBinImage(buttons_width, buttons_height, rightButton0));
  RightButton.addFrame(HexToBinImage(buttons_width, buttons_height, rightButton1));

  OkButton.debug(false);
  OkButton.create(buttons_width,buttons_height, HexToBinImage(buttons_width, buttons_height, okButton0));
  OkButton.addFrame(HexToBinImage(buttons_width, buttons_height, okButton1));

  MenuCursor.debug(false);
  MenuCursor.create(menuCursor_width,menuCursor_height, HexToBinImage(menuCursor_width, menuCursor_height, menuCursor0));
  MenuCursor.addFrame(HexToBinImage(menuCursor_width, menuCursor_height, menuCursor1));
  
  BackButton.drawFrame(0, 116, 0, ST7735_WHITE); 
  LeftButton.drawFrame(42, 116, 0, ST7735_WHITE); 
  RightButton.drawFrame(84, 116, 0, ST7735_WHITE);    
  OkButton.drawFrame(126, 116, 0, ST7735_WHITE);
  tft.drawLine(0,15,0,110, 0xFFFF);
  tft.drawLine(157,15,157,110, 0xFFFF);
  tft.drawLine(0,110,157,110, 0xFFFF);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);  
  tft.setTextSize(1);                 
  tft.setCursor(8, 4);               
  tft.print("DASHBOARD");
  tft.setCursor(75, 4);               
  tft.print("LOGS");
  tft.setCursor(110, 4);               
  tft.print("OPTIONS"); 
  //On rempli les listes des signaux des logs à -1 pour que ces valeurs soient filtrées dès le premier instant où ils sont affichés
  allMinOneLogsValues(logsValues_VL);
  allMinOneLogsValues(logsValues_MQ2);
  allMinOneLogsValues(logsValues_TACH);
  allMinOneLogsValues(logsValues_DHT_HUM);
  allMinOneLogsValues(logsValues_DHT_TEMP);

  


  pinMode(PinTachymetre, INPUT);                                  // Mise en entrée de la pin du tachymetre
  pinMode(fanMOSFET, OUTPUT); 
  digitalWrite(fanMOSFET, LOW); 
 
  //-------------------------------------END FAN----------------------------------

  //-------------------------------------VL----------------------------------
  Serial.println("Adafruit VL6180x test!");
  if (! vl.begin()) {
    Serial.println("Failed to find sensor");
    while (1);
  }
  Serial.println("Sensor found!");
  //-------------------------------------END VL----------------------------------
  dht.begin();
  pinMode(pinRelay, OUTPUT); 
  digitalWrite(pinRelay, LOW);

  //-------------------------------------SD-------------------------------------
//if(!SD.begin(32)){
//    Serial.println("Card Mount Failed");
//    return;
//  }
//  uint8_t cardType = SD.cardType();
//
//  if(cardType == CARD_NONE){
//    Serial.println("No SD card attached");
//    return;
//  }
//
//  Serial.print("SD Card Type: ");
//  if(cardType == CARD_MMC){
//    Serial.println("MMC");
//  } else if(cardType == CARD_SD){
//    Serial.println("SDSC");
//  } else if(cardType == CARD_SDHC){
//    Serial.println("SDHC");
//  } else {
//    Serial.println("UNKNOWN");
//  }
//
//  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
//  Serial.printf("SD Card Size: %lluMB\n", cardSize);
//
//  listDir(SD, "/", 0);
//  createDir(SD, "/mydir");
//  listDir(SD, "/", 0);
//  removeDir(SD, "/mydir");
//  listDir(SD, "/", 2);
//  writeFile(SD, "/hello.txt", "Hello ");
//  appendFile(SD, "/hello.txt", "World!\n");
//  readFile(SD, "/hello.txt");
//  deleteFile(SD, "/foo.txt");
//  renameFile(SD, "/hello.txt", "/foo.txt");
//  readFile(SD, "/foo.txt");
// pas ci-dessous :
//  testFileIO(SD, "/test.txt");
//  Serial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
//  Serial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));
  //-------------------------------------END SD-------------------------------------

  dacWrite(PWMfanPin, 0);
}

void compterTours() {
  /* Fonction appelée suite à des interuptions externes.
   * L'interruption en question est la pin de la sorties des étages du traitement du signal du tachymetre.
   * A chaque niveau haut lu, cette fonction est appellée pour incrémenté le nombre de tours effectué dans le laps de temps de 1800ms.
   * A la fin des 1800ms, ce compteur de tours est initialisé (mais pas dans cette fonction)
   */
  tours++;
}

void buzzer(){ 
  /* Fonction appelée à chaque appui sur un bouton.
   * Je ne peux pas utiliser des interruption pour activer le buzzer car cela est overkill. Le buzzer n'est pas une utile en soit.
   * Donc l'utilisation d'un délais de 15ms équivalent au temps de bipage du buzzer a été nécessaire.
   */ 
  digitalWrite(pinBuzzer, HIGH);
  delay(15);
  digitalWrite(pinBuzzer, LOW);
}

void loop() {
  /* Lit les valeurs des boutons physique de l'inteface utilisateur.
   * Gère les flag pour la getion des menu en fonction des appuis sur boutons
   * Calcule le valeurs des capteurs toutes les 300ms:
   *    Vitesse du ventilateur (RPM - toutes les 1800ms)
   *    Niveau de remplissage du réservoir (mm)
   *    Humidité (%)
   *    Température (°C)
   *    Qualité d'air (%)
   * Gère l'activation de la mise en veille du système entier
   */

  escapeButtonValue = digitalRead(escapeButton);
  leftButtonValue = digitalRead(leftButton);
  rightButtonValue = digitalRead(rightButton);
  okButtonValue = digitalRead(okButton);
      
  if (escapeButtonValue == 1 && lastEscapeButtonValue == 0){                                                    
     BackButton.drawFrame(0, 116, 1, ST7735_WHITE);   
     dacValueIsEnable = 0;
     indexSelection =0;
     okCount = 0;
     if(buzzerEnabled) buzzer();
     if(afkModeEnabled) ESP.restart();
     
   }
   else if (escapeButtonValue == 0 && lastEscapeButtonValue == 1 and not afkModeEnabled) {                                      
     BackButton.drawFrame(0, 116, 0, ST7735_WHITE); 
     
   }
   
   if (leftButtonValue == 1 && lastLeftButtonValue == 0){                                                  
     LeftButton.drawFrame(42, 116, 1, ST7735_WHITE);   
     if(menuSelection>0 and okCount == 0) menuSelection--;
     if(indexSelection>0 and isInMenu and not dacValueIsEnable) indexSelection--;
     if(buzzerEnabled) buzzer();
     if(afkModeEnabled) ESP.restart();
   }
   else if (leftButtonValue == 0 && lastLeftButtonValue == 1 and not afkModeEnabled) {       
     LeftButton.drawFrame(42, 116, 0, ST7735_WHITE);    
   }
   if (leftButtonValue == 1){                                               
     if (dacValue < 200 and dacValueIsEnable and flagMyDislplayClock)dacValue+=1; 
   }
   
   if (rightButtonValue == 1 && lastRightButtonValue == 0){                                                  
     RightButton.drawFrame(84, 116, 1, ST7735_WHITE); 
     if(menuSelection<2 and okCount == 0) menuSelection++;  
     if(isInMenu and not dacValueIsEnable) indexSelection++;
     if(buzzerEnabled) buzzer();
     if(afkModeEnabled) ESP.restart();
   }
   else if (rightButtonValue == 0 && lastRightButtonValue == 1 and not afkModeEnabled) {       
     RightButton.drawFrame(84, 116, 0,ST7735_WHITE);    
   }
   if (rightButtonValue == 1 ){                                                      
     if (dacValue > 180 and dacValueIsEnable and flagMyDislplayClock)dacValue-=1;       
   }
   
   if (okButtonValue == 1 && lastOkButtonValue == 0){                                                  
     OkButton.drawFrame(126, 116, 1, ST7735_WHITE);   
     okCount++; 
     if(buzzerEnabled) buzzer();
     if(afkModeEnabled) ESP.restart();
   }
   else if (okButtonValue == 0 && lastOkButtonValue == 1 and not afkModeEnabled) {       
     OkButton.drawFrame(126, 116, 0, ST7735_WHITE);    
   }

   if (afkModeEnabled == 0){
     if (isRunning){
       temps = micros() - tempsPrecedent;                                               // Calcul du temps écoulé depuis le dernier tour
       if (temps >= delai * 1000) {                                                     // Si le temps écoulé est supérieur à la durée choisie (toutes les "delai" milisecondes il va prendre le nombre de tours effectués dans ce laps de temps pour calculer les rpm)
         detachInterrupt(digitalPinToInterrupt(PinTachymetre));                         // Désactivation de l'interruption pour éviter les compteurs parallèles
         toursParMinute = ((tours * 60 / (temps / 1000000.0))/2)*8;                   // Calcul des tours par minute (/2 car il y a 2 pole par tour dans l'axe du ventilateur)(*8 car le registre divise par 8 la vraie fréquence)
         tours = 0;                                                                     // Réinitialisation du nombre de tours
         tempsPrecedent = micros();                                                     // Mise à jour du temps pour le prochain calcul
         attachInterrupt(digitalPinToInterrupt(PinTachymetre), compterTours, RISING);   // Réactivation de l'interruption pour compter les tours suivants
       }
     }
     myDislplayClock = (millis()/300)%2;
     if (myDislplayClock == 1 and myOldDislplayClock == 0){
       flagMyDislplayClock = 1;
       counter++; 
       uint8_t range = vl.readRange();
       uint8_t status = vl.readRangeStatus(); 
       tankFillLevel = range;
       airQuality = analogRead(pinMQ2);
       humidity = dht.readHumidity();
       temperature = dht.readTemperature();
       if (isnan(humidity) || isnan(temperature)) {
          temperature = 0;
          humidity = 0;
       }
       
        if (previousMenuSelection != menuSelection){ //changement de menu
          tft.fillRect(1,16,156,94, 0x0000); //on efface le contenu des anciennes fenetres
          //Dashboard
          tft.drawLine(0,1,0,15, 0x0000); //x,y à x,y
          tft.drawLine(0,1,67,1, 0x0000);
          tft.drawLine(67,1,67,15, 0x0000);
          tft.drawLine(67,15,157,15, 0x0000);
          //logs
          tft.drawLine(67,15,0,15, 0x0000); 
          tft.drawLine(67,1,67,15, 0x0000);
          tft.drawLine(67,1,104,1, 0x0000);
          tft.drawLine(104,1,104,15, 0x0000);
          tft.drawLine(104,15,157,15, 0x0000);    
          //Options
          tft.drawLine(104,15,0,15, 0x0000); 
          tft.drawLine(104,1,157,1, 0x0000); 
          tft.drawLine(104,1,104,15, 0x0000);
          tft.drawLine(157,1,157,15, 0x0000);
          menuSetup =0;
       }
       if (menuSelection == 0 ){
             
          menuDashboard(); 
       }
       else if (menuSelection == 1){     
       
          menuLogs();
       }
       else if (menuSelection == 2 ){     
          
          menuOptions();
       }
  
       previousMenuSelection = menuSelection;     
     }
     else {
      flagMyDislplayClock = 0;
     }

     if (millis() > 600000 and not isRunning and disableAFKCountdown){
      afkModeEnabled = 1;
      digitalWrite(fanMOSFET, LOW);
     }
   }
   lastEscapeButtonValue = escapeButtonValue;
   lastLeftButtonValue = leftButtonValue;
   lastRightButtonValue = rightButtonValue;
   lastOkButtonValue = okButtonValue;
   myOldDislplayClock = myDislplayClock;
  
   if (afkModeEnabled == 1 and previousAfkModeEnabled ==0){
     tft.fillScreen(ST77XX_BLACK);
     detachInterrupt(digitalPinToInterrupt(PinTachymetre));
     delay(200);
     for(int i = 0; i < 3; i++){
       digitalWrite(pinBuzzer, HIGH);
       delay(50);
       digitalWrite(pinBuzzer, LOW);
       delay(50);       
     }
   }
   previousAfkModeEnabled = afkModeEnabled;
   
}
