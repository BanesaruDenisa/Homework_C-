/* Bănesaru Denisa-Georgiana, grupa 263
 * IDE: Clion, compilator: MinGw
 * Tutore: Deaconu Stefan Eduard */


#include <iostream>
#include <utility>
#include <vector>
#include<string>
#include<memory>
#include <algorithm>

using namespace std;

class PachetClasic {
protected:
    int nrMese;
    bool singur;
    vector<string> alergeni;


public:
    PachetClasic() : nrMese(0), singur(true) {}
    virtual ~ PachetClasic() = default;
    PachetClasic(const PachetClasic & pk) = default;
    PachetClasic &operator=(const PachetClasic & pk) = default;
    PachetClasic(int nrMese, bool singur, const vector<string> &alergeni) : nrMese(nrMese), singur(singur),
                                                                            alergeni(alergeni) {}

    // functiile de afisare/ citire sunt preluate dintr-un tutoriat
    friend ostream &operator<<(ostream &os, PachetClasic &p) {
        p.afisare(os);
        return os;
    }
    friend istream &operator>>(istream &is, PachetClasic &p) {
        p.citire(is);
        return is;
    }

    virtual void citire(istream &is){
        cout << "nrMese: "<<endl;
        is >> nrMese ;
        cout << " singur(0-false, 1-true): "<<endl;
        is >> singur ;
        int nrAlergeni;
        cout << "Numarul de alergeni:"<<endl;
        cin >> nrAlergeni;
        cout << "Lista de alergeni: "<<endl;
        for(int i=0; i< nrAlergeni; i++){
            cout << "Alergenul numarul " << i + 1 << " :";
            string tempAlergeni;
            cin >> tempAlergeni;
            alergeni.push_back(tempAlergeni);
        }

    }
    virtual void afisare(ostream &os) const{
        os << "Numarul de mese: " << nrMese <<endl;
        os<<" Singur(0-false, 1-true)?:  " << singur <<endl;
        os<<" Lista de alergeni" <<endl;

        for(auto & i : alergeni){
            os<< i;
        }
    }

};



class PachetSport : public PachetClasic {
protected:
    int nrPlimbari;

public:
    PachetSport() : nrPlimbari(0) {}
    PachetSport(const PachetSport & ps) = default;
    PachetSport &operator=(const PachetSport & ps) = default;
    ~PachetSport() override = default;

    PachetSport(int nrMese, bool singur, const vector<string> &alergeni, int nrPlimbari) : PachetClasic(nrMese,
                                                                                                                     singur,
                                                                                                                     alergeni),
                                                                                                        nrPlimbari(
                                                                                                                nrPlimbari) {}


    friend ostream &operator<<(ostream &os, PachetSport &p) {
        p.afisare(os);
        return os;
    }
    friend istream &operator>>(istream &is, PachetSport &p) {
        p.citire(is);
        return is;
    }

     void citire(istream &is) override{
        PachetClasic::citire(is);
         unsigned  conditieCitire = 0;
         while (conditieCitire == 0) {
             try{
             cout << "nrPlimbari: " << endl;
             is >> nrPlimbari;
             conditieCitire = 1;
                 if (nrPlimbari > 5) {
                     throw nrPlimbari;
                 }
             } catch (...) {
                 std::cout << "Eroare!\n";
                 conditieCitire = 0;
             }
         }

    }
     void afisare(ostream &os) const override{
        PachetClasic::afisare(os);
        os << "Numarul de plimbari: " << nrPlimbari <<endl;

    }

};



class PachetConfort : public PachetClasic{
protected:
    vector<string> activitati;

public:
    PachetConfort()  = default;
    PachetConfort(const PachetConfort & pc) = default;
    PachetConfort &operator=(const PachetConfort & pc) = default;
    ~PachetConfort() override = default;

    friend ostream &operator<<(ostream &os, PachetConfort &p) {
        p.afisare(os);
        return os;
    }
    friend istream &operator>>(istream &is, PachetConfort &p) {
        p.citire(is);
        return is;
    }

