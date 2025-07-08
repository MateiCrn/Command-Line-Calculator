#include <iostream>
#include<string>
#include<cmath>
using namespace std;

class Calculator
{
    double numar;
    double* rezultate;
    int nrRezultate;
    string* operatii;
    int nrOperatii;

public:

    Calculator()  // constructor explicit
    {
        this->numar = 0;
        this->nrRezultate = 0;
        this->rezultate = nullptr;
        this->operatii = nullptr;
        this->nrOperatii = 0;

    }
    ~Calculator() //destructor
    {
        delete[]this->rezultate;
        delete[]this->operatii;
        this->rezultate = nullptr;
        this->operatii = nullptr;
    }
    Calculator(const Calculator& c)  //constructor de copiere
    {

        this->numar = c.numar;
        this->nrRezultate = c.nrRezultate;
        this->rezultate = new double[this->nrRezultate];
        for (int i = 0; i < c.nrRezultate; i++)
        {
            this->rezultate[i] = c.rezultate[i];
        }
        this->nrOperatii = c.nrOperatii;
        this->operatii = new string[this->nrOperatii];
        for (int i = 0; i < c.nrOperatii; i++)
        {
            this->operatii[i] = c.operatii[i];
        }


    }
    void operator=(const Calculator& c)
    {

        this->numar = c.numar;
        this->nrRezultate = c.nrRezultate;
        delete[]this->rezultate;
        this->rezultate = new double[this->nrRezultate];
        for (int i = 0; i < c.nrRezultate; i++)
        {
            this->rezultate[i] = c.rezultate[i];
        }
        this->nrOperatii = c.nrOperatii;
        delete[]this->operatii;
        this->operatii = new string[this->nrOperatii];
        for (int i = 0; i < c.nrOperatii; i++)
        {
            this->operatii[i] = c.operatii[i];
        }
    }
    void AdaugareRezultat(double rez)
    {

        if (this->rezultate != nullptr)
        {
            if (this->nrRezultate < 10)
            {
                double* aux = new double[++this->nrRezultate];
                for (int i = 0; i < this->nrRezultate - 1; i++)
                {
                    aux[i] = this->rezultate[i];

                }
                aux[this->nrRezultate - 1] = rez;
                delete[]this->rezultate;

                this->rezultate = aux;
            }
            else
            {
                double* aux = new double[this->nrRezultate];
                for (int i = 0; i < this->nrRezultate - 1; i++)
                {
                    aux[i] = this->rezultate[i + 1];
                }
                aux[this->nrRezultate - 1] = rez;
                delete[]this->rezultate;
                this->rezultate = aux;
            }
        }
        else
        {

            this->rezultate = new double[++this->nrRezultate];
            this->rezultate[0] = rez;

        }


    }
    void AdaugareOperatie(string rez)
    {

        if (this->operatii != nullptr)
        {
            if (this->nrOperatii < 10)
            {
                string* aux = new string[++this->nrOperatii];
                for (int i = 0; i < this->nrOperatii - 1; i++)
                {
                    aux[i] = this->operatii[i];
                }
                aux[this->nrOperatii - 1] = rez;
                delete[]this->operatii;

                this->operatii = aux;
            }
            else
            {
                string* aux = new string[this->nrOperatii];
                for (int i = 0; i < this->nrOperatii - 1; i++)
                {
                    aux[i] = this->operatii[i + 1];
                }
                aux[this->nrOperatii - 1] = rez;
                delete[]this->operatii;
                this->operatii = aux;
            }
        }
        else
        {

            this->operatii = new string[++this->nrOperatii];
            this->operatii[0] = rez;
        }

    }

