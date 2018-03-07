/*************************************************************************
	> File Name: config.h
	> Author: 
	> Mail: 
	> Created Time: Tue 06 Mar 2018 03:53:25 PM PST
 ************************************************************************/

#ifndef _CONFIG_H
#define _CONFIG_H

auto g_config = R"(
    {
        "pi": 3.141,
        "happy": true,
        "name": "Niels",
        "nothing": null,
        "answer": 
        {
            "everything": 42
        },
        "list": 
        [
            1,
            0,
            2
        ],
        "object": 
        {
            "currency": "USD",
            "value": 42.99
        }
    }
)"_json;
#endif