     void citire(istream &is) override{
        PachetClasic::citire(is);
        int nrActivitati;
        cout << "Nractivitati: "<<endl;
        is >> nrActivitati ;
        cout << "Lista de activitati: "<<endl;
        for(int i=0; i< nrActivitati; i++){
            cout << "Activitatea numarul " << i + 1 << " :";
            string tempActivitati;
            cin >> tempActivitati;
            activitati.push_back(tempActivitati);
        }


    }
    void afisare(ostream &os) const override{
        PachetClasic::afisare(os);
        os<<" Lista de activitati" <<endl;

        for(auto & i : activitati){
            os<< i;
        }
    }

};

class PachetVIP: virtual public PachetSport, virtual public PachetConfort {
private:
    vector<string> orePlimbare;
    int durataPlimbarii;

public:
    PachetVIP() : durataPlimbarii(0){}
    PachetVIP(const PachetVIP & pv) = default;
    PachetVIP &operator=(const PachetVIP & pv) = default;
    ~PachetVIP() override = default;

    friend ostream &operator<<(ostream &os, PachetVIP &p) {
        p.afisare(os);
        return os;
    }
    friend istream &operator>>(istream &is, PachetVIP &p) {
        p.citire(is);
        return is;
    }

    void citire(istream &is) override{
        PachetSport::citire(is);
        PachetConfort::citire(is);
        int nrOre;
        cout << "Nrore: "<<endl;
        is >> nrOre ;
        cout << "Lista de ore: "<<endl;
        for(int i=0; i< nrOre; i++){
            cout << "Ora plimbare numarul " << i + 1 << " :";
            string tempPlimbari;
            cin >> tempPlimbari;
            orePlimbare.push_back(tempPlimbari);
        }
        cout << "durata: " << endl;
        is >> durataPlimbarii;
    }

    void afisare(ostream &os) const{
        PachetSport::afisare(os);
        PachetConfort::afisare(os);
        os<<" Lista de ore de plimbare" <<endl;

        for(auto & i : orePlimbare){
            os<< i;
        }
        os<<" Durata plimbarii: " << durataPlimbarii <<endl;
    }

};

class Client {
private:
    string numeClient;
    string nrTelefon;
    string adresa;
    string CNP;
public:
    Client() = default;
    ~Client() = default;
    Client(const Client &cl) = default;
    Client &operator=(const Client &cl) = default;
    Client(const string &numeClient, const string &nrTelefon, const string &adresa, const string &cnp) : numeClient(
            numeClient), nrTelefon(nrTelefon), adresa(adresa), CNP(cnp) {}

    friend ostream &operator<<(ostream &os, Client &c) {
        c.afisare(os);
        return os;
    }
    friend istream &operator>>(istream &is, Client &c) {
        c.citire(is);
        return is;
    }
    void citire(istream &is) {
        cout << "numeClient: " << endl;
        is >> numeClient;
        cout << "nrTelefon: " << endl;
        is >> nrTelefon;
        cout << "adresa: " << endl;
        is >> adresa;
        cout << "CNP: " << endl;
        is >> CNP;
    }

    void afisare(ostream &os) const{

       os << "numeClient: " << numeClient << endl;
        os << "nrTelefon: " << nrTelefon<< endl;
        os<< "adresa: " << adresa<<endl;
        os<< "CNP: " << CNP<<endl;
    }


};

class Animal{
private:
    static int static_idAnimal;
    const int idAnimal;
    string numeAnimal;
    int varsta{};
    string rasa;
public:

    Animal() : idAnimal(++static_idAnimal){}   // aici e gresit, dar nu sti sa fac

    Animal(const int idAnimal, const string &numeAnimal, int varsta, const string &rasa);
    ~Animal() =default;
    Animal(const Animal &a) = default;
    Animal &operator=(const Animal &a) = default;

    friend ostream &operator<<(ostream &os, Animal &a) {
        a.afisare(os);
        return os;
    }
    friend istream &operator>>(istream &is, Animal &a) {
        a.citire(is);
        return is;
    }
    void citire(istream &is) {
        cout << "numeAnimal: " << endl;
        is >> numeAnimal;
        cout << "varsta: " << endl;
        is >> varsta;
        cout << "rasa: " << endl;
        is >> rasa;
    }

    void afisare(ostream &os) const{

        cout << "numeAnimal: " << numeAnimal<<endl;
        cout << "varsta: " << varsta<< endl;
        cout << "rasa: " << rasa<<endl;

    }
};
int Animal:: static_idAnimal = 0;

