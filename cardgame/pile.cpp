#include "pile.h"
#include"card.h"
#include "mainwindow.h"
class Game;
extern MainWindow MainWindow;
//extern GameBoard *MainApp;
extern Game *game;
extern QList<Pile*>piles;
//Rule *piledeal::dragRules{DragLast};
Pile::Pile(int x,int y,int dx,int dy,QWidget *parent) :
    QLabel(parent),delta(QPoint(dx,dy)),top(0),bottom(0)
{
    //game->AddPile(this);
    move(x,y);
    resize(71,96);
    setFrameShape(Box);
    setLineWidth(2);
    //this->palette().setColor(BackGROUND_BLUE,BLACK);
    show();
}
/*Pile::~Pile()
{
    Card *c=bottom;
    while(c)
    {
        bottom=c->over;
        delete c;
        c=bottom;

    }

}*/
void Pile::AcceptCards(Card *c, bool expose, bool record)
{
    QPoint cardPosition;
   // if(record)new CardMove(c,c->pile,this);
    if(c->pile)
        //c->pile->ReleaseCards(c,expose);
    if(top)
    {
        c->under=top;
        top->over=c;
        cardPosition=top->pos()+delta/((top->faceup)?1:2);

    }
    else
    {
        cardPosition=pos();
        bottom=c;
        c->under=NULL;


    }
    c->pile=this;
    //top=c->AdjustPositions(cardPosition,delta);

    //if(c->pip==KING&&Type()==PLAYOFF)game->CheckWin();
}
/*void Pile:: FindClosetDrop(Card *c,QMouseEvent *ev)
{
    const int NUM=3;
    QPoint drop=c->pos();
    Pile *closet[NUM]={NULL,NULL,NULL};
    int distance[NUM]={10000,20000,20000};
    for(int i=0;i<game->piles.count();i++)
    {
        Pile *p=game->piles[i];
        if(p==c->pile) continue;
        QPoint diff=drop-(p->top?p->top->pos():p->pos());
        int dist=diff.manhattanLength();
        for(int j=0;j<NUM;j++)
        {
            if(dist<distance[j])
            {std::swap(dist,distance[j]);
                std::swap(p,closet[j]);
            }
        }
    }
    for(int i=0;i<NUM;i++)
    {
        if(closet[i]&&closet[i]->CanBeDropped(c))
        {
            closet[i]->AcceptCards(c);
            return;
        }}
    QPoint p=c->under?(c->under->pos()+c->pile->Delta()/(c->under->faceup?1:2)):
                      c->pile->pos();
    c->AdjustPositions(p,c->pile->delta);
}
*/
/*void Pile::mouseReleaseEvent(QMouseEvent *ev)
{
    OnClickEvent(NULL);
}
bool Pile::CanBeDropped(Card* c)
{
    int i=0;
    bool ok=true;
    while(ok&&DropRule(i))
        ok=DropRule(i++)->Enforce(this,c);
    return ok;
}
bool Pile::CanBeDragged(Card *c)
{
    int i=0;
    bool ok=true;
    while(ok&&DragRule(i))
        ok=DragRule(i++)->Enforce(this,c);
    return ok;

}
void Pile::AddDragRules(int n...)
{
                            va_list lp;
                            va_start(lp,n);
                            int i=0;
                            while(i<n)
                            DropRule(i++,va_arg(lp,Rule*));
                            DropRule(i,NULL);
                            va_end(lp);
                        }

voi Pile::AddDragRules(int n...)
{
    va_list lp;
    va_start(lp,n);
    int i=0;
    while(i<n)
        DragRule(i++,va_arg(lp,Rule*));


}
*/

