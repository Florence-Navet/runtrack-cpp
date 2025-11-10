#include "Pingouin.hpp"



//initialisation de ma colonie
vector<weak_ptr<Pingouin>> Pingouin::colonie;

//initialisation de ma liste statique de lieux
vector<string> Pingouin::lieuxRencontre = {"glacier", "banquise", "océan", "montagne du caillou blanc"};

//initialisation de ma variable bool
bool Pingouin::colonieNettoyee = false;

//initialisation de ma map de lieux de peches
unordered_map<string, string> Pingouin::lieuxDePecheAssocies;

// Constructeurs / destruteurs
Pingouin::Pingouin(string nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom),vitesseGlisse(vitesseGlisse) 
    {
      cout << nom << " vient de rejoindre la colonie." << endl;
    }


Pingouin::Pingouin(const Pingouin& autre)
    : Aquatique(autre.getVitesseNage()), 
    Terrestre(autre.getVitesseMarche()),
    nom(autre.nom + "_copie"),
    vitesseGlisse(autre.vitesseGlisse)
    {
      cout << "Copie du pingouin " << autre.nom << " → " << nom << endl;
    }

    //  Destructeur
Pingouin::~Pingouin() {
    cout << " Le pingouin " << nom << " a quitté la colonie." << endl;
    // nettoyerColonie();
    if (!colonieNettoyee) {
        nettoyerColonie();
        colonieNettoyee = true;
    }

   // =========================
// --METHODE POUR FORMER LA COLONIE--
// =========================

    // Nettoyer les références 
    colonie.erase(
        remove_if(colonie.begin(), colonie.end(),
                  [](weak_ptr<Pingouin> &wp) { return wp.expired(); }),
        colonie.end());
}


void Pingouin::ajouterAuGroupe(shared_ptr<Pingouin> nouveauPingouin) {
    colonie.push_back(nouveauPingouin); // ajout ici du nouveau pingouin
    
    //convertir weak_ptr en shared_ptr
    vector<shared_ptr<Pingouin>> pingouinsActifs;

    for (weak_ptr<Pingouin>&pingouinFaible : colonie)  {
        shared_ptr<Pingouin>pingouin = pingouinFaible.lock(); //transforme weak en shared
        if (pingouin) {
            pingouinsActifs.push_back(pingouin);
        }
    } 


    // Tri via la fonction comparerTemps - booleen 
    // pingouin plus rapide avec plus lent : return true si  a arrive avant b dans le
    // booleen
    sort(pingouinsActifs.begin(), pingouinsActifs.end(), Pingouin::comparerTemps);

    //reconstruction de la colonie
    colonie.clear(); //on vide la colonie


    //on remplit la colonie avec les pingouins triés en les convertissants en weak_ptr
    for (shared_ptr<Pingouin>&pingouin : pingouinsActifs) {
        colonie.push_back(pingouin);
    }

cout << "\n Le pingouin " << nouveauPingouin->getNom()
                << " a été ajouté et la colonie a été triée par temps de parcours." << endl;

 cout << "\nColonie triée par temps de parcours :\n";
    for (shared_ptr<Pingouin>& pingouin : pingouinsActifs) {
    
    cout << "• " << pingouin->getNom()
                  << " → " << pingouin->calculerTempsParcours() << " s" << endl;
    }

    
    
}

bool Pingouin::comparerTemps(const shared_ptr<Pingouin>& a, const shared_ptr<Pingouin>& b) {
    return a->calculerTempsParcours() < b->calculerTempsParcours();
}


void Pingouin::nettoyerColonie() {
    colonie.erase(
        remove_if(colonie.begin(), colonie.end(),
                  [](weak_ptr<Pingouin>& wp) { return wp.expired(); }),
        colonie.end());
}


void Pingouin::afficherColonie() {
    cout << "\nColonie actuelle :" << endl;
    for (weak_ptr<Pingouin> &pingouinFaible : colonie) {
        shared_ptr<Pingouin> pingouin = pingouinFaible.lock();
        if (pingouin) {  
            pingouin->sePresenter();
        }
    }
}



// =========================
// --METHODES LIES AUX LIEUX--
// =========================


void Pingouin::ajouterLieu(const string& lieu) {
    // check si le lieu n'est pas deja existant
    if (find(lieuxRencontre.begin(), lieuxRencontre.end(), lieu) == lieuxRencontre.end()) {
        lieuxRencontre.push_back(lieu);
        cout << " Nouveau lieu ajouté : " << lieu << endl;
    } else {
        cout << "Le lieu " << lieu << " existe déjà." <<endl;
    }
}

