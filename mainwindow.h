#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QInputDialog>
#include <QMainWindow>
#include<Jogo.h>
#include<QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_pushButtonPronto_clicked();

    void on_pushButtonJogar_clicked();

    void on_pushButtonPlayer1_clicked();

    void on_pushButtonPlayer2_clicked();

    void on_pushButtonRestart_clicked();



    void on_pushButtonAbandonarPartida_clicked();

private:
    Ui::MainWindow *ui;
    JOGO::Jogo *Tab;

};

#endif // MAINWINDOW_H
