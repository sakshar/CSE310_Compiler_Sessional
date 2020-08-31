#ifndef INFO_H
#define INFO_H

#include <bits/stdc++.h>

using namespace std;

union value
{
    int i;
    float f;
    char c;
    int* i_Arr;
    float* f_Arr;
    char* c_Arr;
};

class symbolInfo
{
public:
    string name;
    string type;
	string code;
    int dataType=-1;
    int index = -1;
	//int pos = -1;
    value v;
    int sz = 0;
    symbolInfo *prev;
    symbolInfo *next;

    symbolInfo()
    {
        this->next = 0;
        this->prev = 0;
		this->code = "";
    }
    symbolInfo(string name, string type)
    {
        this->name = name;
        this->type = type;
		this->code = "";
        this->next = 0;
        this->next = 0;
    }
	symbolInfo(const symbolInfo* s)
	{
		this->name = s->name;
		this->type = s->type;
		this->dataType = s->dataType;
		this->index = s->index;
		this->sz = s->sz;
		this->code = s->code;
		//this->pos = s->pos;
		this->next = s->next;
        this->prev = s->prev;
		if(s->sz == 0)
		{
				if(s->dataType==0)this->v.i = s->v.i;
				else if(s->dataType==1)this->v.f = s->v.f;
				else if(s->dataType==2)this->v.c = s->v.c;
		}
		else
		{
			if(s->dataType==0)
			{
				this->v.i_Arr = (int*)malloc((s->sz)*sizeof(int));
				for(int k = 0; k<s->sz; k++) this->v.i_Arr[k] = s->v.i_Arr[k];
			}
			else if(s->dataType==1)
			{
				this->v.f_Arr = (float*)malloc((s->sz)*sizeof(float));
				for(int k = 0; k<s->sz; k++) this->v.f_Arr[k] = s->v.f_Arr[k];
			}
			else if(s->dataType==2)
			{
				this->v.c_Arr = (char*)malloc((s->sz)*sizeof(char));
				for(int k = 0; k<s->sz; k++) this->v.c_Arr[k] = s->v.c_Arr[k];
			}
		}
	}
};
#endif