    double operator+(double nr)
    {
        string operatie = (to_string(this->numar) + " + " + to_string(nr) + " = ");
        AdaugareOperatie(operatie);
        AdaugareRezultat(this->numar + nr);
        this->numar = this->numar + nr;


        return (this->numar);

    }
    double operator-(double nr)
    {
        string operatie = (to_string(this->numar) + " - " + to_string(nr) + " = ");
        AdaugareOperatie(operatie);
        AdaugareRezultat(this->numar - nr);
        this->numar = this->numar - nr;

        return(this->numar);


    }
    double operator*(double nr)
    {
        string operatie = (to_string(this->numar) + " * " + to_string(nr) + " = ");
        AdaugareOperatie(operatie);
        AdaugareRezultat(this->numar * nr);
        this->numar = this->numar * nr;

        return  (this->numar);
    }
    double operator /(double nr)
    {
        if (nr == 0)
            cout << "Nu se poate imparti la 0";
        else {
            string operatie = (to_string(this->numar) + " / " + to_string(nr) + " = ");
            AdaugareRezultat(this->numar / nr);
            AdaugareOperatie(operatie);
            this->numar = this->numar / nr;
            return (this->numar);
        }
    }

    double operator !()
    {

        string operatie = ("(- 1)* " + to_string(this->numar) + " = ");
        AdaugareRezultat((-1) * this->numar);
        AdaugareOperatie(operatie);
        this->numar = (-1) * this->numar;
        return  this->numar;
    }
    double RidicareLaPutere(float putere)
    {
        string operatie = (to_string(this->numar) + " ^ " + to_string(putere) + " = ");
        AdaugareRezultat(pow(this->numar, putere));
        AdaugareOperatie(operatie);
        this->numar = pow(this->numar, putere);
        return this->numar;
    }
    double Sqrt()
    {
        if (this->numar < 0)
            cout << "Nu se poate face operatia, numarul dat e negativ " << endl;
        else
        {
            string operatie = ("sqrt( " + to_string(this->numar) + " ) = ");
            AdaugareRezultat(sqrt(this->numar));
            AdaugareOperatie(operatie);
            this->numar = sqrt(this->numar);
            return this->numar;
        }
    }
    double UnuPeX()
    {
        if (this->numar == 0)
            cout << "Nu se poate face operatia,numarul dat e 0 " << endl;
        else
        {
            string operatie = (" 1/ " + to_string(this->numar) + " = ");
            AdaugareRezultat(1 / this->numar);
            AdaugareOperatie(operatie);
            this->numar = 1 / this->numar;
            return this->numar;
        }
    }

    void Clear()
    {
        this->numar = 0;

    }
    void ClearMemory()
    {
        delete[] this->rezultate;
        delete[] this->operatii;
        this->rezultate = nullptr;
        this->operatii = nullptr;
        nrOperatii = 0;
        nrRezultate = 0;
    }
    const void AfisareMemorie()
    {
        cout << endl;

        for (int i = 0; i < this->nrOperatii; i++)
        {
            cout << " " << this->operatii[i] << " " << this->rezultate[i] << endl;

        }
    }
    void operator [](int index)
    {
        if (index > 0 && index < nrRezultate)
            this->numar = rezultate[index];

    }


    double AcelasiNumar()
    {
        AdaugareRezultat(this->numar);
        AdaugareOperatie(to_string(this->numar) + " = ");
        return this->numar;

    }

};


void main()
{
    Calculator c;
    cout << "Afisam rezultatele, pe masura ce se obtin " << endl << endl;
    cout << " " << c + 3;
    cout << " " << c * 3;
    cout << " " << c + 5;
    cout << " " << c + 5;
    c.ClearMemory();
    cout << " " << c * 2;
    cout << " " << c + 4;
    cout << " " << c * 3;
    cout << " " << c + 5;
    cout << " " << c + 5;
    cout << " " << c * 2;
    cout << " " << c + 5;
    cout << " " << c + 5;
    cout << " " << c * 2;
    cout << " " << c.AcelasiNumar();
    cout << " " << !c;
    cout << " " << c.RidicareLaPutere(2);
    c[2];
    cout << " " << c / 3;
    cout << " " << c.Sqrt();
    cout << " " << c.UnuPeX();
    c.Clear();
    cout << " " << c + 10;

    cout << " " << c.RidicareLaPutere(3);
    cout << endl << endl << "Memoria este : " << endl;
    c.AfisareMemorie();

}


