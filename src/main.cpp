#include "DataFetcher.h"
#include "DataFetcher.cpp"
#include <json.hpp>
#include <iostream>

void printUsage() {
    std::cout << "Usage: JsonFetcher [option]\n"
              << "Options:\n"
              << "  --versions         Print the list of versions\n"
              << "  --ltsversion       Print the lts version\n"
              << "  --sha256           Print the sha256\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printUsage();
        return 1;
    }

    std::string option = argv[1];
    std::string url = "https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json";
    Fetcher fetcher;

    try {
        std::string data = fetcher.fetchData(url);
        auto json = nlohmann::json::parse(data);
        

        if (option == "--versions") {
            std::cout << "FETCHING VERSION LIST"<< std::endl;
            std::vector<std::string> versions = fetcher.getVersions(json);
            for (const auto& version : versions) {
                std::cout << version << std::endl;
            }
        } else if (option == "--ltsversion") {
            std::cout << "FETCHING LTSVERSION"<< std::endl;
            std::cout << fetcher.getLtsVersion(json) << std::endl;
        } else if (option == "--sha256") {
            std::cout << "FETCHING SHA256"<< std::endl;
            std::string version = "20150427";
            std::string image = "disk1.img";
            std::cout << fetcher.getSha256(json, version, image) << std::endl;
        } else {
            printUsage();
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
