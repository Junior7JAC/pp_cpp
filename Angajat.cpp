#include"Header.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
Angajati::Angajati()
{
    nume=nullptr;
    nrtelefon=nullptr;
    adresa=nullptr;
    post=nullptr;
    data=nullptr;
    salariu=0;
    id=0;
}
Angajati::Angajati(int id,string nume,string nrtelefon,string adresa,string post,string data,double salariu)
{
    this->nume=nume;
    this->nrtelefon=nrtelefon;
    this->adresa=adresa;
    this->post=post;
    this->data=data;
    this->salariu=salariu;
    this->id=id;

}

Angajati::~Angajati() {}

Angajati::Angajati(const Angajati& a)
{
    this->nume=a.nume;
    this->nrtelefon=a.nrtelefon;
    this->adresa=a.adresa;
    this->post=a.post;
    this->data=a.data;
    this->salariu=a.salariu;
    this->id=a.id;
}

Angajati Angajati:: operator =(const Angajati& a)
{
    if(this==&a)
        return *this;
    this->nume=a.nume;
    this->nrtelefon=a.nrtelefon;
    this->adresa=a.adresa;
    this->post=a.post;
    this->data=a.data;
    this->salariu=a.salariu;
    this->id=a.id;
    return *this;
}

ostream& operator <<(ostream& os,const Angajati& a)
{
    os<<a.id<<"  "<<a.nume<<"  "<<a.nrtelefon<<"  "<<a.adresa<<"  "<<a.post<<"  "<<a.data<<"  "<<a.salariu;
    return os;
}

void CitireDinFisier(vector <Angajati>& ang)
{
    FILE* fp = fopen("test1.csv", "r");
    int i=0;
    if (!fp)
    {
        cout<< "\033[1;31m" <<"Can't open file"<< "\033[0m" <<'\n';
        fclose(fp);
    }
    else
    {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];

        int row = 0;
        int column = 1;

        while (fgets(buffer,1024, fp))
        {
            column = 1;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(buffer, ",");
            i=i+1;
            string nume,nrtelefon,adresa,post,data;
            double salariu;
            int id;
            while (value)
            {
                if (column == 1)
                    id=i;
                if (column == 2)
                    nume=value;
                if (column == 3)
                    nrtelefon=value;
                if (column == 4)
                    adresa=value;
                if (column == 5)
                    post=value;
                if (column == 6)
                    data=value;
                if (column == 7)
                {
                    double an=double(atof(value));
                    salariu=an;
                }
                value = strtok(NULL, ",");
                column++;
            }
            Angajati a(id,nume,nrtelefon,adresa,post,data,salariu);
            ang.push_back(a);

        }
        fclose(fp); // Close the file
    }
    return ;
}

void ScriereInFisier(vector<Angajati>& ang)
{

    FILE *fpt;
    fpt = fopen("test1.csv", "w+");
    fprintf(fpt,"Id,Nume,NumarTelefon,Adresa,Post,Data,Salariu\n");
    int i=0;
    for(auto& x: ang)
    {
        fprintf(fpt,"%d,%s,%s,%s,%s,%s,%.2f \n",x.get_id(), x.get_nume().c_str(), x.get_nrtelefon().c_str(), x.get_adresa().c_str(), x.get_post().c_str(), x.get_data().c_str(), x.get_salariu());
    }
    fclose(fpt);

}

void Meniu(vector<Angajati>& ang)
{
    int optiune;
    do
    {
        cout<< "\033[1;36m" <<"\n\n\n"<<"     MENIU     \n\n"<< "\033[0m" ;
        cout<< "\033[1;36m" <<"Introduceti numarul respectiv pentru ce cautati si apoi apasati enter:\n"<< "\033[0m" ;
        cout<< "\033[1;36m" <<"1. Citirea unui angajat nou\n\n"<< "\033[0m" ;
        cout<< "\033[1;36m" <<"2. Cautare Angajat\n\n"<< "\033[0m" ;
        cout<< "\033[1;36m" <<"3. Afisare Angajati\n\n"<< "\033[0m" ;
        cout<< "\033[1;36m" <<"4. Stergere Angajat\n\n"<< "\033[0m" ;
        cout<< "\033[1;36m" <<"5. Actualizare Angajat\n\n"<< "\033[0m" ;
        cout<< "\033[1;36m" <<"6. Exit\n\n"<< "\033[0m" ;
        cout<< "\033[1;36m" <<"7. Curata Ecranul\n\n"<< "\033[0m" ;
        cin>>optiune;
        if(optiune==1)
            CitAngNou(ang);
        else if(optiune==2)
            MeniuCautAng(ang);
        else if(optiune==3)
            AfisAngajati(ang);
        else if(optiune==4)
            StergereAngajat(ang);
        else if(optiune==5)
            ActualizareAngajat(ang);
        else if(optiune==6)
            return ;
        else if(optiune==7)
            system("cls");//cls clear screen
        else
            cout<< "\033[1;31m" <<"Ati introdus o optiune inexistena. Va rugam alegeti una valida"<< "\033[0m" <<'\n';
    }
    while(1==1);
}

