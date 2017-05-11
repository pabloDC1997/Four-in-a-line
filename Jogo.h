#ifndef JOGO_H
#define JOGO_H

#include<QString>


namespace JOGO{
class Jogo
{
private:

    int quantidadeDeLinhas;
    int quantidadeDeColunas;
    int *tabuleiro;
    QString jogador1;
    QString jogador2;



public:   
     Jogo(int qLinhas, int qColunas);
    ~Jogo();
    int getQuantidadeDeLinhas()const{return quantidadeDeLinhas;}
    int getQuantidadeDeColunas()const{return quantidadeDeColunas;}
    int getElemento(int linha, int coluna)const;
    void setElemento(int linha, int  coluna, int elemento)const;
    void setJogador1(QString nome){this->jogador1 = nome;}
    QString getJogador1(){return jogador1;}
    void setJogador2(QString nome){this->jogador2 = nome;}
    QString getJogador2(){return jogador2;}
    int ganhouHorizontal()const;
    int ganhouVertical()const;
    int ganhouDiagonal()const;
    bool empate()const;
    void restart();
    QString getConjunto()const{
        QString saida="";
        for(int linha= 0;linha<getQuantidadeDeLinhas();linha++){
            for(int coluna = 0; coluna<getQuantidadeDeColunas(); coluna++){
                saida+=QString::number(getElemento(linha,coluna));
                saida +=" ";
            }
            saida +="\n";
        }
        return saida;
    }


};
}

#endif // JOGO_H
