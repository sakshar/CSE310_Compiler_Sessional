#include <bits/stdc++.h>
using namespace std;
void optimize(const char* f)
{
    ofstream opt;
    ifstream unopt;
    unopt.open(f);
    bool am = true;
    bool mul = true;
    if(!unopt.is_open()){
		printf("Cannot open specified file\n");
		return;
	}
    opt.open("1305002_optimized.asm");

    string present = "";
    string prev = "";
	if(unopt.is_open())
	{
		while(!unopt.eof())
		{
			prev = present;
			getline(unopt,present);

			if((prev[0]=='M'&&present[0]=='M')&&(prev[1]=='O'&&present[1]=='O')&&(prev[2]=='V'&&present[2]=='V'))
			{
				if((present.length()==9)&&(prev[4]==present[7]&&prev[5]==present[8])&&(prev[8]==present[4]))
				{
					am = false;
				}
				else if((present.length()==9)&&(prev[4]==present[8])&&(prev[7]==present[4]&&prev[8]==present[5]))
				{
					am = false;
				}
				else if((present.length()==10)&&(prev[4]==present[8] && prev[5]==present[9])&&(prev[8]==present[4]&&prev[9]==present[5]))
				{
					am = false;
				}
				else if((present.length()==11)&&(prev[4]==present[8]&&prev[5]==present[9]&&prev[6]==present[10])&&(prev[9]==present[4]&&prev[10]==present[5]))
				{
					am = false;
				}
				else if((present.length()==11)&&(prev[4]==present[9]&&prev[5]==present[10])&&(prev[8]==present[4]&&prev[9]==present[5]&&prev[10]==present[6]))
				{
					am = false;
				}
				else if((present.length()==9) && (present[8]=='1'))
				{
					am = false;
					mul = false;
				}
			}
			else if((((present[0]=='A')&&(present[1] == 'D'))||((present[0]=='S')&&(present[1] == 'U')))&&(present[8]=='0'))
			{
				am = false;
			}
			else if((present[0]=='M')&&(present[1]=='U'))
			{
				if(prev[8] == '1')
				{
					am = false;
					mul = true;

				}
			}
			if(!mul && am)
			{
			   opt<<prev<<endl;
			   opt<<present<<endl;
			   mul = true;
			}
			else if(am)
			{
				opt<<present<<endl;
			}
			else am = true;
		}
	}
	unopt.close();
	return;
}

/*int main()
{
    optimize("1305002_code.asm");
    return 0;
}*/
