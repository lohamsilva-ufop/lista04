#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//após encontrar o valor, descobre qual a posição.
int descobrePosicao(vector<int> &vetor, int elemento){
    for (int i=0; i<vetor.size(); i++){
        if (elemento == vetor[i]){
            return i;
        }
    }
}


//funcao que descobre o maior elemento
int encontraMaiorElemento(vector<int> vetor, int inicio, int fim){

   //caso base
    if(fim - inicio <= 1){
        return max(vetor[inicio], vetor[fim]);
    } else {
        int meio = (inicio + fim)/2; //pega o meio do vetor
        //passa para a funcao recursiva o inicio ate o meio do vetor
        //n1 irá dividir parte do vetor até encontrar o maior elemento da parte
        int n1 = encontraMaiorElemento(vetor, inicio, meio);
        //passa para a funcao recursiva o meio ate o fim do vetor
        //n2 irá dividir parte do vetor até encontrar o maior elemento da parte
        int n2 = encontraMaiorElemento(vetor, meio+1, fim);
        //compara os maiores valores encontrados por eles e retorna
        return max (n1,n2);
    }
}


//funcao que descobre o menor elemento
int encontraMenorElemento(vector<int> vetor, int inicio, int fim){

   //caso base
    if(fim - inicio <= 1){
        return min(vetor[inicio], vetor[fim]);
    } else {
        int meio = (inicio + fim)/2; //pega o meio do vetor
        //passa para a funcao recursiva o inicio ate o meio do vetor
        //n1 irá dividir parte do vetor até encontrar o maior elemento da parte
        int n1 = encontraMenorElemento(vetor, inicio, meio);
        //passa para a funcao recursiva o meio ate o fim do vetor
        //n2 irá dividir parte do vetor até encontrar o menor elemento da parte
        int n2 = encontraMenorElemento(vetor, meio+1, fim);
        //compara os maiores valores encontrados por eles e retorna
        return min(n1,n2);
    }
}

int main(){

    //declara e insere valores no vetor
    vector<int> vetor = {1,2,3,4,5,6,700,8,9,10};
    //declara a variavel que pega o maior elemento na funcao encontraMaiorElemento
     int elementoMaior = encontraMaiorElemento(vetor,0,9);
    //mostra qual a posicao que se encontra o elemento.
     cout << "O maior elemento " << elementoMaior << " se encontra na posicao: " << descobrePosicao(vetor, elementoMaior) << endl;
     int elementoMenor = encontraMenorElemento(vetor,0,9);
    //mostra qual a posicao que se encontra o elemento.
    cout << "O menor elemento " << elementoMenor << " se encontra na posicao: " << descobrePosicao(vetor, elementoMenor) << endl;

    return 0;
}
