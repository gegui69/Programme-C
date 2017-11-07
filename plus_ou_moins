#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genererNombre(int maximum)
{
    return (rand()%(maximum-1+1))+1;
}

int main()
{
    srand(time(NULL));
    int continuer=1;
    printf("BIENVENUE DANS LE JEU DU PLUS OU DU MOINS\n\n");
    while (continuer)
    {
        int limite=0;
        int plage=0;
        int choix=0;
        int compteur=0;
        int nombre_aleatoire=0;
        int nombre_utilisateur=0;
        while (choix<1 || choix>4)
        {
            printf("Avec quelle difficulte voulez-vous jouer ?\n1 : entre 1 et 100\n2 : entre 1 et 1000\n3 : entre 1 et 10000\n4 : entre 1 et XXX (vous choisissez)\nVotre choix : ");
            scanf("%d",&choix);
            switch(choix)
            {
                case 1:
                    nombre_aleatoire=genererNombre(100);
                    limite=100;
                    break;
                case 2:
                    nombre_aleatoire=genererNombre(1000);
                    limite=1000;
                    break;
                case 3:
                    nombre_aleatoire=genererNombre(10000);
                    limite=10000;
                    break;
                case 4:
                    printf("Entrer votre limite maximum : ");
                    scanf("%d",&plage);
                    nombre_aleatoire=genererNombre(plage);
                    limite=plage;
                    break;
            }
        }
        while (nombre_aleatoire!=nombre_utilisateur)
        {
            printf("\nQuel est le nombre ? : ");
            scanf("%d",&nombre_utilisateur);
            if (nombre_utilisateur<1 || nombre_utilisateur>limite)
            {
                printf("Vous devez saisir un nombre entre 1 et %d\n",limite);
            }
            else
            {
                if (nombre_utilisateur<nombre_aleatoire)
                {
                    printf("Trop petit\n");
                    compteur++;
                }
                else if (nombre_utilisateur>nombre_aleatoire)
                {
                    printf("Trop grand\n");
                    compteur++;
                }
            }
        }
        printf("\nBravo vous avez trouve le nombre mystere qui est : %d\n",nombre_aleatoire);
        printf("Vous avez trouve le nombre mystere en %d coups\n",compteur+1);
        int rejouer=0;
        while (rejouer<1 || rejouer>2)
        {
            printf("\nVoulez-vous rejouer ?\n1 : oui\n2 : non\nVotre choix : ");
            scanf("%d",&rejouer);
            switch (rejouer)
            {
                case 1:
                    printf("\n");
                    break;
                case 2:
                    continuer=0;
                    break;
            }
        }
    }
    printf("\nMerci d'avoir joue avec nous. Au revoir\n");
    return 0;
}
