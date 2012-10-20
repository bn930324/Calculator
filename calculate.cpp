/*
 * Copyright (C) 2011 @HIT Footoo Lab
 * Author:shiyanhui
 * Create Date: 2011-3-20
 */
#include"calculate.h"

Calculation::Calculation( string expression )
{
    this->expression = expression ;
    answer = 0 ;
    operator_stack.size = operand_stack.size = 0 ;
    aMap[ 'C' ] = 0 ;
    aMap[ '+' ] = aMap[ '-' ] = 1 ;
    aMap[ '*' ] = aMap[ '/' ] = 2 ;
}

void Calculation::midfix_to_suffix( )
{
    string tmp = "" ;
    //将表达式扫描一遍
    for( int i = 0 ; i < expression.size( ) ; )
    {
        //如果字符是数字，继续循环下去，直到把这个数字找全，最后，在数字后面加一个'.'，以和别的数字区分开
        if( isdigit( expression[ i ] ) )
        {
            while( i < expression.size( ) )
            {
                if( isdigit( expression[ i ] ) )
                {
                    tmp += expression[ i++ ] ;
                }
                else
                    break ;
            }
            tmp += '.' ;
        }
        //如果是空格，ignore
        else if( expression[ i ] == ' ' )
        {
            i++ ;
            continue ;
        }
        //其他的只能是操作符
        else
        {
            if( expression[ i ] == '(' )
            {
                operator_stack.element[ operator_stack.size++ ] = '(' ;
                i++ ;
            }
            else if( expression[ i ] == ')' )
            {
                while( operator_stack.element[ operator_stack.size - 1 ] != '(' )
                {
                    tmp += operator_stack.element[ --operator_stack.size ] ;
                }
                operator_stack.size-- ;
                i++ ;
            }
            else
            {
                while( operator_stack.size > 0 )
                {
                    if( aMap[ expression[ i ] ] <= aMap[ operator_stack.element[ operator_stack.size - 1 ] ] )
                    {
                        tmp += operator_stack.element[ --operator_stack.size ] ;
                    }
                    else
                        break ;
                }
                operator_stack.element[ operator_stack.size++ ] = expression[ i++ ] ;
            }
        }
    }
    while( operator_stack.size > 0 )
    {
        tmp += operator_stack.element[ --operator_stack.size ] ;
    }
    expression = tmp ;
}

void Calculation::calculate( )
{
    int a = 0 , b = 0 , num = 0 ;
    for( int i = 0 ; i < expression.size( ) ; )
    {
        if( isdigit( expression[ i ] ) )
        {
            string tmp = "" ;
            while( expression[ i ] != '.' )
            {
                tmp += expression[ i++ ] ;
            }
            i++ ;
            ss << tmp ;
            ss >> num ;
            ss.clear( ) ;
            operand_stack.element[ operand_stack.size++ ] = num ;
        }
        else
        {
            b = operand_stack.element[ --operand_stack.size ] ;
            a = operand_stack.element[ --operand_stack.size ] ;
            switch( expression[ i ] )
            {
            case '+':
                operand_stack.element[ operand_stack.size++ ] = a + b ;
                break ;
            case '-':
                operand_stack.element[ operand_stack.size++ ] = a - b ;
                break ;
            case '*':
                operand_stack.element[ operand_stack.size++ ] = a * b ;
                break ;
            case '/':
                operand_stack.element[ operand_stack.size++ ] = a * 1.0 / b ;
            }
            i++ ;
        }
    }
    answer = operand_stack.element[ 0 ] ;
}

int Calculation::get_answer( )
{
    return answer ;
}
