//
// Created by Maks930 on 05/10/2025.
//

#ifndef XPLOTTER_METAINFO_H
#define XPLOTTER_METAINFO_H

#include <string>
#include <vector>

namespace xlp {
    class MetaInfo;

    using author_type = std::string;
    struct Version {
        unsigned major;
        unsigned minor;
        unsigned patch;
    };

};

class xlp::MetaInfo {
public:

private:
    std::vector<author_type> _authors;
    std::string _name;
    std::string _description;
    Version _app_version = {.major = XLP_APP_VER_MAJOR, .minor = XLP_APP_VER_MINOR, .patch = XLP_APP_VER_PATCH};
    Version _project_version = {.major = 0, .minor = 0, .patch = 0};

public:
    MetaInfo();
    MetaInfo(const std::string &name, const std::string &description);
    MetaInfo(const std::string &name, const std::string &description, const Version& project_version);
    MetaInfo(const std::string &name, const std::string &description,
        const Version& project_version, const Version& app_version);

    [[nodiscard]] std::string get_name() const;
    [[nodiscard]] std::string get_description() const;
    [[nodiscard]] Version get_project_version() const;
    [[nodiscard]] std::vector<author_type> get_authors() const;
    [[nodiscard]] Version get_app_version() const;

    void set_authors(const std::vector<author_type> &authors);
    void set_project_version(const Version &project_version);
    void set_app_version(const Version &app_version);
    void set_name(const std::string &name);
    void set_description(const std::string &description);

    void add_author(const author_type &author);
};

namespace std {
    inline std::string to_string(const xlp::Version &version) {
        return std::to_string(version.major) + "." + std::to_string(version.minor) + "." + std::to_string(version.patch);
    }
};

bool operator==(const xlp::Version &lhs, const xlp::Version &rhs);
bool operator!=(const xlp::Version &lhs, const xlp::Version &rhs);
bool operator>(const xlp::Version &lhs, const xlp::Version &rhs);
bool operator<(const xlp::Version &lhs, const xlp::Version &rhs);
bool operator<=(const xlp::Version &lhs, const xlp::Version &rhs);
bool operator>=(const xlp::Version &lhs, const xlp::Version &rhs);


#endif //XPLOTTER_METAINFO_H