#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

std::map<std::string, std::string> build_map(std::ifstream &map_file) {
    std::map<std::string, std::string> trans_map;
    std::string key;
    std::string value;

    while (map_file >> key && std::getline(map_file, value)) {
        if(value.size() > 1) {
            trans_map[key] = value.substr(1); // keep the newest
            // trans_map.insert({key, value.substr(1)}); // keep the oldest
        } else {
            throw std::runtime_error("no rule for " + key);
        }
    }

    return trans_map;
}

const std::string& transform(const std::string& word, const std::map<std::string, std::string> &trans_map) {
    auto it = trans_map.find(word);
    if(it != trans_map.end()) {
        return it->second;
    } else {
        return word;
    }
}

std::string& transform_v2(std::string& word, std::map<std::string, std::string> &trans_map) {
    auto &s = trans_map[word];
    if(s.size()) {
        return s;
    } else {
        return word;
    }
}

void word_transform(std::ifstream &map_file, std::ifstream &input) {
    auto trans_map = build_map(map_file);
    std::string text;

    while(std::getline(input, text)) {
        std::istringstream iss(text);
        std::string word;
        bool firstword = true;

        while (iss >> word) {
            if(firstword) {
                firstword = false;
            } else {
                std::cout << " ";
            }

            std::cout << transform_v2(word, trans_map);
        }

        std::cout << std::endl;
    }
}

int main (int argc, char *argv[]) {
    if(argc < 3) {
        std::cerr << "usage: ./p11_33 map_file input_file" << std::endl;
        return -1;
    }

    std::ifstream map_file(argv[1]);
    std::ifstream input_file(argv[2]);

    if(!map_file) {
        std::cerr << "No map file!" << std::endl;
        std::cerr << "usage: ./p11_33 map_file input_file" << std::endl;
        return -2;
    }

    if(!input_file) {
        std::cerr << "No input file!" << std::endl;
        std::cerr << "usage: ./p11_33 map_file input_file" << std::endl;
        return -3;
    }

    word_transform(map_file, input_file);

    return 0;
}
