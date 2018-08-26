%{
int numChars = 0, numWords = 0, numLines = 0;
%}

%option noyywrap



%%

[0-9]+  {
			printf("Number = %s\n", yytext);
			return 0;
		}

[a-zA-Z0-9]* {
			printf("Identifier = %s \n", yytext);
			return 0;
		}

[ \t\n\r]+	{
		}

%%

int main() {
	while(true)
	{
			yylex();
	}
}