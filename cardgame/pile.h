#ifndef PILE_H
#define PILE_H

#include <QLabel>
class Card;//forward declaration
const int DRAGLAST=6;
const int DROPLAST=6;
//class Rule;
enum piletype{PLAYOFF,DEAL,DELTA,FILED,FREE_CELL};
class Pile : public QLabel
{
    Q_OBJECT
    QPoint delta;
    Card *top;
    Card *bottom;
    int rulesSet;//bit set of rules defined by OR-ing bits
                //defined by 1<<rules;
public:
     Pile(int x,int y,int dx,int dy,QWidget *parent = 0);

    // ~Pile();
     Card *Top(){return top;}
     Card *Bottom(){return bottom;}
     void AcceptCards(Card *c,bool expose=true,bool record=true);
     void ReleaseCards(Card *c,bool expose=true);
     QPoint Delta(){return delta;}
     bool Empty(){return !bottom;}
     //void FindClosestDrop(Card *c,QMouseEvent *ev);
     //bool CanBeDragged(Card *c);//checks relavent rules
     //virtual Rule* DragRule(int i)=0;
     //virtual void DragRule(int i,Rule* r)=0;
     //virtual Rule* DropRule(int i)=0;
     //virtual void DropRule(int i,Rule* r)=0;
     void Deal(QMouseEvent *ev);
     void AddDropRules(int n...);
     void AddDragRules(int n...);



signals:

public slots:

};

#endif // PILE_H
