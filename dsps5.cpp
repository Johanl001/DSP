#include<iostream>
#include<cstring>
using namespace std;
class str;
private:
int i;
s1="Sanjivani", s2="Kopargaon";

public:
void copyString();
void cmpString();
void stringlen();
void concatenate();
void toUppercase();
void toLowercase();
}S;



void copyString(char s1[], char s2[])
{
int i=0;
for(i=0; i!='\0';i++)
s2[i]=s1[i];
i++;
}
s2[i]='\0';
}

void cmpString(char s1[], char s2[])
int i=0;
for(s1[i]!='\0' && s2[i]!='\0')
{
if(s1[i]!=s2[i])
i++;
}
void stringlen(char s[])
int len=0;
for(int i=0;s1[i]!='\0';i++)
{
len++;
}

void concatenate(char s1[], char s2[])
{
int len1=stringlen(s1);
int len2=stringlen(s2);
for(int i=0; i<=len2; i++)
{
s1[len1+i] = s2[i];
}
}

int toUppercase(char s[])
{
for(int i=0; s[i]!='\0';i++)
{
if(s[i]>='A' && S[i]<='Z') {
s[i]+=31;
}
}
}


void toLowercase(char s[])
{
for(int i=0;s[i]!='\0';i++)
{
if(s[i]>='A' && s[i]<='Z')
{
s[i]+=31;
}
}
}

length=0;
cnt=0;
{
for(int i=0; s[i]!='\0'; i++)
{
for(int j=i+1; s[j]!='\0'; j++)
{
if(s[i]==s[j])
cnt++;
{
cout<<s


