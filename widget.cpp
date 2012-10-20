/*
 * Copyright (C) 2011 @HIT Footoo Lab
 * Author:shiyanhui
 * Create Date: 2011-3-20
 */
#include "calculate.h"
#include "widget.h"
#include <QtGui>

Widget::Widget(QWidget *parent) :
        QWidget(parent)
{
    declareVariables() ;
    createLayout() ;
    createConnect() ;
}

void Widget::pushOperatorButton( )
{
    QPushButton *aPushButton = dynamic_cast<QPushButton*>( sender() ) ;
    for( int i = 0 ; i < 4 ; ++ i )
    {
        if( aPushButton == operatorPushButtons[ i ] )
        {
            expressionLineEdit->insert( aPushButton->text() ) ;
            return ;
        }
    }

    Calculation aCalculation( expressionLineEdit->text().toStdString() ) ;
    aCalculation.midfix_to_suffix( ) ;
    aCalculation.calculate( ) ;
    expressionLineEdit->setText( QString( "%1" ).arg( aCalculation.get_answer() ) ) ;
}

void Widget::pushNumberButton( )
{
    QPushButton *aPushButton = dynamic_cast<QPushButton*>( sender() ) ;
    for( int i = 0 ; i < 10 ; ++ i )
    {
        if( aPushButton == numberPushButtons[ i ] )
            expressionLineEdit->insert( QString( "%1" ).arg( i ) ) ;
    }

}

void Widget::pushBracketButton( )
{
    QPushButton *aPushButton = dynamic_cast<QPushButton*>( sender() ) ;
    for( int i = 0 ; i < 2 ; ++ i )
    {
        if( aPushButton == bracketPushButtons[ i ] )
            expressionLineEdit->insert( aPushButton->text() ) ;
    }

}

void Widget::pushClearButton()
{
    expressionLineEdit->clear() ;
}

void Widget::declareVariables()
{
    //declare lineEdit of expression
    expressionLineEdit = new QLineEdit() ;

    //declare number pushbuttons
    for( int i = 0 ; i < 10 ; ++ i )
    {
        numberPushButtons[ i ] = new QPushButton( QString( "%1").arg( i ) ) ;
        numberPushButtons[ i ]->setDefault( true ) ;
    }

    //declare brackets pushbuttons
    const QString brackets[ 2 ] = { "(" , ")" } ;
    for( int i = 0 ; i < 2 ; ++ i )
    {
        bracketPushButtons[ i ] = new QPushButton( brackets[ i ] ) ;
    }

    //declare operator pushbuttons
    const QString operators[ 5 ] = { "+" , "-" , "*" , "/" , "=" } ;
    for( int i = 0 ; i < 5 ; i ++ )
    {
        operatorPushButtons[ i ] = new QPushButton( operators[ i ] ) ;
    }

    //declare clear pushbutton
    clearPushButton = new QPushButton( "clear" ) ;

    //declare layout
    upLayout = new QHBoxLayout ;
    downLayout = new QHBoxLayout ;

    //declare leftdown row layout
    for( int i = 0 ; i < 4 ; i ++ )
    {
        leftDownRowLayout[ i ] = new QHBoxLayout ;
    }
    leftDownLayout = new QVBoxLayout ;

    //declare rightdown row layout
    for( int i = 0 ; i < 3 ; i ++ )
    {
        rightDownRowLayout[ i ] = new QHBoxLayout ;
    }
    rightDownLayout = new QVBoxLayout ;

    globalLayout = new QVBoxLayout ;
}

//built the connect
void Widget::createConnect()
{
    for( int i = 0 ; i < 10 ; ++ i )
    {
        QObject::connect( numberPushButtons[ i ] , SIGNAL( clicked() ) , this , SLOT( pushNumberButton() ) ) ;
    }
    for( int i = 0 ; i < 5 ; ++ i )
    {
        QObject::connect( operatorPushButtons[ i ] , SIGNAL( clicked() ) , this , SLOT( pushOperatorButton() ) ) ;
    }
    for( int i = 0 ; i < 2 ; ++ i )
    {
        QObject::connect( bracketPushButtons[ i ] , SIGNAL( clicked() ) , this , SLOT( pushBracketButton() ) ) ;
    }

    QObject::connect( clearPushButton , SIGNAL( clicked() ) , this , SLOT( pushClearButton() ) ) ;
}

void Widget::createLayout()
{
    upLayout->addWidget( expressionLineEdit ) ;

    //left down
    const int num1[ 3 ] = { 7 , 4 , 1 } ;
    for( int i = 0 ; i < 3 ; ++ i )
    {
        for( int j = 0 ; j < 3 ; ++ j )
        {
            leftDownRowLayout[ i ]->addWidget( numberPushButtons[ j + num1[ i ] ] ) ;
        }
    }

    leftDownRowLayout[ 3 ]->addWidget( numberPushButtons[ 0 ] ) ;
    leftDownRowLayout[ 3 ]->addWidget( bracketPushButtons[ 0 ] ) ;
    leftDownRowLayout[ 3 ]->addWidget( bracketPushButtons[ 1 ] ) ;

    for( int i = 0 ; i < 4 ; ++ i )
    {
        leftDownLayout->addLayout( leftDownRowLayout[ i ] ) ;
    }

    //right down
    const int num2[ 2 ] = { 0 , 2 } ;
    for( int i = 0 ; i < 2 ; ++ i )
    {
        for( int j = 0 ; j < 2 ; ++ j )
        {
            rightDownRowLayout[ i ]->addWidget( operatorPushButtons[ j + num2[ i ] ] ) ;
        }
    }

    rightDownRowLayout[ 2 ]->addWidget( operatorPushButtons[ 4 ] ) ;
    rightDownRowLayout[ 2 ]->addWidget( clearPushButton ) ;

    for( int i = 0 ; i < 3 ; ++ i )
    {
        rightDownLayout->addLayout(( rightDownRowLayout[ i ] ) ) ;
    }

    downLayout->addLayout( leftDownLayout ) ;
    downLayout->addStretch() ;
    downLayout->addLayout( rightDownLayout ) ;

    globalLayout->addLayout( upLayout ) ;
    globalLayout->addLayout( downLayout ) ;

    this->setLayout( globalLayout ) ;
}
