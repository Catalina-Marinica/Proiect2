#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Data
{private:
    int zi;
    char *luna;
    int an;
 public:
     virtual void afisare(ostream &out);
     virtual void citire(istream &in);
     friend ostream& operator<<(ostream&, Data&);
     friend istream& operator>>(istream&, Data&);

     Data(int zi=0, char *luna=NULL, int an=0){
        this->zi=zi;
        if (luna != NULL)
            {this->luna=new char[strlen(luna)];
             strcpy(this->luna,luna);}
        else
             this->luna=luna;
             this->an=an;
     }

     Data(const Data& d){
        this->zi=d.zi;
        this->luna=new char[strlen(d.luna)];
        strcpy(this->luna,d.luna);
        this->an=d.an;
     }


     Data& operator=(const Data &data){
        if(this==&data)
                return *this;

        this->zi=data.zi;
        this->luna=new char[strlen(data.luna)];
        strcpy(this->luna,data.luna);
        this->an=data.an;
        return *this;
    }


     int no_month(){
        if(strcmp(luna,"ianuarie")==0) return 1;
        if(strcmp(luna,"februarie")==0) return 2;
        if(strcmp(luna,"martie")==0) return 3;
        if(strcmp(luna,"aprilie")==0) return 4;
        if(strcmp(luna,"mai")==0) return 5;
        if(strcmp(luna,"iunie")==0) return 6;
        if(strcmp(luna,"iulie")==0) return 7;
        if(strcmp(luna,"august")==0) return 8;
        if(strcmp(luna,"septembrie")==0) return 9;
        if(strcmp(luna,"octombrie")==0) return 10;
        if(strcmp(luna,"noiembrie")==0) return 11;
        return 12;
    }


    int leap_year(){
        if( (an%4==0 && an%100!=0) || an%400==0)
            return 1;
        return 0;
    }


    void set_zi(int zi)
        {this->zi=zi;}

    void set_luna(const char *luna)
        {this->luna=new char[strlen(luna)];
         strcpy(this->luna,luna);}

    void set_an(int an)
        {this->an=an;}

    int get_zi()
        {return this->zi;}

    char* get_luna()
        {return this->luna;}

    int get_an()
        {return this->an;}

    int get_difference(Data d){
         int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
         long int n1=0,n2=0;

         n1=this->an*365+this->zi+this->leap_year();
         for(int i=0;i<this->no_month()-1;i++)
                n1+=monthDays[i];

         n2=d.get_an()*365+d.get_zi()+d.leap_year();
         for(int i=0;i<d.no_month()-1;i++)
                n2+=monthDays[i];
         return n1-n2;
    }

    ~Data(){
         this->zi=0;
         delete this->luna;
         this->an=0;

        }

};

    void Data::citire(istream &in){
        int x,y;
        char luna[256];

        while(true){
            cout<<"\tZi: "; in>>x;
            try{
                if(x<1 || x>31) throw 1;
                break;
            }
            catch(int i)
                {cout<<"Eroare constructor, o luna are intre 1 si 31 de zile.\n";}
        }
        this->zi=x;

        cout<<"\tLuna: ";
        in>>luna;
        this->luna=new char[strlen(luna)];
        strcpy(this->luna,luna);

        while(true){
            cout<<"\tAn: "; in>>y;
            try{
                if(y<1900 || y>2100) throw 1;
                break;
            }
            catch(int i)
                {cout<<"Introduceti un an valid\n";}
        }
        this->an=y;
    }


    void Data::afisare(ostream &out){
        out<<"\nZi: "<<this->zi<<"\n";
        out<<"Luna: "<<this->luna<<"\n";
        out<<"An: "<<this->an<<"\n";
    }


    istream& operator>>(istream& in,Data& d){
        d.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Data& d){
        d.afisare(out);
        return out;
    }


///---------------------------------------------------

class Angajat
{protected:
    string nume,prenume;
    float salariu;
    Data data_angajare;
    static int n;
 public:
     virtual void citire(istream &in);
     virtual void afisare(ostream &out);
     friend ostream& operator<<(ostream&, Angajat&);
     friend istream& operator>>(istream&, Angajat&);
     static void numarObiecte(){ cout<<"Numar angajati: "<<n<<"\n";
                                 cout<<"--------------------------\n";}
     virtual ~Angajat();
     virtual string pozitie()
        {return "angajat";}
     virtual float Prima(float prima)
        { return prima;}


     Angajat(string nume="",string prenume="",float salariu=0,Data data_angajare=Data(0,"0",0)){
        n=n+1;
        this->nume=nume;
        this->prenume=prenume;
        this->salariu=salariu;
        this->data_angajare=data_angajare;
       }

