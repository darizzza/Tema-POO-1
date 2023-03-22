#include <bits/stdc++.h>
using namespace std;

class Produs
{private:
    static int contorIdProdus;
    const int idProdus;
    char *numeProdus;
    string tipProdus;
    char culoareProdus;
    int nrMateriale;
    int *cantitateMateriale;
    double pret;
    bool spalabil;

public:
    ///Constructori
    Produs(); ///Constructorul fara pareametrii
    Produs(char *numeProdus, string tipProdus, char culoareProdus, int nrMateriale, int *cantitateMateriale, double pret, bool spalabil);///Constructorul cu toti parametrii
    Produs(char *numeProdus,string tipProdus);///Constructor cu 2 parametrii
    Produs(const Produs& objProdus);///Constructorul de copiere

    ///Operatori
    Produs& operator=(const Produs&);///Operatorul de atribuire
    friend ostream& operator <<(ostream& out, const Produs& objProdus);///Operatorul << de afisare
    friend istream& operator >>(istream& in, Produs& obj);///Operatorul >> de citire
    Produs& operator++();
    Produs operator++(int);
    Produs& operator--();
    Produs operator--(int);
    Produs operator+(const Produs& objProdus);
    Produs operator+(int);
    friend Produs operator+(int, Produs objProdus);
    Produs operator-(const Produs& objProdus);
    Produs operator-(int);
    friend Produs operator-(int, Produs objProdus);
    bool operator<(const Produs&);
    bool operator==(const Produs&);
    int operator[](int);
    operator int();
    operator int() const {return this->nrMateriale;}

    ///Metode
    void afisare();
    void citire();

    ///GET+SET
    static int getContorIdProdus(){return Produs::contorIdProdus;}
    string getTipProdus(){return Produs::tipProdus;}
    int getNrMateriale(){return Produs::nrMateriale;}
    double getPret(){return Produs::pret;}
    const int* getCantitateMateriale()const {this->cantitateMateriale;}
    friend void afisare2(const Produs& objProdus);

    ///Destructor
    ~Produs();
};

int Produs::contorIdProdus = 10;

///Constructor implicit care initializeaza datele clasei cu valori implicite
Produs::Produs():idProdus(contorIdProdus++)
{numeProdus=new char[strlen("Anonim")+1];
strcpy(numeProdus, "Anonim");
tipProdus="Anonim";
culoareProdus='-';
nrMateriale=0;
cantitateMateriale=NULL;
pret=0.0;
spalabil=false;
}

///Constructorul cu toti parametri, care atribuie valorile primite datelor din clasa
Produs::Produs(char* numeProdus,string tipProdus,char culoareProdus,int nrMateriale,int *cantitateMateriale,double pret,bool spalabil):idProdus(contorIdProdus++)
{this->numeProdus=new char[strlen(numeProdus)+1];
strcpy(this->numeProdus, numeProdus);
this->tipProdus=tipProdus;
this->culoareProdus=culoareProdus;
this->nrMateriale=nrMateriale;
this->cantitateMateriale=new int[nrMateriale];
for(int i=0;i<nrMateriale;i++)
    this->cantitateMateriale[i]=cantitateMateriale[i];
this->pret=pret;
this->spalabil=spalabil;
}

///Constructorul cu 2 parametrii, care atribuie valorile primite doar pentru numele si tipul produsului, iar in rest seteaza cu valori implicite
Produs::Produs(char *numeProdus,string tipProdus):idProdus(contorIdProdus++)
{this->numeProdus=new char[strlen(numeProdus)+1];
strcpy(this->numeProdus, numeProdus);
this->tipProdus=tipProdus;
culoareProdus='-';
nrMateriale=0;
cantitateMateriale=NULL;
pret=0.0;
spalabil=false;
}

///Constructorul de copiere
Produs::Produs(const Produs& objProdus): idProdus(objProdus.idProdus)
{this->numeProdus=new char[strlen(objProdus.numeProdus)+1];
strcpy(this->numeProdus,objProdus.numeProdus);
this->tipProdus=objProdus.tipProdus;
this->culoareProdus=objProdus.culoareProdus;
this->nrMateriale=objProdus.nrMateriale;
this->cantitateMateriale=new int[objProdus.nrMateriale];
for(int i=0;i<objProdus.nrMateriale;i++)
    this->cantitateMateriale[i]=objProdus.cantitateMateriale[i];
this->pret=objProdus.pret;
this->spalabil=objProdus.spalabil;
}

///Supraincarcarea operatorului =
Produs& Produs::operator=(const Produs& objProdus)
{if(this != &objProdus)
    {if(this->numeProdus!=NULL)
        {delete[] this->numeProdus;
        this->numeProdus=NULL;
        }
    this->numeProdus=new char[strlen(objProdus.numeProdus)+1];
    strcpy(this->numeProdus,objProdus.numeProdus);
    this->tipProdus=objProdus.tipProdus;
    this->culoareProdus=objProdus.culoareProdus;
    this->nrMateriale=objProdus.nrMateriale;
    if(this->cantitateMateriale!=NULL)
        {delete[] this->cantitateMateriale;
        cantitateMateriale=NULL;
        }
    this->cantitateMateriale=new int[objProdus.nrMateriale];
    for(int i=0;i<objProdus.nrMateriale;i++)
        this->cantitateMateriale[i]=objProdus.cantitateMateriale[i];
    this->pret=objProdus.pret;
    this->spalabil=objProdus.spalabil;
    }
return *this;
}


