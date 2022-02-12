%option noyywrap
%{
	#include<stdio.h>
	#include<string.h>
	int i = 0;
%}

%%
	([a-zA-Z0-9])*    {i++;}
	{printf("%d\n", i); i = 0;}
%%

int main()
{	
	string s;
	while(gets(s){
		yylex();
	}

	return 0;
}