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

```bash
# 1. Démarrer ton environnement
docker compose up -d

# 2. Entrer dans le conteneur
docker compose exec dev bash

# 3. Compiler ton programme
cmake -S . -B build && cmake --build build

# 4. Lancer ton exécutable
./build/Jour1/Job9/Job9_epreuveHero

# 5. Quitter le conteneur quand tu as fini
exit

# 6. (Optionnel) Tout arrêter
docker compose down

```