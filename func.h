#pragma once

#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
#include<iomanip>
using namespace std;

void write_account();
void dep_draw(int n , int choice);	
void display(int n);	
void modify_account(int n);	
void delete_account(int n);	
void display_all();		

class account
{
    int ac;
    char name[50];
    int deposit;
    char type;

public:
    int retac() const;
    int retdeposit() const;
    char rettype() const;
    void show_account();
    void report() const;
    void dep(int);
    void draw(int);
    void create_account();
    void modify();
}; 
