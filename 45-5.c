#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void in_comment(int c);
void search(int c);
void in_quotes(int c);

FILE* in, * out;
int rbrackets, sbrackets, braces, quotes1, quotes2;

int main()
{
    int c;
    char file_name[20];
    printf("Input file name: ");
    gets(file_name);
    in = fopen(file_name, "rb");//Открыть файл для чтения
    if ((in = fopen(file_name, "rb")) == NULL)
    {
        perror(file_name);
        return 1;
    }
    while ((c = fgetc(in)) != EOF)
    {
        if (c == '/')
        {
            if ((c = fgetc(in)) == '*')
                in_comment(c);//внутри комментария
            else
                search(c);
        }
        else if (c == '\'' || c == '"')
        {
            if (c == '\'')
                quotes1++;
            if (c == '"')
                quotes2++;
            in_quotes(c);
        }
        else
            search(c);
        if (quotes1 < 0)//вывод ошибок
        {
            printf("NOC\n");
            quotes1 = 0;
        }
        if (quotes2 < 0)
        {
            printf("NDC\n");
            quotes2 = 0;
        }
        if (rbrackets < 0)
        {
            printf("NCS\n");
            rbrackets = 0;
        }
        if (sbrackets < 0)
        {
            printf("NKS\n");
            sbrackets = 0;
        }
        if (braces < 0)
        {
            printf("NFS\n");
            braces = 0;
        }
    }
    if (quotes1 > 0)
    {
        printf("NOC\n");
        quotes1 = 0;
    }
    if (quotes2 > 0)
    {
        printf("NDC\n");
        quotes2 = 0;
    }
    if (rbrackets > 0)
    {
        printf("NKRS\n");
        rbrackets = 0;
    }
    if (sbrackets > 0)
    {
        printf("NKVS\n");
        sbrackets = 0;
    }
    if (braces > 0)
    {
        printf("NFS\n");
        braces = 0;
    }
    fclose(in);
    return 0;
}

/*поиск символов*/
void search(int c)
{
    if (c == '(')
        rbrackets++;
    if (c == '[')
        sbrackets++;
    if (c == '{')
        braces++;
    if (c == ')')
        rbrackets--;
    if (c == ']')
        sbrackets--;
    if (c == '}')
        braces--;
}

/*пропуск комментариев*/
void in_comment(int c)
{
    int d;
    c = fgetc(in);
    d = fgetc(in);
    while (c != '*' || d != '/')
    {
        c = d;
        d = fgetc(in);
    }
}

/*поиск кавычек*/
void in_quotes(int c)
{
    int d=0;
    while (d != ')' && d != ';' && d != ',' && d != '}' && d != ']')
    {
        d = fgetc(in);
        if (d == '\\')
            getchar();
        if (d == '\'')
            quotes1--;
        if (d == '"')
            quotes2--;
    }
    if (d == ')')
        rbrackets--;
    if (d == ']')
        sbrackets--;
    if (d == '}')
        braces--;
}
