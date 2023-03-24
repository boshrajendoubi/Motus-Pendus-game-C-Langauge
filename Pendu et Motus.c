#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <windows.h>




void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
    /*0 : Noir  1 : Bleu foncé  2 : Vert foncé  3 : Turquoise  4 : Rouge foncé  5 : Violet
  6 : Vert caca d'oie   7 : Gris clair  8 : Gris foncé  9 : Bleu fluo  10 : Vert fluo
  11 : Turquoise  12 : Rouge fluo  13 : Violet 2  14 : Jaune  15 : Blanc*/
}


char lireCaractere()
{
    char caractere ;

    caractere = getchar();
    caractere = toupper(caractere);


    while (getchar() != '\n') ;

    return caractere ;
}



void motrandom(char str[])
{
    char mot[20][20] = {"YOUTUBE","NETFLIX","WHATSAPP","YAHOO","SNAPCHAT","FACEBOOK","TINDER","ISG","SPOTIFY"};
    int i;
    srand(time(0));
    i = (rand()%9);
    strcpy(str,mot[i]);
}


int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    long i = 0;
    int bonneLettre = 0;


    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }

    return bonneLettre;
}
int help (int lettreTrouvee[])
{
    int i = 0;
    int test = 0;
    while (test == 0)
    {
        if (lettreTrouvee[i] == 0)
        {
            lettreTrouvee[i] = 1;
            test = 1;
        }
        else i++;

    }
    return test ;
}
int gagne(int lettreTrouvee[], long tailleMot)
{
    long i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < tailleMot ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}
