#pragma once
#include <iostream>
#include<string>
#include <vector>
#include<iomanip>
using namespace std;
class clsString
{
private:
    string _Value;
public:
    enum enWhatToCount { CapitallLetters = 0, SmallLetters = 1, All = 2 };
    clsString() {}
    clsString(string Value)
    {
        this->_Value = Value;
    }
    void SetValue(string Value)
    {
        this->_Value = Value;
    }
    string GetValue()
    {
        return _Value;
    }
    _declspec(property(get = GetValue, put = SetValue))string Value;

    string ReadString()
    {
        string S1;
        cout << "\nPlease Enter Your String:";
        getline(cin >> ws, S1);
        return S1;
    }
    static void PrintFirstLetterOfEachWord(string S1)
    {
        bool IsFirstLetter = true;
        for (short I = 0; I < S1.length(); I++)
        {

            if (S1[I] != ' ' && IsFirstLetter)
            {
                cout << S1[I] << "   ";
            }

            IsFirstLetter = (S1[I] == ' ' ? true : false);
        }
        cout << endl;
    }
    void  PrintFirstLetterOfEachWord()
    {
        PrintFirstLetterOfEachWord(this->_Value);
    }
    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool IsFirstLetter = true;
        for (short I = 0; I < S1.length(); I++)
        {
            if (S1[I] != ' ' && IsFirstLetter)
            {
                S1[I] = toupper(S1[I]);
            }
            IsFirstLetter = (S1[I] == ' ' ? true : false);
        }
        return S1;
    }
    void UpperFirstLetterOfEachWord()
    {
        this->_Value = UpperFirstLetterOfEachWord(this->_Value);
    }
    static string LowerFirstLetterOfEachWord(string S1)
    {

        bool IsFirstLetter = true;
        for (short I = 0; I < S1.length(); I++)
        {
            if (S1[I] != ' ' && IsFirstLetter)
            {
                S1[I] = tolower(S1[I]);


            }

            IsFirstLetter = (S1[I] == ' ' ? true : false);

        }
        return S1;

    }
    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }
    static string LowerAllLettersOfAstring(string S1)
    {

        for (short I = 0; I < S1.length(); I++)
        {




            S1[I] = tolower(S1[I]);



        }
        return S1;

    }
    static string UpperAllLettersOfAString(string S1)
    {

        for (short I = 0; I < S1.length(); I++)
        {




            S1[I] = toupper(S1[I]);






        }
        return S1;

    }
    void LowerAllLettersOfAstring()
    {
        _Value = LowerAllLettersOfAstring(this->_Value);
    }
    void UpperAllLettersOfAString()
    {
        _Value = UpperAllLettersOfAString(this->_Value);
    }
    static char InvertCharcterCase(char Char1)
    {

        return  isupper(Char1) ? tolower(Char1) : toupper(Char1);

    }
    static string InvertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = isupper(S1[i]) ? tolower(S1[i]) : toupper(S1[i]);
        }
        return S1;
    }
    void  InvertAllLettersCase()
    {
        _Value = InvertAllLettersCase(this->_Value);
    }

    static int CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        short Count = 0;

        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }

        for (short i = 0; i < S1.length(); i++)
        {

            if (WhatToCount == enWhatToCount::CapitallLetters && isupper(S1[i]))
            {
                Count++;

            }
            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
            {
                Count++;
            }
        }

        return Count;
    }
    static int CountCapitalLettrs(string S1)
    {
        int CountCapitalLettrs = 0;
        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
            {
                CountCapitalLettrs++;
            }


        }
        return CountCapitalLettrs;
    }
    static int  CountSmallLetters(string S1)
    {
        int CountSmallLtters = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
            {
                ++CountSmallLtters;
            }
        }
        return CountSmallLtters;
    }
    int  CountSmallLetters()
    {
        return  CountSmallLetters(_Value);
    }
    int CountCapitalLettrs()
    {
        return CountCapitalLettrs(this->_Value);
    }
    static int CountLetter(string S1, char Letter)
    {
        short Count = 0;




        for (short i = 0; i < S1.length(); i++)
        {

            if (Letter == S1[i])
                Count++;

        }

        return Count;


    }
    static int CountLetter(char Letter, string S1, bool IsMatchCase = false)
    {
        int Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {

            if (IsMatchCase)
            {
                if (Letter == S1[i])
                {
                    Count++;
                }
            }
            else
                if (tolower(Letter) == tolower(S1[i]))
                {
                    Count++;
                }
        }
        return Count;
    }
    static char InvertLetterCase(char C1)
    {
        return  isupper(C1) ? tolower(C1) : toupper(C1);
    }
    static bool VowelsLetters(char C1)
    {
        C1 = towlower(C1);
        return C1 == 'a' || C1 == 'e' || C1 == 'i' || C1 == 'o' || C1 == 'u';
    }
    static int CountAllVowels(string S1)
    {

        int Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (VowelsLetters(S1[i]))
                Count++;
        }
        return Count;
    }
    int CountAllVowels()
    {
        return  CountAllVowels(this->_Value);
    }
    static void  PrintAllVowelsInString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (VowelsLetters(S1[i]))
                cout << S1[i] << "   ";
        }
    }
    void PrintAllVowelsInString()
    {
        PrintAllVowelsInString(_Value);
    }
    static void PrintEachWordInString(string S1, string Delim)
    {

        string sWord = " ";
        int Pos = 0;

        cout << "\n\nYour String Words are:\n";
        while ((Pos = S1.find(Delim)) != -1)
        {

            sWord = S1.substr(0, Pos);
            if (sWord != " ")
            {
                cout << sWord << endl;
            }
            S1.erase(0, Pos + Delim.length());




        }
        if (S1 != " ")
        {
            cout << S1 << endl;

        }



    }
    void PrintEachWordInString()
    {
        PrintEachWordInString(_Value, " ");
    }
    static short CountWords(string S1, string Delim)
    {
        string sWord = " ";
        int Pos = 0, Count = 0;

        while (S1.find(Delim) != -1)
        {
            Pos = S1.find(" ");

            sWord = S1.substr(0, Pos);
            if (sWord != " ")
            {
                Count++;

            }
            S1.erase(0, Pos + Delim.length());
        }
        if (S1 != " ")
        {

            Count++;
        }
        return Count;
    }
    short CountWords()
    {
        return CountWords(this->_Value, " ");
    }
    static vector<string> SplitEachWordInVector(string S1, string Demit)
    {
        vector<string>Split;
        int Pos = 0;
        string Sword = "";
        while ((Pos = S1.find(Demit)) != -1)
        {


            Sword = S1.substr(0, Pos);
            if (Sword != " ")
            {
                Split.push_back(Sword);

            }
            S1.erase(0, Pos + Demit.length());
        }
        if (S1 != "")
        {
            Sword = S1;
            Split.push_back(Sword);

        }

        return Split;

    }
    static string  TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return  S1.substr(i, S1.length() - i);
            }
        }

        return "";
    }
    static string   TrimRight(string S1)
    {
        int lengthstring = S1.length();
        for (short i = lengthstring - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return  S1.substr(0, i + 1);
            }
        }
    }
    static string Trim(string S1)
    {
        return TrimLeft(TrimRight(S1));
    }
    void   TrimRight()
    {
        _Value = TrimRight(this->_Value);
    }
    void  TrimLeft()
    {
        this->_Value = TrimLeft(this->_Value);
    }
    void Trim()
    {
        this->_Value = Trim(TrimRight(this->_Value));
    }
    static string JoingString(vector<string>& Vstring, string Demit)
    {

        string Swords = "";


        for (string& s : Vstring)
        {

            Swords += s + Demit;

        }

        return Swords.substr(0, Swords.length() - Demit.length());

    }
    static string JoingString(string arr[], int Arrlength, string Demit)
    {
        string S1 = "";

        for (short i = 0; i <= Arrlength - 1; i++)
        {

            S1 = S1 + arr[i] + Demit;


        }

        return S1.substr(0, S1.length() - Demit.length());


    }
    static vector<string>SplitString(string S1, string Demit)
    {
        vector<string>Vstring;
        int Pos = 0;
        string Swords = "";
        while ((Pos = S1.find(Demit)) != -1)
        {

            Swords = S1.substr(0, Pos);
            if (Swords != "")
            {
                Vstring.push_back(Swords);
            }

            S1.erase(0, Pos + Demit.length());

        }

        if (S1 != "")
        {
            Vstring.push_back(S1);
        }
        return Vstring;
    }
    vector<string>SplitString(string Demit)
    {
        vector<string>Vstring;
        int Pos = 0;
        string Swords = "";
        while ((Pos = this->_Value.find(Demit)) != -1)
        {

            Swords = _Value.substr(0, Pos);
            if (Swords != "")
            {
                Vstring.push_back(Swords);
            }

            _Value.erase(0, Pos + Demit.length());

        }

        if (_Value != "")
        {
            Vstring.push_back(_Value);
        }
        return Vstring;
    }
    static string ReversedWordsInString(string S1)
    {
        vector<string>Vstring = SplitString(S1, " ");
        vector<string>::iterator iter = Vstring.end();
        string S2;
        while (iter != Vstring.begin())
        {
            iter--;
            S2 = S2 + *iter + " ";
        }
        return TrimRight(S2);
    }
    void  ReversedWordsInString()
    {
        this->_Value = ReversedWordsInString(this->_Value);
    }
    static string ReplaceWordsInStringUsingBuiltInFuncation(string S1, string StringToReplace, string stReplaceTo)
    {
        int Pos = 0;
        Pos = S1.find(StringToReplace);
        while (Pos != std::string::npos)
        {
            S1.replace(Pos, StringToReplace.length(), stReplaceTo);
            Pos = S1.find(StringToReplace);
        }
        return S1;
    }
    string ReplaceWordsInStringUsingBuiltInFuncation(string StringToReplace, string stReplaceTo)
    {
        return  ReplaceWordsInStringUsingBuiltInFuncation(_Value, StringToReplace, stReplaceTo);

    }
    static string RemovePunctutionsFromString(string S1)
    {
        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {

            if (!ispunct(S1[i]))
            {
                S2 += S1[i];


            }


        }
        return S2;

    }
    void RemovePunctutionsFromString()
    {
        this->_Value = RemovePunctutionsFromString(GetValue());
    }
};





