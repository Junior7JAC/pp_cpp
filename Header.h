#ifndef MENIU_H   /* Include guard */
#define MENIU_H
#include<string>
#include<vector>
using namespace std;


class Angajati
{
    string nume, nrtelefon, adresa, post, data;
    double salariu;
    int id;
public:

    Angajati();
    Angajati(int,string,string,string,string,string,double);
    ~Angajati();
    friend CitireDinFisier(Angajati);
    friend ScriereInFisier(Angajati);
    Angajati(const Angajati&);
    Angajati operator =(const Angajati&);
    friend ostream& operator <<(ostream &,const Angajati&);
    string get_nume()
    {
        return this->nume;
    }
    string get_nrtelefon()
    {
        return this->nrtelefon;
    }
    string get_adresa()
    {
        return this->adresa;
    }
    string get_post()
    {
        return this->post;
    }
    string get_data()
    {
        return this->data;
    }
    double get_salariu()
    {
        return this->salariu;
    }
    int get_id()
    {
        return this->id;
    }
    void set_id(int o)
    {
        this->id = o;
    }
     void set_nume(string o)
    {
        this->nume = o;
    }
     void set_nrtelefon(string o)
    {
        this->nrtelefon = o;
    }
     void set_adresa(string o)
    {
        this->adresa = o;
    }
     void set_post(string o)
    {
        this->post = o;
    }
     void set_data(string o)
    {
        this->data = o;
    }
     void set_salariu(double o)
    {
        this->salariu = o;
    }
};
void CitireDinFisier(vector <Angajati>&);
void ScriereInFisier(vector<Angajati>&);
void Meniu(vector <Angajati>&);
void CitAngNou(vector <Angajati>&);
void AfisAngajati(vector <Angajati>&);
void StergereAngajat(vector <Angajati>&);
void ActualizareAngajat(vector <Angajati>&);
void MeniuCautAng(vector <Angajati>&);
void CautDupaId(vector <Angajati>&);
void CautDupaNume(vector <Angajati>&);
void CautDupaPost(vector <Angajati>&);
void CautDupaAdresa(vector <Angajati>&);
void CautDupaNrTelefon(vector <Angajati>&);
void CautDupaData(vector <Angajati>&);
void CautDupaSalariu(vector <Angajati>&);
#endif // FOO_H_