void Pingouin::retirerLieu(const string& lieu) {
    //creation d'un iterateur sur le vector <string>
    vector<std::string>::iterator it = std::remove(lieuxRencontre.begin(), lieuxRencontre.end(), lieu);

    if (it != lieuxRencontre.end()) {
        lieuxRencontre.erase(it, lieuxRencontre.end());
        cout << "Lieu retiré : "<< lieu << endl;
    } else  {

    cout << "Aucun lieu trouvé ne correspond à "<< lieu << " ." << endl;
}


}

void Pingouin::afficherLieux() {
    cout << "\n Lieux de rencontre de nos amis Pingouins :" << endl;
    for(string& lieu : lieuxRencontre) {
        cout <<  " - " << lieu << endl;
    }
}


// =========================
// --AUTRES METHODES--
// =========================



void Pingouin :: sePresenter() const {
    std::cout << "Je m'appelle " << getNom() << " !" << std::endl;
    std::cout << "Je marche à " << getVitesseMarche() << " m/s." << std::endl;
    std::cout << "Je nage à " << getVitesseNage() << " m/s." << std::endl;
    std::cout << "Je glisse à " << vitesseGlisse << " m/s." << std::endl;

}

double Pingouin::calculerTempsParcours() const {

    const double distanceGlisse = 15.0;
    const double distancePlat1 = 20.0;
    const double distanceNage = 50.0;
    const double distancePlat2 = 15.0;


    double tempsGlisse = distanceGlisse / vitesseGlisse;
    double tempsPlat = (distancePlat1 + distancePlat2) / getVitesseMarche();
    double tempsNage = distanceNage / getVitesseNage();

    double tempsTotal = tempsGlisse + tempsPlat + tempsNage;
    return tempsTotal;
}

//Methode affichant temps parcours pour les pingouins
void Pingouin::afficherTempsPourTous() {
    cout << "\n Temps de parcours pour chaque pingouin de la colonie : " << endl;

    for (weak_ptr<Pingouin> &pingouinFaible : colonie) {
        shared_ptr<Pingouin> pingouin = pingouinFaible.lock();

        if (pingouin) {
            double temps = pingouin ->calculerTempsParcours();
            cout << pingouin ->getVitesseMarche() << " m/s à la marche, "
            << pingouin ->getVitesseNage() << " m/s à la nage,"
            << "glisse à " << pingouin -> getVitesseGlisse() << " m/s -> ";
            cout << "temps total : " << temps << " secondes (" << pingouin->getNom() << ")" << endl;
        }
    }
}

// =========================
// --GESTION DES COMPETENCES--
// =========================


void Pingouin::ajouterCompetence(const string& nom, int niveau) {
    // Vérifie si la compétence existe déjà
    if (competences.find(nom) == competences.end()) {
        competences[nom] = niveau;
        cout << " [ "<<this ->nom <<" ] "<< "- Nouvelle compétence ajoutée : " << nom << " (niveau " << niveau << ")" << endl;
    } else {
        cout << " [ "<<this ->nom <<" ] "<< "- La compétence " << nom << " existe déjà. Utilisez modifierCompetence()." << endl;
    }
}

void Pingouin::modifierCompetence(const string&nom, int nouveauNiveau)
{
    map<string, int>::iterator it = competences.find(nom);
    if(it != competences.end()) {
        it->second = nouveauNiveau;
        cout << "Compétence " << nom << " mise à jour au niveau " << nouveauNiveau << endl;
                cout <<"vous avez levUp !!" << endl;
    } else {
        cout << "Aucune compétence particulière associée au nom. " << nom << endl;
    }
}
void Pingouin::supprimerCompetence(const string&nom)
{
        map<string, int>::iterator it = competences.find(nom);
        if (it != competences.end()) {
            competences.erase(it);
            cout << "Compétence " <<nom << " supprimée." <<endl;
        } else 
        {
            cout << " Impossible de supprimer : compétence " << nom  <<" introuvable ou inexistance" << endl;
        }
}

void Pingouin::afficherCompetences() 
{
    cout << "\nCompétences de " << nom << " : " << endl;
    if (competences.empty())
    {
    cout << "  Aucune compétence enregistrée. T'es pas bon !!! " << endl;

    } else 
    {
        for (map <string, int> ::const_iterator it = competences.begin(); it != competences.end(); ++it)
        {
            cout << " - " << it->first << " : niveau " << it->second << endl;
        }
    }
}

// =========================
// GESTION DES AMIS
// =========================