///Supraincarcarea operatorului >>
istream& operator>>(istream& in, Produs& objProdus)
{cout<<"Introduceti numele produsului: "<<endl;
char numeProdus[100];
in>>numeProdus;
if(objProdus.numeProdus!=NULL)
    {delete objProdus.numeProdus;
    objProdus.numeProdus=NULL;
    }
objProdus.numeProdus=new char[strlen(numeProdus)+1];
strcpy(objProdus.numeProdus,numeProdus);

cout<<"Introduceti tipul produsului: "<<endl;
in>>objProdus.tipProdus;

cout<<"Introduceti culoarea produsului: "<<endl;
in>>objProdus.culoareProdus;

cout<<"Introduceti numarul de materiale ale produsului: "<<endl;
in>>objProdus.nrMateriale;

cout<<"Introduceti cantitatea de materiale: "<<endl;
if(objProdus.cantitateMateriale!=NULL)
    {delete[] objProdus.cantitateMateriale;
    objProdus.cantitateMateriale=NULL;
    }
objProdus.cantitateMateriale=new int[objProdus.nrMateriale];
for(int i=0;i<objProdus.nrMateriale;i++)
    in>>objProdus.cantitateMateriale[i];

cout<<"Introduceti pretul produsului: "<<endl;
in>>objProdus.pret;

cout<<"Introduceti daca produsul se poate spala: "<<endl;
in>>objProdus.spalabil;
return in;
}

///Supraincarcarea operatorului <<
ostream& operator<<(ostream& out, const Produs& objProdus)
{out<<"ID: "<<objProdus.idProdus<<endl;
out<<"Nume: "<<objProdus.numeProdus<<endl;
out<<"Tip produs: "<<objProdus.tipProdus<<endl;
out<<"Culoare produs: "<<objProdus.culoareProdus<<endl;
out<<"Numarul materialelor: "<<objProdus.nrMateriale<<endl;
out<<"Cantitatea de materiale: ";
for(int i=0;i<objProdus.nrMateriale;i++)
    out<<objProdus.cantitateMateriale[i]<<" ";
out<<endl;
out<<"Pret: "<<objProdus.pret<<endl;
out<<"Se poate spala: "<<objProdus.spalabil<<endl;
return out;
}

///Supraincarcarea operatorului ++
Produs& Produs::operator++()
{this->nrMateriale++; return *this;}

Produs Produs::operator++(int)
{Produs aux(*this); ++*this; return aux;}

///Supraincarcarea operatorului --
Produs& Produs::operator--()
{this->nrMateriale--; return *this;}

Produs Produs::operator--(int)
{Produs aux(*this); --*this; return aux;}

///Supraincarcarea operatorului +
Produs Produs::operator+(const Produs& objProdus)
{Produs aux(*this);
aux.tipProdus+=objProdus.tipProdus;
aux.nrMateriale+=objProdus.nrMateriale;
return aux;
}

Produs Produs::operator+(int x)
{Produs aux(*this);
aux.nrMateriale+=x;
return aux;
}

Produs operator+(int x, Produs objProdus)
{return objProdus+x;}

///Supraincarcarea operatorului -
Produs Produs::operator-(const Produs& objProdus)
{Produs aux(*this);
aux.nrMateriale-=objProdus.nrMateriale;
return aux;
}

Produs Produs::operator-(int x)
{Produs aux(*this);
aux.nrMateriale-=x;
return aux;
}

Produs operator-(int x, Produs objProdus)
{return objProdus-x;}

///Supraincarcarea operatorului <
bool Produs::operator<(const Produs& objProdus)
{return this->pret<objProdus.pret;}

///Supraincarcarea operatorului ==
bool Produs::operator==(const Produs& objProdus)
{return this->tipProdus==objProdus.tipProdus;}

///Supraincarcarea operatorul de indexare []
int Produs::operator[](int i)
{if(this->cantitateMateriale==NULL)
    throw runtime_error("Nu exista elemente in vector!");
if(i<0||i>this->nrMateriale)
    throw runtime_error("Index invalid!");
else return this->cantitateMateriale[i];
}

///Supraincarcarea operatorul cast
Produs::operator int()
{return this->nrMateriale;}

///Destructor
Produs::~Produs()
{if(this->numeProdus!=NULL)
    {delete[] this->numeProdus;
    this->numeProdus=NULL;
    }
if(this->cantitateMateriale!=NULL)
    {delete[] this->cantitateMateriale;
    cantitateMateriale=NULL;
    }
}

