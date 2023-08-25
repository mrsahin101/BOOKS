#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSYMBL (1 << 7)
#define MAXMSG (1 << 10)
#define MAXCHBUF (1 << 1)
#define MAXTKBUF (1 << 1)
#define MAXBOILER (1 << 4)

enum { STORE, QUAL, TYPE, VAR, BRACKETS };
enum { OK = 0, ERROR };
enum { NO = 0, YES };

int declaration(char *dec, int ispara);
int dcl(char *name, char *out, int allowanon);
int dirdcl(char *name, char *out, int allowanon);
int args(char *out);

int gettoken(void);
void ungettoken(int ttype, char *tk);
int ws(void);
int name(char *p);
int brackets(char *p);
int oparens(char *p);
int contains(char **names, int count, char *name);

void nextdef(void);
int getch(void);
void ungetch(int c);

int tokentype;
char token[MAXSYMBL];

int chbuf[MAXCHBUF];
int chbufp = 0;

int ttbuf[MAXTKBUF];
char tkbuf[MAXTKBUF][MAXSYMBL];
int tkbufp = 0;

char *types[] = { "void",  "char",   "short",  "int",	  "long",
		  "float", "double", "signed", "unsigned" };
int ntypes = 9;
char *stores[] = { "auto", "register", "static", "extern" };
int nstores = 4;
char *quals[] = { "const", "volatile" };
int nquals = 2;

int main(void)
{
	char dec[MAXMSG];
	while (gettoken() != EOF) {
		if (declaration(dec, NO) != OK) {
			nextdef();
		}
	}
	return 0;
}

int declaration(char *dec, int ispara)
{
	char store[MAXSYMBL + MAXBOILER];
	char qual[MAXSYMBL + MAXBOILER];
	char type[MAXMSG];
	char name[MAXSYMBL];
	char out[MAXMSG];

	store[0] = '\0';
	qual[0] = '\0';
	type[0] = '\0';

	if (tokentype == STORE) {
		sprintf(store, " in %s storage", token);
		gettoken();
	}
	if (tokentype == QUAL) {
		sprintf(qual, " %s", token);
		gettoken();
	}
	if (tokentype != TYPE) {
		printf("\nerror: Expected a type\n");
		return ERROR;
	}
	do {
		if (type[0] != '\0')
			strcat(type, " ");
		strcat(type, token);
	} while (gettoken() == TYPE);
	ungettoken(tokentype, token);

	do {
		out[0] = '\0';
		if (dcl(name, out, ispara) != OK) {
			return ERROR;
		} else if (tokentype != ';' && tokentype != ',' &&
			   tokentype != ')') {
			printf("\nsytax error, got %d/%c\n", tokentype,
			       tokentype);
			return ERROR;
		} else {
			sprintf(dec, "%s:%s%s %s%s", name, qual, out, type,
				store);
			if (!ispara)
				printf("\n%s\n", dec);
		}
	} while (!ispara && tokentype == ',');
	return OK;
}

int dcl(char *name, char *out, int allowanon)
{
	int ns, rslt;

	for (ns = 0; gettoken() == '*';)
		ns++;
	if ((rslt = dirdcl(name, out, allowanon)) != OK)
		return rslt;
	while (ns-- > 0)
		strcat(out, " pointer to");
	return OK;
}

