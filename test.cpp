#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <istream>
#include "httpparser.h"
using namespace std;

#define ASSERT(b) do { \
        if (!(b)) { \
                printf("\nAssertion failed at %s:%d %s\n",__FILE__,__LINE__,#b); \
                return false; \
        } \
} while (0)

bool test_connect_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/connect_response.txt");
	ASSERT(a.res.compare("200 Connection established (2 headers, 0 bytes)")==0);
	a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/connect_response_1.txt");
	ASSERT(a.res.compare("200 Connection established (2 headers, 0 bytes)")!=0);
	return true;
}
bool test_delete_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/delete_response.txt");
	ASSERT(a.res.compare("200 OK (5 headers, 30 bytes)") == 0 );
	return true;
}
bool test_get_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/get_response.txt");
	ASSERT(a.res.compare("200 OK (9 headers, 88 bytes)") == 0 );
	return true;
}
bool test_head_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/head_response.txt");
	ASSERT(a.res.compare("200 OK (9 headers, 88 bytes)") == 0 );
	return true;
}
bool test_options_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/options_response.txt");
	ASSERT(a.res.compare("200 OK (4 headers, 0 bytes)") == 0 );
	return true;
}
bool test_post_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/post_response.txt");
	ASSERT(a.res.compare("200 OK (9 headers, 88 bytes)") == 0 );
	return true;
}
bool test_put_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/put_response.txt");
	ASSERT(a.res.compare("201 Created (5 headers, 30 bytes)") == 0 );
	return true;
}
bool test_response_0_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/response_0.txt");
	ASSERT(a.res.compare("200 OK (6 headers, 88 bytes)") == 0 );
	return true;
}
bool test_response_1_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/response_1.txt");
	ASSERT(a.res.compare("404 Not Found (5 headers, 230 bytes)") == 0 );
	return true;
}
bool test_response_2_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/response_2.txt");
	ASSERT(a.res.compare("400 Bad Request (5 headers, 230 bytes)") == 0 );
	return true;
}
bool test_trace_response(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/trace_response.txt");
	ASSERT(a.res.compare("200 OK (5 headers, 39 bytes)") == 0 );
	return true;
}
bool test_bad_code_short(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/trace_response_bad_code_short.txt");
	ASSERT(a.res.compare("The Status-Code element is not valid") == 0 );
	return true;
}
bool test_bad_code_long(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/trace_response_bad_code_long.txt");
	ASSERT(a.res.compare("The Status-Code element is not valid") == 0 );
	return true;
}
bool test_bad_code_empty(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/response/trace_response_bad_code_empty.txt");
	ASSERT(a.res.compare("The Status-Code element is not valid") == 0 );
	return true;
}

bool test_connect_request(){
	string res;
	//assume that if there is no host we still need to put the given url.
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/request/connect_request.txt");
	ASSERT(a.res.compare("CONNECT www.tutorialspoint.com (1 headers, 0 bytes)") == 0 );
	return true;
}
bool test_delete_request(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/request/delete_request.txt");
	ASSERT(a.res.compare("DELETE www.tutorialspoint.com/hello.htm (4 headers, 0 bytes)") == 0 );
	return true;
}
bool test_get_request(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/request/get_request.txt");
	ASSERT(a.res.compare("GET www.tutorialspoint.com/hello.htm (5 headers, 0 bytes)") == 0 );
	return true;
}
bool test_head_request(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/request/head_request.txt");
	ASSERT(a.res.compare("HEAD www.tutorialspoint.com/hello.htm (5 headers, 0 bytes)") == 0 );
	return true;
}
bool test_options_request(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/request/options_request.txt");
	ASSERT(a.res.compare("OPTIONS * (1 headers, 0 bytes)") == 0 );
	return true;
}
bool test_post_request(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/request/post_request.txt");
	ASSERT(a.res.compare("POST www.tutorialspoint.com/cgi-bin/process.cgi (7 headers, 88 bytes)") == 0 );
	return true;
}
bool test_put_request(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/request/put_request.txt");
	ASSERT(a.res.compare("PUT www.tutorialspoint.com/hello.htm (6 headers, 182 bytes)") == 0 );
	return true;
}
bool test_trace_request(){
	string res;
	http_parser a = http_parser("/Users/barakgahtan/CLionProjects/IBM/request/trace_request.txt");
	ASSERT(a.res.compare("TRACE www.tutorialspoint.com (2 headers, 0 bytes)") == 0 );
	return true;
}

bool test_cases_response(){
	//should return all true
	bool test0 = test_connect_response();
	bool test1 = test_delete_response();
	bool test2 = test_get_response();
	bool test3 = test_head_response();
	bool test4 = test_options_response();
	bool test5 = test_post_response();
	bool test6 = test_put_response();
	bool test7 = test_response_0_response();
	bool test8 = test_response_1_response();
	bool test9 = test_response_2_response();
	bool test10 = test_trace_response();
	//check bad cases
	bool test11 = test_bad_code_short();
	bool test12 = test_bad_code_long();
	bool test13 = test_bad_code_empty();
	return true;
	
}

bool test_cases_request(){
	//should return all true
	bool test14 = test_connect_request();
	bool test15 = test_delete_request();
	bool test16 = test_get_request();
	bool test17 = test_head_request();
	bool test18 = test_options_request();
	bool test19 = test_post_request();
	bool test20 = test_put_request();
	bool test21 = test_trace_request();
	return true;
	
}

int main(){
	bool tes1 = test_cases_request();
	bool test2 = test_cases_response();
	return 0;
}