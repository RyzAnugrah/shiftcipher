#include <iostream>
#include <string.h>
using namespace std;

int length, key;

//encryption
void encryption() 
{
    char msg[1000];
    char c; 

    cout << "Input the Message: ";
    cin.ignore(); cin.getline(msg, 1000); //input msg
    cout << "Input the Key: ";
    cin >> key; //input key
    length = strlen(msg);

    for (int i = 0; msg[i] != '\0'; ++i)
    {
        c = msg[i];
        //lowercase
        if (c >= 'a' && c <= 'z')
        {
            c = c - 97; 
            c = (c + key) % 26; 
            c = c + 97;
            msg[i] = c;
        }
        //uppercase
        else if (c >= 'A' && c <= 'Z')
        {
            c = c - 65;
            c = (c + key) % 26;
            c = c + 65;
            msg[i] = c;
        }
    }
    cout << "Encrypted Message: " << msg << endl << endl;
}

//decryption
void decryption()
{
    char msg[1000];
    char c;

    cout << "Input the Message: ";
    cin.ignore(); cin.getline(msg, 1000); //input msg
    cout << "Input the Key: ";
    cin >> key; //input key
    length = strlen(msg);

    for (int i = 0; msg[i] != '\0'; ++i)
    {
        c = msg[i];
        //lowercase
        if (c >= 'a' && c <= 'z')
        {
            c = c - 97;
            if (c - key < 0) //for negative value
            {
                c = 26 + (c - key);
            }
            else
            {
                c = (c - key) % 26;
            }
            c = c + 97;
            msg[i] = c;
        }
        //uppercase
        else if (c >= 'A' && c <= 'Z')
        {
            c = c - 65;
            if (c - key < 0) //for negative value
            {
                c = 26 + (c - key); 
            }
            else
            {
                c = (c - key) % 26;
            }
            c = c + 65;
            msg[i] = c;
        }
    }
    cout << "Decrypted Message: " << msg << endl << endl;
}

int main()
{
    int menu;
    bool stop;
    stop = false;

    while (!stop)
    {
        cout << "==================================\n= SHIFT CIPHER ENCODER & DECODER =" << endl;
        cout << "================================== \n= 1. ENCRYPTION\t\t\t =\n= 2. DECRYPTION \t\t =\n= 3. EXIT \t\t\t =\n==================================\n";
        cout << "Enter the Menu: ";
        cin >> menu;
        cout << endl;

        switch (menu)
        {
        case 1:
            encryption();
            break;

        case 2:
            decryption();
            break;

        case 3:
            stop = true;
            break;
        }
    }
    system("pause");
}