#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genererNombre(int maximum) // Fonction qui genere un nombre aleatoire entre 1 et maximum (parametre envoye a la fonction) et qui retourne le nombre genere
{
    return (rand()%(maximum-1+1))+1;
}

int main()
{
    srand(time(NULL)); // Initialisation de la fonction rand
    int continuer=1;
    printf("                 =============================================\n                 = BIENVENUE DANS LE JEU DU PLUS OU DU MOINS =\n                 =============================================\n\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("Regle du jeu :\nVous devez trouver un nombre dans un interval donne.\nPour vous aider l'ordinateur vous dira si le nombre que vous avez saisit\nest plus grand ou plus petit que le nombre mystere\n");
    printf("--------------------------------------------------------------------------------\n\n");

    while (continuer) // Tant que l'utilisateur veut jouer on reste dans cette boucle
    {
        // Definition des variables
        int limite=0;
        int choix=0;
        int compteur=0;
        int nombre_aleatoire=0;
        int nombre_utilisateur=0;
        int rejouer=0;

        while (choix<1 || choix>4) // Tant que l'utilisateur n'a pas saisit une option valable du menu on reste dans cette boucle qui affiche le choix des difficultes
        {
            printf("\nAvec quelle difficulte voulez-vous jouer ?\n\n1 : entre 1 et 100\n2 : entre 1 et 1000\n3 : entre 1 et 10000\n4 : entre 1 et XXX (vous choisissez)\nVotre choix : ");
            scanf("%d",&choix);
            switch(choix)
            {
                case 1:
                    nombre_aleatoire=genererNombre(100); // On fait appel a la fonction genererNombre defini plus haut en passant 100 comme parametre
                    limite=100;
                    break;
                case 2:
                    nombre_aleatoire=genererNombre(1000); // On fait appel a la fonction genererNombre defini plus haut en passant 1000 comme parametre
                    limite=1000;
                    break;
                case 3:
                    nombre_aleatoire=genererNombre(10000); // On fait appel a la fonction genererNombre defini plus haut en passant 10000 comme parametre
                    limite=10000;
                    break;
                case 4:
                    printf("Entrer votre limite maximum : ");
                    scanf("%d",&limite);
                    nombre_aleatoire=genererNombre(limite); // On fait appel a la fonction genererNombre defini plus haut en passant la limite choisit par l'utilisateur comme parametre
                    break;
            }
        }

        while (nombre_aleatoire!=nombre_utilisateur) // Tant que le nombre que saisit l'utilisateur est different du nombre genere aleatoirement on reste dans cette boucle
        {
            printf("\nQuel est le nombre ? : ");
            scanf("%d",&nombre_utilisateur);
            if (nombre_utilisateur<1 || nombre_utilisateur>limite) // Si le nombre saisit par l'utilisateur est en dehors de la plage on le signale a l'utilisateur
            {
                printf("Vous devez saisir un nombre entre 1 et %d\n",limite);
            }
            else // Sinon on test le nombre saisit par l'utilisateur, on lui donne une indication "trop grand" ou "trop petit" et on incremente le compteur
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
        // Si l'utilisateur trouve le nombre genere aleatoirement on lui rappel le nombre a trouver et le nombre de tentatives qu'il a fait pour le trouver
        printf("Bravo vous avez trouve le nombre mystere qui est : %d\n",nombre_aleatoire);
        printf("Vous avez trouve le nombre mystere en %d coups\n",compteur+1);

        while (rejouer<1 || rejouer>2) // Tant que l'utilisateur n'a pas saisit une option valable on reste dans cette boucle qui demande a l'utilisateur s'il veut rejouer
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
    printf("\nMerci d'avoir joue avec nous. Au revoir.\n");
    //system("pause"); // Si vous etes sous windows, enlevez les "//" avant system("pause"). ca evitera que la fenetre se ferme toute seule a la fin du programme
    return 0;
}