class Designer
{private:
    static int contorIdDesigner;
    const int idDesigner;
    char* numeDesigner;
    char* casaDeModa;
    string nationalitate;
    char sexDesigner;
    int varstaDesigner;
    float venitDesigner;
    bool decedat;
    int* colectiiScoasePeAn;

public:
    ///Constructori
    Designer();///Constructor fara parametrii
    Designer(char* numeDesigner, char* casaDeModa, string nationalitate, char sexDesigner, int varstaDesigner, float venitDesigner, bool decedat, int* colectiiScoasePeAn);///Constructorul cu toti parametrii
    Designer(char* numeDesigner, char*casaDeModa, int varstaDesigner);///Constructor cu 3 parametrii
    Designer(const Designer& objDesigner);///Constructorul de copiere

    ///Operatori
    Designer&operator=(const Designer&);///Operatorul =
    friend ostream& operator <<(ostream& out, const Designer& objDesigner);///Operatorul << de afisare
    friend istream& operator >>(istream& in, Designer& obj);///Operatorul >> de citire
    Designer& operator++();
    Designer operator++(int);
    Designer operator+(const Designer& objDesigner);
    Designer operator+(int);
    friend Designer operator+(int, Designer objDesigner);
    Designer operator-(const Designer& objDesigner);
    Designer operator-(int);
    friend Designer operator-(int, Designer objDesigner);
    bool operator>(const Designer&);
    bool operator==(const Designer&);
    int operator[](int);
    operator int();
    operator int() const {return this->varstaDesigner;}


    ///Metode
    void afisare();
    void citire();

    ///GET+SET
    static int getContorIdDesigner(){return Designer::contorIdDesigner;}
    string getNationalitate(){return Designer::nationalitate;}
    int getVarstaDesigner(){return Designer::varstaDesigner;}
    float getVenitDesigner(){return Designer::venitDesigner;}
    const int* getColectiiScoasePeAn()const {this->colectiiScoasePeAn;}
    friend void afisare2(const Designer& objDesigner);

    ///Destructor
    ~Designer();

};

int Designer::contorIdDesigner = 10;

///Constructorul fara parametrii
Designer::Designer():idDesigner(contorIdDesigner++)
{numeDesigner=new char[strlen("Anonim")+1];
strcpy(numeDesigner,"Anonim");
casaDeModa=new char[strlen("Anonim")+1];
strcpy(casaDeModa,"Anonim");
nationalitate="Anonim";
sexDesigner='-';
varstaDesigner=0;
venitDesigner=0;
colectiiScoasePeAn=NULL;
decedat=false;
}

///Constructorul cu toti parametrii
Designer::Designer(char* numeDesigner,char* casaDeModa,string nationalitate,char sexDesigner,int varstaDesigner,float venitDesigner,bool decedat,int* colectiiScoasePeAn):idDesigner(contorIdDesigner++)
{this->numeDesigner=new char[strlen(numeDesigner)+1];
strcpy(this->numeDesigner,numeDesigner);
this->casaDeModa=new char[strlen(casaDeModa)+1];
strcpy(this->casaDeModa,casaDeModa);
this->nationalitate=nationalitate;
this->sexDesigner=sexDesigner;
this->varstaDesigner=varstaDesigner;
this->venitDesigner=venitDesigner;
this->decedat=decedat;
this->colectiiScoasePeAn=new int[12];
for(int i=0;i<12;i++)
    this->colectiiScoasePeAn[i]=colectiiScoasePeAn[i];

}

///Constructorul cu 3 parametrii
Designer::Designer(char* numeDesigner, char*casaDeModa, int varstaDesigner):idDesigner(contorIdDesigner++)
{this->numeDesigner=new char[strlen(numeDesigner)+1];
strcpy(this->numeDesigner,numeDesigner);
this->casaDeModa=new char[strlen(casaDeModa)+1];
strcpy(this->casaDeModa,casaDeModa);
nationalitate="Anonim";
sexDesigner='-';
this->varstaDesigner=varstaDesigner;
venitDesigner=0;
decedat=false;
colectiiScoasePeAn=NULL;
}

///Constructorul de copiere
Designer::Designer(const Designer& objDesigner): idDesigner(objDesigner.idDesigner)
{this->numeDesigner=new char[strlen(objDesigner.numeDesigner)+1];
strcpy(this->numeDesigner,objDesigner.numeDesigner);
this->casaDeModa=new char[strlen(objDesigner.casaDeModa)+1];
strcpy(this->casaDeModa,objDesigner.casaDeModa);
this->nationalitate=objDesigner.nationalitate;
this->sexDesigner=objDesigner.sexDesigner;
this->varstaDesigner=objDesigner.varstaDesigner;
this->venitDesigner=objDesigner.venitDesigner;
this->decedat=objDesigner.decedat;
this->colectiiScoasePeAn=new int[12];
for(int i=0;i<12;i++)
    this->colectiiScoasePeAn[i]=objDesigner.colectiiScoasePeAn[i];
}

