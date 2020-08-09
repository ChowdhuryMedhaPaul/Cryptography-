#include<bits/stdc++.h>
using namespace std;
int k;
char arry[1000];
string encrypte(string instring)
{
    int value;
    int len=instring.size();
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<27; j++)
        {
            if(instring[i]==arry[j])
            {
                value = (j+k)%27;
                instring[i] = arry[value];
                break;
            }
        }
    }

    return instring;


}
string decrypte(string instring)
{
    int value;
    int len= instring.size();
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<=27; j++)
        {
            if(instring[i]==arry[j])
            {
                value = (j-k);
                if(value>=0||value==-27)
                    value=value%27;
                else
                    value= 27+(value%27);
                    instring[i]=arry[value];
                break;
            }
        }
    }
    return instring ;
}
int main()
{
    string instring;
    for(int i=65,j=0; i<=90; i++)
    {
        arry[j]=i;
        j++;
    }
    arry[26]=32;
    int choice;
    cout << "What do u want to see Please enter \n\t(1)Only Encryption\n\t(2)only Decryption\n\t(3)Both\n";
    cin >> choice;
    printf("Enter your input please\n");
    getline(cin>>ws,instring);
    printf("Enter your constant number k : ");
    cin>>k;
    switch(choice)
    {
    case 1:
        cout << encrypte(instring) <<endl;
        break;


    case 2:
        cout << decrypte(instring) <<endl;
        break;

    case 3:
        cout <<  encrypte(instring) << endl << decrypte(encrypte(instring)) <<endl;
        break;

    case 4:
        exit(0);
    }
    return 0;
}