int pendu()
{
    char s[20];// le pseudo du joueur
    char lettre = 0 ;// lettre donnee par le joueur
    char tabpseudo [5][20] = {"*****","*****","*****","*****","*****"};// matrice des pseudos
    int coupsrestant = 7 ; // les coups restants
    int i = 0 ; // compteur
    int tailleMot ; // la taille de mot secret
    int lettreTrouvee[20];  // tableau des valeurs 1 et 0
    int score = 0; // compteur de score
    int tabscore[5] = {0,0,0,0,0}; // matrice des scores
    int test = 0; // test pour utiliser help 1 seule fois
    int test2 = 0; // test pour ecraser seulment la premier ligne vide dans la matrice des pseudos
    int choix2 = 3; // choix pour les menu
    int indice ; // indice du ligne ou le pseudo actuelle existe
    int en_desordre =0; // test pour le tri a bulles
    int aux; // auxiliaire pour le tri a bulles
    char aux1[20]; // auxiliaire pour le tri a bulles
    time_t seconds,seconds2; // les variables de temps en secondes
    int  x=0;
    int x2=0;
    int  t=70;// la difference entre l'instant x et x2
    while(choix2==3)
    {
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("||----------------------------------------------------------------------------------------**********************-------------------------------------------------------------------------------------------------|| \n");
        printf("||----------------------------------------------------------------------------------------****WELCOME PLAYER****-------------------------------------------------------------------------------------------------|| \n");
        printf("||----------------------------------------------------------------------------------------**********************-------------------------------------------------------------------------------------------------|| \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");

        test2 = 0;
        indice = 0;
        i=0;
        // donner le pseudo et jouer
        while ((test2==0) && (i<5))
        {
            if (strcmp(tabpseudo[i],"*****") == 0)
            {
                fflush(stdin);
                printf("\t\t\t\t\t\t\t\t\t\t\t ENTER YOUR NAME : ");
                scanf("%s",tabpseudo[i]);
                test2 = 1;
                indice = i;
            }
            else i++;
        }
        choix2=1;
        //boucle de jouer\rejouer avec le meme pseudo
        while (choix2==1)
        {
            fflush(stdin);
            test = 0;
            en_desordre =0;
            coupsrestant = 7;
            system("cls");
            motrandom(s);

            tailleMot = strlen(s);

            for (i = 0 ; i < tailleMot ; i++)
            {
                lettreTrouvee[i] = 0;
            }
            seconds=time(NULL);
            x=seconds;
            t=70;
            while (coupsrestant > 0 && !gagne(lettreTrouvee, tailleMot) && (t>0))
            {
                seconds2=time(NULL);
                x2=seconds2;
                t=70-(x2-x);
                printf("||***************************************************************************************************************************************************************************************************************||\n");
                printf("||***************************************************************************************************************************************************************************************************************||\n");
                printf("||**************************************************************************YOU HAVE %i TRYS LEFT AND %i SECONDES , GOOD LUCK*************************************************************************************||",coupsrestant,t);
                printf("||***************************************************************************************************************************************************************************************************************||\n");
                printf("||***************************************************************************************************************************************************************************************************************||\n");
                printf("\t\t\t\t\t\t\t\t\t\t WHAT IS THE SECRET WORD ");

                for (i = 0 ; i < tailleMot ; i++)
                {
                    Color(13,15);
                    if (lettreTrouvee[i])
                    {

                        printf("%c", s[i]);
                    }
                    else
                    {
                        printf("*");
                    }
                    Color(1,15);
                }
                printf("\n*******************************************************************************************************************************************************************************************************************\n");
                printf("*******************************************************************************************************************************************************************************************************************\n");

                if (test==0)
                    printf("\t\t\t\t\t\t\t\t\t\t\t TAP '?' FOR HELP");
                else printf("\t\t\t\t\t\t\t\t\t\t YOU HAVE ALREADY USED HELP");
                printf("\n\t\t\t\t\t\t\t\t\t\t\t ENTER A LETTRE : ");

                do
                {
                    Color(13,15);
                    lettre = lireCaractere();
                    Color(1,15);
                }
                while (((lettre<'A') || (lettre>'Z')) && (lettre != '?'));

                if ((lettre>='A') && (lettre<='Z'))
                {

                    if (!rechercheLettre(lettre, s, lettreTrouvee))
                    {
                        coupsrestant--;
                    }
                }
                else
                {
                    if (test==0)
                    {
                        help(lettreTrouvee);
                        test=1;
                    }
                    // else printf(" YOU HAVE ALREADY USED HELP");

                }
                system("cls");
            }



            // Resultat fin jeux
            // cas gagne
            if (gagne(lettreTrouvee, tailleMot))
            {
                printf("###################################################################################################################################################################################################################\n");
                printf("###################################################################################################################################################################################################################\n");
                Color(2,15);
                printf("\t\t\t\t\t\t\t\t\tCONGRATULATIONS , YOU WON ! THE SECRET WORD IS  : %s \n\n", s);
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOO  OOOOOOOOO  OOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO      OOOOO      OOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO      OOOOO      OOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOO    OOOOOOO    OOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOO  OOOOOOOOOOOOOOOOOOOOOO  OOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOO   OOOOOOOOOOOOOOOOOOOOO  OOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOO   OOOOOOOOOOOOOOOOOOO  OOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOO    OOOOOOOOOOOOOOO   OOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOO     OOOOOOOOO     OOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO               OOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n\n");
                Color(1,15);
                printf("###################################################################################################################################################################################################################\n");
                printf("###################################################################################################################################################################################################################");

                switch (coupsrestant)
                {
                case 7 :
                case 6 :
                    score = 4;
                    printf("\n \t\t\t\t\t\t\t\t\t\t\t         YOUR SCORE IS : %i\n",score);
                    break;
                case 5 :
                case 4 :
                    score = 3;
                    printf("\n \t\t\t\t\t\t\t\t\t\t\t        YOUR SCORE IS : %i\n",score);
                    break;
                case 3 :
                case 2 :
                    score = 2;
                    printf("\n \t\t\t\t\t\t\t\t\t\t\t        YOUR SCORE IS : %i\n",score);
                    break;
                case 1 :
                    score = 1;
                    printf("\n \t\t\t\t\t\t\t\t\t\t\t        YOUR SCORE IS : %i \n",score);
                    break;


                }


            }
            //cas perdu
            else
            {
                printf("###################################################################################################################################################################################################################\n");
                printf("###################################################################################################################################################################################################################\n");
                Color(4,15);
                printf("\t\t\t\t\t\t\t\t   OOPS , YOU LOST ,THE SECRET WORD WAS : %s , BETTER LUCK NEXT TIME : \n\n", s);
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOO  OOOOOOOOO  OOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO      OOOOO      OOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO      OOOOO      OOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOO    OOOOOOO    OOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO               OOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOO     OOOOOOOOO     OOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOO    OOOOOOOOOOOOOOO   OOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOO   OOOOOOOOOOOOOOOOOOO  OOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOO   OOOOOOOOOOOOOOOOOOOOO  OOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOO  OOOOOOOOOOOOOOOOOOOOOO  OOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n\n");

                Color(1,15);
                printf("###################################################################################################################################################################################################################\n");
                printf("###################################################################################################################################################################################################################");



                score = 0;
            }
            tabscore[indice]+=score;


            // Tri des scores


            while (en_desordre==0)
            {

                en_desordre = 1;

                for ( i = 0; i < 5 ; i++)
                {

                    if (tabscore[i] < tabscore[i+1])
                    {
                        aux=tabscore[i];
                        tabscore[i]=tabscore[i+1];
                        tabscore[i+1]=aux;

                        strcpy(aux1,tabpseudo[i]);
                        strcpy(tabpseudo[i],tabpseudo[i+1]);
                        strcpy(tabpseudo[i+1],aux1);

                        en_desordre = 0;

                    }
                }

            }
            // Menu fin de jeu
            printf("###################################################################################################################################################################################################################\n");
            printf("###################################################################################################################################################################################################################");
            printf("###################################################################################################################################################################################################################\n");
            printf("###################################################################################################################################################################################################################");

            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t 1 - REPLAY \n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t 2 - PLACEMENT \n");

            printf("\t\t\t\t\t\t\t\t\t\t\t\t 3 - NEW PLAYER \n");

            printf("\t\t\t\t\t\t\t\t\t\t\t\t 4 - BACK TO MAIN MENU \n");

            printf("\t\t\t\t\t\t\t\t\t\t\t\t 5 - EXIT \n");
            printf("                                                                               \t            ENTER YOUR OPTION : ");
            do
            {

                scanf("%i",&choix2);

            }
            while ((choix2<1) || (choix2>5) );

            if (choix2 == 2)
            {
                //classment
                system("cls");
                printf("----------------------------------------------------------------------------------------------------PLAYER \t");
                printf("SCORE---------------------------------------------------------------------------------------------- \n");
                for (i=0; i<5; i++)
                {
                    fflush(stdin);
                    printf("--------------------------------------------------------------------------------------------------%i - %s \t",i+1,tabpseudo[i]);
                    printf("   %i ---------------------------------------------------------------------------------------------- \n",tabscore[i]);
                }

                printf("\t\t\t\t\t\t\t\t\t\t\t\t 1 - REPLAY\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t 2 - BACK TO MAIN MENU\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t 3 - NEW PLAYER\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t 4 - EXIT\n");
                printf("                                                                                               ENTER YOUR OPTION : ");
                do
                {
                    fflush(stdin);
                    scanf("%i",&choix2);
                }
                while ((choix2<1) || (choix2>4));
                printf("\n\n");
                if (choix2 == 4 ) exit(0);
            }
            if (choix2 == 5) exit(0);




        }
        system("cls");

    }

    return 0;
}
/************************************************************************/



