#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int  main(){
  double a;
  double sum;
  double mid;
  double mid_m;
  double mid_v;
  double vari;
  
  ifstream fin1("datensumme.txt");
  ifstream fin2("datensumme.txt");
    
  ofstream fout1("mittelwerte.txt");
  ofstream fout2("varianz.txt");
  
  for(int n = 0; n < 26; n++){   //Mittelwerte und Varianzen in 26 Blöcken  
    sum = 0;
    vari = 0;

    for(int i = 0 ; i < 9 ; ++i){   //Mittelwerte werden berechnet
     fin1 >> a;
     sum += a;
    }
    mid = sum/9;
    for(int i = 0; i < 9; ++i){   //Varianz wird berechnet
      fin2 >> a;
      vari += pow((a - mid), 2); //pow(base, exp)
    }
    vari = vari / 9;

    fout1 << mid << endl;   //Varianz und Mittelwerte werden in .txt gespeichert
    fout2 << vari << endl;
  }   //Mittelwerte und Varianzen in 26 Blöcken END

  fout1.close();    //Mittelwerte von Varianz und Mittelwert 
  fout2.close();
  ifstream fin3("mittelwerte.txt");
  ifstream fin4("varianz.txt");
  sum = 0;
  for (int i = 0 ; i < 26 ; ++i){   //Mittelwert der Mittelwerte wird berechnet
    fin3 >> a;
    sum += a;
  }
  mid_m = sum/26;
  
  sum = 0;
  for (int i = 0 ; i < 26 ; ++i){   //Mittelwert der Varianzen wird berechnet
    fin4 >> a;
    sum += a;
  }
  mid_v = sum/26;

  cout << "Mittelwert der Mittelwerte: " << mid_m << endl; 
  cout << "Der Mittelwert ist gleich dem Mittelwert der hier berechneten Mittelwerte" << endl;
  cout << "Mittelwert der Varianzen: " << mid_v << endl; 
  cout << "Der hier berechnete Mittelwert der Varianzen ist kleiner als die Varianz aus stichprobe.cc." << endl;
  //Die Varianz aus stichprobe.cc ist geringer als der Mittelwert der hier berechneten Varianzen.
  fin1.close();
  fin2.close();
  fin3.close();
  fin4.close();
}