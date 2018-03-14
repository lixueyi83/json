/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 06 Mar 2018 03:22:13 PM PST
 ************************************************************************/

#include <iostream>
#include <fstream> 
#include "json.hpp"
#include "config.h"
using namespace std;

using json = nlohmann::json; 

int main(void)
{
    cout << "------------------------------" << endl;
    /* test 1 */
    json j;
    j["pi"] = 3.14;
    j["happy"] = true;
    j["name"] = "Tony";
    j["answer"]["something"] = 42;
    j["list"] = {1,2,3,4};
    j["object"] = {{"currency","USD"},{"value", 42.99}};
    cout << j["object"] << endl;
    cout << j << endl;
    
    cout << "------------------------------" << endl;
    /* test 2 */
    auto j2 = R"(
        {
            "happy": true,
            "pi": 3.14159
        }
    )"_json;
    
    cout << j2 << endl;
    
    cout << "------------------------------" << endl;
    /* test 3 */
    string file = "myjson.json";
    std::ifstream i(file.c_str());
    //auto j3 = json::parse("myjson.json");
    json j3;
    i >> j3;
    cout << j3 << endl;
    
    cout << "------------------------------" << endl;
    /* test 4 */
    cout << g_config << endl;

    cout << "------------------------------" << endl;
    /* test 5 */
    std::map<std::string, int> c_map { {"one", 1}, {"two", 2}, {"three", 3} };
    json j_map(c_map);
    cout << j_map << endl;



    return 0;
}
