#include <iostream>
#include "header/HealthPackage.h"
#include <fstream>

using namespace std;

ofstream fout("bills.txt");


int main() {

    HealthPackage empty;
    HealthPackage client(23, true, 3, false);
    HealthPackage happyClient(47, false, 3, false);
    HealthPackage curiousClient(77, false, 12, true);

    fout << client;


    return 0;
}