void Pingouin::ajouterAmis(std::shared_ptr<Pingouin>ami)
{
    if(!ami)
    {
        cout << "[" <<nom<< "] Erreur: Impossible d'ajouter un ami inexistant." <<endl;
    }

    //Empêcher qu'un pingouin s'ajoute lui-même en ami
    if (ami.get() == this)
    {
        cout << "[" << nom << "] ne peut pas être son propre ami ! \n Je sais c'est dur d'être seul." << endl;
    }

    // verifions si déjà ami
    for (const weak_ptr<Pingouin>& amiFaible : amis) 
    {
        std::shared_ptr<Pingouin> pingouin = amiFaible.lock();
        if(pingouin && pingouin == ami) 
        {
            cout << " [ " << nom << " ] est déjà ami avec [ " << ami->getNom() << " ] " <<endl;
            return;
        }
    }
    amis.insert(ami);
    cout << " [  " << nom << " ] est maintenant ami avec [ "<< ami->getNom()<< " ] " <<endl;

}

// retirer ami si on est faché hihi
void Pingouin::retirerAmis(shared_ptr<Pingouin>ami) 
{
    if (!ami) return;

    bool retirer = false;

    set<weak_ptr<Pingouin>, owner_less<weak_ptr<Pingouin>>> copieAmis = amis;

        for (const weak_ptr<Pingouin>& amiFaible : copieAmis) 
        {
            shared_ptr<Pingouin> pingouin = amiFaible.lock();

            if (!pingouin) 
            {
                amis.erase(amiFaible);
            } else if (pingouin == ami)
            {
                amis.erase(amiFaible);
                cout << "[" << this->nom << "] n'est plus ami avec [" << ami->getNom() << "] " << endl;
                retirer = false;
            }

        }

}


// afficher amis
void Pingouin::afficherAmis()
{
    cout << "\n[ " <<this->nom << " ] liste de ses amis : "<< endl;

    bool aDesPotes = false;
      cout << "Mes amis sont :" << endl;

    for (const weak_ptr<Pingouin>& amiFaible : amis)
    {
        shared_ptr<Pingouin> pingouin = amiFaible.lock();

        if(pingouin)
        {
            cout << " Le Pingouin : " << pingouin->getNom() <<endl;
            aDesPotes = true;
        }
    }
        if (!aDesPotes) {
        cout << " Sorry ! Il est temps d'être sociable. T'as pas d'amis." << endl;
        }
}

// =========================
// JOURNAL DE BORD DU PINGOUIN
// =========================
void Pingouin::ajouterDonneesJournal(const std::string&date, const std::string& description)
{
    if(journal.find(date) == journal.end())
    {
        journal[date] = description;
        cout << " [ " << this->nom << " ] Nouvelle entrés ajoutée au journal ( " << date << " ) : " << description << endl;

    } else {
                cout << " [ " << this->nom << " ] Entrée déjà existante pour la date   " << date << " . Utilisez modifierEntreeJournal()." <<endl;
    }
}

void Pingouin::modifierDonneesJournal(const std::string&date, const std::string& nouvelleDescription)
{
    std::unordered_map<std::string, std::string>::iterator it = journal.find(date);

    if (it != journal.end())
    {
        it ->second = nouvelleDescription;
        cout << " [ " <<this->nom << " ] Entrée du : " <<date << " - mise à jour : " <<nouvelleDescription << endl;
    } else
    {
        cout << " [ " << this->nom << "] Aucun journal trouvé pour la date du " << date << "."<<endl;
    }
    
}

void Pingouin::supprimerDonneesJournal(const std::string&date)
{


    if (journal.find(date) != journal.end())
    {
        journal.erase(date);
        std::cout << "[ " << nom << " ] Entrée du " << date << " supprimée du journal." << std::endl;
    }
    else
    {
        std::cout << "[ " << nom << " ] Aucun journal à supprimer pour la date " << date << "." << std::endl;
    }
}

void Pingouin::afficherJournal()
{
    std::cout << "\n Journal de bord de [ " << this->nom << " ] "<<std::endl;

    if(journal.empty())
    {
        std::cout << "Rien à signaler pour l'instant. On s'ennuie." <<std::endl;
        return;
    }
for (const pair<string, string>& entree : journal)
    {
        cout << " - " << entree.first << " : " << entree.second << endl;
    }
}

// ===============
// JO  DES PINGOUINS
// ===============

void Pingouin::ajouterTempsCompétition(double temps)
{
    if (temps < 0) 
    {
        cout << " [  " << this->nom << " ] Temps non validé : " << temps << " secondes." << endl; 
    } else
    {
        tempsCompetitions.insert(temps);
        cout << " [  " << this->nom << " ] a terminé la compétition en " << temps << " secondes !" << endl;
    }
    
}

void Pingouin::afficherTempsCompetition()
{
    cout << "\nTemps de compétition de [ " << nom << " ] : " << endl;

    if(tempsCompetitions.empty())
    {
        cout << "Aucun temps enregistré. Ce pingouin n'a pas encore concouru !!" <<endl;
    }

    int rang = 1;
     for (const double&temps : tempsCompetitions)
     {
        cout << " " << rang << " performance " << temps<< " secondes" << endl;
        rang++;
     }
     cout << "Meilleur temps : " << *tempsCompetitions.begin() << "secondes ! " << endl;

}