///Supraincarcarea operatorului =
Designer& Designer::operator=(const Designer& objDesigner)
{if(this != &objDesigner)
    {if(this->numeDesigner!=NULL)
        {delete[] this->numeDesigner;
        this->numeDesigner=NULL;
        }
    this->numeDesigner=new char[strlen(objDesigner.numeDesigner)+1];
    strcpy(this->numeDesigner,objDesigner.numeDesigner);
    if(this->casaDeModa!=NULL)
        {delete[] this->casaDeModa;
        this->casaDeModa=NULL;
        }
    this->casaDeModa=new char[strlen(objDesigner.casaDeModa)+1];
    strcpy(this->casaDeModa,objDesigner.casaDeModa);
    this->nationalitate=objDesigner.nationalitate;
    this->sexDesigner=objDesigner.sexDesigner;
    this->varstaDesigner=objDesigner.varstaDesigner;
    this->venitDesigner=objDesigner.venitDesigner;
    this->decedat=objDesigner.decedat;
    if(this->colectiiScoasePeAn !=NULL)
        {delete[] this->colectiiScoasePeAn;
        colectiiScoasePeAn=NULL;
        }
    this->colectiiScoasePeAn=new int[12];
    for(int i=0;i<12;i++)
        this->colectiiScoasePeAn[i]=objDesigner.colectiiScoasePeAn[i];
    }
return *this;
}


///Supraincarcarea operatorului >>
istream& operator>>(istream& in,Designer& objDesigner)
{cout<<"Introduceti numele Designer-ului: "<<endl;
char numeDesigner[100];
in>>numeDesigner;
if(objDesigner.numeDesigner!=NULL)
    {delete objDesigner.numeDesigner;
    objDesigner.numeDesigner=NULL;
    }
objDesigner.numeDesigner=new char[strlen(numeDesigner)+1];
strcpy(objDesigner.numeDesigner,numeDesigner);

cout<<"Introduceti casa de moda a designer-ului: "<<endl;
char casaDeModa[100];
in>>casaDeModa;
if(objDesigner.casaDeModa!=NULL)
    {delete objDesigner.casaDeModa;
    objDesigner.casaDeModa=NULL;
    }
objDesigner.casaDeModa=new char[strlen(casaDeModa)+1];
strcpy(objDesigner.casaDeModa,casaDeModa);

cout<<"Introduceti nationalitatea designer-ului: "<<endl;
in>>objDesigner.nationalitate;

cout<<"Introduceti sexul designer-ului: "<<endl;
in>>objDesigner.sexDesigner;

cout<<"Introduceti varsta desiger-ului: "<<endl;
in>>objDesigner.varstaDesigner;

cout<<"Introduceti venitul designer-ului: "<<endl;
in>>objDesigner.venitDesigner;

cout<<"Introduceti daca designer-ul este decedat: "<<endl;
in>>objDesigner.decedat;

cout<<"Introduceti colectiile scoase in ultimul an: "<<endl;
if(objDesigner.colectiiScoasePeAn!=NULL)
    {delete[] objDesigner.colectiiScoasePeAn;
    objDesigner.colectiiScoasePeAn=NULL;
    }
objDesigner.colectiiScoasePeAn=new int[12];
for(int i=0;i<12;i++)
    in>>objDesigner.colectiiScoasePeAn[i];
return in;
}

///Supraincarcarea operatorului <<
ostream& operator<<(ostream& out, const Designer& objDesigner)
{out<<"ID: "<<objDesigner.idDesigner<<endl;
out<<"Nume: "<<objDesigner.numeDesigner<<endl;
out<<"Casa de moda: "<<objDesigner.casaDeModa<<endl;
out<<"Nationalitate: "<<objDesigner.nationalitate<<endl;
out<<"Sexul: "<<objDesigner.sexDesigner<<endl;
out<<"Varsta: "<<objDesigner.varstaDesigner<<endl;
out<<"Venit: "<<objDesigner.venitDesigner<<endl;
out<<"Decedat: "<<objDesigner.decedat<<endl;
out<<"Colectiile scoase pe an: ";
for(int i=0;i<12;i++)
    out<<objDesigner.colectiiScoasePeAn[i]<<" ";
out<<endl;
return out;
}

///Supraincarcarea operatorului ++
Designer& Designer::operator++()
{this->varstaDesigner++; return *this;}

Designer Designer::operator++(int)
{Designer aux(*this); ++*this; return aux;}

///Supraincarcarea operatorului +
Designer Designer::operator+(const Designer& objDesigner)
{Designer aux(*this);
aux.nationalitate+=objDesigner.nationalitate;
aux.varstaDesigner+=objDesigner.varstaDesigner;
return aux;
}

Designer Designer::operator+(int x)
{Designer aux(*this);
aux.varstaDesigner+=x;
return aux;
}

Designer operator+(int x, Designer objDesigner)
{return objDesigner+x;}

///Supraincarcarea operatorului -
Designer Designer::operator-(const Designer& objDesigner)
{Designer aux(*this);
aux.varstaDesigner-=objDesigner.varstaDesigner;
return aux;
}

Designer Designer::operator-(int x)
{Designer aux(*this);
aux.varstaDesigner-=x;
return aux;
}

Designer operator-(int x, Designer objDesigner)
{return objDesigner-x;}