Animal::Animal(const int idAnimal, const string &numeAnimal, int varsta, const string &rasa) : idAnimal(idAnimal),
                                                                                               numeAnimal(numeAnimal),
                                                                                               varsta(varsta),
                                                                                               rasa(rasa) {}


class Formular {
private:
    // Laboratul 11
    static int static_idFormular;
    const int idFormular;
    string dataInceput;
    string dataFinal;
    vector<shared_ptr<PachetClasic>> pachet;
    vector<shared_ptr<Animal>> animal;
    vector<shared_ptr<Client>> client;
public:

    Formular() : idFormular(++static_idFormular) {}
    ~Formular() = default;
    Formular(const Formular &f) = default;
    Formular &operator=(const Formular &f) = default;

    Formular(const int idFormular, const string &dataInceput, const string &dataFinal,
             const vector<shared_ptr<PachetClasic>> &pachet, const vector<shared_ptr<Animal>> &animal,
             const vector<shared_ptr<Client>> &client) : idFormular(idFormular), dataInceput(dataInceput),
                                                         dataFinal(dataFinal), pachet(pachet), animal(animal),
                                                         client(client) {}

    friend ostream &operator<<(ostream &os, Formular &f) {
        f.afisare(os);
        return os;
    }
    friend istream &operator>>(istream &is, Formular &f) {
        f.citire(is);
        return is;
    }

    void citire(istream &is) {
        cout << "dataInceput in format (YYYY/MM/DD): " << endl;
        is >> dataInceput;
        cout << "dataFinal in format (YYYY/MM/DD): " << endl;
        is >> dataFinal;

        int nrPachete;
        is >> nrPachete;
        for (int i = 0; i < nrPachete; i++) {
            std::shared_ptr<PachetClasic> tempPachet;
            unsigned int opt;
            cout << "Tip pachet (1-clasic, 2-sportiv, 3-confort, 4-VIP): ";
            cin >> opt;
            switch (opt) {
                case 1: {
                    tempPachet = make_shared<PachetClasic>();
                    break;
                }
                case 2: {
                    tempPachet = make_shared<PachetSport>();
                    break;
                }
                case 3: {
                    tempPachet = make_shared<PachetConfort>();
                    break;
                }
                case 4: {
                      tempPachet = make_shared<PachetVIP>();
                    break;
                }
            }
            tempPachet->citire(is);
            pachet.push_back(tempPachet);
        }
    }

    void afisare(ostream &os) const {
        os << "dataInceput in format (YYYY/MM/DD): " << dataInceput << endl;
        os << "dataFinal in format (YYYY/MM/DD): " << dataFinal<< endl;
        os << "Pachetul: " << endl;
        for(auto & i : pachet){
            i->afisare(os);
        }
    }


};


class Meniu{
private:
    static Meniu *instance;
    Meniu() = default;
    vector<shared_ptr<Formular>> form;
public:
    ~Meniu() = default;
    static Meniu *getInstance() {
        if (instance == nullptr) {
            instance = new Meniu;
        }
        return instance;
    }

    static void optiuni(){
        cout << "1. Adaugare formular nou" << endl;
        cout << "2. Afisare formulare" << endl;
        cout << "3. Selectare formular detalii" <<endl;
        cout << "4. Afisare formulare crescator" <<endl;
        cout << "0. Exit" <<endl;
    }

    void adaugaFormular(){
        int nrFormulare;
        cout << "Numarul de formulare este: "<<endl;
        cin >> nrFormulare;

        for(int i=0; i<nrFormulare; i++){
            unsigned int opt, cond=0;
            shared_ptr<Formular> tempForm;
            cin >> reinterpret_cast<bool &>(tempForm);
            form.push_back(tempForm);

            }

        }
    void afisareFromulare(){
        for (auto &i : form) {
            form.afisare(cout);
        }
    }

};


void appRun() {
    int option = 0;
    Meniu *meniu = Meniu::getInstance();
    do {
        Meniu::optiuni();
        std::cout << "Introduceti numarul optiunii: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                meniu->adaugaFormular();
                break;
            }
            case 2: {
                meniu->afisareFormulare();
                break;
            }
            case 3: {

                break;
            }

        }
    } while (option != 0);
}

int main() {

    appRun();
    return 0;
}
