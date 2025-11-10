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

🧠 TABLEAU RÉCAPITULATIF DES STRUCTURES ET SMART POINTERS
| Type / Concept | Rôle principal | Quand l’utiliser | Caractéristiques clés | Exemple dans ton code |
| ----------------------------- | ----------------------------------------------------------- | ------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| 🧩 `shared_ptr<T>` | Pointeur intelligent **partagé** (référence comptée) | Quand **plusieurs objets** doivent partager la même instance | - Compte automatiquement le nombre de références <br>- Détruit l’objet quand plus personne ne le référence <br>- Permet de partager un pingouin dans plusieurs listes ou groupes | `shared_ptr<Pingouin> pingu = make_shared<Pingouin>("Pingu", ...);`<br>→ utilisé pour créer et gérer tes pingouins dans la colonie |
| 🕸️ `weak_ptr<T>` | Pointeur **faible** (non propriétaire) vers un `shared_ptr` | Quand tu veux **référencer un objet sans prolonger sa durée de vie** | - Ne modifie pas le compteur de référence <br>- Devient automatiquement invalide (`expired()`) si l’objet meurt <br>- Nécessite `.lock()` pour l’utiliser | `weak_ptr<Pingouin>` dans la `colonie` ou le `set` d’amis → évite les **références circulaires** entre amis pingouins |
| 📚 `set<T>` | Ensemble **ordonné** d’éléments **uniques** | Quand tu veux **éviter les doublons** et garder un **ordre automatique** | - Pas de doublon <br>- Trié automatiquement (croissant par défaut) <br>- Accès rapide (arbre binaire) | `set<weak_ptr<Pingouin>> amis;` <br>→ stocke les amis sans doublon et dans un ordre déterministe |
| 🪶 `multiset<T>` | Ensemble **ordonné** qui autorise les **doublons** | Quand plusieurs valeurs identiques peuvent coexister | - Trié automatiquement <br>- Autorise plusieurs mêmes valeurs | `multiset<double> tempsCompetitions;` <br>→ plusieurs temps pour une même course |
| 🗺️ `map<Key, Value>` | Dictionnaire **ordonné** (clé → valeur) | Quand tu veux une **relation unique** clé → valeur triée par clé | - Pas de doublon de clé <br>- Clés triées automatiquement <br>- Accès rapide en O(log n) | `map<string,int> competences;` <br>→ chaque compétence unique avec son niveau |
| ⚡ `unordered_map<Key, Value>` | Dictionnaire **non ordonné** (basé sur des hash) | Quand l’ordre importe peu mais tu veux un **accès ultra rapide** | - Pas trié <br>- Accès moyen en O(1) <br>- Très efficace pour les recherches | `unordered_map<string,string> journal;` ou `lieuxDePecheAssocies;` <br>→ accès direct aux données via la clé |
| 🧃 `unordered_set<T>` | Ensemble **non ordonné** de valeurs uniques | Quand tu veux juste **savoir si un élément existe**, sans ordre | - Pas trié <br>- Pas de doublon <br>- Accès rapide via hash | `unordered_set<string> emplacementsNourriture;` <br>→ stocke les lieux de bouffe découverts sans doublon |

🎯 EN RÉSUMÉ VISUEL (mnémonique rapide)

| Catégorie       | Ordonné ? | Doublons ?      | Clé → Valeur ? | Exemple concret            |
| --------------- | --------- | --------------- | -------------- | -------------------------- |
| `set`           | ✅ Oui    | ❌ Non          | ❌ Non         | Amis (uniques)             |
| `multiset`      | ✅ Oui    | ✅ Oui          | ❌ Non         | Temps de courses multiples |
| `map`           | ✅ Oui    | ❌ (clé unique) | ✅ Oui         | Compétences                |
| `unordered_map` | ❌ Non    | ❌ (clé unique) | ✅ Oui         | Journal, Lieux de pêche    |
| `unordered_set` | ❌ Non    | ❌ Non          | ❌ Non         | Emplacements de nourriture |

🧭 Et côté pointeurs

| Type         | Propriétaire ?   | Compte de référence ? | Peut devenir nul ?   | Exemple typique                                            |
| ------------ | ---------------- | --------------------- | -------------------- | ---------------------------------------------------------- |
| `unique_ptr` | ✅ Oui           | ❌ Non                | ✅ Oui               | Quand un seul objet détient la ressource (pas utilisé ici) |
| `shared_ptr` | ✅ Oui (partagé) | ✅ Oui                | ✅ Oui               | Gérer un pingouin dans plusieurs listes                    |
| `weak_ptr`   | ❌ Non           | ❌ Non                | ✅ Oui (`expired()`) | Amis entre pingouins sans fuite mémoire                    |

💡 Conseils d’usage

| Besoin                                       | Structure idéale               | Pourquoi                                                                    |
| -------------------------------------------- | ------------------------------ | --------------------------------------------------------------------------- |
| Une colonie avec gestion mémoire automatique | `vector<weak_ptr<Pingouin>>`   | Évite les cycles `shared_ptr` (les pingouins ne se possèdent pas entre eux) |
| Des relations d’amitié                       | `set<weak_ptr<Pingouin>>`      | Évite doublons + évite prolonger la vie des amis                            |
| Journal personnel                            | `unordered_map<string,string>` | Accès rapide par date (clé = date)                                          |
| Compétences                                  | `map<string,int>`              | Clés triées → affichage propre et lisible                                   |
| Temps de compétition                         | `multiset<double>`             | Autorise plusieurs temps, automatiquement triés                             |
| Lieux de bouffe                              | `unordered_set<string>`        | Pas de doublon, accès rapide                                                |
| Lieux de pêche associés aux meetups          | `unordered_map<string,string>` | Association rapide clé → valeur                                             |
