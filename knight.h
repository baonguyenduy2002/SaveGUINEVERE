#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;

const int WIN=0;
const int MADBEAR=1;
const int BANDIT=2;
const int LORDLUPIN=3;
const int ELF=4;
const int TROLL=5;
const int SHAMAN=6;
const int VAJSH=7;
const int EXCALIBUR=8;
const int MYTHRIL=9;
const int EXCALIPOOR=10;
const int MUSHMARIO=11;
const int MUSHFIBO=12;
const int MUSHGHOST=13;
const int MUSHKNIGHT=14;
const int REMEDY=15;
const int PHOENIXDOWN=16;
const int MERLIN=17;
const int NINA=18;
const int ABYSS=19;
const int TIMEENTRANCE=20;
const int GUINEVERE=21;
const int LIGHTWING=22;
const int ODIN=23;
const int DRAGONSWORD=24;
const int BOWSER=99;
const int Normal=100;
const int Arthur=101;
const int Lancelot=102;
const int Paladin=103;
const int Dragon=104;


const int EVENT_SIZE = 100;
const int MAX_CHARACTER_EACH_LINE = 250;

int q,greatpower=0,Odincount=0,Dragonpower=0,KnightClass=100,OdinHelp=1,OdinPower=0,arise,score,fibo[20],maxHP,excalibur=0,excalipoor=0,mythril=0,tired=0,tinycount=0,frogcount=0,HPrevive=0,levelrevive=0;
string password;

struct knight
{
   int HP;
   int DF;
   int level;
   int remedy;
   int gold;
   int phoenixdown;
};

// read data from input file to corresponding variables
// return 1 if successfully done, otherwise return 0

