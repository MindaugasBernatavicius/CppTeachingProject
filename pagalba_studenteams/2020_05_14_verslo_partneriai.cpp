#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// [DONE] - Individuali užduotis yra tokia, kad galima aprašyti klasę objektui (pvz.: „lemputė“)
// [DONE] - ir klasę kaupiančią ir apdorojančią informaciją apie daug objektų (pvz.: „sietynas“).
// [DONE] - Visi įvedimo, išvedimo, skaitymo ir rašymo metodai turi būti realizuojami tarpinėse sąsajos klasėse, kurios yra šabloninės <template>.
// [DONE] - Sietynas klasė turi paveldėti tarpinę sąsajos klasę
// [DONE] - Parašyti programą „verslo partneriai“.
// [DONE] - Kiekvieną įrašą sudaro laukai: įmonės pavadinimas, direktoriaus pavardė, darbuotojų skaičius, miestas, telefono numeris.
// [DONE] - Konstruktoriai ir, jei reikia, destruktoriai
// [DONE] - Metodai objekto savybių keitimui (set) ir nuskaitymui (get)
// [DONE] - Įrašų papildymas ir šalinimas duomenų faile
// [DONE] - Turi būti aprašytos bent 3 klasės, realizuojant paveldėjimą
// [DONE] - Turi būti panaudoti dinaminiai sąrašai (pvz. „sietyno“ klasėje galima saugoti informaciją ir apie 1, ir apie 1000 lempučių)
// [DONE] - Turi būti perdengti srauto (<< ir >>), sumos (+) operatoriai. Sumos operatorių galima panaudoti kaip papildymo, t.y. pridėjimo prie „sietyno“ operatorių
// [DONE] - Viena klasė turi būti šabloninė, t.y. turi leisti panaudoti tas pačias klases su kitokiais duomenų tipais

template <class T>
class Sarasas {
    private:
        vector<T> reiksmes;

    public:
        Sarasas (){}
        Sarasas (T pirmaReiksme) {
            reiksmes.push_back(pirmaReiksme);
        }
        void prideti(T reiksme){
            reiksmes.push_back(reiksme);
        }
        Sarasas operator=(const Sarasas &t2) {
            this->reiksmes = t2.reiksmes;
            return *this;
        }
        friend Sarasas &operator+(Sarasas &s, T &t) {
            s.reiksmes.push_back(t);
            return s;
        }
        friend ostream &operator<<(ostream &os, Sarasas &s) {
            for(auto it = s.reiksmes.begin(); it != s.reiksmes.end(); ++it)
                os << *it << endl;
            return os;
        }

        void nuskaitytiIsFailo(string failoVardas){
            ifstream fin;
            fin.open(failoVardas.c_str());
            string line;
            T t;
            Sarasas sarasas;
            while(getline(fin, line)){
                istringstream s(line);
                string field;
                int idx = 0;
                t = T();
                while (getline(s, field,',')){
                    if(idx == 0){
                        t.setImonesPavadinimas(field);
                    } else if(idx == 1){
                        t.setDirektoriausPavarde(field);
                    } else if(idx == 2){
                        t.setDarbuotojuSkaicius(stoi(field));
                    } else if(idx == 3){
                        t.setMiestas(field);
                    } else if(idx == 4){
                        t.setTelNumeris(field);
                    }
                    idx++;
                }
                // demonstracija uzklojimo '=' bei '+' operatoriu
                *this = sarasas + t;
            }
        }

        void irasytiIfaila(string failoVardas){
            ofstream fout;
            fout.open(failoVardas.c_str());
            fout << *this;
            fout.close();
        }

        void trintiEilute(){
            cout << "Kuria eilute trinti" << endl;
            int i = 0;
            string pasirinkimas;
            for(auto it = reiksmes.begin(); it != reiksmes.end(); ++it)
                cout << i++ << " -- " << *it << endl;

            cin >> pasirinkimas;
            reiksmes.erase(reiksmes.begin() + stoi(pasirinkimas));
        }

