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
