#include <bits/stdc++.h>

using namespace std;

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