///Supraincarcarea operatorului>
bool Designer::operator>(const Designer& objDesigner)
{return this->varstaDesigner>objDesigner.varstaDesigner;}

///Supraincarcarea operatorului ==
bool Designer::operator==(const Designer& objDesigner)
{return this->casaDeModa==objDesigner.casaDeModa;}

///Supraincarcarea operatorului []
int Designer::operator[](int i)
{if(this->colectiiScoasePeAn==NULL)
    throw runtime_error("Nu exista elemente in vector");
if(i<0||i>=12)
    throw runtime_error("Index invalid");
else return this->colectiiScoasePeAn[i];
}

///Supraincarcarea operatorului cast
Designer::operator int()
{return this->varstaDesigner;}

///Destructor
Designer::~Designer()
{if(this->numeDesigner!=NULL)
    {delete[] this->numeDesigner;
    this->numeDesigner=NULL;
    }
if(this->casaDeModa!=NULL)
    {delete[] this->casaDeModa;
    this->casaDeModa=NULL;
    }
if(this->colectiiScoasePeAn!=NULL)
    {delete[] this->colectiiScoasePeAn;
    this->colectiiScoasePeAn=NULL;
    }
}

class Comanda
{private:
    static int contorIdComanda;
    const int idComanda;
    char* numeClient;
    int nrProduse;
    int* produse;
    float costProduse;
    bool discount;

public:
    ///Constructor
    Comanda();///Fara parametri
    Comanda(char* numeClient, int nrProduse, int* produse, float costProduse, bool discount);///Cu toti parametrii
    Comanda(char* numeClient, int nrProduse);///Cu 2 parametrii
    Comanda(const Comanda& objComanda);///De copiere

    ///Operatori
    Comanda& operator=(const Comanda&);
    friend ostream& operator <<(ostream& out, const Comanda& objComanda);
    friend istream& operator >>(istream& in, Comanda& objComanda);
    Comanda& operator++();
    Comanda operator++(int);
    Comanda operator+(const Comanda& objComanda);
    Comanda operator+(int);
    friend Comanda operator+(int, Comanda objComanda);
    Comanda operator-(const Comanda& objComanda);
    Comanda operator-(int);
    friend Comanda operator-(int, Comanda objComanda);
    bool operator<=(const Comanda&);
    bool operator==(const Comanda&);
    int operator[](int);
    operator int();
    operator int() const {return this->nrProduse;}

    ///Metode
    void afisare();
    void citire();

    ///GET+SET
    static int getContorIdComamnda(){return Comanda::contorIdComanda;}
    int getNrProduse(){return Comanda::nrProduse;}
    float getCostProduse(){return Comanda::costProduse;}
    const int* getProduse()const {this->produse;}
    friend void afisare2(const Comanda& objComanda);

    ///Destructor
    ~Comanda();
};

int Comanda::contorIdComanda= 1000;

///Constructorul fara parametri
Comanda::Comanda():idComanda(contorIdComanda++)
{numeClient=new char[strlen("Anonim")+1];
strcpy(numeClient,"Anonim");
nrProduse=0;
produse=NULL;
costProduse=0;
discount=false;
}

///Constructorul cu toti parametrii
Comanda::Comanda(char* numeClient,int nrProduse,int* produse,float costProduse,bool discount):idComanda(contorIdComanda++)
{this->numeClient=new char[strlen(numeClient)+1];
strcpy(this->numeClient,numeClient);
this->nrProduse=nrProduse;
this->produse=new int[nrProduse];
for(int i=0;i<nrProduse;i++)
    this->produse[i]=produse[i];
this->costProduse=costProduse;
this->discount=discount;
}

///Constructorul cu 2 parametrii
Comanda::Comanda(char* numeClient,int nrProduse):idComanda(contorIdComanda++)
{this->numeClient=new char[strlen(numeClient)+1];
strcpy(this->numeClient,numeClient);
this->nrProduse=nrProduse;
produse=NULL;
costProduse=0.0;
discount=false;
}

///Constructorul de copiere
Comanda::Comanda(const Comanda& objComanda):idComanda(objComanda.idComanda)
{this->numeClient=new char[strlen(objComanda.numeClient)+1];
strcpy(this->numeClient,objComanda.numeClient);
this->nrProduse=objComanda.nrProduse;
this->produse=new int[objComanda.nrProduse];
for(int i=0;i<objComanda.nrProduse;i++)
    this->produse[i]=objComanda.produse[i];
this->costProduse=objComanda.costProduse;
this->discount=objComanda.discount;
}

///Supraincarcarea operatorului =
Comanda& Comanda::operator=(const Comanda& objComanda)
{if(this!= &objComanda)
    {if(this->numeClient!=NULL)
        {delete[] this->numeClient;
        numeClient=NULL;
        }
    this->numeClient=new char[strlen(objComanda.numeClient)+1];
    strcpy(this->numeClient,objComanda.numeClient);
    this->nrProduse=objComanda.nrProduse;
    if(this->produse!=NULL)
        {delete[] this->produse;
        produse=NULL;
        }
    this->produse=new int[objComanda.nrProduse];
    for(int i=0;i<objComanda.nrProduse;i++)
        this->produse[i]=objComanda.produse[i];
    this->costProduse=objComanda.costProduse;
    this->discount=objComanda.discount;
    }
return *this;
}

