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

./build/Jour2/Job01_10/main

# 5. Quitter le conteneur quand tu as fini

exit

# 6. (Optionnel) Tout arrêter

docker compose down

```

```
