#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "pile.h"
#include "rulesdialog.h"
//#include <QDebug>

char *game_selection;
int Num_of_cards;
int Num_of_rows;
Card *deck[104];
Pile *piledeck[104];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //lcd1 = new QLCDNumber(2, this);
    //lcd1->hide();
    //lcd1->setPalette(Qt::red);
    //reDraw(this);
}

void MainWindow::reDraw(QWidget *parent)
{
    //game_selection="Memory";
    Card::Initialized();
    for(int i=0;i<2*Num_of_cards;i++)
    {
        if(i<Num_of_cards)
            deck[i]=new Card(i,ui->centralWidget);
        else
            deck[i]=new Card(i-Num_of_cards,ui->centralWidget);
    }
    Shuffle(deck,2*Num_of_cards);
    //cards arrangements
    if(Num_of_cards>13)
        Num_of_cards=13;
    int n=0;
    for(int i=0,y=0;i<Num_of_rows;i++)
    {
        for(int j=0,x=0;j<Num_of_cards;j++)
        {
            piledeck[n]=new Pile(x,y,10,10,ui->centralWidget);
            deck[n]->move(x,y);
            deck[n]->raise();
            deck[n]->show();
            piledeck[n]->AcceptCards(deck[n],true,true);
            //flip this for
            //deck[n]->Flip();
            x+=71;
            n++;
        }
        y+=96;
    }
}

MainWindow::~MainWindow()
{
    //killTimer(timerId);
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    //qDebug() << "Update...";
    //lcd1->display(timerId);
    //timerId++;
}

void MainWindow::cleardeck()
{
    for(int i=0;i<104;i++)
    {
        if(piledeck[i]!=NULL)
        {
            delete piledeck[i];
            piledeck[i] = NULL;
        }
        if(deck[i]!=NULL)
        {
            delete deck[i];
            deck[i] = NULL;
        }
    }
}

void MainWindow::on_action2X2_triggered()
{
    game_selection="Memory2x2";
    cleardeck();
    setMinimumSize(300,300);
    //lcd1->move(200,100);
    //timerId=0;
    //timerId = startTimer(1000);
    //lcd1->show();
    Num_of_cards=2;
    CARDS_ON_DESK=Num_of_cards;
    Num_of_rows=2;
    reDraw(this);
}

void MainWindow::on_action4X2_triggered()
{
    game_selection="Memory4x2";
    cleardeck();
    setMinimumSize(450,400);
    //lcd1->move(200,100);
    //timerId=0;
    //timerId = startTimer(1000);
    //lcd1->show();
    Num_of_cards=4;
    CARDS_ON_DESK=Num_of_cards;
    Num_of_rows=2;
    reDraw(this);
}


void MainWindow::on_action6X2_triggered()
{
    cleardeck();
    setMinimumSize(450,400);
    Num_of_cards=6;
    CARDS_ON_DESK=Num_of_cards;
    Num_of_rows=2;
    reDraw(this);
}

void MainWindow::on_action8X2_triggered()
{
    cleardeck();
    setMinimumSize(570,400);
    Num_of_cards=8;
    CARDS_ON_DESK=Num_of_cards;
    Num_of_rows=2;
    reDraw(this);
}

void MainWindow::on_action10X2_triggered()
{
    cleardeck();
    setMinimumSize(710,400);
    Num_of_cards=10;
    CARDS_ON_DESK=Num_of_cards;
    Num_of_rows=2;
    reDraw(this);
}

void MainWindow::on_action13X2_triggered()
{
    cleardeck();
    setMinimumSize(925,400);
    Num_of_cards=13;
    CARDS_ON_DESK=Num_of_cards;
    Num_of_rows=2;
    reDraw(this);
}

void MainWindow::on_actionMedium_2_triggered()
{
    cleardeck();
    setMinimumSize(925,410);
    //lcd1->move(100,100);
    //timerId = startTimer(1000);
    Num_of_cards=26;
    CARDS_ON_DESK=Num_of_cards;
    Num_of_rows=4;
    reDraw(this);
}

void MainWindow::on_actionHard_triggered()
{
    cleardeck();
    setMinimumSize(925,728);
    //lcd1->move(100,100);
    //timerId = startTimer(1000);
    Num_of_cards=52;
    CARDS_ON_DESK=Num_of_cards;
    Num_of_rows=8;
    reDraw(this);
}

void MainWindow::on_actionRules_triggered()
{
    RulesDialog rulesDialog;
    rulesDialog.setModal(true);
    rulesDialog.exec();
}
