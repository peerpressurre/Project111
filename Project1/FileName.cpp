#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <filesystem> 

class File{
private:
    std::fstream file;

public:
    File(const std::string& filename, std::ios_base::openmode mode) {
        file.open(filename, mode);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
        }
    }

    ~File() {
        if (file.is_open()) {
            file.close();
        }
    }

    bool isOpen() const {
        return file.is_open();
    }

    void write(const std::string& data) {
        file << data;
    }

    std::string read() {
        std::string content;
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        return content;
    }
};

std::map<std::string, int> frequencyMap(std::string& text) {
    std::map<std::string, int> frequencyMap;
    std::string word;
    std::istringstream ss(text);

    while(ss >> word) {
        while (!word.empty() && !std::isalpha(word.back())) {
            word.pop_back();
        }
        if (!word.empty()) {
            frequencyMap[word]++;
        }
        else {
            std::cout << "Empty word encountered!" << std::endl;
        }
    }

    return frequencyMap;
}


int main() {
    File inputFile("input.txt", std::ios::in);
    File outputFile("output.txt", std::ios::out);

    std::string text = inputFile.read();
    //inputFile.close();

    std::map<std::string, int> frmap = frequencyMap(text);
    std::cout << "Words:       quantity" << std::endl;
    for (auto& pair : frmap)
    {
        std::cout << "Word: " << pair.first << "    " << "Count: " << pair.second << std::endl;
    }
    std::string maxstr;
    int max = 0;
    for (auto& pair : frmap)
    {
        if (pair.second > max)
        {
            max = pair.second;
            maxstr = pair.first;
        }
    }
    std::cout << "Most encountered word: " << maxstr << " - " << frmap[maxstr] << std::endl;
    return 0;
}
