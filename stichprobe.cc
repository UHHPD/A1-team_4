#include <iostream>
#include <fstream>
#include <cmath>

int  main(){
  std::ifstream fin1("datensumme.txt");
  std::ifstream fin2("datensumme.txt");
  
  int a;
  double sum = 0;
  double mid;
  double vari;
  double sig;
  
  for (int i = 0 ; i < 234 ; ++i){
    fin1 >> a;
    sum += a;
  }
  mid = sum/234;

  for (int i = 0; i < 234; ++i){
    fin2 >> a;
    vari += pow((a - mid), 2);
  }
  vari = vari / 234;
  sig = sqrt(vari);
  
  std::cout << "Mittelwert: " << mid << std::endl;
  std::cout << "Varianz: " << vari << std::endl;
  std::cout << "Standartabweichung: " << sig << std::endl;
  
  fin1.close();
  fin2.close();
}

