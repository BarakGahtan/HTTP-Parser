#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <istream>
#include "httpparser.h"
#include <assert.h>

int main(int argc, char *argv[]) {
	if(!argv[1]){
		cout<<"No input file"<< endl;
		return 0;
	}
	string givenFile = argv[1];
	Http_Parser a = Http_Parser(givenFile);
	return 0;
}