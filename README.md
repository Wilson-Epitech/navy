<div align="center">

# Navy

**Une bataille navale entre deux terminaux qui communiquent par signaux Unix.**

<img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> <img alt="Make" src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=gnu&logoColor=white"/> <img alt="Unix" src="https://img.shields.io/badge/Unix-333333?style=for-the-badge&logo=linux&logoColor=white"/>

<sub>Projet à 2 · 2023</sub>

</div>

<br/>

<p align="center"><img src=".github/assets/term-navy.png" alt="Navy" width="820"/></p>

## En deux mots

Deux joueurs lancent le programme dans deux terminaux. Ils n'ont pas de socket : tout passe par **`SIGUSR1` et `SIGUSR2`**. Le second joueur se connecte au premier avec son PID, puis chacun voit sa flotte et la grille adverse.

## Ce que ça fait

- Connexion entre deux processus avec `kill` et `sigaction`
- Lecture et validation du fichier de positions des bateaux
- Affichage des deux grilles
- La phase d'attaque n'est pas terminée

## Sous le capot

Le premier joueur affiche son PID et attend un signal. Le second envoie `SIGUSR1` à ce PID, et le premier récupère l'expéditeur via `siginfo_t` : les deux processus se connaissent, sans aucun socket.

## Lancer le projet

```bash
make
./navy maps/pos1                  # joueur 1, affiche son PID
./navy <PID_joueur_1> maps/pos2   # joueur 2
```

## L'équipe

<a href="https://github.com/Wilson-Epitech/navy/graphs/contributors"><img src="https://contrib.rocks/image?repo=Wilson-Epitech/navy" alt="Contributeurs"/></a>

Yanis Harkouk, Wilson Bordichon

**Ma part :** J'ai écrit la lecture et la vérification du fichier de positions, la **connexion entre les deux terminaux** et l'affichage des grilles.
