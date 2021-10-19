#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void countFrequency(string s) {

	vector<vector<int> > buckets(26);

	int displacementInASCII = 97;
	int AsciiValueOfLetter = 0;
	int count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		AsciiValueOfLetter = static_cast<int>(s[i]) - displacementInASCII;
		if (buckets.at(AsciiValueOfLetter).size() == 0) {
			buckets.at(AsciiValueOfLetter).push_back(1);
		}
		else {
			count = buckets.at(AsciiValueOfLetter).at(0);
			buckets.at(AsciiValueOfLetter).clear();
			count++;
			buckets.at(AsciiValueOfLetter).push_back(count);
			count = 0;
		}
	}

	for (int i = 0; i < buckets.size(); i++) {
		if (buckets.at(i).size() != 0) {
			cout << static_cast<char>(i + displacementInASCII) << ": " << buckets.at(i).at(0) << endl;
		}
	}
}



int main() {
	string s = "aardvark";

	countFrequency(s);
	return 0;
}