     Angajat(const Angajat& a){
        this->nume=a.nume;
        this->prenume=a.prenume;
        this->data_angajare=a.data_angajare;
    }

     Angajat& operator=(const Angajat &angajat){
        if(this==&angajat)
            return *this;

        this->nume=angajat.nume;
        this->prenume=angajat.prenume;
        this->salariu=angajat.salariu;
        this->data_angajare=angajat.data_angajare;
        return *this;
    }

     void set_nume(string nume)
        {this->nume=nume;}

     void set_prenume(string prenume)
        {this->prenume=prenume;}

     void set_data(Data data_angajare)
        {this->data_angajare=data_angajare;}

     string get_nume()
        {return this->nume;}

     string get_prenume()
        {return this->prenume;}

     Data get_data()
        {return this->data_angajare;}
};

int Angajat::n;
Angajat::~Angajat(){}

    void Angajat::citire(istream &in){
        string x,y;
        float f;
        Data d;
        cout<<"Nume: "; in>>x;
        this->nume=x;
        cout<<"Prenume: "; in>>y;
        this->prenume=y;
        cout<<"Salariu: "; in>>f;
        this->salariu=f;
        cout<<"Data angajare:\n"; in>>d;
        this->data_angajare=d;
    }

    istream& operator>>(istream& in,Angajat& a){
        a.citire(in);
        return in;
    }

    void Angajat::afisare(ostream &out){
        out<<"Nume: "<<this->nume<<"\n";
        out<<"Prenume: "<<this->prenume<<"\n";
        out<<"Salariu: "<<this->salariu<<"\n";
        out<<"Data angajare: "<<this->data_angajare.get_zi()<<" "<<this->data_angajare.get_luna()<<" "<<this->data_angajare.get_an()<<"\n";
    }

    ostream& operator<<(ostream& out, Angajat& a){
        a.afisare(out);
        return out;
    }


///---------------------------------------------------

class Part_Time:public Angajat
{private:
    int nr_ore_zi;
    Data final_contract;
 public:
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Part_Time&);
    friend ostream& operator<<(ostream&, Part_Time&);
    string pozitie()
        {return "part_time";}

    float Prima(float prima){
        Data fin(31,"decembrie",2020);
        if(fin.get_difference(final_contract)>0)
            return 75*prima/100;
        return prima;
    }

    Part_Time(string nume="",string prenume="",float salariu=0,Data data_angajare=Data(0,"0",0),
                        int nr_ore_zi=0,Data final_contract=Data(0,"0",0)):Angajat(nume,prenume,salariu,data_angajare){
        this->nr_ore_zi=nr_ore_zi;
        this->final_contract=final_contract;
    }

    Part_Time(const Part_Time &part_time):Angajat(part_time){
        this->nr_ore_zi=part_time.nr_ore_zi;
        this->final_contract=part_time.final_contract;
    }

    Part_Time& operator=(const Part_Time &part_time){
        if(this==&part_time)
            return *this;
        Angajat::operator=(part_time);
        this->nr_ore_zi=part_time.nr_ore_zi;
        this->final_contract=part_time.final_contract;
        return *this;
    }

    void set_final_contract(Data final_contract)
        {this->final_contract=final_contract;}

    void set_nr_ore_zi(int nr_ore_zi)
        {this->nr_ore_zi=nr_ore_zi;}

    Data get_final_contract()
        {return this->final_contract;}

    int get_nr_ore_zi()
        {return this->nr_ore_zi;}


    ~Part_Time(){}
};

    void Part_Time::citire(istream &in){
        Angajat::citire(in);
        cout<<"Numar ore/zi: ";
        in>>this->nr_ore_zi;
        cout<<"Final contract:\n";
        in>>this->final_contract;

    }

    void Part_Time::afisare(ostream &out){
        Angajat::afisare(out);
        out<<"Numar ore/zi: "<<this->nr_ore_zi<<"\n";
        out<<"Final contract: "<<this->final_contract.get_zi()<<" "<<this->final_contract.get_luna()<<" "<<this->final_contract.get_an()<<"\n";

    }

    istream& operator>>(istream& in,Part_Time& p){
        p.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Part_Time& p){
        p.afisare(out);
        return out;
    }


///---------------------------------------------------

