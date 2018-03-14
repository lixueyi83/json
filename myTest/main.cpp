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

void create_json_object(void)
{
    cout << "----------------1--------------" << endl;
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
    
    cout << "----------------2--------------" << endl;
    /* test 2 */
    auto j2 = R"(
        {
            "happy": true,
            "pi": 3.14159
        }
    )"_json;
    
    cout << j2 << endl;
    
    cout << "----------------3--------------" << endl;
    /* test 3 */
    string file = "myjson.json";
    std::ifstream i(file.c_str());
    //auto j3 = json::parse("myjson.json");
    json j3;
    i >> j3;
    cout << j3 << endl;
    
    cout << "----------------4--------------" << endl;
    /* test 4 */
    cout << g_config << endl;
}


void json_from_string()
{
    cout << "--- 1. create object from string literal" << endl;
    json j = R"(
        {
            "happy": true,
            "pi": 3.14159
        }
    )"_json;
    cout << j << endl;
    
    cout << "\n--- 2. explicit convert json object to string" << endl;
    string s = j.dump();
    cout << s << endl;
    
    cout << "\n--- 3. serialization with pretty printing with spaces to indent" << endl;
    const int indentspaces = 4;
    cout << j.dump(indentspaces) << endl;
}

void json_to_string()
{
    /* store a string in a JSON value */
    json j_string = "this is a string";
    cout << j_string << endl;

    /* retrieve the string value (implicit JSON to std::string conversion) */
    std::string cpp_string = j_string;
    cout << cpp_string << endl;
    
    /* retrieve the string value (explicit JSON to std::string conversion) */
    auto cpp_string2 = j_string.get<std::string>();
    cout << cpp_string2 << endl;

    /* retrieve the serialized value (explicit JSON serialization) */
    std::string serialized_string = j_string.dump();
    cout << serialized_string << endl;
}

void stl_like_access()
{
    // create an array using push_back
    json j;
    j.push_back("foo");
    j.push_back(1);
    j.push_back(true);

    // also use emplace_back
    j.emplace_back(1.78);

    // iterate the array
    for (json::iterator it = j.begin(); it != j.end(); ++it) 
    {
      std::cout << *it << '\n';
    }
}

void convert_from_stl_container()
{
    std::map<std::string, int> c_map { {"one", 1}, {"two", 2}, {"three", 3} };
    json j_map(c_map);
    cout << j_map.dump(4) << endl;
}

int main()
{
    //create_json_object();
    //json_from_string();
    //json_to_string();
    //stl_like_access();
    convert_from_stl_container();
    
    return 0;
}


