//verifier la proposition de l'utilisateur (alphabetique et de meme len que motsec


int verif(char proposition[20], char motsec[20])
{
   int test=0;
   int i=0;


   if (strlen(proposition)==strlen(motsec))
      {
        test=0;
      }
   else
{
test=1;
}

    while (test==0 && i<(strlen(proposition)-1))
    {

      if (proposition[i]<'A' || proposition[i]>'Z' && proposition[i]<'a' || proposition[i]>'z')
       {
           test=1;

       }
       else
       {
           test=0;
           i++;
       }

}
return test;
}

//verifier la proposition de help
int vhelp(char proposition[20])
{
    int testt=0;
    if(proposition[strlen(proposition)-1]=='?' && strlen(proposition)==1)
    {
        testt=0;
    }
    else
    {
        testt=1;
    }
    return testt;
}


//motus
void motus()
{
    char lib[20][30]= {"informatique","gestion","algorithme","institut","miel","fabuleux","canada","tolerance","analyse","attention",
                       "soleil","mirroir","passion","roman","classique","livre","pendu","theatre","projet","determination"
                      };//remplir la biblio des mots secrets
    char motsec[20];// le mot secret choisi aléatoirement
    char tabpseudo [5][20] = {"*****","*****","*****","*****","*****"};// le tableau des pseudo
    char psd[20]; // le pseudo du joueur aactuel
    int classement[5]= {0,0,0,0,0};// le tableau des scores
    int i,j,p,k;//des compteurs
    int score=0;// le score d'un joueur
    int help;// controle d'utilisation de help
    int trouve=0;// si l'utilisateur trouve le mot secret ou pas
    int coup=7;// nombre de tentatives
    int nombre = 0; //nombre alea pour donner le num du mot
    char motmask[20];//le mot ou les lettres bien placés sont mis, sa forme initiale est u********
    char malplace[30]="";//les lettres de la proposition de l'utilisateur qui sont malplacés
    char proposition[20];// laa proposition de l'utilisateur
    time_t seconds,seconds2;// les variables de temps en secondes
    int  x=0;// les variables de tmp entiers
    int x2=0;
    int  s=70;// la différence entre l'instant x et x2
    int  choix=3;// le choix de "new player": d'entrer un nouveau pseudo
    while(choix==3)
    {
        srand(time(NULL)); // Initialisation de la donnée seed

//debut du jeu

        system("cls");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("||----------------------------------------------------------------------------------------**********************-------------------------------------------------------------------------------------------------|| \n");
        printf("||----------------------------------------------------------------------------------------****WELCOME PLAYER****-------------------------------------------------------------------------------------------------|| \n");
        printf("||----------------------------------------------------------------------------------------**********************-------------------------------------------------------------------------------------------------|| \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");

//les pseudos

        int test2 = 0;
        int indice = 0;
        i = 0;
        while ((test2==0) && (i<5))
        {
            if (strcmp(tabpseudo[i],"*****") == 0)
            {
                fflush(stdin);
                printf("\t\t\t\t\t\t\t\t\t\t\t ENTER YOUR NAME : ");
                scanf("%s",tabpseudo[i]);
                test2 = 1;
                indice = i;
            }
            else i++;
        }
        choix=1;
        while (choix==1)
        {

//donner un nombre aleatoire pour choisir le mot secret du biblio
            nombre = rand() % (19 + 1 - 1);
            nombre ++;


            // attribuer le mot choisi aleatoirement au motsec

            for (i=1; i<=20; i++)
            {
                if (i==nombre)
                {
                    strcpy(motsec,lib[i]);
                }
            }


//preparer le mot masqué
            strncpy(motmask,motsec,1);

            for(i=1; i<strlen(motsec); i++)
            {
                motmask[i]='*';
            }

            motmask[strlen(motmask)]='\0';


            printf("%s\n",motmask);
            help=1;// pour forcer l'utilisateur à utiliser help une seule fois
            seconds=time(NULL);
            x=seconds;

//************************************************

            help=1;
            coup=7;
            trouve= 0 ;

            while( coup>0 && s>0 && trouve==0)//temps
            {
                seconds2=time(NULL);
                x2=seconds2;
                s=70-(x2-x);
                coup--;
                system("cls");
                printf("||***************************************************************************************************************************************************************************************************************||\n");
                printf("||***************************************************************************************************************************************************************************************************************||\n");
                printf("||**************************************************************************YOU HAVE %i TRYS LEFT AND %i SECONDES , GOOD LUCK*************************************************************************************||",coup,s);
                printf("||***************************************************************************************************************************************************************************************************************||\n");
                printf("||***************************************************************************************************************************************************************************************************************||\n");


                printf("\t\t\t\t\t\t\t\t\t\t WHAT IS THE SECRET WORD ?\n\n\n");
                printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\n[\t%s\t]  \t%s\t",malplace,motmask);
                printf(" \t\t\t\t\t\t\t\t\t\t PS: IT'S COMPOSED OF %i LETTRES \n",strlen(motsec));
                fflush(stdin);
                strcpy(malplace,"                     ");
               if (help!=0)//si l'utilisateur n'a pas utilisé help
                {
                    printf(" \n\n\t TAP '?' FOR HELP \n");

//recevoir la proposition de l'utilisateur
              do{
                printf("\n\t\t\t\t\t\t\t\t\t\t\t ENTER A WORD : ");
                scanf("%s",proposition);
                fflush(stdin);
              }
               while ( verif(proposition,motsec)!=0 && vhelp(proposition)!=0);
                for(k=0; k<strlen(proposition); k++)
                {
                    proposition[k]=tolower(proposition[k]);
                }
                seconds2=time(NULL);
                x2=seconds2;
                s=70-(x2-x);
                if (vhelp(proposition)==0 && help!=0)
                {
                    p=rand()%strlen(motsec);
                    motmask[p]=motsec[p];
                    help=0;
                    score--;
                }
                }
                else
                {
                    if (help==0)
                    {
                        printf("\n\t\t\t\t U'VE ALREADY USED HELP NOW \n\n");

// controle de saisie sur longeur, type des carac

                        int k;

                        do
                        {
                            printf("\n\t\t\t\t\t\t\t\t\t\t\t ENTER A WORD : ");
                            fflush(stdin);
                            scanf("%s",proposition);
                        }
                         while ( verif(proposition,motsec)!=0 && vhelp(proposition)!=0);
                        printf("\n");
//mettre la proposition de l'utilisateur en miniscule

                        for(k=0; k<strlen(proposition); k++)
                        {
                            proposition[k]=tolower(proposition[k]);
                        }
                    }


//tester la proposition de l'utilisateur
                    for(i=0; i<strlen(motsec); i++)
                    {
                        if(proposition[i]==motsec[i])
                        {
                            motmask[i]=proposition[i];


                        }
                        else
                        {
                            j=-1;
                            do
                            {
                                j++;

                            }
                            while (motsec[j]!=proposition[i] && j< strlen(motsec));

                            if(motsec[j]==proposition[i])
                            {

                                malplace[strlen(malplace)-1]=proposition[i];
                                malplace[strlen(malplace)]='-';
                                malplace[strlen(malplace)+1]='\0';


                            }

                        }
                    }


                    if(strcmp(motmask,motsec)==0)
                    {
                        trouve=1;
                    }
                    else
                    {
                        trouve=0;
                    }

                }
            }


            if(trouve==1 && coup>0 && s>0)
            {
                system("cls");
                {
                    //calcul du score
                    switch (7-coup)
                    {
                    case 0 :
                        score=score+4;

                        break;

                    case 1 :
                        score=score+4;

                        break;

                    case 2 :
                        score=score+3;

                        break;
                    case 3 :
                        score=score+3;

                        break;

                    case 4 :
                        score=score+2;

                        break;
                    case 5 :
                        score=score+2;

                        break;
                    case 6 :
                        score=score+1;

                        break;
                    }
                }


                Color(1,15);
                printf("###################################################################################################################################################################################################################\n");
                printf("###################################################################################################################################################################################################################\n");
                Color(2,15);
                printf("\t\t\t\t\t\t\t\t\tCONGRATULATIONS , YOU WON ! THE SECRET WORD IS  : %s \n\n", motsec);
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOO  OOOOOOOOO  OOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO      OOOOO      OOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO      OOOOO      OOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOO    OOOOOOO    OOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOO  OOOOOOOOOOOOOOOOOOOOOO  OOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOO   OOOOOOOOOOOOOOOOOOOOO  OOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOO   OOOOOOOOOOOOOOOOOOO  OOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOO    OOOOOOOOOOOOOOO   OOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOO     OOOOOOOOO     OOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO               OOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n\n");
                Color(1,15);
                printf("###################################################################################################################################################################################################################\n");
                printf("###################################################################################################################################################################################################################");
                printf("\n \t\t\t\t\t\t\t\t\t\t\t         YOUR SCORE IS : %i\n",score);
                // Sleep(3);
            }


            else
            {
                system("cls");
                printf("###################################################################################################################################################################################################################\n");
                printf("###################################################################################################################################################################################################################\n");
                Color(4,15);
                printf("\t\t\t\t\t\t\t\t   OOPS , YOU LOST ,THE SECRET WORD WAS : %s , BETTER LUCK NEXT TIME : \n\n", motsec);
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOO  OOOOOOOOO  OOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO      OOOOO      OOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO      OOOOO      OOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOO    OOOOOOO    OOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOO               OOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOO     OOOOOOOOO     OOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOO    OOOOOOOOOOOOOOO   OOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOO   OOOOOOOOOOOOOOOOOOO  OOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOO   OOOOOOOOOOOOOOOOOOOOO  OOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOO  OOOOOOOOOOOOOOOOOOOOOO  OOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
                printf("\t\t\t\t\t\t\t\t\t\t OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n\n");

                Color(1,15);
                printf("###################################################################################################################################################################################################################\n");
                printf("###################################################################################################################################################################################################################");

                // Sleep(3);
                score = 0;

            }
            classement[k]+=score;
            int en_desordre=0;
            int aux;
            char aux1[20];


            while (en_desordre==0)
            {

                en_desordre = 1;

                for ( i = 0; i < 5 ; i++)
                {

                    if (classement[i] < classement[i+1])
                    {
                        aux=classement[i];
                        classement[i]=classement[i+1];
                        classement[i+1]=aux;

                        strcpy(aux1,tabpseudo[i]);
                        strcpy(tabpseudo[i],tabpseudo[i+1]);
                        strcpy(tabpseudo[i+1],aux1);

                        en_desordre = 0;

                    }
                }

            }


//menu de sortie
            printf("###################################################################################################################################################################################################################\n");
            printf("###################################################################################################################################################################################################################");
            printf("###################################################################################################################################################################################################################\n");
            printf("###################################################################################################################################################################################################################");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t 1 - REPLAY\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t 2 - PLACEMENT\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t 3 - NEW PLAYER\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t 4 - BACK TO MAIN MENU\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t 5 - EXIT\n");
            printf("                                                                               \t         ENTER YOUR OPTION : ");
            do
            {
                fflush(stdin);
                scanf("%i",&choix);
            }
            while ((choix<1) || (choix>5));

            if (choix == 2)
            {
                //classment
                system("cls");
                printf("----------------------------------------------------------------------------------------------------PLAYER \t");
                printf("SCORE---------------------------------------------------------------------------------------------- \n");
                for (i=0; i<5; i++)
                {
                    fflush(stdin);
                    printf("--------------------------------------------------------------------------------------------------%i - %s \t",i+1,tabpseudo[i]);
                    printf("   %i ---------------------------------------------------------------------------------------------- \n",classement[i]);
                }

                printf("\t\t\t\t\t\t\t\t\t\t\t\t 1 - REPLAY\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t 2 - BACK TO MAIN MENU\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t 3 - NEW PLAYER\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t 4 - EXIT\n");
                printf("                                                                                        ENTER YOUR OPTION : ");
                do
                {
                    fflush(stdin);
                    scanf(" %i",&choix);
                }
                while ((choix<1) || (choix>4));

                printf("\n\n");
                if( choix==4 || choix==5)
                {
                    system("cls");
                    printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
                    printf("||----------------------------------------------------------------------------------------**********************-------------------------------------------------------------------------------------------------|| \n");
                    printf("||----------------------------------------------------------------------------------------****SEE YOU NEXT TIME %s ! ****----------------------------------------------------------------------------------------|| \n",tabpseudo[indice]);
                    printf("||----------------------------------------------------------------------------------------**********************-------------------------------------------------------------------------------------------------|| \n");
                    printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");

                    exit(0);
                }

            }
            system("cls");




        }
    }

}



