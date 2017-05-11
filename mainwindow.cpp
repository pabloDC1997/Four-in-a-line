#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Tab(0)

{
    ui->setupUi(this);
    ui->pushButtonJogar->setEnabled(false);
    ui->tableWidgetTabuleiro->setEnabled(false);
    ui->pushButtonPlayer1->setEnabled(false);
    ui->pushButtonPlayer2->setEnabled(false);
    ui->tableWidgetTabuleiro->setEnabled(false);
    ui->pushButtonRestart->setEnabled(false);
    ui->textEditNexte->setEnabled(false);
    ui->pushButtonAbandonarPartida->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(Tab) delete Tab;

}



void MainWindow::on_pushButtonPronto_clicked()
{
    try{
        QString nome1= QInputDialog::getText(this,"JOGADOR","Nome 1:");
        QString nome2= QInputDialog::getText(this,"JOGADOR","Nome 2:");

    Tab=new JOGO::Jogo(7,7);

    Tab->setJogador1(nome1);
    Tab->setJogador2(nome2);
    ui->tableWidgetTabuleiro->setRowCount(7);
    ui->tableWidgetTabuleiro->setColumnCount(7);
    ui->pushButtonJogar->setEnabled(true);



    ui->pushButtonPronto->setEnabled(false);
    ui->textEditNexte->setText(Tab->getConjunto());
    ui->pushButtonAbandonarPartida->setEnabled(true);
    }catch(QString &erro){
        QMessageBox::information(this,"ERRO: ",erro);
    }

}

void MainWindow::on_pushButtonJogar_clicked()
{
    Tab->restart();
    QString n1="Player: ",n2="Player: ";
    ui->labelJogador1->setText(n1+=Tab->getJogador1());
    ui->labelJogador2->setText(n2+=Tab->getJogador2());
    ui->pushButtonPlayer1->setEnabled(true);
    ui->pushButtonJogar->setEnabled(false);
    ui->textEditNexte->setText(Tab->getConjunto());

}


void MainWindow::on_pushButtonPlayer1_clicked()
{
    try{
        int linha=0, coluna=0;
        QMessageBox vencedor;
        QString nome="Vencedor:";
            linha=6;

            coluna=QInputDialog::getInt(this,Tab->getJogador1(),"COLUNA");
            while(linha>=0){
                if(Tab->getElemento(linha,coluna-1)!=0){
                    linha--;
                }else{break;}
            }
            Tab->setElemento(linha,coluna-1,1);
            QTableWidgetItem *jogada=new QTableWidgetItem();
            jogada->setBackground(Qt::black);
            ui->tableWidgetTabuleiro->setItem(linha,coluna-1,jogada);

            if(Tab->empate()){
                vencedor.setText("EMPATE");
                vencedor.exec();
                ui->pushButtonRestart->setEnabled(true);
            }else{
            if(Tab->ganhouHorizontal()==1||Tab->ganhouVertical()==1||Tab->ganhouDiagonal()==1){
                nome+=Tab->getJogador1();
                vencedor.setText(nome);
                vencedor.exec();
                ui->pushButtonRestart->setEnabled(true);

            }else{
                ui->pushButtonPlayer1->setEnabled(false);
                ui->pushButtonPlayer2->setEnabled(true);
            }
        }

        ui->textEditNexte->setText(Tab->getConjunto());
   }catch(QString &erro){
       QMessageBox::information(this,"ERRO: ",erro);
    }
}



void MainWindow::on_pushButtonPlayer2_clicked()
{
    try{
        int linha=0, coluna=0;
        QMessageBox vencedor;
        QString nome="Vencedor: ";
            linha=6;
            coluna=QInputDialog::getInt(this,Tab->getJogador2(),"COLUNA");
            while(linha>=0){
                if(Tab->getElemento(linha,coluna-1)!=0){
                    linha--;
                }else{break;}
            }
            Tab->setElemento(linha,coluna-1,2);
            QTableWidgetItem *jogada=new QTableWidgetItem();
            jogada->setBackground(Qt::blue);
            ui->tableWidgetTabuleiro->setItem(linha,coluna-1,jogada);

            if(Tab->empate()){
                vencedor.setText("EMPATE");
                vencedor.exec();
                ui->pushButtonRestart->setEnabled(true);
            }else{
            if(Tab->ganhouHorizontal()==2||Tab->ganhouVertical()==2||Tab->ganhouDiagonal()==2){
                nome+=Tab->getJogador2();
                vencedor.setText(nome);
                vencedor.exec();
                ui->pushButtonRestart->setEnabled(true);

            }else{
                ui->pushButtonPlayer1->setEnabled(true);
                ui->pushButtonPlayer2->setEnabled(false);
            }
        }

    ui->textEditNexte->setText(Tab->getConjunto());
   }catch(QString &erro){
       QMessageBox::information(this,"ERRO: ",erro);
    }
}

void MainWindow::on_pushButtonRestart_clicked()
{
    Tab->restart();
    ui->tableWidgetTabuleiro->clear();
    ui->pushButtonPlayer1->setEnabled(false);
    ui->pushButtonPlayer2->setEnabled(false);
    ui->pushButtonJogar->setEnabled(false);
    ui->pushButtonPronto->setEnabled(true);
    ui->labelJogador1->clear();
    ui->labelJogador2->clear();
    ui->textEditNexte->setText(Tab->getConjunto());
    ui->pushButtonRestart->setEnabled(false);
}



void MainWindow::on_pushButtonAbandonarPartida_clicked()
{
    ui->pushButtonPlayer1->setEnabled(false);
    ui->pushButtonPlayer2->setEnabled(false);
    ui->pushButtonJogar->setEnabled(false);
    ui->pushButtonPronto->setEnabled(false);
    ui->labelJogador1->clear();
    ui->labelJogador2->clear();
    ui->tableWidgetTabuleiro->clear();
    ui->pushButtonRestart->setEnabled(true);
}
