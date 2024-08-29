#ifndef DATAFETCHER_H
#define DATAFETCHER_H

#include <string>
#include <json.hpp>

class DataFetcher {
public:
    virtual ~DataFetcher() = default;
    virtual std::string fetchData(const std::string& url) = 0;

    virtual std::vector<std::string> getVersions(const nlohmann::json& json) = 0;
    virtual std::string getLtsVersion(const nlohmann::json& json) = 0;
    virtual std::string getSha256(const nlohmann::json& json, const std::string& version, const std::string& image) = 0;
};

#endif // DATAFETCHER_H
