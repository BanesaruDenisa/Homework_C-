#include <iostream>
#include<vector>
#include <algorithm>
#include<memory>

using namespace std;

class Reviews{
private:
    string numeClient;
    int durata{};
    int nota{};
public:
    Reviews() = default;
    Reviews( string &numeClient, int durata, int nota) : numeClient(numeClient), durata(durata), nota(nota) {}
    ~Reviews()=default;

    const string &getNumeClient() const {
        return numeClient;
    }

    void setNumeClient(const string &numeClient) {
        Reviews::numeClient = numeClient;
    }

    int getDurata() const {
        return durata;
    }

    void setDurata(int durata) {
        Reviews::durata = durata;
    }

    int getNota() const {
        return nota;
    }

    void setNota(int nota) {
        Reviews::nota = nota;
    }

    friend istream &operator>>(istream &is, Reviews &reviews)
    {
        cout << " Nume cient: "<<endl;
        is >> reviews.numeClient ;
        cout << " Durata: "<<endl;
        is >> reviews.durata;
        cout<< " Nota: "<< endl;
        is >> reviews.nota;
        return is;
    }

    friend ostream &operator<<(ostream &os, Reviews &reviews)
    {
        os << "Nume Client: " << reviews.numeClient << " Durata: " << reviews.durata << " Nota: " << reviews.nota<< endl;
        return os;
    }



};

class HolidayResort {
protected:
    string tara;
    string oras;
    string denumire;
    double pretZi;
    vector<Reviews *> recenzii;

public:
    HolidayResort() : pretZi(0) {}
    HolidayResort(const string &tara, const string &oras, const string &denumire, double pretZi,
                  const vector<Reviews *> &recenzii) :
                   tara(tara),
                   oras(oras),
                   denumire(denumire),
                   pretZi(pretZi),
                   recenzii(recenzii){}

    HolidayResort(const HolidayResort& h) {
        this->tara = h.tara;
        this->oras = h.oras;
        this->denumire = h.denumire;
        this->pretZi = h.pretZi;
        this->recenzii = h.recenzii;
    }


    HolidayResort& operator=(const HolidayResort& h){
        this->tara = h.tara;
        this->oras = h.oras;
        this->denumire = h.denumire;
        this->pretZi = h.pretZi;
        this->recenzii = h.recenzii;
        return *this;
    }
    virtual ~HolidayResort() = default;

    const string &getTara() const {
        return tara;
    }

    void setTara(const string &tara) {
        HolidayResort::tara = tara;
    }

    const string &getOras() const {
        return oras;
    }

    void setOras(const string &oras) {
        HolidayResort::oras = oras;
    }

    const string &getDenumire() const {
        return denumire;
    }

    void setDenumire(const string &denumire) {
        HolidayResort::denumire = denumire;
    }

    double getPretZi() const {
        return pretZi;
    }

    void setPretZi(double pretZi) {
        HolidayResort::pretZi = pretZi;
    }

    const vector<Reviews *> &getRecenzii() const {
        return recenzii;
    }

    void setRecenzii(const vector<Reviews *> &recenzii) {
        HolidayResort::recenzii = recenzii;
    }

    friend istream &operator>>(istream &is, HolidayResort & h)
    {
        h.citire(is);
        return is;
    }

    virtual istream &citire(istream &is)
    {
        cout<< "Tara: " << endl;
        is >> tara;
        cout << "Orasul: "<<endl;
        is >> oras;
        cout << "Denumire resort: "<< endl;
        is >> denumire;
        cout << "Pretul pe zi: "<< endl;
        is >> pretZi;
        cout << "Numarul de recenzii: ";
        int cntr;
        is >> cntr;
        recenzii.reserve(cntr);
        if(cntr == 0)
            cout<< "Nu avem recenzii inca "<<endl;
        for(int i=0; i < cntr; i++)
        {
            auto *x = new Reviews();
            is >> (*x);
            recenzii.push_back((*&x));
        }

        return is;
    }

    friend ostream &operator<<(ostream &os, HolidayResort &h)
    {
        h.afisare(os);
        return os;
    }

    virtual ostream &afisare(ostream &os) const
    {
        os << "Tara: " << tara << '\n';
        os << "Oras: " << oras << '\n';
        os << "Denumire: " << denumire << '\n';
        os << "Pret: " << pretZi << '\n';
        os << "Reviews: \n";
        for(auto i : recenzii)
            os << *i << endl;

        return os;
    }

};


enum TypeOfView{
    SEAVIEW,
    OCEANVIEW
};

class IslandTourism: public HolidayResort{
private:
    int nrInsule;
protected:
    TypeOfView view;
public:
    IslandTourism() : nrInsule(0), view(SEAVIEW) {}

    IslandTourism(const string &tara, const string &oras, const string &denumire, double pretZi,
                  const vector<Reviews *> &recenzii, int nrInsule, TypeOfView view) : HolidayResort(tara, oras,
                                                                                                    denumire, pretZi,
                                                                                                    recenzii),
                                                                                      nrInsule(nrInsule), view(view) {}


    ~IslandTourism() override = default;

    IslandTourism(const IslandTourism & i)  : HolidayResort(i) {
        this->nrInsule = i.nrInsule;
        this->view = i.view;

    }
    IslandTourism& operator=(const IslandTourism & i){
        this->nrInsule = i.nrInsule;
        this->view = i.view;
        return *this;
    }


    istream &citire(istream &is) override {
        HolidayResort::citire(is);
        cout<<"View: 0- SEAVIEW, 1- OCEANVIEW ";
        is>> reinterpret_cast<bool &>(view);
        cout <<"Numar de insule: ";
        is >> nrInsule;
        return is;
    }

