#include <iostream>
#include <string>


using namespace std;

class pacjent{
public:
    string imie;
    double waga;
    double wzrost;
private:
    double BMI;
public:
    pacjent(string i, double j, double k){
    imie = i;
    waga = j;
    wzrost = k;
    BMI = 0;
    }

    double oblicz_BMI(){
        BMI= waga/(wzrost*wzrost);

        return BMI;
    }
    /*
        nazwa: oblicz_BMI
        co robi: oblicza BMI pacjenta na podstawie wzoru (waga/wzrost^2)
        parametr wejsciowy: brak
        parametr wyjsciowy: double BMI
    */

    string opis_BMI(){
        oblicz_BMI();

        if(BMI < 18.5){
            return "niedowaga" ;
        }else if(BMI<= 24.9 ){
            return "prawidlowa";
        }else if(BMI<= 29.9 ){
            return "nadwaga";
        }else{
            return "oty³osc";
        }
    }
      /*
        nazwa: opis_BMI
        co robi: klasyfikuje obliczone BMI i dopasowuje odpowiedni stan pacjenta
        parametr wejsciowy: brak
        parametr wyjsciowy: string ze stanem pacjenta
    */

    void wyswietl_dane(){
        cout<<"Imie :"<<"  "<<imie<<endl;
        cout<<"Waga :"<<waga<<"kg"<<endl;
        cout<<"Wzrost :"<<wzrost<<"m"<<endl;
        cout<<"BMI :"<< oblicz_BMI()<<endl;
        cout<<"Opis :"<< opis_BMI() <<endl;
    }
      /*
        nazwa: wyswietl_dane
        co robi: zbiera wszystkie informacje o danym pacjencie i wypisuje je w konsoli
        parametr wejsciowy:brak
        parametr wyjsciowy:stringi i double z informacjami o pacjencie
    */

};

int main()
{

    pacjent pacjenci[3]={
        pacjent("Ania", 65, 1.60),
        pacjent("Marek", 67, 1.90),
        pacjent("Maciek", 34, 1.75)
    };

    double najwieksze_BMI = 0;
    int indeks = 0;

    for(int i=0; i < 3; i++){
        pacjenci[i].wyswietl_dane();
        cout<<endl;
        if(pacjenci[i].oblicz_BMI() > najwieksze_BMI){
            najwieksze_BMI = pacjenci[i].oblicz_BMI();
            indeks = i;
        }
    }
    cout<<endl;
    cout<<"Pacjent z najwiekszym BMI :"<<endl;
    pacjenci[indeks].wyswietl_dane();

    return 0;
}
