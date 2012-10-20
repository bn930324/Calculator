/*
 * Copyright (C) 2011 @HIT Footoo Lab
 * Author:shiyanhui
 * Create Date: 2011-3-20
 */
#ifndef CALCULATE_H
#define CALCULATE_H

#include<string>
#include<sstream>
#include<map>
#define STACK_SIZE 100

using namespace std ;

struct CharStack
{
    int size ;
    char element[ STACK_SIZE ] ;
};

struct IntStack
{
    int size ;
    int element[ STACK_SIZE ] ;
};

class Calculation
{
public:
    //构造函数
    Calculation( string ) ;
    //中缀表达式转换为后缀表达式
    void midfix_to_suffix() ;
    //计算
    void calculate() ;
    //得到结果
    int get_answer() ;
private:
    string expression ; //表达式
    int answer ; //result
    CharStack operator_stack ; //存储操作符
    IntStack operand_stack ; //存储操作数
    stringstream ss ;
    map< char , int > aMap ; //操作符到优先级的映射
};

#endif

