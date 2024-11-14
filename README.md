
# TP INF224 Augustin CURINIER

Taper make run dans le répertoire cpp pour lancer le serveur puis make run dans le répertoire swing pour lancer la télécommande client java.

## Partie C++

### 4ème étape

La méthode play() qui permet de jouer un objet multimédia est abstraite (purement virtuelle). On la déclare avec le mot clé virtual puis "int=0".

La classe multimédia est devenue abstraite (purement virtuelle), on ne peut donc plus instancier cette classe.

### 5ème étape

C'est le polymorphisme d'héritage qui nous permet de faire cela. Dans le cas du C++ il faut créer un tableu de pointeurs multimédia* qui pointent vers des photos et des vidéos; afin de pouvoir traiter tous les éléments du tableau de la même manière. En Java, on pourrait faire un cast et faire une liste d'objets de la classe Multimédia (mais ce sont aussi des pointeurs).

### 7ème étape

La classe Film doit être modifiée car elle contient une allocation dynamique avec new; il faut penser à supprimer le tableau des durées des chapitres avec un delete dans le destructeur.

### 10ème étape 

On pourrait mettre le constructeur de la classe en privé par exemple.

## Java swing

### Etape 1

Lorsqu'on écrit trop de mots dans la zone de texte sans aller à la ligne, le texte disparaît et n'est plus afficher, il "sort".