double Pingouin::meilleurTemps()
 {
    if (tempsCompetitions.empty())
    return -1.0;

    return *tempsCompetitions.begin();
}

// =========================
// RECHERCHE DE NOURRITURE
// =========================

void Pingouin::ajouterLieuBouffe(const std::string& lieu)
{
// verifions si deja trouve le lieu de bouffe
    if (emplacementsNourriture.find(lieu)== emplacementsNourriture.end()) 
{
    emplacementsNourriture.insert(lieu);
    cout << " [ " << this->nom << " ]  a découvert un nouvel emplacement de bouffe : " << lieu << " . " << endl;
} else
{
    cout << " [ "<< this->nom << "  ] connait déja l'emplacement " << lieu << "." <<endl;
}


}

void Pingouin::retirerLieuBouffe(const std::string& lieu)
{


    if( emplacementsNourriture.find(lieu) != emplacementsNourriture.end())
    {
        emplacementsNourriture.erase(lieu);
        cout << " [  "<<this->nom<<  " ] a oublié ou perdu l'accé à l'emplacement " << lieu << "." << endl;
    } else
    {
       cout << " [  "<<this->nom<<" ] ne connait pas l'emplacement "<< lieu << " ."<<endl;
    }
    
}

void Pingouin::afficherLieuBouffe() 
{
    std::cout <<"\nEmplacements de nourriture connus par [  "<<this->nom<<" ] : "   << endl;

    if (emplacementsNourriture.empty())
    {
        cout << " Aucun lieu decouvert pour le moment !!" << endl;
    }

    for (const string& lieu : emplacementsNourriture) 
    {
        cout << " - " << lieu << endl;
    }
}

// =========================
// ASSOCIATION LIEUX MEETUP ↔ LIEUX DE PÊCHE
// =========================

void Pingouin::initialiserLieuxDePeche()
{
    lieuxDePecheAssocies = 
    {
    
            {"glacier", "Le lieu maudit"},
            {"banquise", "le trou de l'enfer"},
            {"océan", "les abysses sans fonds"},
            {"montagne du caillou blanc", "la montagne du destin"}
        
    };
    cout << "\n Associations entre meetup et lieu de pêche initialisées !" << endl;
}

void Pingouin::seRendreAuMeetUp(const std::string& lieu)
{
    if (std::find(lieuxRencontre.begin(),lieuxRencontre.end(), lieu) == lieuxRencontre.end())
    {
        cout << "[ "<< this->nom << " ] ne connait pas le lieu de meetup  " << lieu << "  !" << endl;
        return;
    }

    cout << " [ " << this->nom << " ] se rend au meetup "<< lieu << "..." <<endl;

    //verifions si le lieu est associé à une zone de peche


     if (lieuxDePecheAssocies.find(lieu)== lieuxDePecheAssocies.end())
     {
        cout << "Aucune zone de pêche n'est liée à ce lieu de meetup " << endl;
        return;
     }
     string zonePeche = lieuxDePecheAssocies[lieu];
     cout << "-> Zone de pêche associée : " << zonePeche <<endl;


     //random pour trouver un poison
   
     int chance_poisson = std::rand() % 100; // 0 à 99

     if (chance_poisson < 60)
     {
        cout << " [ " << this->nom << " ] a trouvé un poisson à "<<zonePeche << " ! " << endl;

        //ajout emplacement de nourriture
        emplacementsNourriture.insert(zonePeche);
     } else
     {
        cout << " [ " << this->nom << " ] n’a rien trouvé aujourd’hui à " << zonePeche << "..." << endl;
     }
     

}

void Pingouin::afficherAssociationsMeetUpPeche()
{
    cout << "\n Liste des association Meetup <-> Lieux de Pêches : " << endl;

    if (lieuxDePecheAssocies.empty())
    {
        cout << " Aucune association trouvée entre les deux !! " << endl;
        return;
    }

    for (const pair<string, string>& association : lieuxDePecheAssocies)
    {
        cout << " - " << association.first << " <-> " << association.second <<endl;
    }
}


// ====================
// GETTERS & SETTERS
// ====================

// --- Vitesses ---
void Pingouin::setVitesseNage(double vitesse) {
    Aquatique::setVitesseNage(vitesse);
}

void Pingouin::setVitesseMarche(double vitesse) {
    Terrestre::setVitesseMarche(vitesse);
}

void Pingouin::setVitesseGlisse(double vitesse) {
    vitesseGlisse = vitesse;
}

double Pingouin::getVitesseGlisse() const {
    return vitesseGlisse;
}

// --- Identité ---
string Pingouin::getNom() const {
    return nom;
}



