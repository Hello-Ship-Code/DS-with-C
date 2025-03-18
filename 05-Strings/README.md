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

## Using C-style strings with gets (not recommended)

```c
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char name[100];
    printf("Enter a name: ");
    gets(name); // gets is unsafe and not recommended
    printf("\nHello, %s\n", name);
    return 0;
}

```

## Using std::getline

```c
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    cout << "Enter a name: ";
    getline(cin, name);
    cout << "Hello, " << name << endl;
    return 0;
}

```

## Length of a string

```c
int main()
{
    char s[] = "welcome";
    int i; // If not declared here it'll give out of scope error as we are using n outside for loop;
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
    char A[] = "Welcome";
    // char A[] = "WeLCom4"; // if we have other then alphabets it'll be untouched
    for(int i=0;A[i]!='\0';i++)
    {
        // s[i]=s[i]+32; to covert them to lower
        // s[i]=s[i]-32; to convert them to upper
        if(A[i]>=65 && A[i]<90)
            {
                A[i]+=32;
            }
            else if( A[i]>=97 && A[i]<122)
            {
                A[i]-=32;
            }
    }
    printf("Length of string A = %d\n",i);
    printf("The string %s: ",A);
    return 0;
}
output: wELCOME;
```

## Counting vowels and consonants

```c
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    int vcount = 0, ccount = 0;

    cout << "Enter a string: ";
    getline(cin, a);

    for (int i = 0; i < a.length(); ++i) {
        char ch = a[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vcount++;
        } else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            ccount++;
        }
    }

    cout << "Number of vowels: " << vcount << endl;
    cout << "Number of consonants: " << ccount << endl;

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
#include <iostream>

int main() {
    char a[] = "How are you";  // Example with normal spacing
    // char a[] = "How are   u";  // Example with multiple spaces

    int word = 0;
    bool inWord = false;

    for(int i = 0; a[i] != '\0'; i++) {
        if(a[i] != ' ') {
            if(!inWord) {
                word++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    printf("Number of words = %d\n", word);
    return 0;
}

```

## validate a string

- There are two methods to check weather a string is valid or not or else we can use regular expression.

```c
#include <iostream>
#include <string>

using namespace std;

// Function to check if a string is alphanumeric
bool isAlphanumeric(const string &name) {
    for (int i = 0; i < name.length(); ++i) {
        if (!(name[i] >= 'A' && name[i] <= 'Z') && 
            !(name[i] >= 'a' && name[i] <= 'z') && 
            !(name[i] >= '0' && name[i] <= '9')) {
            return false;
        }
    }
    return true;
}

int main() {
    string name;
    cout << "Enter a string: ";
    getline(cin, name);

    if (isAlphanumeric(name)) {
        cout << "The string is alphanumeric." << endl;
    } else {
        cout << "The string contains non-alphanumeric characters." << endl;
        return 0;
    }

    // Further processing can be done here if the string is alphanumeric

    return 0;
}

```

## Reverse a string

```c
#include <stdio.h>

int main() {
    char A[] = "Python";
    char B[7];  // Array to hold the reversed string including the null terminator
    int i;

    // Find the length of the string
    for (i = 0; A[i] != '\0'; i++) {}
    i = i - 1;  // Adjust i to point to the last character

    // Reverse the string into B
    int j;
    for (j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    B[j] = '\0';  // Null terminate the reversed string

    // Print the reversed string
    printf("%s\n", B);

    return 0;
}

```

```c
#include <stdio.h>

int main() {
    char A[] = "Python";
    char t;
    int i, j;

    // Find the length of the string
    for (j = 0; A[j] != '\0'; j++) {}
    j = j - 1;  // Adjust j to point to the last character

    // Reverse the string
    for (i = 0; i < j; i++, j--) {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }

    // Print the reversed string
    printf("%s\n", A);

    return 0;
}

```

### comparing & palindrome

```c
#include <stdio.h>

int main() {
    char A[] = "Painter";
    char B[] = "Painting";
    int i, j;

    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++) {
        if (A[i] != B[j]) {
            break;
        }
    }

    if (A[i] == B[j]) {
        printf("Equal");
    } else if (A[i] < B[j]) {
        printf("Smaller");
    } else {
        printf("Greater");
    }

    return 0;
}

```

## palindrome

