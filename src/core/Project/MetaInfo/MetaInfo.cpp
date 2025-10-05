//
// Created by Maks930 on 05/10/2025.
//

#include <core/Project/MetaInfo/MetaInfo.h>

using namespace xlp;


MetaInfo::MetaInfo() {
    _authors.push_back(author_type(std::getenv("USERNAME")));
    _description = "";
    _name = "Untitled";
}

MetaInfo::MetaInfo(const std::string &name, const std::string &description) {
    _authors.push_back(author_type(std::getenv("USERNAME")));
    _description = description;
    _name = name;
}

MetaInfo::MetaInfo(const std::string &name, const std::string &description, const Version &project_version) {
    _authors.push_back(author_type(std::getenv("USERNAME")));
    _description = description;
    _name = name;
    _project_version = project_version;
}

MetaInfo::MetaInfo(const std::string &name, const std::string &description, const Version &project_version,
    const Version &app_version) : MetaInfo(name, description, project_version) {
    _app_version = app_version;
}

std::string MetaInfo::get_name() const {
    return _name;
}

std::string MetaInfo::get_description() const {
    return _description;
}

Version MetaInfo::get_project_version() const {
    return _project_version;
}

std::vector<author_type> MetaInfo::get_authors() const {
    return _authors;
}

Version MetaInfo::get_app_version() const {
    return _app_version;
}

void MetaInfo::set_authors(const std::vector<author_type> &authors) {
    _authors = authors;
}

void MetaInfo::set_project_version(const Version &project_version) {
    _project_version = project_version;
}

void MetaInfo::set_app_version(const Version &app_version) {
    _app_version = app_version;
}

void MetaInfo::set_name(const std::string &name) {
    _name = name;
}

void MetaInfo::set_description(const std::string &description) {
    _description = description;
}

void MetaInfo::add_author(const author_type &author) {
    _authors.push_back(author);
}

bool operator==(const xlp::Version &lhs, const xlp::Version &rhs) {
    return lhs.major == rhs.major && lhs.minor == rhs.minor && lhs.patch == rhs.patch;
}

bool operator!=(const xlp::Version &lhs, const xlp::Version &rhs) {
    return lhs.major != rhs.major || lhs.minor != rhs.minor || lhs.patch != rhs.patch;
}

bool operator>(const xlp::Version &lhs, const xlp::Version &rhs) {
    return lhs.major > rhs.major || lhs.minor > rhs.minor || lhs.patch > rhs.patch;
}

bool operator<(const xlp::Version &lhs, const xlp::Version &rhs) {
    return lhs.major < rhs.major || lhs.minor < rhs.minor || lhs.patch < rhs.patch;
}

bool operator<=(const xlp::Version &lhs, const xlp::Version &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const xlp::Version &lhs, const xlp::Version &rhs) {
    return !(lhs < rhs);
}