/************************************************************************/
int main ()
{
    int x=3;
    //presentation
    Color(1,15);

    printf("\n\n\n\n\n\n\n\n\n\n");

    printf(" \t\t\t\t\t\t\t\t\t\t*||--------------------------------------------------------||*\n");
    printf( "\t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
    printf(" \t\t\t\t\t\t\t\t\t\t*||  MADE BY             :                                 ||*\n");
    printf(" \t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
    printf(" \t\t\t\t\t\t\t\t\t\t*||           JENDOUBI BOSHRA && SALHI NASSIM              ||*\n");
    printf(" \t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
    printf(" \t\t\t\t\t\t\t\t\t\t*||             HIGHER INSTITUT OF MANAGMENT               ||*\n");
    printf(" \t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
    printf(" \t\t\t\t\t\t\t\t\t\t*||                     2020-2021                          ||*\n");
    printf(" \t\t\t\t\t\t\t\t\t\t*||--------------------------------------------------------||*\n");

    Sleep(5);
    system("cls");

       do
    {
        Color(1,15);
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("||                                                                                           WELCOME                                                                                                             ||  \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("||                                                                                          -1-PENDU                                                                                                             || \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("||                                                                                          -2-MOTUS                                                                                                             ||  \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("                                                                                            -3-EXIT                                                                                                              || \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("||---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
        printf("                                                                                        ENTER YOUR OPTION : ");

        do
        {

            scanf("%i",&x);


        }
        while ((x<1) || (x>3) );




        switch(x)
        {
        case 1 :
        {
            fflush(stdin);
            system("cls");
            pendu();
        }
        break;

        case 2 :
        {
            fflush(stdin);
            system("cls");
            motus();
        }
        break;
            }
   } while(x!=3);
       if (x==3)

        {
        fflush(stdin);
        system("cls");
        Color(1,15);
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("\n");
        printf("  \t\t\t\t\t\t\t\t\t\t*||--------------------------------------------------------||*\n");
        printf( " \t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
        printf("  \t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
        printf("  \t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
        printf("  \t\t\t\t\t\t\t\t\t\t*||                     G O O D B Y E                      ||*\n");
        printf("  \t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
        printf("  \t\t\t\t\t\t\t\t\t\t*||                   THANKS FOR PLAYING                   ||*\n");
        printf("  \t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
        printf("  \t\t\t\t\t\t\t\t\t\t*||                                                        ||*\n");
        printf("  \t\t\t\t\t\t\t\t\t\t*||--------------------------------------------------------||*\n");
        Sleep(3);
        exit(0);
    }





    return 0;
}
