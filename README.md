# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin verrs data>`

# Alex Boyajian
DA: 202498372

## Les fonctionnalités que j'ai choisi d’implémenter

1- Détection des doublons plus intelligente (même titre, auteur, ISBN).

2- Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).

## Questions

### Question 1: C++

``` cpp
void FileManager::sauvegarderLeFichierJournal(const string& evenement, const string& description) {
    filesystem::path cheminJournal = filesystem::path(booksFileName).parent_path() / "journal.txt";

    ofstream file(cheminJournal, ios::app);

    if (file.is_open()) {
        time_t tempsActuel   = time(nullptr);
        tm* dateEtTemps = localtime(&tempsActuel);

        file << put_time(dateEtTemps, "%Y-%m-%d %H:%M:%S") << " - [" << evenement << "] "  << description << "\n";
    } else {
        cout << "Erreur, Il n'est pas possible d'écrire dans le fichier journal : " << cheminJournal << "\n";
    }
}
```

### Explications

Une notion qu'on n'a pas encore vue en classe est la journalisation.
Elle consiste à faire un log pour chacune de nos actions.

- `parent_path()` : permet de récupérer le répertoire parent du fichier des livres
- `ofstream file(...)` : permet d'écrire dans le fichier de journalisation
- `ios::app` : permet d'ajouter les nouvelles informations à la fin du fichier sans écraser les données déjà écrites dans le fichier `journal.txt`
- `if (file.is_open())` : permet de vérifier si le fichier a été ouvert
- `time_t` : représente le temps utilisé par le programme pour obtenir la date et l'heure actuelles
- `time(nullptr)` : permet de récupérer l'heure actuelle et le `nullptr` signifie qu'aucune adresse mémoire n'est fournie pour recevoir le résultat de la fonction
- `tm*` : c'est un pointeur qui contient l'adresse d'une structure avec les informations de la date et de l'heure
- `localtime(&tempsActuel)` : fonction qui convertit la valeur du temps en date et heure locales, puis retourne un pointeur vers une structure `tm`
- `put_time(...)` : fonction qui transforme les informations de date et d'heure en texte
- `"%Y-%m-%d %H:%M:%S"` : format de la date et de l'heure (année-mois-jour heure:minute:seconde)

### Exemple de sorties du code du projet

```text
2026-10-16 00:16:15 - [AJOUT LIVRE] test1|test1|111|1|
2026-10-16 00:16:35 - [SUPPRESSION LIVRE] Lettres persanes|Montesquieu|9782070381001|1|
```
## Question 2: Options de développement possible

Une solution plus adaptée pour la gestion de la bibliothèque d'Alexandrie est d'adopter MySQL.
On adopte cette solution, car si, dans le futur, la bibliothèque contient des millions de livres et plusieurs utilisateurs, il serait difficile de gérer toutes ces données localement avec notre programme C++. On va adopter ce changement puisqu'il permettra de stocker efficacement les informations de plusieurs livres et utilisateurs dans la base de données de la bibliothèque.

Pour interfacer ceci avec le C++, je vais utiliser un connecteur comme MySQL Connector/C++. Le programme va être capable de communiquer avec la bd.
Cela permettra de faire l'évolution de la bibliothèque d'Alexandrie en étant capable de stocker des millions de livres.