    ostream &afisare(ostream &os) const override {
        HolidayResort::afisare(os);
        os<<"View: 0- SEAVIEW, 1- OCEANVIEW : "<< view <<'\n';
        os<<"Numar de insule: "<< nrInsule <<'\n';
        return os;

    }

};


class MountainTourism : public HolidayResort{
private:
    double inaltime;
    double distanta;
    int nrTrasee;
public:
    MountainTourism() : inaltime(0), distanta(0), nrTrasee(0) {}

    MountainTourism(const string &tara, const string &oras, const string &denumire, double pretZi,
                    const vector<Reviews *> &recenzii, double inaltime, double distanta, int nrTrasee) : HolidayResort(
            tara, oras, denumire, pretZi, recenzii), inaltime(inaltime), distanta(distanta), nrTrasee(nrTrasee) {}

    ~MountainTourism() override = default;

    istream &citire(istream &is) override {
        HolidayResort::citire(is);

        cout<<" Inaltimea: ";
        is>>inaltime;
        cout<<"Distanta: ";
        is>>distanta;
        cout<<"Numarul de trasee: ";
        is>>nrTrasee;
        return is;
    }

    ostream &afisare(ostream &os) const override {
        HolidayResort::afisare(os);

        os<<"Inaltimea: "<<inaltime<<'\n';
        os<<"Distanta: "<<distanta<<'\n';
        os<<"Numarul de trasee: "<<nrTrasee <<'\n';
        return os;
    }


};


class TravelAgency{
private:
    double IslandDiscount{};
    double MountainDiscount{};
    double PercentileDiscount{};
    vector<HolidayResort *> resorts;
public:

    TravelAgency(double islandDiscount, double mountainDiscount, double percentileDiscount) : IslandDiscount(
            islandDiscount), MountainDiscount(mountainDiscount), PercentileDiscount(percentileDiscount) {}


    HolidayResort *allocate(HolidayResort *h){
        auto *asIsland = dynamic_cast<IslandTourism *>(h);
        auto *asMountain = dynamic_cast<MountainTourism *>(h);
        if (asIsland){
            return new IslandTourism(*asIsland);
        } else if (asMountain) {
            return new MountainTourism(*asMountain);
        }
        return nullptr;
    }

    HolidayResort *createHoliday(){
        int tip;
        cout<< "Tip vacanta (1 - Island, 2 - Mountain): ";
        cin >>tip;
        HolidayResort *h = nullptr;
        if(tip == 1) {
            h = new IslandTourism;
        } else if (tip == 2){
            h = new MountainTourism;
        }
        if(h) {
            cin >> *h;
        }
        return h;

    }

    TravelAgency(const vector<HolidayResort *> & res) {

        for(auto *resort : res) {
            resorts.push_back(allocate(resort));
        }
    }

    // citirea a n resorturi
    void citireR() {

        int nr;
        cout << " nr = ";
        cin >> nr;
        for(int i=0; i<nr; i++) {
            cout<< "Citeste resort "<< i + 1 << endl;
            resorts.push_back(createHoliday());
        }
    }

    //adaugare resort
    void adaugareR() {

        resorts.push_back(createHoliday());
    }

    //afisae resort
    void afisareR() {
        int i =0;
        for (auto &res : resorts) {
            i++;
            cout<< "Se afiseaza resortul: "<< i <<endl; ;
            res->afisare(cout);
            cout<< "-----------------------\n";
        }
    }
    void adaugaDiscount() {

        cout << "Introdu discount pentru Island: \n";
        cin >> IslandDiscount;
        cout << "Introdu discount pentru Mountain: \n";
        cin >> MountainDiscount;
        cout<< "Introdu discount procentual (%): \n";
        cin >> PercentileDiscount;

    }

    void afiseazaSumar() {

        for (auto &res : resorts) {

            // calculez discountul cel mai mare care trebuie aplicat
            auto *islT = dynamic_cast<IslandTourism *>(res);
            if(islT){

                if(islT->getPretZi() - IslandDiscount < islT->getPretZi() - PercentileDiscount/100)
                    islT->setPretZi(islT->getPretZi() - IslandDiscount) ;
                else
                    islT->setPretZi(islT->getPretZi() - PercentileDiscount/100) ;
            }

            auto *mounT = dynamic_cast<MountainTourism *>(res);
            if(mounT){

                if(mounT->getPretZi() - MountainDiscount < mounT->getPretZi() - PercentileDiscount/100)
                    mounT->setPretZi(mounT->getPretZi() - MountainDiscount) ;
                else
                    mounT->setPretZi(mounT->getPretZi() - PercentileDiscount/100) ;
                }
            }
    }

    // menu
    void showMenu() {
        cout<< "1. Citeste n resorturi "<< endl;
        cout<< "2. Adauga resort nou "<<endl;
        cout<< "3. Afisaza resorturi "<<endl;
        cout<< "4. Adauga discount "<<endl;
        cout<< "5. Calculeaza pret final "<<endl;         /// calculeaza dar nu afiseaza pretul final, trebuie apasat tsta 3 dupa 5 si e ok :)
        cout<< "6. Exit "<<endl;
    }

    void run() {
        int optiune;
        while(true) {
            showMenu();
            cout<< "Optiune: ";
            cin>> optiune;

            if(optiune == 1){
                citireR();
            } else if (optiune == 2) {
                adaugareR();
            } else if(optiune == 3) {
                afisareR();
            } else if(optiune == 4) {
                adaugaDiscount();
            } else if(optiune == 5) {
                afiseazaSumar();
            }
            else { break ;}
        }
    }
};


int main() {

    vector<HolidayResort *> v;

    TravelAgency app(v);
    app.run();

    return 0;
}
