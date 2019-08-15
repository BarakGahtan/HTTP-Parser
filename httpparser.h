#ifndef IBM_HTTPPARSER_H
#define IBM_HTTPPARSER_H

#endif //IBM_HTTPPARSER_H
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

/*
 * exceptions to handle different cases.
 */
class invalidCode : public std::exception {
	const char *message;
public :
	invalidCode(const char *msg = "") : message(msg) {};
	
	const char *what() const noexcept override {
		return message;
	}
};

class invalidMethod : public std::exception {
	const char *message;
public :
	invalidMethod(const char *msg = "") : message(msg) {};
	
	const char *what() const noexcept override {
		return message;
	}
};

/*
 * class to define the parser.
 */
class Http_Parser {
	
	/*
	 * descriptions: translates a method into a string.
	 * input:
	 *      method in ints.
	 *          1 for GET request.
	 *          2 for HEAD request.
	 *          3 for POST request.
	 *          4 for PUT request.
	 *          5 for DELETE request.
	 *          6 for CONNECT request.
     *          7 for OPTIONS request.
     *          8 for TRACE request.
	 * output :
	 *          the correct string.
	 */
	string getRequest(int whichFile);
	
	/*
	 * desctiption: remove the first word from a given line, "delimeter" is space".
	 *
	 * inout: string : the line.
	 * output: the line without the first word.
	 */
	string removeFirstWord(string line);
	
	/*
	* description: calculate the number of headers for a given file.
	*
	* input: string given file name
	*
	* output: number of headers in int.
	*/
	int getNumberOfHeaders(string fileName);
	
	/*
 * checks if the input file is response or request.
 * each response file should starts with HTTP/(version)
 * each request file should start with one of the Methods
 * GET, HEAD, POST, PUT, DELETE, CONNECT, OPTIONS, TRACE.
 *
 * parameters : input file name ( the path )
 * output:
 *          0 for response file.
 *          1 for GET request.
 *          2 for HEAD request.
 *          3 for POST request.
 *          4 for PUT request.
 *          5 for DELETE request.
 *          6 for CONNECT request.
 *          7 for OPTIONS request.
 *          8 for TRACE request.
 */
	int responseOrRequest(string fileName);
	
	/*
	 * description: returns the URL to be added to the host.
	 * input : line ( line from the given file, with the url in it).
	 * output: URL.
	 * edge cases:
	 *              if the url is only '/' then return "", host is enough.
	 *              if it is options and * then return *.
	 *
	 */
	string getURL(string line);
	
	/*
	 * description:
	 *          output as in the given instruction.
	 *
	 * input:
	 *          int method = request method, as stated with numbers above.
	 *          string fileName = given file name.
	 *
	 */
	string requestHandler(int method , string fileName); // same
	
	
	/*
	 * description:
	 *          output as in the given instruction.
	 *
	 * input:
	 *          string fileName = given file name.
	 */
	string responseHandler(string fileName);

public:
	Http_Parser(string givenPath);
	
	string res;
};