///Supraincarcarea operatorului >>
istream& operator>>(istream& in, Comanda& objComanda)
{cout<<"Introduceti numele clientului: "<<endl;
char numeClient[100];
in>>numeClient;
if(objComanda.numeClient!=NULL)
    {delete objComanda.numeClient;
    objComanda.numeClient=NULL;
    }
objComanda.numeClient=new char[strlen(numeClient)+1];
strcpy(objComanda.numeClient,numeClient);

cout<<"Introduceti numarul de produse: "<<endl;
in>>objComanda.nrProduse;

cout<<"Introduceti produsele: "<<endl;
if(objComanda.produse!=NULL)
    {delete[] objComanda.produse;
    objComanda.produse=NULL;
    }
objComanda.produse=new int[objComanda.nrProduse];
for(int i=0;i<objComanda.nrProduse;i++)
    in>>objComanda.produse[i];

cout<<"Introduceti costul produselor: "<<endl;
in>>objComanda.costProduse;

cout<<"Introduceti daca exista discount: "<<endl;
in>>objComanda.discount;
return in;
}

///Supraincarcarea operatorului <<
ostream& operator<<(ostream& out, const Comanda& objComanda)
{out<<"ID: "<<objComanda.idComanda<<endl;
out<<"Numele clientului: "<<objComanda.numeClient<<endl;
out<<"Numarul de produse: "<<objComanda.nrProduse<<endl;
out<<"Produse: ";
for(int i=0;i<objComanda.nrProduse;i++)
    out<<objComanda.produse[i]<<" ";
out<<endl;
out<<"Costul comenzii: "<<objComanda.costProduse<<endl;
out<<"Discount: "<<objComanda.discount<<endl;
return out;
}

///Supraincarcarea operatorului ++
Comanda& Comanda::operator++()
{this->nrProduse++; return *this;}

Comanda Comanda::operator++(int)
{Comanda aux(*this); ++*this; return aux;}

///Supraincarcarea operatorului +
Comanda Comanda::operator+(const Comanda& objComanda)
{Comanda aux(*this);
aux.nrProduse+=objComanda.nrProduse;
return aux;
}

Comanda Comanda::operator+(int x)
{Comanda aux(*this);
aux.nrProduse+=x;
return aux;
}

Comanda operator+(int x, Comanda objComanda)
{return objComanda+x;}

///Supraincarcarea operatorului -
Comanda Comanda::operator-(const Comanda& objComanda)
{Comanda aux(*this);
aux.nrProduse-=objComanda.nrProduse;
return aux;
}

Comanda Comanda::operator-(int x)
{Comanda aux(*this);
aux.nrProduse-=x;
return aux;
}

Comanda operator-(int x, Comanda objComanda)
{return objComanda-x;}

///Supraincarcarea operatorului <=
bool Comanda::operator<=(const Comanda& objComanda)
{return this->nrProduse<=objComanda.nrProduse;}

///Supraincarcarea operatorului==
bool Comanda::operator==(const Comanda& objComanda)
{return this->numeClient==objComanda.numeClient;}

///Supraincarcarea operatorului []
int Comanda::operator[](int i)
{if(this->produse==NULL)
    throw runtime_error("Nu exista elemente in vector!");
if(i<0||i>this->nrProduse)
    throw runtime_error("Index invalid");
else return this->produse[i];
}

///Supraincarcarea operatorului cast
Comanda::operator int()
{return this->nrProduse;}

///Destructor
Comanda::~Comanda()
{if(this->numeClient!=NULL)
    {delete[] this->numeClient;
    this->numeClient=NULL;
    }
if(this->produse!=NULL)
    {delete[] this->produse;
    this->produse=NULL;
    }
}

class Client
{private:
    static int contorIdClient;
    const int idClient;
    char* numeClient;
    string emailClient;
    char sexClient;
    int varstaClient;
    int nrComenzi;
    int* istoricComenzi;
    float puncteClient;
    bool vipClient;

public:
    ///Constructori
    Client();
    Client(char* numeClient, string emailClient, char sexClient, int varstaClient, int nrComenzi, int* istoricComenzi, float puncteClient, bool vipClient);
    Client(char* numeClient, string emailClient);
    Client(const Client& objClient);

    ///Operatori
    Client& operator=(const Client&);
    friend ostream& operator <<(ostream& out, const Client& obj);
    friend istream& operator >>(istream& in, Client& objClient);
    Client& operator++();
    Client operator++(int);
    Client operator+(const Client& objClient);
    Client operator+(int);
    friend Client operator+(int, Client objClient);
    Client operator-(const Client& objClient);
    Client operator-(int);
    friend Client operator-(int, Client objClient);
    bool operator>=(const Client&);
    bool operator==(const Client&);
    int operator[](int);
    operator int();
    operator int() const {return this->nrComenzi;}

