# runtrack-cpp

Runtrack focused on C++

Faire la commande pour executer le mingw configuré dans le json

```json
cmake --preset mingw
```

## Builder

```bash
cmake --build --preset mingw-build

```

### Lancer l'executable

```bash
./build/nomFichier.exe
```

### pb de jeu de caractere UTF-8

taper :

```bash
chcp.com 65001
```

```bash
docker compose exec dev bash -c "cmake -S . -B build && cmake --build build && ./build/Job1_hello_world"
```

````bash
# 1. Démarrer ton environnement
docker compose up -d

# 2. Entrer dans le conteneur
docker compose exec dev bash

# 3. Compiler ton programme dans le dossier /app de mon conteneur
cmake -S . -B build && cmake --build build
# cmake -S . -B build -f '/app/CMakeLists.txt' && cmake --build build

```bash
cmake --build build --clean-first

````

# 4. Lancer ton exécutable

./build/Jour2/Job01_12/main

# 5. Quitter le conteneur quand tu as fini

exit

# 6. (Optionnel) Tout arrêter

docker compose down

```

```

---

# Smart Pointers & Containers — Résumé Simplifié

## 1. shared_ptr - Le Protecteur de mémoire 👥

- garde le **controle de la memoire**
- tant qu'il existe une **ref active**, il est **vivant**
- si pers le connait -> **supprimé automatiquement**

qd ? **plusieurs parties du programme** partagent le **même objet** et que tu souhaites
que la **memoire** soit géree **automatiquement**.

## 2. weak_ptr - souvenir fragile 👻

- **n'empêche** pas la destruction objet
- avec.lock() : sert à savoir **si l'obj existe toujours**
- pas de pingouin "fantome"(ref morte)

qd ? qd on veut **referencer un obj ss le posséder**( amitiés, relations
temporaires, cache memoire)

## 3. map : cahier d'école 📖

- range par **ordre alphabétique** les clés
- peux chercher **rapidement** une données précise

qd ? association **nom** <-> **valeurs** avec ordre ou tri qui compte

## 4. unordered_map - cahier desordonné ⚡

idem 3 mais **sans trié**

qd ? table hashage / rapide pour chercher / pas d'ordre

## 5. set : boites souvenirs 🪶

- collection d'élements **uniques et triés**
- **Aucun doublon** possible

qd ? quand on veut **eviter les doublons** et qu'on veut un **tri automatique**

## 6. multiset - boite à scores 🏁

commet le set mais **accepte les doublons** et aussi avec un **tri**

qd ? on peut stocker **plusieurs valeurs identiques** mais **triés** (scores, notes, temps,... )

## 7. unordered_set - tel un sac sans ordre 🎒

- Collection sans ordre mais sans doublons
- Rapide pour vérifier si un élément **existe ou pas**

qd ? pour tester **existence d'un élement rapidement** sans se soucier de l'ordre.