int startJourney(knight theKnight, int nEvent, int *arrEvent){
    maxHP=theKnight.HP;
    for (q=2;q<maxHP;q++){
        if ((maxHP%q)==0){q=2000;}
    }
    for (int x=1;x<maxHP;x++){
        for (int y=1;y<maxHP;y++){
            double z=sqrt(x*x+y*y);
            if ((z-int(z))==0){if ((x+y+z)==maxHP) KnightClass=Dragon;}
        }
    }
    if (q==maxHP){KnightClass=Paladin;}
    if (maxHP==999){KnightClass=Arthur;}
    if (maxHP==888){KnightClass=Lancelot;}
    for (int i = 0; i < nEvent; i++)
    {
        int theEvent = arrEvent[i];
        //cout << theEvent << endl;
        if (KnightClass==Arthur||KnightClass==Paladin||Dragonpower==1){greatpower=1;}
        if (KnightClass==Lancelot){if((theKnight.level%2)==1){greatpower=1;} else {greatpower=0;}}
        switch (theEvent)
        {
            case WIN:
                i=nEvent;
                break;

            case MADBEAR:{
                int b = (i+1)%10;
                int levelO = (i+1)>6?(b>5?b:5):b;
                if (greatpower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 10;
                }
                else if (OdinPower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 10;
                }
                else if ((theKnight.level>levelO||excalibur==1)&&excalipoor==0){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 10;
                }
                else if ((excalipoor==1||theKnight.level<levelO)&&mythril==0){
                    int damage = 10*levelO;
                    theKnight.HP+= theKnight.DF - damage;
                }
                break;}

            case BANDIT:{
                int b = (i+1)%10;
                int levelO = (i+1)>6?(b>5?b:5):b;
                if (greatpower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 20;
                }
                else if (OdinPower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 20;
                }
                else if ((theKnight.level>levelO||excalibur==1)&&excalipoor==0){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 20;
                }
                else if ((excalipoor==1||theKnight.level<levelO)&&mythril==0){
                    int damage = 25*levelO;
                    theKnight.HP+= theKnight.DF - damage;
                }
                break;}

            case LORDLUPIN:{
                int b = (i+1)%10;
                int levelO = (i+1)>6?(b>5?b:5):b;
                if (greatpower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 30;
                }
                else if (OdinPower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 30;
                }
                else if ((theKnight.level>levelO||excalibur==1)&&excalipoor==0){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 30;
                }
                else if ((excalipoor==1||theKnight.level<levelO)&&mythril==0){
                    int damage = 55*levelO;
                    theKnight.HP+= theKnight.DF - damage;
                }
                break;}

            case ELF:{
                int b = (i+1)%10;
                int levelO = (i+1)>6?(b>5?b:5):b;
                if (greatpower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 40;
                }
                else if (OdinPower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 40;
                }
                else if ((theKnight.level>levelO||excalibur==1)&&excalipoor==0){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 40;
                }
                else if ((excalipoor==1||theKnight.level<levelO)&&mythril==0){
                    int damage = 75*levelO;
                    theKnight.HP+= theKnight.DF - damage;
                }
                break;}

            case TROLL:{
                int b = (i+1)%10;
                int levelO = (i+1)>6?(b>5?b:5):b;
                if (greatpower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 50;
                }
                else if (OdinPower==1){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 50;
                }
                else if ((theKnight.level>levelO||excalibur==1)&&excalipoor==0){
                    theKnight.level++;
                    theKnight.DF++;
                    theKnight.gold+= 50;
                }
                else if ((excalipoor==1||theKnight.level<levelO)&&mythril==0){
                    int damage = 95*levelO;
                    theKnight.HP+= theKnight.DF - damage;
                }
                break;}

            case SHAMAN:{
                int b = (i+1)%10;
                int levelO = (i+1)>6?(b>5?b:5):b;
                if (frogcount==0 && tinycount==0){
                if (greatpower==1){
                    theKnight.level+=2;
                    theKnight.DF+=2;
                }
                else if (OdinPower==1){
                    theKnight.level+=2;
                    theKnight.DF+=2;
                }
                else if (theKnight.level>levelO&&excalipoor==0){
                    theKnight.level+=2;
                    theKnight.DF+=2;
                }
                else if (theKnight.level<levelO||excalipoor==1){
                    theKnight.HP=theKnight.HP/5;
                    if (theKnight.HP==0){theKnight.HP=1;}
                    tinycount=3;
                    HPrevive=1;
                }}
                break;}

            case VAJSH:{
                int b = (i+1)%10;
                int levelO = (i+1)>6?(b>5?b:5):b;
                if (frogcount==0 && tinycount==0){
                if (greatpower==1){
                    theKnight.level+=2;
                    theKnight.DF+=2;
                }
                else if (OdinPower==1){
                    theKnight.level+=2;
                    theKnight.DF+=2;
                }
                else if (theKnight.level>levelO&&excalipoor==0){
                    theKnight.level+=2;
                    theKnight.DF+=2;
                }
                else if (theKnight.level<levelO||excalipoor==1){
                    levelrevive=theKnight.level;
                    theKnight.level=1;
                    frogcount=3;
                }}
                break;}

            case EXCALIBUR:{
                if (Dragonpower==0){
                excalibur=1;
                excalipoor=0;}
                break;}

            case MYTHRIL:{
                if (tired==0){
                mythril=6;
                tired=8;
                }
                break;}

            case EXCALIPOOR:{
                if (theKnight.level<5&&greatpower==0&&KnightClass!=Dragon){
                    excalipoor=1;
                    excalibur=0;
                }
                break;}

            case MUSHMARIO:{
                theKnight.HP+=50;
                break;}

            case MUSHFIBO:{
                int i=2;
                fibo[1]=1;
                fibo[2]=1;
                while (fibo[i]<theKnight.HP){
                    fibo[i+1]=fibo[i]+fibo[i-1];
                    i++;
                }
                theKnight.HP+=fibo[i-1];
                break;}

            case MUSHGHOST:{
                if (OdinPower==0){
                if (KnightClass!=Paladin&&Dragonpower!=1){
                theKnight.HP-=50;
                theKnight.DF-=5;
                if (theKnight.HP<=0){theKnight.HP=1;}
                if (theKnight.DF<=0){theKnight.DF=1;}
                }}
                break;}

            case MUSHKNIGHT:{
                maxHP+=50;
                if (maxHP>999){maxHP=999;}
                theKnight.HP=maxHP;
                break;}

            case REMEDY:{
                theKnight.remedy++;
                if (theKnight.remedy>99){theKnight.remedy=99;}
                break;}

            case PHOENIXDOWN:{
                theKnight.phoenixdown++;
                if (theKnight.phoenixdown>99){theKnight.phoenixdown=99;}
                break;}

            case MERLIN:{
                if (tinycount>0){
                    theKnight.HP=theKnight.HP*5;
                    HPrevive=0;
                    tinycount=0;
                }
                if (frogcount>0){
                    theKnight.level=levelrevive;
                    levelrevive=0;
                    frogcount=0;
                }
                theKnight.level++;
                theKnight.HP=maxHP;
                break;}

            case NINA:{
                double sumHP=0,sumgold=0;
                for (int j=1;j<=theKnight.HP;j++){
                    if ((theKnight.HP%j)==0) sumHP+=j;
                }
                for (int j=1;j<=theKnight.gold;j++){
                    if ((theKnight.gold%j)==0) sumgold+=j;
                }
                sumHP=sumHP/theKnight.HP;
                sumgold=sumgold/theKnight.gold;
                if (sumHP==sumgold){
                    if (tinycount>0||frogcount>0){
                        if (HPrevive==1){
                        theKnight.HP=theKnight.HP*5;}
                        HPrevive=0;
                        tinycount=0;
                        if(levelrevive>0){theKnight.level=levelrevive;}
                        levelrevive=0;
                        frogcount=0;
                        theKnight.HP=maxHP;
                }}
                else {if (theKnight.gold>=50){
                    if (tinycount>0||frogcount>0){
                        if (HPrevive==1){
                        theKnight.HP=theKnight.HP*5;}
                        HPrevive=0;
                        tinycount=0;
                        if(levelrevive>0){theKnight.level=levelrevive;}
                        levelrevive=0;
                        frogcount=0;
                        theKnight.gold-=50;
                    }
                    while (theKnight.HP<maxHP&&theKnight.gold>0){
                        theKnight.HP++;
                        theKnight.gold--;
                    }
                }}
                break;}

            case ABYSS:{
                int sumpassword,sa,ka,la,ja;
                if (Dragonpower==1){}
                else if (OdinPower==1){

                }
                else if (theKnight.level<7){
                    if (theKnight.gold>=50){
                        theKnight.gold-=50;
                    }
                    else {
                        password+=to_string(theKnight.HP)+to_string(theKnight.DF)+to_string(theKnight.level)+to_string(theKnight.remedy)+to_string(theKnight.gold)+to_string(theKnight.phoenixdown);
                        sumpassword=0;
                        sa= password.length();
                        for (ja=0;ja<sa;ja++){
                                ka=0;
                                la=0;
                                while (ka<2&&la<sa){
                                    if (password[la]==password[ja]){ka++;}
                                    la++;
                                }
                                if (ka==1){sumpassword+=(password[ja]-'0');}
                        }
                        if (sumpassword<15){
                            theKnight.HP=0;
                        }
                    }
                }
                break;}

            case TIMEENTRANCE:{
                arise=i+1;
                break;}

            case GUINEVERE:{
                for (int j=i-1;j>=0;j--){
                    arrEvent[2*i-j]=arrEvent[j];
                    nEvent=2*i+1;
                }
                break;}

            case LIGHTWING:{
                if (arrEvent[i+1]==0||arrEvent[i+1]==21||arrEvent[i+2]==0||arrEvent[i+2]==21||arrEvent[i+3]==0||arrEvent[i+3]==21){
                    i=nEvent;
                } else {i=i+3;}
                break;}

            case ODIN:{
                if (OdinHelp==1){
                    OdinPower=1;
                    OdinHelp=0;
                    Odincount=3;
                }
                break;}

            case DRAGONSWORD:{
                if (KnightClass==Dragon){
                    Dragonpower=1;
                }
                break;}

            case BOWSER:{
                if (OdinPower==1){
                    theKnight.level=10;
                }
                else switch (KnightClass){
                    case Normal:{
                        if (theKnight.level<10){theKnight.HP=0;theKnight.phoenixdown=0;}
                        break;
                    }
                    case Arthur:{
                        theKnight.level=10;
                        break;
                    }
                    case Lancelot:{
                        theKnight.level=10;
                        break;
                    }
                    case Paladin:{
                        if (theKnight.level>=8){theKnight.level=10;} else {theKnight.HP=0;theKnight.phoenixdown=0;}
                        break;
                    }
                    case Dragon:{
                        if (Dragonpower==1){theKnight.level=10;} else {theKnight.HP=0;theKnight.phoenixdown=0;}
                        break;
                    }
                }
                break;}
        }
    //Prepare for the next event
    password+=to_string(theEvent);
    if (theKnight.HP<=0){
            if (theKnight.phoenixdown>0){
                theKnight.HP=maxHP;
                theKnight.phoenixdown--;
                if (levelrevive>0){
                    theKnight.level=levelrevive;
                    levelrevive=0;
                }
                tinycount=0;
                HPrevive=0;
                frogcount=0;
                levelrevive=0;
                if (arise>0){i=arise-1;}
            } else {i=nEvent;}
        }
    if (mythril>0){
            mythril--;
        }
        if (tired>0){
            tired--;
        }
        if (Odincount==0){
            OdinPower=0;
        }
        if (Odincount>0){
            Odincount--;
        }
        if (frogcount>0){
            frogcount--;
            } else if (frogcount==0&&levelrevive>0){
                theKnight.level==levelrevive;
                levelrevive=0;
        }
        if (tinycount>0){
            tinycount--;
            } else if (tinycount==0&&HPrevive==1){
                theKnight.HP=theKnight.HP*5;
                HPrevive=0;
        }
    if (theKnight.remedy>0 && frogcount>0){
            theKnight.remedy--;
            theKnight.level=levelrevive;
            frogcount=0;
            levelrevive=0;
        }
    if (theKnight.remedy>0 && tinycount>0){
            theKnight.remedy--;
            theKnight.HP=theKnight.HP*5;
            tinycount=0;
            HPrevive=0;
        }
    if (theKnight.HP>maxHP){theKnight.HP=maxHP;}
    if (theKnight.DF>20){theKnight.DF=20;}
    if (theKnight.gold>500){theKnight.gold=500;}
    if (theKnight.level>10){theKnight.level=10;}
    }
    if (theKnight.HP>0){score=theKnight.DF+theKnight.gold+theKnight.HP+theKnight.level+theKnight.phoenixdown+theKnight.remedy;}
    else {score=-1;}
    return score;
}