```c
#include <stdio.h>

int main() {
    char A[] = "Python";
    char B[7];  // Array to hold the reversed string, 7 including the null terminator
    int i, j;

    // Find the length of the string
    for (i = 0; A[i] != '\0'; i++) {}
    i = i - 1;  // Adjust i to point to the last character

    // Reverse the string into B
    for (j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    B[j] = '\0';  // Null terminate the reversed string

    // Check if A is a palindrome by comparing it with B
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++) {
        if (A[i] != B[j]) {
            break;
        }
    }

    if (A[i] == '\0' && B[j] == '\0') {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}


```

or

```c
#include <stdio.h>
#include <string.h> // For strlen

int main() {
    char A[] = "Python";
    int length = strlen(A); // Find the length of the string
    char B[length + 1];  // Array to hold the reversed string including the null terminator
    int i, j;

    // Reverse the string into B
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    B[j] = '\0';  // Null terminate the reversed string

    // Check if A is a palindrome by comparing it with B
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++) {
        if (A[i] != B[j]) {
            break;
        }
    }

    if (A[i] == '\0' && B[j] == '\0') {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}

```

or

```c
#include <stdio.h>
#include <string.h> // For strlen function

int main() {
    char A[] = "Python";
    int length = strlen(A);
    int isPalindrome = 1;  // Assume the string is a palindrome

    // Check for palindrome
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (A[i] != A[j]) {
            isPalindrome = 0;  // Found a mismatch
            break;  // No need to continue checking
        }
    }

    // Print if the string is a palindrome
    if (isPalindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}

```

## Duplicates

- comparing with other letter
- using hashing
- using bitwise

```c
int main(){
    char A[] = "finding";
    int H[26],i;
    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]+=1;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            printf("%c",i+97);
            printf("%d",H[i]);
        }
    }
}

```

## With Upper and lower

```c
#include<stdio.h>

int main(){
    char A[] = "FInDInG";
    int H[52],i;
    for(i=0;A[i]!='\0';i++)
    {
       if(A[i]>=65 && A[i]<=90)
       {
           H[A[i] - 'A']++;
       }
      else if(A[i]>=97 && A[i]<=122)
      {
          H[A[i]-'a' + 26]++;
      }
    }
    for(i=0;i<52;i++)
    {
        if(H[i]>1)
        {
            if(i < 26) {
                printf("%c %d\n", 'A' + i, H[i]);
            } else {
                printf("%c %d\n", 'a' + i - 26, H[i]);
            }
        }
    }
    return 0;
}
```

## duplicates using bitwise

### bitwise operations

- left shift '<<'
- bits ORing ( Merging )
- bits ANDing ( Masking )

1 byte = 8 bits. If we store in bytes its counts from 7-0. 7 is known as most significant bit, 0 is known as least significant bit.

if we were to store 0 in 1 byte it'll be stored as:
0 -> [0,0,0,0,0,0,0,0]
1 -> [0,0,0,0,0,0,0,1]
2 -> [0,0,0,0,0,0,1,0]...

binary form of each byte are representated as
128,64,32,16,8,4,2,1
128 -> [1,0,0,0,0,0,0,0]
64  -> [0,1,0,0,0,0,0,0]
32  -> [0,0,1,0,0,0,0,0]
16  -> [0,0,0,1,0,0,0,0]
8   -> [0,0,0,0,1,0,0,0]
4   -> [0,0,0,0,0,1,0,0]
2   -> [0,0,0,0,0,0,1,0]
1   -> [0,0,0,0,0,0,0,1]

using this we can also write all the other number if we want three
2 + 1 = 3 in binary form
3 -> [0,0,0,0,0,0,1,1]
here we are adding 2 + 1 to get 3

for 7 its 4 + 2 + 1
7 -> [0,0,0,0,1,1,1]

## left shift

- We shift bit by one place if its h<<1.
- If we want to shift by 2 places we use h<<2. This are multiple of 2.

## Bitwise AND (&)

The bitwise AND operation compares each bit of its two operands. If both corresponding bits are 1, the resulting bit is 1. Otherwise, the resulting bit is 0.

Here are the rules for the bitwise AND operation:

0&0=0
0&1=0
1&0=0
1&1=1

example:
a = 10 -> 8 + 2 = 10 => 1010
b = 6  -> 4 + 2 = 6  => 0110
Now we perform and operation on this. It's done on bitwise `and` level 10 & 6 = 2.

## Bitwise OR (|)

The bitwise OR operation compares each bit of its two operands. If at least one of the corresponding bits is 1, the resulting bit is 1. Otherwise, the resulting bit is 0.

