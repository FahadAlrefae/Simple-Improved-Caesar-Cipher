//
//  main.cpp
//  csci191lab1
//
//  Created by Fahad alrefae on 7/5/17.
//  Copyright © 2017 Fahad alrefae. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


char rotate(char a, int numOfseq) // To rotate back to letter 'a' in case of exceeding letter 'z'
{
    char c;
        c = a+numOfseq;
    return static_cast<char>(c - 26);
}

char rotateback(char a, int numOfseq)// To rotate back to letter 'a' in case of position is before 'a'
{
    char c;
    c = a-numOfseq;
    return static_cast<char>(c + 26);
}

string encrypt(string str)
{
    string aux = "";
    char c;
   
    for(int j = 0; j < str.length(); j+=2)
    {
    
        if (isalpha(str[j])) //ignore if there is punctuation marks and/or spaces
        {
            if((str[j]+5) > 122)//if the letter is out of range
            {
                aux +=(rotate(str[j], 5));
            }
            else
            {
                c = str[j];
                aux += static_cast<char>(c+5);
            }
        }
        else
        {
            aux += str[j];
            aux += rotate(str[j+1], 5);
            j++;
        }
        for(int i = j+1; i < str.length();)
        {
            if (isalpha(str[i])) //ignore if there is punctuation marks and/or spaces
            {
                if((str[i]+19) > 122) //if the letter is out of range
                {
                    aux += rotate(str[i], 19);// to rotate if the letter + 19 is beyond z
                }
                else
                {
                    c = str[i];
                    aux += static_cast<char>(c+19);
                }
            }
            i = str.length(); // to break out of the loop
    }

    }
    return aux;
}

string decrypt(string str)
{
    string aux = "";
    char c;

    for(int j = 0; j < str.length(); j+=2)
    {
        
       if((str[j]-5) < 97)//if the letter is out of range
        {
            aux += rotateback(str[j], 5);// if the letter is before the a
        }
        else
        {
            c = str[j];
            aux += static_cast<char>(c-5);
        }
        
        for(int i = j+1; i < str.length(); i += 2)
        {
            if((str[i]-19) < 97)
            {
               aux += rotateback(str[i], 19);
            }
            else
            {
                c = str[i];
                aux += static_cast<char>(c-19);
            }
            i = str.length();
        }
    }
    
    return aux;
}

void menu()
{
    string str = "";
    int input;
    
    while (1)
    {
        cout << "Choose one of the following 4 options: " << endl;
        cout << "1- To cipher a new plaintext." << endl;
        cout << "2- To decipher the resulting text." << endl;
        cout << "3- To decipher a new cyphertext." << endl;
        cout << "4- Quit." << endl;
        
        cin >>input;
        
        switch (input)
        {
            case 1:
                cout << "Enter a plaintext (without punctuation marks or spaces) you would like to cipher: " << endl;
                cin.ignore();
                getline(cin, str);
                cout << endl << endl << "The ciphered text is: " << encrypt(str) << endl << endl;
                break;
            case 2:
                cout << "the deciphered text is: " << decrypt(encrypt(str)) << endl << endl;
                break;
            case 3:
                if(str == "")
                    cout << "Error! Plaintext is empty!" << endl;
                cout << "Enter a plaintext you would like to decipher: " << endl;
                cin.ignore();
                getline(cin, str);
                cout << endl << endl << "The deciphered text is: " << decrypt(str) << endl << endl;
                break;
            case 4:
                exit(1);
                break;
            default:
                break;
        }
    }
}
int main(int argc, const char * argv[])
{
    menu();
    return 0;
}
