#ifndef PROIECT_1_HEALTHPACKAGE_H
#define PROIECT_1_HEALTHPACKAGE_H
#include <iostream>

using namespace std;



class HealthPackage {

private:

    int age, validity;
    bool loyalCustomer, retired;
    double price;

public:

    HealthPackage();
    HealthPackage(int _age, bool _loyalCustomer, int _validity, bool _retired);
    HealthPackage (const HealthPackage&);                                          // constructor copiere
    HealthPackage& operator=(const HealthPackage&);                                // op atribuire
    friend istream& operator>>(istream &, HealthPackage&);                         // op citire
    friend ostream& operator<<(ostream &, HealthPackage&);                         // op afisare
    double computePrice();                                                       // functie care calculeaza pretul
    int getAge() const;

    void setAge(int age);

    bool isLoyalCustomer() const;

    void setLoyalCustomer(bool loyalCustomer);

    bool isRetired() const;

    void setRetired(bool retired);

    int getValidity() const;

    void setValidity(int validity);

    double getPrice() const;

    void setPrice(double price);

};



#endif //PROIECT_1_HEALTHPACKAGE_H
