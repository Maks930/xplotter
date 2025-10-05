//
// Created by Maks930 on 05/10/2025.
//

#include <gtest/gtest.h>

#include "../src/core/Project/MetaInfo/MetaInfo.h"



TEST(BooleanOperators, Care1) {
    xlp::Version ver1{.major = 1, .minor = 0, .patch = 0};
    xlp::Version ver2{.major = 1, .minor = 1, .patch = 5};

    EXPECT_EQ(ver1 == ver1, true);
    EXPECT_EQ(ver1 != ver1, false);

    EXPECT_EQ(ver1 == ver2, false);
    EXPECT_EQ(ver1 != ver2, true);
}

TEST(BooleanOperators, Case2) {
    xlp::Version ver1{.major = 1, .minor = 0, .patch = 0};
    xlp::Version ver2{.major = 1, .minor = 1, .patch = 5};

    EXPECT_EQ(ver1 > ver2, false);
    EXPECT_EQ(ver1 < ver2, true);

    EXPECT_EQ(ver1 >= ver2, false);
    EXPECT_EQ(ver1 <= ver2, true);
}

TEST(VersionSerialize, Case1) {
    xlp::Version ver1{.major = 1, .minor = 0, .patch = 0};

}

TEST(METAINFO_TEST, Case1) {
    xlp::Version ver_app{.major = 1, .minor = 0, .patch = 0};
    xlp::MetaInfo info("Test_name", "Test_desc", {1,0,0});
    xlp::Version ver{.major = XLP_APP_VER_MAJOR, .minor = XLP_APP_VER_MINOR, .patch = XLP_APP_VER_PATCH};

    EXPECT_EQ(info.get_name(), "Test_name");
    EXPECT_EQ(info.get_description(), "Test_desc");
    EXPECT_EQ(info.get_authors().size(), 1);
    EXPECT_EQ(info.get_authors().at(0), std::getenv("USERNAME"));
    EXPECT_EQ(info.get_app_version() == ver, true);
    EXPECT_EQ(info.get_project_version() == ver_app, true);
}