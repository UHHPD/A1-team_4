#include <iostream>
#include <fstream>

using namespace std;

//Funktion für das Summieren kann nicht schaden.
int sum(int num_1, int num_2){
  return num_1 + num_2;
}

int main(){
  int num_1, num_2;

  ifstream fin("daten.txt");
  ofstream fout("datensumme.txt");

  for(int n = 0; n < 234; ++n){
    fin >> num_1;
    fin >> num_2;
    fout << sum(num_1, num_2) << endl;
  }

  fin.close();
  fout.close();
}