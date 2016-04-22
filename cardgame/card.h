#ifndef CARD_H
#define CARD_H

#include <QLabel>
#include <QMouseEvent>

extern char *game_selection;
extern int CARDS_ON_DESK;
enum cardColors{BLACK,RED};
enum pips{ACE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING};
enum suits{CLUBS,DIAMONDS,HEARTS,SPADES};
class Pile;

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class Card : public QLabel
{
    Q_OBJECT
private:
    static QImage faces[53];
    static bool initialized;
    int value;//0-51
    Card *under;
    Card *over;
    Pile *pile;
    cardColors color;
    pips pip;
    suits suit;
    bool faceup;
    bool moving;
    bool okToDrag;
    bool hasMouseDown;
    static QPoint mouseDownOffset;
    static QPoint startDragPos;
    static Qt::MouseButtons buttonDown;
    static QPoint popUpPos;
    static Card* popUpCard;
    static Card* popUpCard1;
    static int s,p,cc;
    static int count_cards;
public:
    explicit Card(int v, QWidget *parent = 0);
    Card(pips p,suits s,QWidget *parent=0);
    suits Suit(){return suit;}

    pips Pip(){return pip;}
    cardColors Color(){return color;}
    Pile* Pileup(){return pile;}
    Card* Over(){return over;}
    Card* Under(){return under;}
    int StackSize();

   static void Initialized();
    void FaceUp(bool f);
    bool FaceUp(){return faceup;}
    int  CountCards(){return count_cards;}
    void mousePressEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;
    //void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    //void mouseReleaseEvent(QMouseEvent *ev);
    //void mouseDoubleEvent(QMouseEvent *ev);

    void Move(Pile* to,bool expose=true);
    Card* AdjustPositions(QPoint newpos,QPoint delta);
    void AlignWithPile();
    void Playoff();
    void Animate(QPoint newpos);
    void Flip(){FaceUp(faceup^1);}
    QSize sizeHint() const;
    void CheckCard();
signals:

public slots:
 friend class Pile;
};
void Shuffle(Card* Deck[],int n);

#endif // CARD_H