void CitAngNou(vector <Angajati>& ang)
{
    string nume,nrtelefon,adresa,post,data;
    double salariu;
    int id=ang.size() + 1;
    cout<< "\033[1;36m" <<"Introduceti numele noului angajat"<< "\033[0m" <<'\n';
    cin.get();
    getline(cin,nume);
    cout<< "\033[1;36m" <<"Introduceti numarul de telefon al noului angajat"<< "\033[0m" <<'\n';
    getline(cin,nrtelefon);
    cout<< "\033[1;36m" <<"Introduceti adresa noului angajat"<< "\033[0m" <<'\n';
    getline(cin,adresa);
    cout<< "\033[1;36m" <<"Introduceti postul noului angajat"<< "\033[0m" <<'\n';
    getline(cin,post);
    cout<< "\033[1;36m" <<"Introduceti data angajarii"<< "\033[0m" <<'\n';
    getline(cin,data);
    cout<< "\033[1;36m" <<"Introduceti salariul noului angajat"<< "\033[0m" <<'\n';
    cin>>salariu;
    Angajati a(id,nume,nrtelefon,adresa,post,data,salariu);
    ang.push_back(a);
    cout<< "\033[1;32m"  <<"Actiunea a fost efectuata cu succes!"<< "\033[0m" <<'\n';
    ScriereInFisier(ang);
}

void AfisAngajati(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    for(auto& x : ang)
        cout<<x<<'\n';
    cout<< "\033[1;32m" <<"Actiunea a fost efectuata cu succes!"<< "\033[0m" <<'\n';
}

void StergereAngajat(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    int aux;
    cout<< "\033[1;36m" <<"Introduceti id-ul angajatului care doriti sa fie sters\n"<< "\033[0m" ;
    cin.get();
    cin>>aux;
    if(aux<=0||aux>ang.size())
    {
        cout<< "\033[1;31m" << "Id-ul angajatului cautat nu exista" << "\033[0m" <<'\n';
        return ;
    }
    ang.erase(ang.begin()+aux-1);
    for(int i=aux-1; i<=ang.size(); i++)
    {
        ang[i].set_id(i+1);
    }
    cout<< "\033[1;32m" <<"Actiunea a fost efectuata cu succes!"<< "\033[0m" <<'\n';
    ScriereInFisier(ang);
}


void ActualizareAngajat(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    cout<< "\033[1;36m" <<"Scrieti id-ul angajatului pe care doriti sa il actualizati"<< "\033[0m" <<'\n';
    int aux;
    cin>>aux;
    if(aux<=0||aux>ang.size())
    {
        cout<< "\033[1;31m" <<"Id-ul introdus nu exista"<< "\033[0m" <<'\n';
        return ;
    }
    do
    {

        int alegere;
        cout<< "\033[1;36m" <<"Alegeti ce vreti sa actualizati"<< "\033[0m" <<'\n';
        cout<< "\033[1;36m" <<"1. Numele angajatului"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"2. Numarul de telefon"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"3. Adresa"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"4. Post ocupat"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"5. Data angajarii"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"6. Salariul"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"7. Inapoi"<< "\033[0m" <<'\n'<<'\n';
        cin>>alegere;
        if(alegere==1)
        {
            cout<< "\033[1;36m" <<"\n\nIntroduceti noul nume\n"<< "\033[0m" ;
            string nou;
            cin.get();
            getline(cin, nou);
            ang[aux-1].set_nume(nou);
            ScriereInFisier(ang);
        }
        else if(alegere==2)
        {
            cout<< "\033[1;36m" <<"\n\nIntroduceti noul numar de telefon\n"<< "\033[0m" ;
            string nou;
            cin.get();
            getline(cin, nou);
            ang[aux-1].set_nrtelefon(nou);
            ScriereInFisier(ang);

        }
        else if(alegere==3)
        {
            cout<< "\033[1;36m" <<"\n\nIntroduceti noua adresa \n"<< "\033[0m" ;
            string nou;
            cin.get();
            getline(cin, nou);
            ang[aux-1].set_adresa(nou);
            ScriereInFisier(ang);

        }
        else if(alegere==4)
        {
            cout<< "\033[1;36m" <<"\n\nIntroduceti noul post ocupat\n"<< "\033[0m" ;
            string nou;
            cin.get();
            getline(cin, nou);
            ang[aux-1].set_post(nou);
            ScriereInFisier(ang);

        }
        else if(alegere==5)
        {
            cout<< "\033[1;36m" <<"\n\nIntroduceti noua data a angajarii\n"<< "\033[0m" ;
            string nou;
            cin.get();
            getline(cin, nou);
            ang[aux-1].set_data(nou);
            ScriereInFisier(ang);

        }
        else if(alegere==6)
        {
            cout<< "\033[1;36m" <<"\n\nIntroduceti noul salariu\n"<< "\033[0m" ;
            double nou;
            cin>>nou;
            ang[aux-1].set_salariu(nou);
            ScriereInFisier(ang);
        }
        else if(alegere==7)
        {
            return ;
        }

        else
            cout<< "\033[1;31m" <<"\n\n"<<"Nu ati ales o obtiune valida! Va rugam sa incercati din nou"<< "\033[0m" <<"\n";
        if(alegere>=1&&alegere<=7)
        {
            cout<< "\033[1;32m" <<'\n'<<"Instructiunea sa efectuat cu succes"<< "\033[0m" <<"\n\n";
        }

    }
    while(1==1);
}