class Permanent:public Angajat
{private:
    int nr_minori_intretinere;
 public:
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Permanent&);
    friend ostream& operator<<(ostream&, Permanent&);
    string pozitie()
        {return "permanent";}
    float Prima(float prima){
        Data fin(31,"decembrie",2020);
        int vechime=int(fin.get_difference(data_angajare)/365);
        return prima+prima*vechime*nr_minori_intretinere/100;
    }

    Permanent(string nume="",string prenume="",float salariu=0,Data data_angajare=Data(0,"0",0),
                        int nr_minori_intretinere=0):Angajat(nume,prenume,salariu,data_angajare)
        {this->nr_minori_intretinere=nr_minori_intretinere;}


    Permanent(const Permanent &permanent):Angajat(permanent)
        {this->nr_minori_intretinere=permanent.nr_minori_intretinere;}

    Permanent& operator=(const Permanent &permanent){
        if(this==&permanent)
            return *this;
        Angajat::operator=(permanent);
        this->nr_minori_intretinere=permanent.nr_minori_intretinere;
        return *this;
    }

    void set_nr_minori_intretinere(int nr_minori_intretinere)
        {this->nr_minori_intretinere=nr_minori_intretinere;}

    int get_nr_minori_intretinere()
        {return this->nr_minori_intretinere;}

    ~Permanent(){}
};

    void Permanent::citire(istream &in){
        Angajat::citire(in);
        cout<<"Numar minori intretinere: ";
        in>>this->nr_minori_intretinere;
    }

    void Permanent::afisare(ostream &out){
        Angajat::afisare(out);
        out<<"Numar minori intretinere: "<<this->nr_minori_intretinere<<"\n";

    }

    istream& operator>>(istream& in,Permanent& p){
        p.citire(in);
        return in;
    }

    ostream& operator<<(ostream& out, Permanent& p){
        p.afisare(out);
        return out;
    }

///---------------------------------------------------




    void tip(Angajat *&a) {
        string s;
        while(true){
            cout<<"\nIntroduceti tipul angajatului(part_time/permanent): ";
            cin>>s;
            try{
                if(s=="part_time"){
                    a=new Part_Time;
                    cin>>*a;
                    break;
                }
                else
                    if(s=="permanent"){
                        a=new Permanent;
                        cin>>*a;
                        break;
                    }
                    else
                        throw 10;
            }


            catch(int j)
                {cout<<"Nu ati introdus un tip valid. Incercati part_time sau permanent.\n ";}
        }
    }


void meniu(){
    cout << endl<<"-------- MENIU ---------" << endl
         << "1. Citeste angajatii " << endl
         << "2. Citeste prima de baza"<<endl
         << "3. Afiseaza angajatii"<<endl
         << "4. Afiseaza numarul de angajati" << endl
         << "5. Afiseaza angajatii+prima fiecaruia"<<endl
         << "6. Exit\n\n" << endl
         << "Insereaza actiune: ";
}


int main()
{Angajat **angajati;
 int i,n,choice,vizitat[100]={0};
 float prima=0;
 cout<<"Lunile se vor citi cu litere mici(ex:ianuarie,februarie etc...)\n";
 cout<<"Cititi cati angajati vreti sa aveti: ";
 cin>>n;
 angajati=new Angajat*[n];


 do{
  meniu();
  cin>>choice;
  switch(choice){
    case 1:
        for(i=0;i<n;i++)
            {tip(angajati[i]);
             vizitat[i]=1;}
        cout<<"\n--------------------------\n";
        break;

    case 2:
        cout<<"Citeste prima de baza: "; cin>>prima;
        cout<<"\n--------------------------\n";
        break;

    case 3:
        for(int i=0;i<n;i++)
            if(vizitat[i]==1){
                cout<<"\nTipul angajatului: "<<angajati[i]->pozitie()<<"\n"<<*angajati[i];
                cout<<"--------------------------\n";
                }
        break;
    case 4:
        Angajat::numarObiecte();
        break;
    case 5:
        for(int i=0;i<n;i++)
            if(vizitat[i]==1){
                cout<<"\nTipul angajatului: "<<angajati[i]->pozitie()<<"\n"<<*angajati[i];
                cout<<"Prima: "<<angajati[i]->Prima(prima)<<"\n";
            }
        break;
    case 6:
        break;
    default:
        cout<<"Actiune invalida"<<endl;
            break;
       }
  }while(choice!=6);


    ///downcast//
    cout<<"\nDowncast: part_time->angajat\n";
    Part_Time *a=(Part_Time*)new Angajat;
    cin>>*a;
    cout<<"\n";

    cout<<"\nDowncast: permanent->angajat\n";
    Permanent *b=(Permanent*)new Angajat;
    cin>>*b;
    cout<<"\n";

    cout<<a->pozitie()<<"\n"<<*a;
    cout<<endl;
    cout<<b->pozitie()<<"\n"<<*b;

    delete a;
    delete b;

    for(i=0;i<n;i++)
        delete angajati[i];



return 0;
}
