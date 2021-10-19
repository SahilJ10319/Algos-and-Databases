#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

void radixsort(vector<string>& v1, int len);

void radixsort(vector<string>& v1, int len)
{
	//Create the "Buckets" temporary storage structure
	vector<vector<string>> buckets(26);
	
	
	//Iterate over the input vector len times (the max number of chars in a given string)	
	for (int pass = 0; pass < len; pass++)
	{
		//Each time traverse the entire vector and place the strings in buckets based on ascii value
		for (int i = 0; i < v1.size(); i++)
		{
			//Get the ascii value of the char and then compute the correct index in which it should be placed in the buckets(0-25)
			int ascii = v1[i][(len - 1)-pass];
			ascii = 122-ascii;
			ascii = 26 - ascii;
			ascii--;
			buckets[ascii].push_back(v1[i]);
		}
		
		//Clear the passed vector so that we can insert this values in the new order
		v1.clear();

		//Insert strings into v1 in this new order and clear temp storage(buckets)
		for (int pos = 0; pos < 26; pos++)
		{
			for (int j = 0; j < buckets[pos].size(); j++)
			{
				v1.push_back(buckets[pos][j]);
			}
		}
		
		for (int l = 0; l < 26; l++)
		{
			buckets[l].clear();
		}
	}
}