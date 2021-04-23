#include <iostream>
#include <queue> 
#include <vector>
#include <cstring>
typedef struct competidor
{
	long int escrita, reacao;
	int indice;
} Competidor;

using namespace std;


Competidor vencedor(Competidor um, Competidor dois, int tam){

  long int r1, r2;
  r1 = um.reacao + (um.escrita * tam);
  r2 = dois.reacao + (dois.escrita * tam);
  if(r1<r2){
    return um;
  }else if(r1>r2){
    return dois;
  }else {
    if(um.indice< dois.indice)
      return um;
    else
      return dois;
  }
}


int main() {
  int n;
  char str[100001];
  cin >> n;

  Competidor aux;
  queue<Competidor> a; 

  // ler jogadores enfileirando
  while(a.size()<n){
    long int r,e;
    cin >> r >> e;
    aux.indice = a.size();
    aux.escrita = e;
    aux.reacao = r;
    a.push(aux);
    // cout << aux.indice << aux.reacao<< aux.escrita << endl;
  }
  cin >> str;
  int tamString = strlen(str);
  int batalha = 1;
  vector<int> rodadas(n,1);
  while(a.size()>1)
  {
    Competidor um, dois, v;

    um = a.front();
    a.pop();
    dois = a.front();
    a.pop();

    v = vencedor(um, dois, tamString);
    rodadas[v.indice]++;
    // cout << v.indice << v.reacao<< v.escrita << endl;
    a.push(v);
    tamString+=tamString;
  }

  // imprimir
  cout << rodadas[0];
  for(int i = 1;i<n;i++){
    cout << " " << rodadas[i];
  }
  cout << "\n";

}