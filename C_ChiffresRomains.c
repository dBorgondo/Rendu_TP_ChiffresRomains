#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nb_romains 7
#define max_romain 16
int getChoice();
void RomanToArabic();
void ArabicToRoman();

//Main
//**
//Description :
//Traduit des chiffres romains en chiffres arabes ou des chiffres arabes en chiffres romain
//Entr�es :
//Chiffre Arabe, Chiffre Romain, Choix
//Sorties :
//Chiffre Arabe Traduit, Chiffre Romain Traduit
//**
int main()
{
    int nChoice=0;
    do{
    nChoice=getChoice();//On demande � l'utilisateur de choisir sa conversion et si il souhaite arreter le programme.
    if(nChoice==1){//Si il entre 1 on fait une conversion de chiffres arabes vers chiffres romains
        ArabicToRoman();
    }
    else if(nChoice==2){// Si il entre 2 on fait une conversion de chiffre romain vers chiffre arabe
        RomanToArabic();
    }
    }while (nChoice!=0);//On effectue ces actions en boucle jusqu'� ce que l'utilisateur entre 0
    return 0;
}
//Fonction
//**
//Description :
//Demande � l'utilisateur quel type de conversion il souhaite faire ou si il souhaite arret� le programme.
//Entr�es :
//Choix de l'utilisateur
//Sorties :
//Choix de l'utilisateur
//**
int getChoice(){
    int nChoice = 0;
    printf("\n\n Quel type de conversion souhaitez-vous faire :\n 1 : Chiffres Arabe vers chiffres romain. \n 2 : Chiffres Romain vers chiffres arabes. \n 0: Arreter le programme \n");
    scanf("%d",&nChoice);
    fflush(stdout);
    return nChoice;
}

//Proc�dure
//**
//Description :
//Traduit un chiffre romain en chiffre arabe.
//Entr�es :
//Chiffre Romain
//Sorties :
//Chiffre Arabe
//**
void RomanToArabic(){
    char cSymbols[nb_romains] = "IVXLCDM";//Table de symboles romain
    int nValues[nb_romains] = {1,5,10,50,100,500,1000};//Table de valeurs des symboles
    int nCounter=0;//Position trait� dans la chaine
    int nCounterSymbol=0;//Compteur du symbole qui sert de comparaison
    char cRomain[max_romain]; //Chiffre Romain entr� par l'utilisateur(Taille de 16 car le plus grand chiffre possible est : MMMDCCCLXXXVIII)
    int nUnder=0; //Distance entre un chiffre romain et son chiffre soustractif dans la table de symbole (Ex : Le chiffre soustractif de X et V est I)
    int nTotal=0; //Valeur � laquel on ajoute la valeur des chiffres romain trait�
    printf("Veuillez entrer votre chiffre romain : \n");
    scanf("%s",cRomain);
    printf("\n%s correspond a : ",cRomain);
    for (nCounter=(strlen(cRomain)-1);nCounter>=0;nCounter--){//On effectue cette boucle jusqu'� avoir trait� tout les caract�re du nombre romain
        nUnder=((nCounterSymbol%2==0)? 2 : 1); //On d�finie nUnder il vaut 2 pour les nombres au compteur pair(V,L,D) de la table et 1 pour les nombres au compteur impair(I,X,C,M) de la table
        if (cRomain[nCounter]==cSymbols[nCounterSymbol-nUnder]){//On v�rifie si le symbole � la position nCounter correspond au symbole de soustraction du symbole pr�c�dent
            nTotal-=nValues[nCounterSymbol-nUnder]; //Si c'est le cas on soustrait �a valeur au total
            }
        else {
            while(cRomain[nCounter]!=cSymbols[nCounterSymbol]){//On incr�mente le compteur des symboles jusqu'� arriver au symbole correspondant � la positon nCounter dans la chaine
                        nCounterSymbol+=1;
            }

        nTotal+=nValues[nCounterSymbol];//Une fois le symbole trouv� on ajouter �a valeur au total
        }
    }
    printf("%d",nTotal); //On affiche le total
}

//Fonction
//**
//Description :
//Transforme un chiffre arabe en chiffre romain.
//Entr�es :
//Chiffre Arabe
//Sorties :
//Chiffre Romain
//**
void ArabicToRoman(){
    char cSymbols[nb_romains] = "IVXLCDM"; //Table de symboles romain
    int nValues[nb_romains] = {1,5,10,50,100,500,1000};//Table de valeurs des symboles
    int nCounter=6; //Compteur du symbole romain en cours de traitement
    int nNumber=0; //Nombre entr�e par l'utilisateur
    int nUnder=0;  //Distance entre un chiffre romain et son chiffre soustractif dans la table de symbole (Ex : Le chiffre soustractif de X et V est I)
    printf("Veuillez entrer votre nombre : \n");
    scanf("%d",&nNumber);
    printf("\n%d correspond a : ",nNumber);
    while(nNumber>0){ //Boucle g�n�ral on s'arrete quand le nombre est �gal � 0
        if (nNumber>=nValues[nCounter]){ //On v�rifie si la valeur du symbole en cours traitement est plus petite que le nombre
            printf("%c",cSymbols[nCounter]); //Si c'est le cas on l'affiche
            nNumber-=nValues[nCounter]; //Et on soustrait �a valeur au nombre entr�e par l'utilisateur
        }
        else {
                nUnder=((nCounter%2==0)? 2 : 1); //On d�finie nUnder il vaut 2 pour les nombres au compteur pair(V,L,D) de la table et 1 pour les nombres au compteur impair(I,X,C,M) de la table
                if (nNumber>=(nValues[nCounter]-nValues[nCounter-nUnder])){//Sinon on v�rifie si la valeur du symbole moins la valeur de son symbole de soustraction est plus petit que le nombre
                    printf("%c%c",cSymbols[nCounter-nUnder],cSymbols[nCounter]); //Si c'est le cas on les affiche
                    nNumber-=nValues[nCounter]-nValues[nCounter-nUnder]; //On soustrait leurs valeurs au nombre entr�e par l'utilisateur
                }
                else nCounter--;//Si ce n'est pas le cas on passe au symbole suivant

        }
    }
}


