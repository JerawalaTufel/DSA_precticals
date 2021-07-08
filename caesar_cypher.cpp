#include<iostream>
#include<fstream>
#include <cctype>
#include<String.h>
#include <bits/stdc++.h>

using namespace std;
const int MAX = 26;
// rendom generation of alphabets for  key
string printRandomString(int n)
{
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };

    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % MAX];

        ofstream outfile2;

   //write key in file , every time you run program key is different
   outfile2.open("KEY_alphabet.txt");
   outfile2<<res;
   outfile2.close();

    return res;
}

//key generation
int key_generation()
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//string text = " ";
	int numVal = 0;
	int sum = 0;
srand(time(NULL));
	string text = printRandomString(1)  ;
	//cout << "Enter text: ";
	//cin >> text;

	for(unsigned int i = 0; i < text.size(); i++){ //Check if letters are lower case then convert it to upper case.
		if(islower(text[i])){
			text[i] = toupper(text[i]);
		}
	}

	for(unsigned int y = 0; y < text.size(); y++){
		for(unsigned int w = 0; w < alpha.size(); w++){ //Do the conversion from letters to int.
			if(text[y] == alpha[w]){
				numVal = (int)(alpha[w] - 'A' + 1);
				sum += numVal;
			}
		}
	}

    return sum;
}

//encrypt massage
string encrypt_Text(string pt,int key)
{
    string cipher_text = "";

   // int key = int(Key)-65;

    for(int i=0;i<pt.length();i++)
    {
        if(pt[i]==' ')
        {
            cipher_text += ' ';
            continue;
        }

        int v;

        if(pt[i]>='a')
            v = pt[i]-97;
        else
            v = pt[i]-65;

        if (key >= 0)
            v = (v+key)%26;
        else
            v = (v+26+key)%26;

        if(pt[i]>='a')
            v = v+97;
        else
            v = v+65;

        cipher_text += char(v);
    }

  //  cout << "\nCipher Text : " << cipher_text << endl;

    return cipher_text;
}
// decrypt massage
string decrypt_Text(string ct,int key)
{
    string plain_text = "";

    //int key = int(Key)-65;

    for(int i=0;i<ct.length();i++)
    {
        if(ct[i]==' ')
        {
            plain_text += ' ';
            continue;
        }

        int v;
        if(ct[i]>='a')
            v = ct[i]-97;
        else
            v = ct[i]-65;

        if (key >= 0)
            v = (v+26-key)%26;
        else
            v = (v-key)%26;

        if(ct[i]>='a')
            v = v+97;
        else
            v = v+65;

        plain_text += char(v);
    }

    return plain_text;
}

void Cryptanalytics(string cipher_text)
{
    ofstream possible_output ("possible_output.txt");

    possible_output << "Possible Original Text" << endl;

    for(int j=1;j<=26;j++)
    {
        int key = j;
        string plain_text = "";

        for(int i=0;i<cipher_text.length();i++)
        {
            if(cipher_text[i]==' ')
            {
                plain_text += ' ';
                continue;
            }

            int v;

            if(cipher_text[i]>='a')
                v = cipher_text[i]-97;
            else
                v = cipher_text[i]-65;

            if (key >= 0)
                v = (v+26-key)%26;
            else
                v = (v-key)%26;


            if(cipher_text[i]>='a')
                v = v+97;
            else
                v = v+65;

            plain_text += char(v);
        }

        possible_output << j << ". " << plain_text << endl;
          cout << j << ". " << plain_text << endl;
    }

    possible_output.close();
}


int main()
{
// take value from file and perform encryption
    ifstream infile;
    ofstream outfile;
    infile.open("PT.txt");

    if(infile.fail())
    {
        cout<<"Error in opening file "<<endl;

    }
    string text;
    int key;
while(!infile.eof()){
    infile >>text;
}
    //cout<<"Enter the key:";
   // cin>>key;
   key = key_generation();
    cout<<endl;
   // cout<<"cipher_text:"<<encrypt(text,key);
   string enc= encrypt_Text(text,key);

  cout<<"cypher text :"<<enc;
   //write cipher in file
   outfile.open("CT.txt");
   outfile<<enc;
   outfile.close();



   ifstream infile1;
    ofstream outfile1;

    //take value from file
    infile1.open("CT.txt");

    if(infile1.fail())
    {
        cout<<"Error in opening file "<<endl;

    }

while(!infile1.eof()){
    infile1 >>text;
}
   // cout<<"Enter the key:";
   // cin>>key;
    cout<<endl;
   // cout<<"cipher_text:"<<encrypt(text,key);
   enc=decrypt_Text(text,key);

   //write value in file after decryption
   outfile1.open("OUTPUT.txt");
   outfile1<<enc;
   outfile1.close();


   ofstream outfile2;

   //write key in file , every time you run program key is different
   outfile2.open("KEY_number.txt");
   outfile2<<key;
   outfile2.close();

   Cryptanalytics(text);
    return 0;
}
