# Strings

- Characters set / ASCII codes
- Characters Array
- String
- Creating a string

A character a takes 1 byte of memory to store the ascii code for example ascii code of A = 65; In the char temp='A'; ASCII code 65 is stored in tamp;

## string declaration

char x[5];
char x[5]={'A','B','C','D','E'};
char x[]={'A','B','C','D','E'};
char x[5]={'A','B','C','0','0'};
char name[] = "JOHN";

string is set of characters

'\0' string delimeter. This is use to represent the end of the string.
Also known as End of string character, NULL char, string terminator.

char name[10]={'J','O','H','N','\0'}
Array Characters name {'J','O','H','N',\0,0,0,0,0,0}

```c
char name[10]={'J','O','H','N','\0'}
printf("%s",name);
scanf("%s",name); // this only takes a single word (Taj mahel)
gets(name); // takes multiple words in a string
```

## Length of a string

```c
int main()
{
    char s[] = "welcome";
    for(int i=0;s[i]!='\0';i++)
    {}
    printf("Length of string S = %d",i);
    return 0;
}

```

## Changing the case ( Lower, Upper )

```c
int main()
{
    char s[] = "WELCOME";
    char s[] = "WeLCom4"; // if we have other then alphabets it'll be untouched
    for(int i=0;s[i]!='\0';i++)
    {
        // s[i]=s[i]+32; to covert them to lower
        // s[i]=s[i]-32; to convert them to upper
        if(a[i]>=65 && a[i]<=90)
            a[i]+=32;
        else if(a[i]>=97 or 'a' && a[i]<=122)
            a[i]-=32;
    }
    printf("%s",s);
    return 0;
}

```

## Counting vowels and consonents

```c
int main()
{
    char s[] = "How are you";
    int vcount = 0, ccount = 0;
    for(int i=0;s[i]!='\0';i++)
    {
        if (a[i]='a' || 'i' ....||'E') 
        {
            vcount++;
        }
        else if((a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122))
        {
            ccount++;
        }
    }
    printf("Length of string S = %d",i);
    return 0;
}

```

## Count words

```c
int main()
{
    char s[] = "How are you";
    int word=0
    for(int i=0;s[i]!='\0';i++)
    {
        if(a[i]=='')
        {
            word++;
        }
    }
    printf("Length of string S = %d",word+1);
    return 0;
}
```

What if we have white space ( continue amount of spaces )

```c
int main()
{
    char a[] = "How are you";
    //char a[] = "How are   u";
    int word=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ' && a[i-1]!=' ')
        {
            word++;
        }
    }
    printf("Length of string S = %d",word+1);
    return 0;
}
```

## validate a string

- There are two methods to check weather a string is valid or not else we can use regular expression.

```c
valid(char *name)
{
    for(int i=0;name[i]!='\0';i++ )
    {
        if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char *name="Ani?321";
    if(valid(name)){
        printf("valid string");
    }
    else
    {
        printf("invalid string");
    }
}
```
