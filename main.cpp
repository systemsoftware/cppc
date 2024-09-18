#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <string>

namespace fs = std::filesystem;

using namespace std;

int main(int argc, char* argv[]) {
    string compiler_command = "clang++";  

    string curr = fs::current_path().string(); 

    bool deleteAfterCompile = false;

    bool allFiles = false;

    int version = 17; 
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if (arg == "-v") {
            if (i + 1 < argc) {
                version = std::stoi(argv[++i]);
                cout << "Using C++ version " << version << endl;
            } else {
                cerr << "Error: -v option requires a version argument" << endl;
                return 1;
            }
        } else if (arg == "-c") {
            if (i + 1 < argc) {
                compiler_command = argv[++i];
                cout << "Using compiler: " << compiler_command << endl;
            } else {
                cerr << "Error: -c option requires a compiler command argument" << endl;
                return 1;
            }
        }else if(arg == "-d") {
            deleteAfterCompile = true;
            cout << "Files will be deleted after compilation." << endl;
        }else if(arg == "-a") {
            allFiles = true;
            cout << "Compiling all files in the directory." << endl;
        }
    }

    string files;

    for (const auto& entry : fs::directory_iterator(curr)) {
        if(allFiles) {
            if (entry.is_directory()) continue;
            if (entry.path().filename() == ".DS_Store") continue;
            if (entry.path().extension() == ".o" || entry.path().extension() == ".out") continue;
            files += entry.path().string() + " ";
        }else if (entry.path().extension() == ".cpp" || entry.path().extension() == ".h") {
            files += entry.path().string() + " ";
        }
    }


    if (files.empty()) {
        cerr << "No .cpp files found to compile." << endl;
        return 1;
    }

    string compiledFileName;

    string command = compiler_command + " -std=c++" + to_string(version) + " " + files;
    int result = system(command.c_str());

        for(const auto& entry : fs::directory_iterator(curr)) {
        if(entry.path().extension() == ".out") {
            compiledFileName = entry.path().filename().string();
            break;
        }
    }

    if (compiledFileName.empty()) {
        cerr << "No output file generated." << endl;
        return 1;
    }

    result = system(("./" + compiledFileName).c_str());

if (result != 0) {
    cerr << "Command failed with code: " << result << endl;
    return 1;
}

    if (result != 0) {
        cerr << "Command failed with code: " << result << endl;
        return 1;
    }

    if(deleteAfterCompile) {
        for (const auto& entry : fs::directory_iterator(curr)) {
            if (entry.path().extension() == ".o" || entry.path().extension() == ".out") {
                fs::remove(entry.path());
                cout << endl << endl << "Deleted: " << entry.path() << endl;
            }
        }
    }

    return 0;
}
