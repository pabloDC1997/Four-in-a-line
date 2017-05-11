#include "Jogo.h"

namespace JOGO {



Jogo::Jogo(int qLinhas, int qColunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    tabuleiro(0)

{

    if(qLinhas<4||qColunas<4) throw QString("Tabuleiro não pode ser menor que 4x4");
try{
    tabuleiro=new int[qLinhas*qColunas];    

    }catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");

            }
    quantidadeDeLinhas = qLinhas;
    quantidadeDeColunas = qColunas;
}


Jogo::~Jogo()
{
    if(tabuleiro) delete[] tabuleiro;

}

int Jogo::getElemento(int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString ("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos=linha*quantidadeDeColunas+coluna;
    return *(tabuleiro+pos);


}

void Jogo::setElemento(int linha, int  coluna, int elemento)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString ("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");

    int pos =  linha*quantidadeDeColunas+coluna;
    *(tabuleiro+pos) = elemento;
}
int Jogo::ganhouHorizontal()const{
    int cont=0;
    for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
            if(this->getElemento(linha,coluna)==1){
                cont++;
                if(cont==4)return 1;
            }else{
                cont=0;
            }
        }
       cont=0;
    }


        cont=0;
        for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
            for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
                if(this->getElemento(linha,coluna)==2){
                    cont++;
                    if(cont==4)return 2;
                }else{
                    cont=0;
                }
            }
           cont=0;
        }

        return 0;
}
int Jogo::ganhouVertical()const{
    int cont=0;
    for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
        for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
            if(this->getElemento(linha,coluna)==1){
                cont++;
                if(cont==4)return 1;
            }else{
                cont=0;
            }
        }
        cont=0;
    }


      cont=0;
       for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
           for(int linha=0;linha<this->quantidadeDeLinhas;linha++){
               if(this->getElemento(linha,coluna)==2){
                   cont++;
                   if(cont==4)return 2;
               }else{
                   cont=0;
               }
           }
           cont=0;
       }

    return 0;
}
bool Jogo::empate()const{
    for(int linha=0; linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
           if(this->getElemento(linha,coluna)==0){
               return false;
           }
        }
    }
    return true;
}
int Jogo::ganhouDiagonal()const{
    //~~~~~~METODOS PRA CAÇAR PARA A DIREITA~~~~~~~~~~~~~~
        //metodo de caçar na diagonal  Principal para direita
        int cont=0;
        for(int i=0; i<=6;i++){
           if(getElemento(i,i)==1){
              cont++;
            if(cont==4){
               return 1;
            }
           }else{
                 cont=0;
           }
        }

        //metodo pra caçar encima na diagonal prinincipal para direita
        for(int numero=1;numero<=3;numero++){
         cont=0;
         for(int C=numero, L=0;C<=6;C++,L++){
               if(getElemento(L,C)==1){
                cont++;
            if(cont==4){
              return 1;
            }
               }else{
                 cont=0;
               }
           }
        }

        //metodo pra caçar embaixo na diagonal principal pra direita
        for(int numero=1;numero<=3;numero++){
        cont=0;
         for(int L=numero, C=0;L<=6;L++, C++){
               if(getElemento(L,C)==1){
                cont++;
            if(cont==4){
               return 1;
            }
               }else{
                 cont=0;
               }
         }

        }

        //~~~~~~METODOS PRA CAÇAR PARA A ESQUERDA~~~~~~~~~~~~
        //metodo pra caçar na diagonal  principal para esquerda
        cont=0;
        for(int L=0, C=6;C>=0; L++,C--){
              if(getElemento(L,C)==1){
                 cont++;
                 if(cont==4){
                     return 1;
                 }
              }else{
                cont=0;
              }

        }



        //metodo para caça na diagonal encima da diagonal principal para esquerda
        for(int numero=5;numero>=3;numero--){
            cont=0;
         for(int L=0, C=numero; C>=0; L++,C--){
               if(getElemento(L,C)==1){
                cont++;
                if(cont==4){
                    return 1;
                }
               }else{
                 cont=0;
               }

         }

        }

        //metodo para caça na diagonal embaixo da diagonal principal para esquerda
        for(int numero=1; numero<=3; numero++){
            cont=0;
           for(int L=numero, C=6; L<=6; L++,C--){
              if(getElemento(L,C)==1){
                 cont++;
                 if(cont==4){
                     return 1;
                 }
              }else{
                    cont=0;
              }
           }
        }




        //caso nada
        return 0;

}
void Jogo::restart(){
    for(int linha=0; linha<this->quantidadeDeLinhas;linha++){
        for(int coluna=0;coluna<this->quantidadeDeColunas;coluna++){
            this->setElemento(linha,coluna,0);
        }
    }
}

}

