#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

static inline string trim(const string &s) {
    size_t i = s.find_first_not_of(" \t\r\n");
    if (i == string::npos) return "";
    size_t j = s.find_last_not_of(" \t\r\n");
    return s.substr(i, j - i + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;
    string dummy;
    getline(cin, dummy); // eat endline after Q

    unordered_map<string,string> kv;   // key: "tag1.tag2~attr" -> value
    vector<string> stackPath;          // current tag stack

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        line = trim(line);

        // closing tag
        if (line.size() >= 3 && line[0] == '<' && line[1] == '/') {
            if (!stackPath.empty()) stackPath.pop_back();
            continue;
        }

        // strip <  >
        if (line.front() == '<') line.erase(line.begin());
        if (!line.empty() && line.back() == '>') line.pop_back();
        line = trim(line);

        // extract tag name (up to first space or end)
        string tag;
        size_t sp = line.find(' ');
        if (sp == string::npos) {
            tag = line;
            line.clear();
        } else {
            tag = line.substr(0, sp);
            line.erase(0, sp + 1);
        }
        stackPath.push_back(tag);

        // build current path "a.b.c"
        string path;
        for (size_t k = 0; k < stackPath.size(); ++k) {
            if (k) path += ".";
            path += stackPath[k];
        }

        // parse attributes: name = "value" ... (values may contain spaces)
        size_t pos = 0;
        while (pos < line.size()) {
            // skip spaces
            while (pos < line.size() && isspace(line[pos])) ++pos;
            if (pos >= line.size()) break;

            // find '='
            size_t eq = line.find('=', pos);
            if (eq == string::npos) break;
            string attr = trim(line.substr(pos, eq - pos));

            // find value inside quotes after '='
            size_t firstQ = line.find('"', eq + 1);
            size_t secondQ = (firstQ == string::npos) ? string::npos
                                                      : line.find('"', firstQ + 1);
            if (firstQ == string::npos || secondQ == string::npos) break;

            string value = line.substr(firstQ + 1, secondQ - firstQ - 1);

            kv[path + "~" + attr] = value;

            pos = secondQ + 1; // continue scanning for more attributes
        }
    }

    for (int i = 0; i < Q; ++i) {
        string query;
        getline(cin, query);
        auto it = kv.find(query);
        if (it == kv.end()) cout << "Not Found!\n";
        else                cout << it->second << "\n";
    }
    return 0;
}