int dirdcl(char *name, char *out, int allowanon)
{
	int rslt;

	if (tokentype == VAR)
		strcpy(name, token);
	else if (tokentype == '(') {
		if ((rslt = dcl(name, out, allowanon)) != OK)
			return rslt;
		if (tokentype != ')') {
			printf("\nerror: missing )\n");
			return ERROR;
		}
	} else if (allowanon) {
		strcpy(name, "<unnamed>");
		allowanon = NO;
		ungettoken(tokentype, token);
	} else {
		printf("\nerror: expected variable name or (dcl)\n");
		return ERROR;
	}
	while (gettoken() == '(' || tokentype == BRACKETS) {
		if (tokentype == '(') {
			strcat(out, " function taking");
			if ((rslt = args(out)) != NO) {
				return rslt;
			}
		} else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
	return OK;
}

int args(char *out)
{
	char dec[MAXMSG];
	int argcount = 0;
	char *seperator = " argument ";
	int expectarg = YES;

	if (gettoken() == ')') {
		/* fun() */
		expectarg = NO;
	} else if (tokentype == TYPE && strcmp(token, "void") == 0) {
		if (gettoken() == ')')
			/* fun(void) */
			expectarg = NO;
		else {
			ungettoken(tokentype, token);
			tokentype = TYPE;
			strcpy(token, "void");
		}
	}

	if (expectarg) {
		do {
			if (argcount++ > 0)
				gettoken();
			if (declaration(dec, YES) != OK)
				return ERROR;
			strcat(out, seperator);
			strcat(out, dec);
			seperator = " and argument ";
		} while (tokentype == ',');
	}
	if (tokentype == ')') {
		if (argcount == 0)
			strcat(out, " no arguments");
		strcat(out, " returning");
	} else {
		printf("\nerror: expected closing parentheses "
		       "after arguments (got %d/%c)\n",
		       tokentype, tokentype);
		return ERROR;
	}
	return OK;
}

int gettoken(void)
{
	if (tkbufp > 0) {
		--tkbufp;
		tokentype = ttbuf[tkbufp];
		strcpy(token, tkbuf[tkbufp]);
	} else {
		ws();
		if (!(oparens(token) || brackets(token) || name(token))) {
			token[0] = tokentype = getch();
			token[1] = '\0';
		}
	}
	return tokentype;
}

void ungettoken(int ttype, char *tk)
{
	if (tkbufp >= MAXTKBUF) {
		printf("ungettoken: too many tokens\n");
	} else {
		ttbuf[tkbufp] = ttype;
		strcpy(tkbuf[tkbufp], tk);
		tkbufp++;
	}
}

int ws(void)
{
	char c;
	int rslt = NO;

	while (isspace(c = getch()))
		rslt = YES;
	ungetch(c);
	return rslt;
}

int name(char *p)
{
	char c, *tkn;
	int rslt = NO;

	tkn = p;
	if (isalpha(c = getch()) || c == '_') {
		rslt = YES;
		for (*p++ = c; isalnum(c = getch()) || c == '_';)
			*p++ = c;
		*p = '\0';
		if (contains(types, ntypes, tkn))
			tokentype = TYPE;
		else if (contains(stores, nstores, tkn))
			tokentype = STORE;
		else if (contains(quals, nquals, tkn))
			tokentype = QUAL;
		else
			tokentype = VAR;
	}
	ungetch(c);
	return rslt;
}

int brackets(char *p)
{
	char c;

	if ((c = getch()) == '[') {
		for (*p++ = c; (*p++ = (c = getch())) != ']';)
			;
		*p = '\0';
		tokentype = BRACKETS;
		return YES;
	}
	ungetch(c);
	return NO;
}

int oparens(char *p)
{
	char c;

	if ((c = getch()) == '(') {
		*p++ = tokentype = '(';
		*p = '\0';
		return YES;
	}
	ungetch(c);
	return NO;
}

void nextdef(void)
{
	int c;

	while ((c = getch()) != ';' && c != EOF)
		;
	if (c == EOF)
		ungetch(c);
}

int contains(char **names, int count, char *name)
{
	int i;

	for (i = 0; i < count; i++)
		if (strcmp(name, names[i]) == 0)
			return YES;
	return NO;
}

int getch(void)
{
	return (chbufp > 0) ? chbuf[--chbufp] : getchar();
}

void ungetch(int c)
{
	if (chbufp >= MAXCHBUF)
		printf("ungetch: too many characters\n");
	else
		chbuf[chbufp++] = c;
}