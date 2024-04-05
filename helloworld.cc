#include <vector>
#include <iostream>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <node_api.h>

namespace fs = std::filesystem;

napi_value MoveFiles(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    size_t strLength;
    napi_get_value_string_utf8(env, argv[0], nullptr, 0, &strLength);
    std::string extension(strLength, '\0');
    napi_get_value_string_utf8(env, argv[0], &extension[0], strLength + 1, &strLength);

    std::unordered_map<std::string, std::string> extensionToFolder;
    extensionToFolder["." + extension] = "/Users/aurelienbrachet/Desktop/" + extension;

    std::string path = "/Users/aurelienbrachet/Downloads";
    for (const auto& entry : fs::directory_iterator(path)) {
        if(!entry.is_directory()) {
            std::string ext = entry.path().filename().extension().string();
            if (extensionToFolder.find(ext) != extensionToFolder.end()) {
                fs::path destPath = fs::path(extensionToFolder[ext]) / entry.path().filename();
                try {
                    fs::rename(entry.path(), destPath);
                    std::cout << "File moved successfully: " << entry.path().filename() << std::endl;
                } catch (fs::filesystem_error& e) {
                    std::cerr << "Error moving file: " << e.what() << '\n';
                }
            }
        }
    }

    std::string message = "Operation was successful";
    napi_value result;
    napi_status status = napi_create_string_utf8(env, message.c_str(), message.length(), &result);

    return result;
}


napi_value init(napi_env env, napi_value exports) {

    napi_value find_primes = find_primes;

    napi_create_function(env, nullptr, 0, MoveFiles, nullptr, &find_primes);

    return find_primes;
}

NAPI_MODULE(hello, init)


/* 
    ORIGINAL C++ FUNCTION THAT WAS TESTED TO MOVE FILES FROM /DOWNLOAD TO DESKTOP

int main() {
    std::unordered_map<std::string, std::string> extensionToFolder;

 /   extensionToFolder[".jpg"] = "/Users/aurelienbrachet/Desktop/images";
    extensionToFolder[".png"] = "/Users/aurelienbrachet/Desktop/images";
    extensionToFolder[".MOV"] = "/Users/aurelienbrachet/Desktop/MOV"; 
    extensionToFolder[".mp3"] = "/Users/aurelienbrachet/Desktop/mp3";

    int numberOfJpg = 0;
    int numberOfPng = 0;
    int numberOfPdf = 0;
    int numberOfMOV = 0;

    std::string path = "/Users/aurelienbrachet/Downloads";
    for (const auto & entry : fs::directory_iterator(path)) {
        if(!entry.is_directory()) {
            std::string ext = entry.path().filename().extension();
            fs::path path = entry.path();
            if (extensionToFolder.find(ext) != extensionToFolder.end()) {
                fs::path destPath = fs::path(extensionToFolder[ext]) / path.filename();
                try {
                    fs::rename(path, destPath);
                    std::cout << "File moved successfully." << entry.path().filename() << std::endl;
                } catch (fs::filesystem_error& e) {
                    std::cerr << "Error moving file: " << e.what() << '\n';
                }
            }
            // && extensionToFolder.find()
            // std::cout << entry.path().filename().extension() << std::endl;
        }
    }
    std::cout << numberOfMOV << std::endl;
    std::cout << numberOfPng << std::endl;
    std::cout << numberOfJpg << std::endl;
        
    return 0;
} */