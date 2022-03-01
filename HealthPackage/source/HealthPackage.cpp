#include <iostream>
#include<fstream>
#include<string>
#include "../header/HealthPackage.h"

using namespace std;

HealthPackage::HealthPackage()
{
    age = 0;
    loyalCustomer = false;
    validity = 0;
    retired = false;
    price = 0;
}

HealthPackage::HealthPackage(int _age, bool _loyalCustomer, int _validity, bool _retired)
{
    this->age = _age;
    this->loyalCustomer = _loyalCustomer;
    this->validity = _validity;
    this->retired = _retired;

}

HealthPackage :: HealthPackage(const HealthPackage& cl)
{
    this->age = cl.age;
    this->loyalCustomer = cl.loyalCustomer;
    this->validity = cl.validity;
    this->retired = cl.retired;
}

HealthPackage& HealthPackage::operator=(const HealthPackage& cl)
{
    this->age = cl.age;
    this->loyalCustomer = cl.loyalCustomer;
    this->validity = cl.validity;
    this->retired = cl.retired;

    return *this;
}

istream& operator>>(istream &is, HealthPackage& cl)
{
    cout<< "Age: " << "\n";
    is >> cl.age;
    cout<< "Is loyal customer: " << "\n";
    is >> cl.loyalCustomer;
    cout<< "Validity: " << "\n";
    is >> cl.validity;
    cout<< "Is retired: " << "\n";
    is >> cl.retired;
    return is;
}

ostream& operator<<(ostream &out, HealthPackage& cl)
{
    out<< "The age is: " << cl.age << "\n";
    out<< "Is the customer loyal (0 - no, 1 - yes): " << cl.loyalCustomer << "\n";
    out<< "Validity is "<< cl.validity<< " months "<< "\n";
    out<< "Is the customer retired (0 - no, 1 - yes): " << cl.retired << "\n";
    out<<"The price is: "<< cl.computePrice() << " RON \n";

    return out;
}

int HealthPackage::getAge() const {
    return age;
}

void HealthPackage::setAge(int age) {
    HealthPackage::age = age;
}

bool HealthPackage::isLoyalCustomer() const {
    return loyalCustomer;
}

void HealthPackage::setLoyalCustomer(bool loyalCustomer) {
    HealthPackage::loyalCustomer = loyalCustomer;
}

bool HealthPackage::isRetired() const {
    return retired;
}

void HealthPackage::setRetired(bool retired) {
    HealthPackage::retired = retired;
}

int HealthPackage::getValidity() const {
    return validity;
}

void HealthPackage::setValidity(int validity) {
    HealthPackage::validity = validity;
}

double HealthPackage::getPrice() const {
    return price;
}

void HealthPackage::setPrice(double price) {
    HealthPackage::price = price;
}

double HealthPackage:: computePrice()
{
    if (validity == 1)
        price = 300;
    if (validity == 3)
        price = 790.99;
    if (validity == 12)
        price = 2900;

    if (age <= 16) {
        if (loyalCustomer == 0)
            price = 0;
        else { price = price - price * 0.15 - price * 0.10; }
    }
    if(16 < age && age<= 25 ) {
        if (loyalCustomer == 0)
            price = price - price * 0.10;
        else
            price = price - 2 * price * 0.10;
    }
    if(25 < age && age <= 50) {
        if (loyalCustomer == 0)
            price = price - price * 0.05;
        else
            price = price - price * 0.05 - price * 0.10;
    }
    if(age > 50 and retired) {
        if (loyalCustomer == 0)
            price = price - price * 0.35;
        else
            price = price - price * 0.35 - price * 0.10;
    }
    return price;
}
