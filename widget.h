/*
 * Copyright (C) 2011 @HIT Footoo Lab
 * Author:shiyanhui
 * Create Date: 2011-3-20
 */
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QString ;
class QLineEdit ;
class QPushButton ;
class QHBoxLayout ;
class QVBoxLayout ;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget( QWidget *parent = 0 ) ;

private slots:
    void pushOperatorButton() ;
    void pushNumberButton() ;
    void pushBracketButton() ;
    void pushClearButton() ;

private:
    void declareVariables() ;
    void createLayout() ;
    void createConnect() ;

    QLineEdit *expressionLineEdit ;
    QPushButton *numberPushButtons[ 10 ] ;
    QPushButton *bracketPushButtons[ 2 ] ;

    QPushButton *operatorPushButtons[ 5 ] ;
    QPushButton *clearPushButton ;

    //for left down row pushbuttons
    QHBoxLayout *leftDownRowLayout[ 4 ] ;

    //for right down row pushbuttons
    QHBoxLayout *rightDownRowLayout[ 3 ] ;

    //for left layout
    QVBoxLayout *leftDownLayout ;
    //for right layout
    QVBoxLayout *rightDownLayout ;
    //for down layout
    QHBoxLayout *downLayout ;
    //for up layout
    QHBoxLayout *upLayout ;
    //for global layout
    QVBoxLayout *globalLayout ;

};

#endif // WIDGET_H
