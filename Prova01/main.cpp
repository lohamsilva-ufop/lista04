#include <iostream>
#include <vector>

using namespace std;

int soma(vector<int> vetor, int inicio, int fim){
    if(inicio == fim){
        return vetor[inicio];
    } else {

    int media = (fim+inicio)/2;
    int soma1 = soma(vetor,inicio,media);
    int soma2 = soma(vetor,media+1,fim);
    return soma1 + soma2;
    }
}

void busca(vector<int> vetor, int chave, int inicio, int fim){

    if(inicio == fim){
        if(chave == vetor[inicio]){
            cout << "O elemento esta na posicao: " << inicio;
        }

    } else {
        int meio = (fim+inicio)/2;
         busca(vetor, chave, inicio, meio);
         busca(vetor, chave, meio+1, fim);
    }
}




int main(){

    vector <int> vetor = {1,2,3,4,5,8};
   cout << "A soma e: " << soma(vetor, 0, 5);
   cout << endl;
   busca(vetor, 4, 0, 5);

    return 0;
}
