#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>


using namespace std;

// Клас для роботи з файлами
class File {
private:
    std::fstream file;

public:
    File(const string& filename, ios_base::openmode mode) {
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

    void write(const string& data) {
        file << data;
    }

    string read() {
        string content;
        string line;
        while (getline(file, line)) {
            content += line + "\n";
        }
        return content;
    }
};

// Функція для формування частотного словника
std::map<std::string, int> buildFrequencyMap(const std::string& text) {
    std::map<std::string, int> frequencyMap;
    std::string word;
    std::istringstream iss(text);

    while (iss >> word) {
        // Видаляємо символи пунктуації з кінця слова
        while (!word.empty() && !std::isalpha(word.back())) {
            word.pop_back();
        }
        // Збільшуємо лічильник для цього слова
        frequencyMap[word]++;
    }

    return frequencyMap;
}

map<string, int> frequencyMap(string& text) {
    map<string, int> frequencyMap;
    string word;
    istringstream ss(text);

    while (ss >> word)
    {
        while (!word.empty() && isalpha(word.back()))
        {
            word.pop_back();
        }
        frequencyMap[word]++;
    }

    return frequencyMap;
}



int main() {
    File inputFile("input.txt", ios::in);
    File outputFile("output.txt", ios::out);
    
    string text = inputFile.read();
    map<string, int> frmap = frequencyMap(text);

    cout << "Words:          quantity" << endl;
    for (auto& pair : frmap)
    {
        cout << pair.first << "    -     " << pair.second << endl;
    }
    
    return 0;
}