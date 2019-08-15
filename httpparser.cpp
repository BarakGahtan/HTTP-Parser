#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <istream>
#include "httpparser.h"
using namespace std;

int Http_Parser::getNumberOfHeaders(string fileName){
	ifstream inputFile(fileName);
	int counter=0;
	if (inputFile.is_open() && inputFile.good()) {
		string currentLine = "";
		while (getline(inputFile, currentLine)) {
			if (currentLine.empty()) {
				break;
			}
			counter++;
		}
	}
	return counter-1;
}

string Http_Parser::removeFirstWord(string line){
	std::string::size_type index = 0;  //consider change n to index
	index = line.find_first_not_of( " \t", index );
	index = line.find_first_of( " \t", index );
	line.erase( 0,  line.find_first_not_of( " \t", index ) );
	return line;
}

int Http_Parser::responseOrRequest(string fileName){
	ifstream input_file(fileName);
	string line = "";
	if (input_file.is_open() && input_file.good()) {
		string line = "";
		getline(input_file, line);
		if( line.find("HTTP/") == 0)
			return 0;
		else if( line.find("GET") == 0)
			return 1;
		else if( line.find("HEAD") == 0)
			return 2;
		else if( line.find("POST") == 0)
			return 3;
		else if( line.find("PUT") == 0)
			return 4;
		else if( line.find("DELETE") == 0)
			return 5;
		else if( line.find("CONNECT") == 0)
			return 6;
		else if( line.find("OPTIONS") == 0)
			return 7;
		else if( line.find("TRACE") == 0)
			return 8;
		else
			throw invalidMethod("The method is not valid");
		
	}
	return -1; // should not get here - error
}

string Http_Parser::getURL(string line){
	std::string::size_type index = 0;
	index = line.find_first_not_of( " \t", index );
	index = line.find_first_of( " \t", index );
	line.erase( 0,  line.find_first_not_of( " \t", index ) );
	if(line[0] == '/' && line[1]==' ') return "";
	if(line[0] == '*') return "*";
	index++;
	index = line.find_first_of( " \t", index );
	line.erase( index,  line.find_first_not_of( " \t", line.size() ) );
	return line;
}

string Http_Parser::getRequest(int whichFile){
	if(whichFile == 1)
		return "GET";
	else if( whichFile == 2)
		return "HEAD";
	else if( whichFile == 3)
		return "POST";
	else if( whichFile == 4)
		return "PUT";
	else if( whichFile == 5)
		return "DELETE";
	else if( whichFile == 6)
		return "CONNECT";
	else if( whichFile == 7)
		return "OPTIONS";
	else if( whichFile == 8)
		return "TRACE";
	return "";
	
}

string Http_Parser::requestHandler(int method , string fileName) {
	ifstream inputFile(fileName); //open the file
	string line, host, urlForHost, numberOfBytes;
	string res = getRequest(method);
	int flagContent = 0;
	int flagHost = 0;
	getline(inputFile, line);
	urlForHost = getURL(line);
	
	if (inputFile.is_open() && inputFile.good()) {
		line = "";
		while (getline(inputFile, line)) {
			if (line.find("Host:") != std::string::npos) {
				flagHost = 1;
				host = removeFirstWord(line);
				res+= " " + host + urlForHost;
			}
			if(line.find("Content-Length:") != std::string::npos || line.find("Content-length:") != std::string::npos) {
				flagContent = 1;
				numberOfBytes += removeFirstWord(line);
			}
		}
	}
	if(flagHost == 0){
		res += " " + urlForHost;
	}
	res += " (" + to_string(getNumberOfHeaders(fileName)) + " headers,";
	if(flagContent == 0){
		res += " 0 bytes)";
	}else{
		res += " " + numberOfBytes +" "+ "bytes)";
	}
	return res;
}

string Http_Parser::responseHandler(string fileName) {
	ifstream inputFile(fileName); //open the file
	string line, statusCode,numberOfBytes,res;
	line = "";
	int flagContent = 0;
	if (inputFile.is_open() && inputFile.good()) {
		getline(inputFile, line);
		statusCode = removeFirstWord(line);
	}
	size_t checkLengthOfDigits = statusCode.find_first_of( " \t", 0 );
	if( checkLengthOfDigits != 3){
		throw invalidCode("The Status-Code element is not valid");
	}
	res += statusCode + " (";
	int headers = getNumberOfHeaders(fileName);
	res+= to_string(headers) + " headers, ";
	if (inputFile.is_open() && inputFile.good()) {
		line = "";
		while (getline(inputFile, line)) {
			if(line.find("Content-Length:") != std::string::npos || line.find("Content-length:") != std::string::npos) {
				flagContent = 1;
				numberOfBytes += removeFirstWord(line);
			}
		}
		if( flagContent == 0){
			res += "0 bytes)";
		}else{
			res+= numberOfBytes + " bytes)";
		}
		return res;
	}
	return res;
}

Http_Parser::Http_Parser(string givenPath){
	try{
		int checkFile = responseOrRequest(givenPath);
		if( checkFile > 0){
			res = requestHandler(checkFile,givenPath);
			cout<< res << endl;
		}else{
			try{
				res = responseHandler(givenPath);
				cout<<  res << endl;
			}catch(invalidCode& e){
				res = e.what();
				cout<< e.what() <<endl;
			}

		}
	}catch (invalidMethod& e){
		res = e.what();
		cout<< e.what()<<endl;
	}
}