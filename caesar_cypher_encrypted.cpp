#include<iostream>
#include<fstream>
#include<string>

using namespace std;


string encrypt(string text,int key)
{
string result="";

for(int i=0;i<text.length();i++)
{
    if(isupper(text[i]))
    {
        result+=char(int(text[i]+key-65)%26 +65);

    }
    else
    {

        result+=char(int(text[i]+key-97)%26 +97);
    }

}

    return result;
}


int main()
{

    ifstream infile;
    ofstream outfile;
    infile.open("number.txt");

    if(infile.fail())
    {
        cout<<"Error in opening file "<<endl;

    }
    string text;
    int key;
while(!infile.eof()){
    infile >>text;
}
    cout<<"Enter the key:";
    cin>>key;
    cout<<endl;
   // cout<<"cipher_text:"<<encrypt(text,key);
   string enc=encrypt(text,key);

   outfile.open("new.txt");
   outfile<<enc;
   outfile.close();
    return 0;
}

