#include "DataFetcher.h"
#include <curl/curl.h>
#include <stdexcept>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

class Fetcher : public DataFetcher {
public:
    std::string fetchData(const std::string& url) override {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);


            // Increase timeout to handle large files
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 300L);

            // Follow HTTP redirects if needed
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            
            // Enable verbose output for debugging
            // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if(res != CURLE_OK) {
                throw std::runtime_error("Failed to fetch data from " + url);
            }
        }
        return readBuffer;
    }

    std::vector<std::string> getVersions(const nlohmann::json& json) {
        std::vector<std::string> versionKeys;
        auto versions = json["products"]["com.ubuntu.cloud:server:10.04:amd64"]["versions"];
        for (auto it = versions.begin(); it != versions.end(); ++it) {
            versionKeys.push_back(it.key());
        }
        return versionKeys;
    }

    std::string getLtsVersion(const nlohmann::json& json) {
        return json["products"]["com.ubuntu.cloud:server:10.04:amd64"]["version"];
    }

    std::string getSha256(const nlohmann::json& json, const std::string& version, const std::string& image) {
        return json["products"]["com.ubuntu.cloud:server:10.04:amd64"]["versions"][version]["items"][image]["sha256"];
    }

};
