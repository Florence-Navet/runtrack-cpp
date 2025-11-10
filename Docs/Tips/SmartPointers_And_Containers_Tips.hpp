/**
 * ===============================================================
 * 🧠 Fichier pédagogique : SmartPointers_And_Containers_Tips.hpp
 * Auteur : Florence
 * Projet : Colonie de Pingouins 🐧
 * ===============================================================
 * 
 * Ce fichier résume les concepts utilisés dans ton projet :
 * - Pointeurs intelligents (smart pointers)
 * - Conteneurs STL (map, set, unordered_map, etc.)
 * - Cas d’usage spécifiques à ta simulation
 * 
 * Il sert de référence et peut être inclus dans ton projet
 * uniquement à titre documentaire.
 */

#ifndef SMARTPOINTERS_AND_CONTAINERS_TIPS_HPP
#define SMARTPOINTERS_AND_CONTAINERS_TIPS_HPP

/*
===============================================================
🎯 1. LES POINTEURS INTELLIGENTS (SMART POINTERS)
===============================================================

→ Objectif : gérer la mémoire automatiquement, sans “delete”.

🔹 unique_ptr<T>
    - Possède un seul propriétaire.
    - Non copiable (seulement déplaçable).
    - Détruit automatiquement l’objet quand il sort du scope.
    ➤ Utilisation : ressource unique (fichier, connexion, etc.)

🔹 shared_ptr<T>
    - Pointeur partagé entre plusieurs propriétaires.
    - Compte de références interne (ref count).
    - L’objet est détruit quand plus aucun shared_ptr ne le référence.
    ➤ Utilisation : un Pingouin appartient à la colonie,
                    mais peut aussi être référencé ailleurs.

🔹 weak_ptr<T>
    - Référence "faible" vers un shared_ptr.
    - Ne prolonge PAS la durée de vie de l’objet.
    - Permet de vérifier si l’objet existe encore (expired()).
    - Nécessite .lock() pour être utilisé.
    ➤ Utilisation : amitiés entre pingouins (évite les cycles mémoire).

---------------------------------------------------------------
🧊 Exemple dans ton projet :
---------------------------------------------------------------
vector<weak_ptr<Pingouin>> colonie;         // Liste globale des pingouins
set<weak_ptr<Pingouin>> amis;               // Réseau d’amis sans doublon
shared_ptr<Pingouin> p = make_shared<Pingouin>("Pingu", 2.5, 1.8, 3.0);
---------------------------------------------------------------
*/


/*
===============================================================
📚 2. LES CONTENEURS STL
===============================================================

Les conteneurs sont des structures génériques de la STL (Standard Template Library)
qui servent à stocker, trier, et manipuler efficacement des collections de données.

Chaque conteneur a son usage optimal.

---------------------------------------------------------------
|  Type               | Ordonné | Doublons | Clé → Valeur | Exemple projet |
|---------------------|----------|-----------|---------------|----------------|
| vector<T>           | ❌       | ✅        | ❌            | Liste colonie  |
| set<T>              | ✅       | ❌        | ❌            | Liste d’amis   |
| multiset<T>         | ✅       | ✅        | ❌            | Temps courses  |
| map<K,V>            | ✅       | ❌        | ✅            | Compétences    |
| unordered_map<K,V>  | ❌       | ❌        | ✅            | Journal / pêche|
| unordered_set<T>    | ❌       | ❌        | ❌            | Lieux bouffe   |
---------------------------------------------------------------

📍 vector<T>
    - Tableau dynamique indexé.
    - Accès rapide par indice.
    - Doublons autorisés.
    ➤ Utilisation : la colonie de pingouins.

📍 set<T>
    - Ensemble trié, sans doublon.
    ➤ Utilisation : liste d’amis d’un pingouin.

📍 multiset<T>
    - Ensemble trié, avec doublons autorisés.
    ➤ Utilisation : plusieurs temps de compétition.

📍 map<K,V>
    - Dictionnaire trié (clé unique → valeur).
    ➤ Utilisation : compétences ("plongée" → 5).

📍 unordered_map<K,V>
    - Dictionnaire non trié, accès rapide par hash.
    ➤ Utilisation : journal, association meetup ↔ pêche.

📍 unordered_set<T>
    - Ensemble non trié, sans doublon.
    ➤ Utilisation : lieux de nourriture découverts.

---------------------------------------------------------------
🧊 Exemples concrets :
---------------------------------------------------------------

map<string, int> competences;
// "plongée" → 5, "pêche" → 8

unordered_map<string, string> journal;
// "2025-11-03" → "Première glissade réussie"

multiset<double> tempsCompetitions;
// {10.5, 11.3, 10.5, 12.1}

unordered_set<string> emplacementsNourriture;
// {"océan", "banquise", "glacier"}
---------------------------------------------------------------
*/


/*
===============================================================
🧭 3. CHOISIR LE BON OUTIL
===============================================================

| Besoin                                    | Choix idéal | Pourquoi |
|-------------------------------------------|-------------|----------|
| Une liste globale de pingouins            | vector<weak_ptr<Pingouin>> | Gestion mémoire simple, sans cycles |
| Relations d’amitié                        | set<weak_ptr<Pingouin>>    | Pas de doublon entre amis |
| Compétences du pingouin                   | map<string,int>            | Triées, affichage propre |
| Journal d’événements                      | unordered_map<string,string>| Accès rapide par date |
| Lieux de nourriture                       | unordered_set<string>      | Unique, accès rapide |
| Lieux de pêche associés aux meetups       | unordered_map<string,string>| Recherche rapide clé ↔ valeur |
| Historique de performances (temps courses)| multiset<double>           | Trié + doublons autorisés |

---------------------------------------------------------------
💡 Règle d’or :
---------------------------------------------------------------
👉 “Ordonné” (map, set) = lisible, trié, mais un peu plus lent.  
👉 “Unordered” = ultra rapide, mais désordonné.

---------------------------------------------------------------
🔥 Exemple de combinaison parfaite :
---------------------------------------------------------------
- Colonies : vector<weak_ptr<Pingouin>>
- Amis : set<weak_ptr<Pingouin>>
- Compétences : map<string,int>
- Journal : unordered_map<string,string>
- Lieux de pêche : unordered_map<string,string>
- Temps de compétition : multiset<double>
- Nourriture : unordered_set<string>
---------------------------------------------------------------
*/


/*
===============================================================
🧩 4. BONNES PRATIQUES
===============================================================

✅ Utiliser make_shared<T>() au lieu de new
✅ Vérifier weak_ptr avec .expired() avant de l’utiliser
✅ Parcourir un unordered_map avec iterateurs pour performance
✅ Préférer unordered_map aux map si l’ordre n’a aucune importance
✅ Ne jamais stocker directement des shared_ptr croisés (risque de fuite)

---------------------------------------------------------------
⚠️ Exemple d’erreur évitée :
---------------------------------------------------------------
shared_ptr<Pingouin> A, B;
A->ami = B;
B->ami = A;    // ❌ fuite mémoire circulaire
➡️ Solution : utiliser weak_ptr pour les amis
---------------------------------------------------------------
*/

#endif // SMARTPOINTERS_AND_CONTAINERS_TIPS_HPP
