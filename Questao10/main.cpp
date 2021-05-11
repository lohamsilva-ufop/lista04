#include <iostream>
#include <vector>
using namespace std;

//A altura de um nó é a distancia da sua raiz até seu descendente mais afastado.

//Registro para definir a arvore
struct no{
    int dado;
    int indice_direita;
    int indice_esquerda;
};

int calculaAltura (vector <no> tree, int posicao) {
   if (tree[posicao].indice_direita == NULL || tree[posicao].indice_esquerda == NULL){
      return 0; // altura da árvore vazia
   } else {
      int altura_esquerda = calculaAltura(tree, tree[posicao].indice_esquerda);
      int altura_direita = calculaAltura(tree, tree[posicao].indice_direita);


      if (altura_esquerda < altura_direita){
        return altura_direita + 1;
      } else{
        return altura_esquerda + 1;
   }
   posicao++;
}
}
//procedimento para imprimir a arvore:
void imprimeArvore(vector <no> arv){
        for(int i=0; i<arv.size();i++){
                  cout << "No: " << i << " :" <<endl;
                  cout << "dado: " << arv[i].dado << endl;
                  if (arv[i].indice_direita == NULL){
                        cout << "indice do no direito sem elemento: folha" << endl;
                  } else {
                        cout << "indice do no direito: " << arv[i].indice_direita << endl;
                  }

                  if (arv[i].indice_esquerda == NULL){
                        cout << "indice do no esquerdo sem elemento: folha" << endl;
                  } else{
                        cout << "indice do no esquerdo:" << arv[i].indice_esquerda << endl;
                  }

                  cout << endl;
            }
}


int main()
{
    vector <no> tree; //declaracao do vetor arvore do tipo nу
    no novo;

    novo.dado = 12;
    novo.indice_direita = 1;
    novo.indice_esquerda = 2;
    tree.push_back(novo);

    novo.dado = 16;
    novo.indice_direita = NULL ;
    novo.indice_esquerda = NULL;
    tree.push_back(novo);

    novo.dado = 4;
    novo.indice_direita = 3;
    novo.indice_esquerda = 4 ;
    tree.push_back(novo);

    novo.dado = 8;
    novo.indice_direita = NULL ;
    novo.indice_esquerda = 5;
    tree.push_back(novo);

    novo.dado = 2;
    novo.indice_direita = NULL;
    novo.indice_esquerda = NULL;
    tree.push_back(novo);

    novo.dado = 6;
    novo.indice_direita = NULL;
    novo.indice_esquerda = NULL;
    tree.push_back(novo);

    imprimeArvore(tree);

    cout << endl << "A altura da arvore e: " << calculaAltura(tree, 0);

    return 0;
}