void MeniuCautAng(vector <Angajati>& ang)
{


    int optiune;
    do
    {
        cout<< "\033[1;36m" <<"Cauta angajatul dupa:"<< "\033[0m" <<'\n';
        cout<< "\033[1;36m" <<"1. Id"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"2. Nume"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"3. Postul Ocupat"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"4. Adresa"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"5. Numar telefon"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"6. Data angajarii"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"7. Salariu"<< "\033[0m" <<'\n'<<'\n';
        cout<< "\033[1;36m" <<"8. Inapoi"<< "\033[0m" <<'\n'<<'\n';
        cin>>optiune;
        if (optiune==1)
        {
            CautDupaId(ang);
            return ;
        }
        else if (optiune==2)
        {
            CautDupaNume(ang);
            return ;
        }
        else if (optiune==3)
        {
            CautDupaPost(ang);
            return ;
        }
        else if (optiune==4)
        {
            CautDupaAdresa(ang);
            return;
        }
        else if (optiune==5)
        {
            CautDupaNrTelefon(ang);
            return ;
        }
        else if (optiune==6)
        {
            CautDupaData(ang);
            return;
        }
        else if (optiune==7)
        {
            CautDupaSalariu(ang);
            return ;
        }
        else if (optiune==8)
            return ;
        else
            cout<< "\033[1;31m" <<"Date incorecte! Va rugam sa introduceti alt numar"<< "\033[0m" <<'\n';
    }
    while(1==1);
}



void CautDupaId(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    int aux,ok=0;
    cout<< "\033[1;36m" <<"Indroduceti id-ul angajatului cautat\n"<< "\033[0m" ;
    cin>>aux;
    if(aux <= ang.size() && aux > 0)
    {
        cout<<ang[aux-1].get_id()<<" "<<ang[aux-1].get_nume()<<" "<<ang[aux-1].get_nrtelefon()<<" "<<ang[aux-1].get_adresa()<<" "<<ang[aux-1].get_post()<<" "<<ang[aux-1].get_data()<<" "<<ang[aux-1].get_salariu()<<'\n';
        ok++;
    }
    if(ok==0)
        cout<< "\033[1;31m" <<"Angajatul cu id-ul introdus nu exista"<< "\033[0m" <<'\n';
    if(ok>=1)
        cout<< "\033[1;32m" <<"Actiunea a fost efectuata cu succes!"<< "\033[0m" <<'\n';
}


void CautDupaNume(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    string aux;
    cout<< "\033[1;36m" <<"Indroduceti numele angajatului cautat\n"<< "\033[0m" ;
    cin.get();
    getline(cin, aux);
    int ok=0;
    for(auto& x : ang)
    {
        //   cout<<x.get_nume().find(aux)<<'\n';

        size_t found = x.get_nume().find(aux);

        if (found!=string::npos)
        {
            cout<<x.get_id()<<" "<<x.get_nume()<<" "<<x.get_nrtelefon()<<" "<<x.get_adresa()<<" "<<x.get_post()<<" "<<x.get_data()<<" "<<x.get_salariu()<<'\n';
            ok++;
        }
    }
    if(ok==0)
        cout<< "\033[1;31m" <<"Angajatul cu numele introdus nu exista"<< "\033[0m" <<'\n';
    if(ok>=1)
        cout<< "\033[1;32m" <<"Actiunea a fost efectuata cu succes!"<< "\033[0m" <<'\n';
}

