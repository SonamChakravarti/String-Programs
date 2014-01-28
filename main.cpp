/* 
 * File:   main.cpp
 * Author: Sona
 *
 * Created on January 18, 2014, 10:02 AM
 */

#include <cstdlib>
#include<iostream>
#include<string>
#include<string.h>
#include<strings.h>

using namespace std;

/*
 * 
 */
class ChangeString{
    string in,out;
public:
    void swap(char *x, char *y){
        char temp;
        temp= *x;
        *x=*y;
        *y=temp;
    }
    void rev(char *text){
        char temp,*end;
        if(text==NULL)
            return;
        end=text+strlen(text);
        while(end>=text){
            temp=*text;
            *text++=*end;
            *end--=temp;
        }
        
    }
    void rev(char *text,char *end){
        char temp;
        while(end>text){
            temp=*text;
            *text++=*end;
            *end--=temp;
        }
        
    }
    void revWord(char *text){
        char *start=text;
        char *temp=text;
        
        while(*temp){
            temp++;
            if (*temp == '\0')
            {
                    rev(start, temp-1);
            }
  
           else if(*temp == ' ')
           {
                    rev(start, temp-1);
                    start = temp+1;
           }
        }
        rev(text, temp-1);
    }
    void edit(char *text){
        int i=0,j=0,loop=1;
        while(text[i]!='\0'){
            if(loop==1 && text[i]!='b' && text[i]!='a')
            {
                text[j]=text[i];
                j=j+1;
            }
            if(loop==2 && text[i]!='c')
            {
                text[j]='a';
                j=j+1;
               if( text[i]!='b' && text[i]!='a')
                {
                        text[j]=text[i];
                        j=j+1;
                }
            }
            if(text[i]=='a')
            {
                loop=2;
            }
            else
                loop=1;
            
            
            i=i+1;
        }//while
        if(loop==2)
            {
                 text[j]='a';
                j=j+1;
            }
        text[j]='\0';
    }//edit
    void sub(char *one, char* two, int lenone, int lentwo){
        
    }
    void perm(char *text,int begin,int end){
        int j;
        
        if(begin==end)
            cout<<text<<endl;
        else
            for(j=0;j<=end;j++){
                swap(text+begin,text+j);
                perm(text,begin+1,end);
                swap(text+begin,text+j);
            }
    }
    int partition(char *text,int begin,int end){
        char a=text[end];
        int sem=begin-1;
        int j;
        for(j=begin;j<=end-1;j++)
        {
            if (text[j]<=a){
                sem++;
                swap(&text[sem],&text[j]);
            }
        }
        swap(&text[sem+1],&text[end]);
        return (sem+1);
        
    }
    void sort(char *text,int begin, int end){
        int x;
        if(begin<end){
            x=partition(text,begin,end);
            sort(text,begin,end-1);
            sort(text,begin+1,end);
        }
        
    }
    int checked(char *text,int n){
        bool arr[255];
        int i,index=256;
        for(i=0;i<255;i++){
            arr[i]=false;
        }
        for(i=0;i<n;i++){
            if(arr[text[i]]==false)
                arr[text[i]]=true;
            else
            {
                arr[text[i]]=false;
                return index=i;
            }
        }
        return index;
        
        
    }
    
};
int main() {
ChangeString s;    
int input;    
string inString,inString1;

cout<<"Menu:" <<endl;
cout<<"1. Reverse string \n2. Reverse words and string \n"
        "3. Remove b and ac from string \n4. Longest Common Substring \n5. Permutation of string"
        "\n6. Sorting of string \n7. Checking string for unique characters"<<endl;
cin>>input;
switch(input){
        case 1: {
             cout<<"Enter the string to be reversed"<<endl;
             cin.clear();
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             getline(cin,inString);
             cout<<"String entered is : "<<inString<<endl;
             s.rev(const_cast<char*>(inString.c_str()));
             cout<<"Reversed String: "<<endl;
             cout<<inString;
             break;
        }
        case 2:
        {
            cout<<"Enter the string to be Reversed Word wise"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,inString);
            cout<<"String entered is : "<<inString<<endl;
            s.revWord(const_cast<char*>(inString.c_str()));
            cout<<"Reversed String: "<<endl;
            cout<<inString;
            break;
        }
    case 3:{
            cout<<"Enter the string to be spliced"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,inString);
            cout<<"String entered is : "<<inString<<endl;
            s.edit(const_cast<char*>(inString.c_str()));
            cout<<"Edited String: "<<endl;
            cout<<inString;
            break;
    }
    case 4:{
            cout<<"Enter the string 1 to be compared"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,inString);
            cout<<"String entered is : "<<inString<<endl;
            cout<<"Enter the string 2 to be compared"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,inString1);
            cout<<"String entered is : "<<inString1<<endl;
           // s.sub(const_cast<char*>(inString.c_str()),const_cast<char*>(inString1.c_str()),strlen(inString),strlen(inString1));
            cout<<"Edited String: "<<endl;
            cout<<inString;
            break;
    }
    case 5: {
            int n;    
            cout<<"Enter the string to be permuted"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,inString);
            cout<<"String entered is : "<<inString<<endl;
            n=inString.length()-1;
            s.perm(const_cast<char*>(inString.c_str()),0,n);
            break;
        
    }
    case 6: {
            int n;    
            cout<<"Enter the string to be sorted"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,inString);
            cout<<"String entered is : "<<inString<<endl;
            n=inString.length()-1;
            s.sort(const_cast<char*>(inString.c_str()),0,n);
             cout<<"Edited String: "<<endl;
            cout<<inString;
            break;
        
    }
    case 7: {
            int n,index;    
            cout<<"Enter the string to be checked"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,inString);
            cout<<"String entered is : "<<inString<<endl;
            n=inString.length();
            index=s.checked(const_cast<char*>(inString.c_str()),n);
            cout<<"Checked String: "<<endl;
            cout<<index;
            break;
        
    }
        default: cout<<"Incorrect Option selected"<<endl;
}
    
 
    return 0;
}

