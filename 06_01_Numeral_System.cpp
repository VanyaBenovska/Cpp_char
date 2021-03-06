// 06_01_Numeral_System.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<sstream>
#include<map>   
#include<iomanip>                    
#include <stack>
using namespace std;
//if map doesnt contain char, [] will add a new KeyValuePair in map	

string TransformCodeToStrNumber(string codeChars, const map<int, char>& dataMap)
{
	string strDigits;
	for(size_t i = 0; i < codeChars.size(); i++)
	{
		char ch = codeChars[i];
		for (auto it = dataMap.begin(); it != dataMap.end(); it++)
		{
			if (it->second == ch)
			{
				int digit = it->first;

				char aChar = '0' + digit;   //or  48 + digit;
				strDigits += string(1, aChar);
				break;
			}
		}
	}
	return strDigits; 
}


string intToString(int num)
{
	stack<string> dataStack;
	string strNum;
	while (num > 0)
	{
		int digit = num % 10;
		//strNum += string(1, digit);
		char chDigit = '0' + digit;
		dataStack.push(string(1, chDigit));
		num /= 10;		
	}
	while(!dataStack.empty())
	{
		strNum += dataStack.top();
		dataStack.pop();
	}
	return strNum;
}

string CodeIntNumber(int num, map<int, char>& dataMap)
{
	stack<char> dataStack;
	string strCodedNum;
	while (num > 0)
	{
		int digit = num % 10;		
		char codedDigit = dataMap[digit];    //char chDigit = '0' + digit;
		dataStack.push(codedDigit);
		num /= 10;
	}
	while (!dataStack.empty())
	{
		strCodedNum += string(1, dataStack.top());
		dataStack.pop();
	}
	return strCodedNum;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	string codeChars;
	getline(cin, codeChars);
	map<int, char> dataMap;
	istringstream iss(codeChars);
	for (int i = 0; i <= 9; i++)
	{
		char ch;
		iss >> ch;
		dataMap[i] = ch;
	}
	getline(cin, codeChars);
	string strNum01 = TransformCodeToStrNumber(codeChars, dataMap);
	string::size_type sz;   // alias of size_t
	int num01 = stoi(strNum01, &sz);

	getline(cin, codeChars);
	string strNum02 = TransformCodeToStrNumber(codeChars, dataMap);	
	int num02 = stoi(strNum02, &sz);
	int sum = num01 + num02;

	//char buffer[33];	
	//itoa(number, buffer, 10);
	//or
	// char aChar = '0' + digit;   //or  48 + digit;

	cout << CodeIntNumber(sum, dataMap) << endl;
	
	//string sumStr = intToString(sum);
    return 0;
}