void CautDupaPost(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    string aux;
    cout<< "\033[1;36m" <<"Indroduceti postul angajatului cautat\n"<< "\033[0m" ;
    cin.get();
    getline(cin, aux);
    int ok=0;
    for(auto& x : ang)
    {
        //   cout<<x.get_nume().find(aux)<<'\n';

        size_t found = x.get_post().find(aux);

        if (found!=string::npos)
        {
            cout<<x.get_id()<<" "<<x.get_nume()<<" "<<x.get_nrtelefon()<<" "<<x.get_adresa()<<" "<<x.get_post()<<" "<<x.get_data()<<" "<<x.get_salariu()<<'\n';
            ok++;
        }
    }
    if(ok==0)
        cout<< "\033[1;31m" <<"Angajatul cu postul introdus nu exista"<< "\033[0m" <<'\n';
    if(ok>=1)
        cout<< "\033[1;32m" <<"Actiunea a fost efectuata cu succes!"<< "\033[0m" <<'\n';

}




void CautDupaAdresa(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    string aux;
    cout<< "\033[1;36m" <<"Indroduceti adresa angajatului cautat\n"<< "\033[0m" ;
    cin.get();
    getline(cin, aux);
    int ok=0;
    for(auto& x : ang)
    {
        //   cout<<x.get_nume().find(aux)<<'\n';

        size_t found = x.get_adresa().find(aux);

        if (found!=string::npos)
        {
            cout<<x.get_id()<<" "<<x.get_nume()<<" "<<x.get_nrtelefon()<<" "<<x.get_adresa()<<" "<<x.get_post()<<" "<<x.get_data()<<" "<<x.get_salariu()<<'\n';
            ok++;
        }
    }
    if(ok==0)
        cout<< "\033[1;31m" <<"Angajatul cu adresa introdusa nu exista"<< "\033[0m" <<'\n';
    if(ok>=1)
        cout<< "\033[1;32m" <<"Actiunea a fost efectuata cu succes!"<< "\033[0m" <<'\n';
}

void CautDupaNrTelefon(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    string aux;
    cout<< "\033[1;36m" <<"Indroduceti numarul de telefon al angajatului cautat\n"<< "\033[0m" ;
    cin.get();
    getline(cin, aux);
    int ok=0;
    for(auto& x : ang)
    {
        //   cout<<x.get_nume().find(aux)<<'\n';

        size_t found = x.get_nrtelefon().find(aux);

        if (found!=string::npos)
        {
            cout<<x.get_id()<<" "<<x.get_nume()<<" "<<x.get_nrtelefon()<<" "<<x.get_adresa()<<" "<<x.get_post()<<" "<<x.get_data()<<" "<<x.get_salariu()<<'\n';
            ok++;
        }
    }
    if(ok==0)
        cout<< "\033[1;31m" <<"Angajatul cu numarul de telefon introdus nu exista"<< "\033[0m" <<'\n';
    if(ok>=1)
        cout<< "\033[1;32m" <<"Actiunea a fost efectuata cu succes!"<< "\033[0m" <<'\n';
}

void CautDupaData(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    string aux;
    cout<< "\033[1;36m" <<"Indroduceti data angajatului cautat\n"<< "\033[0m" ;
    cin.get();
    getline(cin, aux);
    int ok=0;
    for(auto& x : ang)
    {
        //   cout<<x.get_nume().find(aux)<<'\n';

        size_t found = x.get_data().find(aux);

        if (found!=string::npos)
        {
            cout<<x.get_id()<<" "<<x.get_nume()<<" "<<x.get_nrtelefon()<<" "<<x.get_adresa()<<" "<<x.get_post()<<" "<<x.get_data()<<" "<<x.get_salariu()<<'\n';
            ok++;
        }
    }
    if(ok==0)
        cout<< "\033[1;31m" <<"Angajatul cu data introdusa nu exista"<< "\033[0m" <<'\n';
    if(ok>=1)
        cout<< "\033[1;32m"<<"Actiunea a fost efectuata cu succes!"<< "\033[0m"<<'\n';

}

void CautDupaSalariu(vector <Angajati>& ang)
{
    if(ang.size()==0)
    {
        cout<< "\033[1;31m" <<"Nu avem angajati"<< "\033[0m" <<'\n';
        return;
    }
    double aux;
    int ok=0;
    cout<< "\033[1;36m" <<"Indroduceti salariul angajatului cautat\n"<< "\033[0m" ;
    cin>>aux;
    for(auto& x : ang)
    {
        if(x.get_salariu() == aux)
        {
            cout<<x.get_id()<<" "<<x.get_nume()<<" "<<x.get_nrtelefon()<<" "<<x.get_adresa()<<" "<<x.get_post()<<" "<<x.get_data()<<" "<<x.get_salariu()<<'\n';
            ok++;
        }
    }
    if(ok==0)
        cout<< "\033[1;31m" <<"Angajatul cu salariul introdus nu exista"<< "\033[0m" <<'\n';
    if(ok>=1)
        cout<< "\033[1;32m" <<"Actiunea a fost efectuata cu succes!"<< "\033[0m" <<'\n';
}