    ///Metode
    void afisare();
    void citire();

    ///Get+Set
    static int getContorIdClient(){return Client::contorIdClient;}
    const char* getNumeClient()const{this->numeClient;}
    string getEmailClient(){return Client::emailClient;}
    int getVarstaClient(){return Client::varstaClient;}
    int getNrComenzi(){return Client::nrComenzi;}
    float getPuncteClient(){return Client::puncteClient;}
    const int* getIstoricComenzi()const {this->istoricComenzi;}
    friend void afisare2(const Client& objClient);

    ///Destructori
    ~Client();
};

int Client::contorIdClient = 1000;

///Constructorul fara parametrii
Client::Client():idClient(contorIdClient++)
{numeClient=new char[strlen("Anonim")+1];
strcpy(numeClient,"Anonim");
emailClient="Anonim";
sexClient='-';
varstaClient=0;
nrComenzi=0;
istoricComenzi=NULL;
puncteClient=0;
vipClient=false;
}

///Constructorul cu toti parametrii
Client::Client(char* numeClient,string emailClient,char sexClient,int varstaClient,int nrComenzi,int* istoricComenzi,float puncteClient,bool vipClient):idClient(contorIdClient++)
{this->numeClient=new char[strlen(numeClient)+1];
strcpy(this->numeClient,numeClient);
this->emailClient=emailClient;
this->sexClient=sexClient;
this->varstaClient=varstaClient;
this->nrComenzi=nrComenzi;
this->istoricComenzi=new int[nrComenzi];
for(int i=0;i<nrComenzi;i++)
    this->istoricComenzi[i]=istoricComenzi[i];
this->puncteClient=puncteClient;
this->vipClient=vipClient;
}

///Constructorul cu 2 parametrii
Client::Client(char* numeClient, string emailClient):idClient(contorIdClient++)
{this->numeClient=new char[strlen(numeClient)+1];
strcpy(this->numeClient,numeClient);
this->emailClient=emailClient;
sexClient='-';
varstaClient=0;
nrComenzi=0;
istoricComenzi=NULL;
puncteClient=0.0;
vipClient=false;
}

///Constructorul de copiere
Client::Client(const Client& objClient):idClient(objClient.idClient)
{this->numeClient=new char[strlen(objClient.numeClient)+1];
strcpy(this->numeClient,objClient.numeClient);
this->emailClient=objClient.emailClient;
this->sexClient=objClient.sexClient;
this->varstaClient=objClient.varstaClient;
this->nrComenzi=objClient.nrComenzi;
this->istoricComenzi=new int[objClient.nrComenzi];
for(int i=0;i<objClient.nrComenzi;i++)
    this->istoricComenzi[i]=objClient.istoricComenzi[i];
this->puncteClient=objClient.puncteClient;
this->vipClient=objClient.vipClient;
}

///Supraincarcarea operatorului =
Client& Client::operator=(const Client& objClient)
{if(this !=&objClient)
    {if(this->numeClient!=NULL)
        {delete[] this->numeClient;
        this->numeClient=NULL;
        }
    this->numeClient=new char[strlen(objClient.numeClient)+1];
    strcpy(this->numeClient,objClient.numeClient);
    this->emailClient=objClient.emailClient;
    this->sexClient=objClient.sexClient;
    this->varstaClient=objClient.varstaClient;
    this->nrComenzi=objClient.nrComenzi;
    if(this->istoricComenzi!=NULL)
        {delete[] this->istoricComenzi;
        this->istoricComenzi=NULL;
        }
    this->istoricComenzi=new int[objClient.nrComenzi];
    for(int i=0;i<objClient.nrComenzi;i++)
        this->istoricComenzi[i]=objClient.istoricComenzi[i];
    this->puncteClient=objClient.puncteClient;
    this->vipClient=objClient.vipClient;
    }
}

///Supraincarcarea operatorului >>
istream& operator>>(istream& in,Client& objClient)
{cout<<"Introduceti numele clientului: "<<endl;
char numeClient[100];
in>>numeClient;
if(objClient.numeClient!=NULL)
    {delete objClient.numeClient;
    objClient.numeClient=NULL;
    }
objClient.numeClient=new char[strlen(numeClient)+1];
strcpy(objClient.numeClient,numeClient);

cout<<"Introduceti email-ul clientului: "<<endl;
in>>objClient.emailClient;

cout<<"Introduceti sexul clientului: "<<endl;
in>>objClient.sexClient;

cout<<"Introduceti varsta clientului: "<<endl;
in>>objClient.varstaClient;

cout<<"Introduceti numarul de comenzi: "<<endl;
in>>objClient.nrComenzi;

cout<<"Introduceti istoricul comenzilor: "<<endl;
if(objClient.istoricComenzi!=NULL)
    {delete[] objClient.istoricComenzi;
    objClient.istoricComenzi=NULL;
    }
objClient.istoricComenzi=new int[objClient.nrComenzi];
for(int i=0;i<objClient.nrComenzi;i++)
    in>>objClient.istoricComenzi[i];

cout<<"Introduceti punctele clientului: "<<endl;
in>>objClient.puncteClient;

cout<<"Introduceti daca clientul este V.I.P.: "<<endl;
in>>objClient.vipClient;
return in;
}

