#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <locale>
#include <Windows.h>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <thread>
#include <unistd.h>

using namespace std;

DWORD fact(int N)
{
    if (N == 0)
        return 1;
    else 
        return N * fact(N - 1); 
}


void p(string A, string s1)
{
   ofstream f1;
   f1.open(s1, ios_base::app);
   f1<<A<<"\n";
   f1.close();
}

void P(int k, string A, int N, string s1)
{
    if (k == N)
        p(A, s1);
    for (int i = k; i < N; i++)
    {
        swap(A[k], A[i]);
        P(k + 1, A, N, s1);
    }
}

void foo (FILE *in)
{
	ofstream f1;
	
	char a[255], str[255];
	int i=0,j=0;
	char *s;
	string s1,stroka="";
	while(!feof(in))
	{
		s = fgets (str,sizeof(str),in);
		j++;
		itoa(j,a,10);
		s1=a;
		s1=s1+".txt";
		i=0;
		for (i=0; str[i]!=NULL; i++)
		{
			stroka+=str[i];
		}
		
		cout<<"POTOK1"<<endl;
		f1.open(s1, ios_base::out);
		f1<<"Исходная строка: "<<str<<"\n";
		f1<<"Количество возможных перестановок: "<<itoa(fact(stroka.length()), str, 10)<<"\n\nВыполнил поток #1\n"<<"\nВозможные перестановки: \n\n";
		f1.close();
		
   		sort(stroka.begin(), stroka.end());
    	P(0, stroka, stroka.length(), s1);
		
		
		
		stroka="";
		
		
	}
}



void bar (FILE *in2)
{
	ofstream f1;
	
	char a[255], str[255];
	int i=0,j=0;
	char *s;
	string s1,stroka="";
	while(!feof(in2))
	{
		s = fgets (str,sizeof(str),in2);
		j++;
		itoa(j,a,10);
		s1=a;
		s1=s1+".txt";
		i=0;
		for (i=0; str[i]!=NULL; i++)
		{
			stroka+=str[i];
		}
		
		cout<<"POTOK2"<<endl;
		f1.open(s1, ios_base::out);
		f1<<"Исходная строка: "<<str<<"\n";
		f1<<"Количество возможных перестановок: "<<itoa(fact(stroka.length()), str, 10)<<"\n\nВыполнил поток #2\n"<<"\nВозможные перестановки: \n\n";
		
		f1.close();
		
		sort(stroka.begin(), stroka.end());
    	P(0, stroka, stroka.length(), s1);
    	
    	stroka="";
	}
}



int main (int argc, char *argv[])
{
	FILE *in, *in2;
	ofstream f1;
	char str[255],a[255];
	int i=0,j=0;
	string s1;
	char *s,*s2;
	
	in = fopen (argv[1],"r");
	in2 = fopen (argv[2],"w");
	
	while(!feof(in))
	{
		s = fgets (str,sizeof(str),in);
		fprintf(in2,s);
	}
	
	fclose(in);
	fclose(in2);
	
	
	in = fopen (argv[1],"r");
	in2 = fopen (argv[2],"r");

	 
	cout<<"LOADING....DONE"<<endl;
	
		thread t1 (foo, in);
		thread t2 (bar, in2);
		t1.join();
		t2.join();
	
	cout<<"SUCCESS!";
	fclose(in);
	fclose(in2);
	
}