    protected:
        friend ostream &operator<<(ostream &os, T &t) {
            os << t.getImonesPavadinimas() << ","
               << t.getDirektoriausPavarde() << ","
               << t.getDarbuotojuSkaicius() << ","
               << t.getMiestas() << ","
               << t.getTelNumeris();
            return os;
        }

        friend istream &operator>>(istream &is, T &t) {
            cout << "Iveskite kompanijos pavadinima:";
            string tmp1;
            is >> tmp1; is.get();
            t.setImonesPavadinimas(tmp1);
            cout << endl;

            cout << "Iveskite kompanijos vadovo pavarde:";
            string tmp2;
            is >> tmp2; is.get();
            t.setDirektoriausPavarde(tmp2);
            cout << endl;

            cout << "Iveskite darbuotoju skaiciu:";
            string tmp3;
            is >> tmp3; is.get();
            t.setDarbuotojuSkaicius(stoi(tmp3));
            cout << endl;

            cout << "Iveskite miesta:";
            string tmp4;
            is >> tmp4; is.get();
            t.setMiestas(tmp4);
            cout << endl;

            cout << "Iveskite tel numeri:";
            string tmp5;
            is >> tmp5; is.get();
            t.setTelNumeris(tmp5);
            cout << endl;

            return is;
        }
};

// paveldime iš klases Sarasas, tam kad galėtume pasinaudoti ostream &operator<< padengimu,
// nes salyga neleidzia jo dengti pacioje kompanijos klaseje
class Kompanija : protected Sarasas<Kompanija>{
    private:
        string imonesPavadinimas;
        string direktoriausPavarde;
        int darbuotojuSkaicius{};
        string miestas;
        string telNumeris;

    public:
        string getImonesPavadinimas() {
            return imonesPavadinimas;
        }
        void setImonesPavadinimas(string imonesPavadinimas) {
            this->imonesPavadinimas = imonesPavadinimas;
        }
        string getDirektoriausPavarde() const {
            return this->direktoriausPavarde;
        }
        void setDirektoriausPavarde(string direktoriausPavarde) {
            this->direktoriausPavarde = direktoriausPavarde;
        }
        int getDarbuotojuSkaicius() {
            return this->darbuotojuSkaicius;
        }
        void setDarbuotojuSkaicius(int darbuotojuSkaicius) {
            this->darbuotojuSkaicius = darbuotojuSkaicius;
        }
        string getMiestas() {
            return this->miestas;
        }
        void setMiestas(string miestas) {
            this->miestas = miestas;
        }
        string getTelNumeris() {
            return this->telNumeris;
        }
        void setTelNumeris(string telNumeris) {
            this->telNumeris = telNumeris;
        }
        Kompanija(){}
};

class VersloPartneriai: public Sarasas<Kompanija> {};

int main(int argc, char ** argv) {
    string duomenuFailas = "./data.txt";
    VersloPartneriai versloPartneriai;
    string pasirinkimas;
    do {
        cout << "Pasirinkite operacija: " << endl;
        cout << " - Spauskite 1: nuskaityti duomenis is failo ir atspausdinti" << endl;
        cout << " - Spauskite 2: trinti duomenu eilute" << endl;
        cout << " - Spauskite 3: prideti nauja eilute" << endl;
        cout << " - Spauskite q/Q: nutraukti programa" << endl;

        cin >> pasirinkimas;

        if(pasirinkimas == "1"){
            versloPartneriai.nuskaitytiIsFailo(duomenuFailas);
            cout << versloPartneriai << endl;
        } else if(pasirinkimas == "2"){
            versloPartneriai.nuskaitytiIsFailo(duomenuFailas);
            versloPartneriai.trintiEilute();
            versloPartneriai.irasytiIfaila(duomenuFailas);
            cout << "Istrinta" << endl;
        } else if(pasirinkimas == "3"){
            Kompanija k;
            cin >> k;
            versloPartneriai.nuskaitytiIsFailo(duomenuFailas);
            versloPartneriai.prideti(k);
            versloPartneriai.irasytiIfaila(duomenuFailas);
            cout << "Prideta!" << endl;
        }
    } while(pasirinkimas != "q" && pasirinkimas != "Q");
}