///Supraincarcarea operatorului <<
ostream& operator<<(ostream& out, const Client& objClient)
{out<<"ID: "<<objClient.idClient<<endl;
out<<"Nume: "<<objClient.numeClient<<endl;
out<<"Email: "<<objClient.emailClient<<endl;
out<<"Sexul: "<<objClient.sexClient<<endl;
out<<"Varsta: "<<objClient.varstaClient<<endl;
out<<"Numarul de comenzi: "<<objClient.nrComenzi<<endl;
out<<"Istoricul comenzilor: ";
for(int i=0;i<objClient.nrComenzi;i++)
    out<<objClient.istoricComenzi[i]<<" ";
out<<endl;
out<<"Puncte client: "<<objClient.puncteClient<<endl;
out<<"Client VIP: "<<objClient.vipClient<<endl;
return out;
}

///Supraincarcarea operatorului ++
Client& Client::operator++()
{this->nrComenzi++; return *this;}

Client Client::operator++(int)
{Client aux(*this); ++*this; return aux;}

///Supraincarcarea operatorului +
Client Client::operator+(const Client& objClient)
{Client aux(*this);
aux.emailClient+=objClient.emailClient;
aux.nrComenzi+=objClient.nrComenzi;
return aux;
}

Client Client::operator+(int x)
{Client aux(*this);
aux.nrComenzi+=x;
return aux;
}

Client operator+(int x, Client objClient)
{return objClient+x;}

///Supraincarcarea operatorului -
Client Client::operator-(const Client& objClient)
{Client aux(*this);
aux.nrComenzi-=objClient.nrComenzi;
return aux;
}

Client Client::operator-(int x)
{Client aux(*this);
aux.nrComenzi-=x;
return aux;
}

Client operator-(int x, Client objClient)
{return objClient-x;}

///Supraincarcarea operatorului >=
bool Client::operator>=(const Client& objClient)
{return this->nrComenzi>=objClient.nrComenzi;}

///Supraincarcarea operatorului ==
bool Client::operator==(const Client& objClient)
{return this->emailClient==objClient.emailClient;}

///Supraincarcarea operatorului []
int Client::operator[](int i)
{if(this->istoricComenzi==NULL)
    throw runtime_error("Nu exista elemente in vector!");
if(i<0||i>this->nrComenzi)
    throw runtime_error("Index invalid");
else return this->istoricComenzi[i];
}

///Supraincarcarea operatorului cast
Client::operator int()
{return this->nrComenzi;}

///Destructor
Client::~Client()
{if(this->numeClient!=NULL)
    {delete[] this->numeClient;
    this->numeClient=NULL;
    }
if(this->istoricComenzi!=NULL)
    {delete[] this->istoricComenzi;
    this->istoricComenzi=NULL;
    }
}
int main()
{
    int optiune,ct=0;
    Client listaClienti[1000];
    do
    {cout<<"BUN VENIT LA CASA DE MODA!!"<<endl<<endl;
    cout<<"Optiunile pe care le puteti alege:"<<endl;
    cout<<"1. Adaugati un client."<<endl;
    cout<<"2. Stergeti un client."<<endl;
    cout<<"3. Vizualizare date ale unui client"<<endl;
    cout<<"4. Vizualizati toti clientii."<<endl;
    cout<<"5. Iesire."<<endl<<endl;
    cout<<"(Scrieti doar cifra corespunzatoare optiunii, fara alte simboluri)"<<endl;
    cout<<"Optiunea dumneavoastra: ";
    cin>>optiune;

    switch(optiune)
            {case 1:
                {Client x;
                cin>>x;
                listaClienti[ct++]=x;
                cout<<"Client adaugat cu succes!";
                break;
                }
            case 2:
                {char* nume;
                cout<<"Introduceti numele clientului: ";
                cin>>nume;
                bool gasit=false;
                for(int i=0;i<ct&&!gasit;i++)
                    {Client x;
                    x=listaClienti[i];
                    if(strcmp(x.getNumeClient(),nume)==0)
                        {gasit=true;
                        for(int j=i;j<ct;j++)
                            listaClienti[j]=listaClienti[j+1];
                        cout<<"Client eliminat cu succes!"<<endl;
                        }
                    }
                break;
                }
            case 3:
                {if(ct==0){cout<<"Nu exista clienti!"<<endl; break;}
                for(int i=0;i<ct;i++)
                    cout<<listaClienti[i]<<endl;
                break;
                }
            case 4:
                {for(int i=0;i<ct;i++)
                    cout<<listaClienti[i]<<endl;
                break;
                }
            case 5:
                {cout<<"Se initializeaza iesirea...."<<endl;
                break;
                }
            default:
                {cout <<"Incercati una dintre variantele de mai sus!"<< endl;
                break;
                }
            }
        }while(optiune!=5);
    return 0;
}
