#include <bits/stdc++.h>
#include "1305002_SymbolInfo.h"

#define NULL_VALUE -99999

using namespace std;

class symbolTable
{
public:
    int n;
    symbolInfo **head;
    symbolInfo **tail;

    symbolTable(int n);
    int hashFunction(string name);
    void insertSymbol(FILE *logout,string name, string type);
    int lookSymbol(string name);
    void deleteSymbol(string name);
    void printTable(FILE *logout);
};

symbolTable::symbolTable(int n)
{
    this->n = n;
    this->head = new symbolInfo*[n];
    this->tail = new symbolInfo*[n];
    for(int i = 0; i<n; i++)
    {
        head[i] = 0;
        tail[i] = 0;
    }
}

int symbolTable::hashFunction(string name)
{
    int sum = 0;

    for(int i = 0; i<name.length(); i++)
    {
        sum+=name[i];
    }

    return sum%this->n;
}

void symbolTable::insertSymbol(FILE *logout,string name, string type)
{
    int pre = lookSymbol(name);
    if (pre == NULL_VALUE)
    {
        int row = hashFunction(name);
        symbolInfo *newSymbol = new symbolInfo();
        newSymbol->name = name;
        newSymbol->type = type;
        if(head[row] == 0)
        {
            head[row] = newSymbol;
            tail[row] = newSymbol;
        }
        else
        {
            newSymbol->next = 0;
            newSymbol->prev = tail[row];
            tail[row]->next = newSymbol;
            tail[row] = newSymbol;
        }
        int col = lookSymbol(name);
        return;
    }
    fprintf(logout,"<%s,%s> already exists\n", name.c_str(), type.c_str());
}

int symbolTable::lookSymbol(string name)
{
    int row = hashFunction(name);
    symbolInfo *temp = new symbolInfo();
    temp = head[row];
    int col = 0;
    while(temp!=0)
    {
        if(temp->name == name)
        {
            return col;
        }
        else
        {
            temp = temp->next;
            col++;
        }
    }
    return NULL_VALUE;
}

void symbolTable::deleteSymbol(string name)
{
    int col = lookSymbol(name);
    if(col != NULL_VALUE)
    {
        int row = hashFunction(name);
        symbolInfo * temp = new symbolInfo();
        temp = head[row];
        if(col == 0)
        {
            if(head[row] == tail[row])
            {
                head[row] = 0;
                tail[row] = 0;
            }
            else
            {
                head[row]->next->prev = 0;
                head[row] = head[row]->next;
            }
        }
        else
        {
            for(int i = 0; i<col; i++)
                temp = temp->next;
            if(temp == tail[row])
            {
                tail[row]->prev->next = 0;
                tail[row] =  tail[row]->prev;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
        }
        delete temp;
        return;
    }
}

void symbolTable::printTable(FILE *logout)
{
    int row = this->n;
    symbolInfo *temp = new symbolInfo();
    for(int i = 0; i<row; i++)
    {
        temp = head[i];
        if(temp!=0)
        {
            fprintf(logout,"%d --> ",i);
            while(temp != 0)
            {
                fprintf(logout,"<%s,%s>",temp->name.c_str(),temp->type.c_str());
                temp = temp->next;
            }
            fprintf(logout,"\n");

        }
    }
}
