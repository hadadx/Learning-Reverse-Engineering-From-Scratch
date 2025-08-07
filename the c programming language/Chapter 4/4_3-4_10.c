/*
Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.

Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.

Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
Appendix B, Section 4.

Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.

Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?

Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.

Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design.

Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define PEWVIOUS_NUMBER 2
#define PEWVIOUS_MINUS 1
#define PEWVIOUS_NONE 0

int getop(char num, char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

void print_top();
void duplicate();
void swap();
void clear();

int sp = 0;
double val[MAXVAL];

char buf[BUFSIZE];
int bufp = 0;

char eofBushd = 0;

char line[MAXOP];
int i = 0;

int main()
{
    int type;
    int previous = PEWVIOUS_NONE;
    double op2;
    char s[MAXOP];

    char varClickd;
    double varA = 0;
    double varB = 0;

    fgets(line, sizeof(line), stdin);

    while (line[i] != '\0')
    {
        type = getop(line[i], s);

        switch (type)
        {
        case NUMBER:
            if (previous == PEWVIOUS_MINUS)
            {
                double t = atof(s);
                t = -t;
                push(t);
                previous = PEWVIOUS_NONE;
            }

            else
            {
                push(atof(s));
                previous = PEWVIOUS_NUMBER;
            }

            break;
        case '+':
            push(pop() + pop());
            previous = PEWVIOUS_NONE;
            break;
        case '*':
            push(pop() * pop());
            previous = PEWVIOUS_NONE;
            break;
        case '-':
            if (previous == PEWVIOUS_NUMBER)
            {
                op2 = pop();
                push(pop() - op2);
                previous = PEWVIOUS_NONE;
            }
            else
            {
                previous = PEWVIOUS_MINUS;
            }

            break;

        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
                previous = PEWVIOUS_NONE;
            }
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = (int)pop();
            if (op2 != 0.0)
            {
                push((int)pop() % (int)op2);
                previous = PEWVIOUS_NONE;
            }
            else
                printf("error: integer modulo by zero\n");
            break;
        case 'p':
            print_top();
            break;
        case 'd':
            duplicate();
            break;
        case 's':
            swap();
            break;
        case 'c':
            clear();
            break;
        case 'i':
            op2 = pop();
            push(sin(op2));
            break;
        case 'e':
            op2 = pop();
            push(exp(op2));
            break;
        case '=':
            if (varClickd == 'A')
            {
                pop();
                varA = pop();
            }
            else if (varClickd == 'B')
            {
                pop();
                varB = pop();
            }
            break;

        case 'A':
            push(varA);
            varClickd = 'A';
            break;
        case 'B':
            push(varB);
            varClickd = 'B';
            break;
        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '\n':
            printf("\t%.2lf\n", pop());
            break;
        case ' ':
            break;
        case '\t':
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char num, char s[])
{
    int is;

    if (num == ' ' || num == '\t')
    {
        i++;
       return num;
    }

    if (!isdigit(num) && num != '.')
    {
        i++;
        return num;
    }

    is = 0;

    if (isdigit(num))
    {
        if (line[i + 1] == '.')
        {
            while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            {
                s[is] = line[i];
                is++;
                i++;
            }
            s[is++] = '\0';
            return NUMBER;
        }
        else
        {
            s[is] = num;
            s[++is] = '\0';
            i++;
            return NUMBER;
        }
    }
}

int getch(void)
{
    if (eofBushd == 1)
    {
        eofBushd = 0;
        return EOF;
    }

    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (c == EOF)
    {
        eofBushd = 1;
        buf[bufp++] = c;
    }

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void print_top()
{
    double top = val[sp - 1];
    printf("top of the stack = %.2lf\n", top);
}
void duplicate()
{
    push(val[sp - 1]);
}
void swap()
{
    double first = pop();
    double secound = pop();

    push(first);
    push(secound);
}

void clear()
{
    while (pop() != 0.0)
        ;
}

void ungets(const char s[])
{
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        ungetch(s[i]);
    }
}