Here are the rules for the bitwise OR operation:

0|0=0
0|1=1
1|0=1
1|1=1

example:
a = 10 -> 8 + 2 = 10 => 1010
b = 6  -> 4 + 2 = 6  => 0110
Now we perform and operation on this. It's done on bitwise `or` level 10 & 6 = 14.

## merging & masking

- Setting a bit `on` is known as merging
- checking a bit is `on` or `not` is known as masking.

```c
int main()
{
    char A[] = "finding";
    long int h=0,x=0;
    for(int i=0;A[i]!='\0';i++)
    {
        x=1;
        x = x<<(A[i]-97);
        if((x&h)>0)
        {
            printf("%c is duplicate",A[i]);
        }
        else
        {
            h=x|h;
        }
    }
    return 0;
}
```

## Anagram

An anagram is a word or phrase formed by rearranging the letters of another word or phrase, typically using all the original letters exactly once. Anagrams can be simple words or more complex phrases.

For example:

- "listen" is an anagram of "silent"
- "elbow" is an anagram of "below"
- "state" is an anagram of "taste"

Anagrams are often used in word puzzles and games.

```c
#include <stdio.h>
#include <string.h>
// #include <ctype.h> to handle Upper cases

int main() {
    char A[] = "decimal";
    char B[] = "medical";

    // Check if lengths of both strings are equal
    if (strlen(A) != strlen(B)) {
        printf("Not anagram\n");
        return 0;
    }

    int h[26] = {0};
    int i;

    // Increment counts for characters in A
    for (i = 0; A[i] != '\0'; i++) {
        h[/*tolower*/A[i] - 'a']++;
    }

    // Decrement counts for characters in B
    for (i = 0; B[i] != '\0'; i++) {
        h[/*tolower*/B[i] - 'a']--;
        // If any character count goes negative, not an anagram
        if (h[/*tolower*/B[i] - 'a'] < 0) {
            printf("Not anagram\n");
            return 0;
        }
    }

    // If we reach here, strings are anagrams
    printf("Anagram\n");

    return 0;
}

```

## permutations

A permutation is a specific arrangement or ordering of a set of elements. The concept of permutations is fundamental in mathematics, particularly in the fields of combinatorics and probability. Here’s a detailed explanation of permutations:

Definition
A permutation of a set is a rearrangement of its elements. If you have a set with `n` n distinct elements, a permutation involves selecting `n` n elements in some order.

### Example Set: {A, B, C}

Permutations:

- ABC
- ACB
- BAC
- BCA
- CAB
- CBA

For a set of three elements (A, B, C), there are 3! =3×2×1=6 permutations.

Formula
The number of permutations of `n` n distinct elements is given by `n!` n! (n factorial), which is the product of all positive integers up to `n`.

Types of Permutations

- Simple Permutations: Where all elements are distinct and each element is used exactly once.
- Permutations with Repetition: Where some elements can be repeated, and the order of selection matters.
- Circular Permutations: Arrangements of elements in a circle where rotations of the same arrangement are considered identical.

## Applications

### Permutations are used in various fields, including

- Cryptography: Permutations are used in encryption algorithms.
- Combinatorial Optimization: Problems like the traveling salesman problem involve finding the optimal permutation of a set of elements.
- Probability: Calculating probabilities of different outcomes often involves permutations.
- Computer Science: Permutations are used in algorithms and data structures.

we are using

- State space tree ( cause the leafs are showing us the results )
- Backtracking
- finding out all permutations is know as `Brute Force`.
- recursion

```C
#include <iostream>

using namespace std;

void perm(char s[], int k) {
    static int a[10] = {0};    // Array to track which characters are used
    static char res[10];       // Array to store the current permutation

    if (s[k] == '\0') {        // Base case: if we reach the end of the string
        res[k] = '\0';         // Null-terminate the result string
        cout << res << endl;   // Output the current permutation
    } else {
        for (int i = 0; s[i] != '\0'; i++) {   // Loop through all characters in the input string
            if (a[i] == 0) {   // If the character s[i] is not yet used in the current permutation
                res[k] = s[i]; // Include s[i] in the current position of the result
                a[i] = 1;      // Mark s[i] as used
                perm(s, k + 1); // Recur for the next position
                a[i] = 0;      // Backtrack: unmark s[i] as used
            }
        }
    }
}

int main() {
    char s[] = "abc";
    perm(s, 0);   // Start generating permutations from index 0
    return 0;
}
```

---End---
