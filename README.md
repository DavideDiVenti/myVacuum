# myVacuum
La conception d'un projet s'est déroulé dans le cadre d'un cours de bureaux d'études. Le projet en question est un aspirateur digital. 
Le rendu 3D du projet peut être directement visionné en cliquant sur [ce lien hypertexte](https://a360.co/3LSl4pl) (ouvrez ensuite *depuis le navigateur*).

## Introduction
Le projet en question consiste en un aspirateur doté de fonctionnalités numériques supplémentaires. Comme tout aspirateur domestique, il a pour fonction principale d'aspirer les miettes, la poussière, le sable, etc. Toutefois, contrairement à ses homologues, myVacuum est capable de fournir à son utilisateur un état de santé en temps réel grâce à un écran. Cet état inclut des informations telles que la température interne de l'appareil, le niveau de remplissage du réservoir, la qualité de l'air aspiré, la vitesse du ventilateur, et bien d'autres encore.

L'utilisateur peut contrôler l'aspirateur à partir d'une interface utilisateur. Cette dernière prend la forme d'une télécommande filaire équipée d'un petit écran et de 4 boutons poussoirs. L'interface comprend plusieurs menus préprogrammés, notamment une zone permettant de visualiser et de commander l'état de l'appareil (puissance d'aspiration), ainsi qu'une autre zone permettant d'acquérir des données et de créer des graphiques des données lues par les capteurs en temps réel. 

## Le répertoire [*myVacuumCode*](https://github.com/DavideDiVenti/myVacuum/tree/main/myVacuumCode)
L'aspirateur intègre le microcontrôleur ESP32. Les codes téléversés sont dans le répertoire [myVacuumCode](https://github.com/DavideDiVenti/myVacuum/tree/main/myVacuumCode). Ce-dernier assemble tous les périphériques de l'aspirateur (voir [Rapport]()) afin de centraliser le tout.

## Le répertoire [*Documents*](https://github.com/DavideDiVenti/myVacuum/tree/main/Documents)
Divers documents sont situés dans ce répertoire. Des informations supplémentaires s'y trouvent :
* Un dossier [Impressions_3D](https://github.com/DavideDiVenti/myVacuum/tree/main/Documents/Impressions_3D) contenant l'entièreté des fichiers d'impression au format stl. 
* Un dossier [Images](https://github.com/DavideDiVenti/myVacuum/tree/main/Documents/Images) contenant quelques aperçuts finaux du projet (PCB, Mécanique, Schémas, ...)
* Un fichier [Rapport]() correspondant au rapport du projet sous le format pdf. Dedans se trouve l'entièreté du contenu (schémas, développements techniques, ...) ainsi qu'un tableau des pinouts de l'ESP32.

## Youtube
Il est toujours plus ludique d'observer le projet sous forme de vidéos :

### Démonstration du projet :
Dans cette vidéo, l'aspirateur aspire plusieurs type de déchets (copeaux d'aluminium, terre, copeaux de bois, ...).
