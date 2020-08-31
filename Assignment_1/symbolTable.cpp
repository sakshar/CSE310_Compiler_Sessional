#include <bits/stdc++.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define MAX_SIZE 15
using namespace std;

ofstream out("output.txt");
class symbolInfo
{
public:
    string name;
    string type;
    symbolInfo *prev;
    symbolInfo *next;

    symbolInfo();
};

symbolInfo::symbolInfo()
{
    this->next = 0;
    this->prev = 0;
}

class symbolTable
{
public:
    int n;
    symbolInfo **head;
    symbolInfo **tail;

    symbolTable(int n);
    int hashFunction(string name);
    void insertSymbol(string name, string type);
    int lookSymbol(string name);
    void deleteSymbol(string name);
    void printTable();
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

void symbolTable::insertSymbol(string name, string type)
{
    cout<<"I "<<name<<" "<<type<<endl;
    out<<"I "<<name<<" "<<type<<endl;
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
        cout<<"< "<<name<<","<<type<<" > Inserted at position "<<row<<", "<<col<<endl;
        out<<"< "<<name<<","<<type<<" > Inserted at position "<<row<<", "<<col<<endl<<endl<<endl;
        return;
    }
    cout<<"< "<<name<<","<<type<<" > already exists\n";
    out<<"< "<<name<<","<<type<<" > already exists\n"<<endl<<endl;
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
    cout<<"D "<<name<<endl;
    out<<"D "<<name<<endl;
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
        cout<<"Deleted from "<<row<<", "<<col<<endl;
        out<<"Deleted from "<<row<<", "<<col<<endl<<endl<<endl;
        return;
    }
    cout<<name<<" not found\n";
    out<<name<<" not found\n"<<endl<<endl;
}

void symbolTable::printTable()
{
    cout<<"P\n";
    out<<"P\n";
    int row = this->n;
    symbolInfo *temp = new symbolInfo();
    for(int i = 0; i<row; i++)
    {
        temp = head[i];
        cout<<i<<"-->";
        out<<i<<"-->";
        while(temp != 0)
        {
            cout<<" < "<<temp->name<<" : "<<temp->type<<" >";
            out<<" < "<<temp->name<<" : "<<temp->type<<" >";
            temp = temp->next;
        }
        cout<<endl;
        out<<endl;
    }
    out<<endl<<endl;
}

int main()
{
    char m[20] = "abal";
    strcat(m,"dhur");
    printf("%s\n",m);
    symbolTable** table = (symbolTable**)malloc(2*sizeof(symbolTable*));
    table[0] = new symbolTable(13);
    table[1] = new symbolTable(31);
    table[0]->insertSymbol("a","ID");
    table[1]->insertSymbol("a","ID");
    table[0]->printTable();
    table[1]->printTable();
    /*symbolTable tab(7);
    tab.insertSymbol("foo","FUNCTION");
    tab.insertSymbol("i","IDENTIFIER");
    int x = tab.lookSymbol("foo");
    x = tab.lookSymbol("j");
    tab.insertSymbol("123","NUMBER");
    tab.printTable();
    tab.deleteSymbol("ja");
    tab.deleteSymbol("123");
    tab.printTable();
    tab.insertSymbol("231","NUMBER");
    tab.insertSymbol("105","NUMBER");
    tab.printTable();
    tab.insertSymbol("<=","RELOP");
    tab.insertSymbol("==","RELOP");
    tab.printTable();
    tab.insertSymbol("<=","RELOP");
    tab.deleteSymbol("==");
    tab.printTable();
    tab.deleteSymbol("231");
    tab.insertSymbol("204","NUMBER");
    tab.printTable();
    tab.deleteSymbol("204");
    tab.insertSymbol("123","NUMBER");
    tab.printTable();*/

    /*freopen("in2.txt","r",stdin);
    int n;
    char ch;
    cin>>n;
    symbolTable tab(n);
    while(cin>>ch)
    {
        if(ch == 'I')
        {
            string name, type;
            cin>>name>>type;
            tab.insertSymbol(name,type);
        }
        else if(ch == 'L')
        {
            string name;
            cin>>name;
            cout<<"L "<<name<<endl;
            out<<"L "<<name<<endl;
            int ins = tab.lookSymbol(name);
            if(ins == NULL_VALUE)
            {
                cout<<name<<" not found\n";
                out<<name<<" not found\n"<<endl<<endl;
            }
            else
            {
                int row = tab.hashFunction(name);
                symbolInfo *temp = new symbolInfo();
                temp = tab.head[row];
                for(int i = 0; i<ins; i++)
                    temp = temp->next;
                cout<<"< "<<name<<","<<temp->type<<" > Found at position "<<row<<", "<<ins<<endl;
                out<<"< "<<name<<","<<temp->type<<" > Found at position "<<row<<", "<<ins<<endl<<endl<<endl;
            }
        }
        else if(ch == 'D')
        {
            string name;
            cin>>name;
            tab.deleteSymbol(name);
        }
        else if(ch == 'P')
            tab.printTable();
    }*/
    out.close();
}
