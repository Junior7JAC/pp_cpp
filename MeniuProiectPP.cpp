#include "Header.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

vector<Angajati> ang;

int main()
{
    system("cls");
    CitireDinFisier(ang);
    Meniu(ang);
    ScriereInFisier(ang);

    return 0;
}
