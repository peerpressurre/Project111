#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>


using namespace std;

// ���� ��� ������ � �������
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

// ������� ��� ���������� ���������� ��������
std::map<std::string, int> buildFrequencyMap(const std::string& text) {
    std::map<std::string, int> frequencyMap;
    std::string word;
    std::istringstream iss(text);

    while (iss >> word) {
        // ��������� ������� ���������� � ���� �����
        while (!word.empty() && !std::isalpha(word.back())) {
            word.pop_back();
        }
        // �������� �������� ��� ����� �����
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

    }
}

int main() {
    File inputFile("input.txt", std::ios::in);
    File outputFile("output.txt", std::ios::out);

    if (!inputFile.isOpen() || !outputFile.isOpen()) {
        return 1;
    }

    // ������ ���� �������� �����
    std::string text = inputFile.read();

    // ������� ��������� �������
    std::map<std::string, int> frequencyMap = buildFrequencyMap(text);

    // �������� ���������� ��� �� �����
    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // ��������� ������� ����� ������� �����
    std::string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto& pair : frequencyMap) {
        if (pair.second > maxFrequency) {
            mostFrequentWord = pair.first;
            maxFrequency = pair.second;
        }
    }

    // �������� ������� ����� ������� �����
    std::cout << "Most frequent word: " << mostFrequentWord << " (frequency: " << maxFrequency << ")" << std::endl;

    // �������� ��������� � ����
    for (const auto& pair : frequencyMap) {
        outputFile.write(pair.first + ": " + std::to_string(pair.second) + "\n");
    }

    return 0;
}