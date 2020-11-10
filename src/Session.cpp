//
// Created by spl211 on 08/11/2020.
//

#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Session.h"

using json = nlohmann::json;
using namespace std;

Session::Session(const std::string &path) {
    ifstream i(path);
    json j;
    j << i;
    g=Graph(j["graph"]);
    treeType= j["tree"];


};

