#include "card.h"
#include"pile.h"
#include <ctime>
#include <stdio.h>
#include <QMouseEvent>
#include <QMessageBox>

//static declaration allocations
QImage Card::faces[53];//0 is ACE of clubs;51 is king of spades;52 is back
bool Card::initialized;
int opencards=0;
int no_of_clicks=0;
int total_card_count=0;
int CARDS_ON_DESK=0;
QPoint Card::mouseDownOffset;
QPoint Card::startDragPos;
Qt::MouseButtons Card::buttonDown;
QPoint Card::popUpPos;
Card*  Card::popUpCard;
Card*  Card::popUpCard1;

Card::Card(int v,QWidget *parent) :
    QLabel(parent),value(v),under(0),over(0),pile(0),faceup(false),moving(false)
  ,hasMouseDown(false)
{
//    count_cards++;
    suit=static_cast<suits>(value/13);
    pip=static_cast<pips>(value%13);
    color = static_cast<cardColors>((suit>>1)^(suit&1));
    FaceUp(faceup);
}

Card::Card(pips p,suits s,QWidget *parent):QLabel(parent),pip(p),suit(s),under(0),over(0)
   ,pile(0),faceup(false),moving(false),hasMouseDown(false)
{
     value=suit*13+pip;
     color = static_cast<cardColors>((suit>>1)^(suit&1));
     FaceUp(faceup);
}

void Card::FaceUp(bool f)
{
    faceup=f;
    setPixmap(QPixmap::fromImage(faces[faceup?value:52]));
}

void Card::Initialized()
{
    if(initialized) return;
    initialized=true;
    CARDS_ON_DESK=0;
    char suit[]={'c','d','h','s'};
    char pip[]={'1','2','3','4','5','6','7','8','9','a','b','c','d'};
    QString fname=":/cards/c1.bmp";
    //count_cards=0;
    int n=0;
    for(int s=CLUBS;s<=SPADES;++s)
    {
        fname[8]=suit[s];
        for(int p=ACE;p<=KING;++p)
        {
            fname[9]=pip[p];
            faces[n++]=QImage(fname);
        }
    }
    faces[n]=QImage(":/cards/zCardBack.bmp");
}

QSize Card::sizeHint() const
{
    return QSize(71,96);
}

void Shuffle(Card* Deck[],int n)
{
    if(CARDS_ON_DESK!=n)
        CARDS_ON_DESK=n;
    total_card_count=0;
    no_of_clicks=0;
    srand((int)time(0));
    Card *temp;
    int k;
    while(n>0)
    {
        k=rand()%n--;
        temp=Deck[k];
        Deck[k]=Deck[n];
        Deck[n]=temp;
        temp->raise();
    }
}

void Card::mousePressEvent(QMouseEvent *ev)
{
    switch(ev->button())
    {
    case Qt::LeftButton:
        if(game_selection=="Memory2x2")
        {
            this->Flip();
            CheckCard();
        }
        if(game_selection=="Memory4x2")
        {
            this->Flip();
            CheckCard();
        }
        break;
    case Qt::RightButton:
        this->Flip();
        break;
    default:;
    }
}
void Card::CheckCard()
{
    opencards++;
    no_of_clicks++;
    if(opencards==1)
    {
        popUpCard=this;
    }
    if(opencards==2)
    {
        popUpCard1=this;
        if(popUpCard->Color()==this->Color()&&popUpCard->Pip()==this->Pip()&&popUpCard->Suit()==this->Suit()&&popUpCard!=this)
        {
            popUpCard->move(-76,-91);
            this->move(-76,-91);
            opencards=0;
            total_card_count++;
            no_of_clicks--;
            if(total_card_count==(CARDS_ON_DESK/2))
            {
                QString text = "U WON THE GAME! WITH : "+QString::number(no_of_clicks)+" GUESSES.";
                QMessageBox::information(this,"WON", text);
            }
        }
    }
    if(opencards==3)
    {
        opencards=0;
        popUpCard->Flip();
        popUpCard1->Flip();
        this->Flip();
    }
}

/*
void Card::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point=event->globalPos()+mouseDownOffset;
    QPoint moved=point-pos();
    if(moved.manhattanLength()>4)
        moving=true;
    if(moving)
        move(pos()+moved);
        //AdjustPositions(point,pile?pile->Delta():QPoint(0,10));
}

void Card::CheckCards(QObject *obj)
{
    if(obj!=NULL)
    {
        opencards++;
        if(opencards==1)
        {
            s=obj->Suit();
            p=obj->Pip();
            cc=obj->Color();
            obj->Flip();
            popUpCard=obj;
        }
        if(opencards==2)
        {
            obj->Flip();
            if(s==obj->Suit() && p==obj->Pip() && cc==obj->Color())
            {
                popUpCard=NULL;
                delete popUpCard;
                obj=NULL;
                delete obj;
            }
            opencards=0;
        }
    }
}

void Card::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->buttons())return;
    if(popUpCard)
    {
        popUpCard->move(popUpPos);
        popUpCard=NULL;
        return;
    }
    if(moving&&pile)
        pile->FindClosestDrop(this,ev);
    else
        if(pile)
        {
            QPoint point=ev->globalPos()+mouseDownOffset;
            QPoint moved=point-pos();
            if(moved.manhattanLength()<=4);
                //pile->OnClickEvent(this);
        }
    moving=false;
    okToDrag=false;
}

Card* Card::AdjustPositions(QPoint newPos,QPoint delta)
{
    //Card *c
}
*/

