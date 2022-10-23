/*Créer un projet Console sous Visual Studio 2017 ou 2019 qui fera tourner un petit jeu de simulation simple de bataille entre deux unités (chevalier contre orc).
Vous êtes libre d'utiliser des librairies externes de votre choix si vous estimez en avoir besoin, à condition que le projet que vous allez fournir à la fin puisse
se lancer sans avoir besoin d'installer un autre logiciel.
Vous devez nous rendre un fichier zip contenant un repo git local. Celui-ci devra contenir sur la branche master la solution Visual que nous aurons juste
à compiler et lancer pour tester votre programme.
Voici une description des règles à respecter. Si certaines règles ne vous semblent pas claires ou qu'il manque de précisions, vous êtes libre de faire des choix
à condition de nous les préciser dans votre mail de retour.
 
Caractéristiques du chevalier :
- Il dispose de 20 points de vie et d'un bouclier de 50 points.
- Il dispose d'une épée lui permettant de faire 5 points de dégâts par tour.
- Il dispose d'une capacité "charge" lui permettant de faire le double de dégâts ce tour-ci. Cette capacité ne peut être utilisée que tous les 3 tours de jeu.
Elle a 60% de chance de réussir. Si elle ne réussit pas, il faudra attendre les 3 tours mentionnés ci-dessus pour la tenter de nouveau.
- Les dégâts pris par le chevalier sont d'abord infligés au bouclier et lorsque le bouclier n'a plus de points, l'unité perd des points de vie.
 
Caractéristiques de l'orc
- L'orc dispose de 60 points de vie mais n'a pas de bouclier.
- Il dispose d'une hache lui permettant de faire 8 points de dégâts par tour.
- Il dispose d'une capacité "stun" lui permettant d'étourdir l'ennemi pendant un tour. Un ennemi étourdi ne pourra pas faire de dégât ce tour-ci.
Cette capacité ne peut être utilisée que tous les 5 tours de jeu. Elle a 20% de chance de réussir.
Si elle ne réussit pas, il faudra attendre les 5 tours mentionnés ci-dessus pour la tenter de nouveau.
 
Voici le déroulement de la partie :
- Un tour de jeu est constitué de 2 éléments successifs : lancement de capacités spéciales, puis combat entre les unités.
- Il y a autant de tour de jeu que nécessaire pour que l'un des côtés gagne la partie.
- Un côté gagne la partie quand l'unité adverse a été tuée.
- Pour le combat entre 2 unités, chaque unité inflige directement les dégâts à l'unité ennemie (en prenant en compte les éventuels effets des capacités).
 
Contraintes supplémentaires :
- Afin de vérifier que votre programme fonctionne normalement, il serait appréciable de pouvoir suivre l'évolution de la partie en affichant notamment les informations
de chaque unité à chaque tour de jeu.
- Il faut que le programme soit correctement architecturé pour qu'il soit facile d'ajouter de nouvelles classes et/ou de nouvelles caractéristiques.
 
Bonus :
- Pour rendre le jeu plus "dynamique", il pourrait être sympa de pouvoir faire des choix avant le lancement de la partie/pendant la partie. Vous êtes libre de faire une/des
propositions et de les implémenter.*/


#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "head.h"

int main()
{
    std::cout<<"Yes bébé allez ça marche"<<std::endl;
    Combat o_Combat;
    o_Combat.Combattre();
    return 0;
}