#include <gtest/gtest.h>
#include <memory>
#include "../src/parse_cargo_file.cpp"

class ParseCargoFileTests : public ::testing::Test {
public:
protected:
  void SetUp() override { }
  void TearDown() override {}
};

TEST_F(ParseCargoFileTests,InvalidFileName){
    EXPECT_THROW(parse_cargo_file("doesnotexist.yaml"), std::invalid_argument);
}

TEST_F(ParseCargoFileTests,InvalidCargoIdLineWithNoSemiColon){
    EXPECT_THROW(parse_id_line("123"), std::invalid_argument);
}

TEST_F(ParseCargoFileTests,InvalidCargoIdLineWithCharacter){
    EXPECT_THROW(parse_id_line("13a232:"), std::invalid_argument);
}

TEST_F(ParseCargoFileTests,InvalidCargoIdLineWithNegativeNumber){
    EXPECT_THROW(parse_id_line("-123:"), std::invalid_argument);
}

TEST_F(ParseCargoFileTests,ValidIDLine){
    EXPECT_EQ(parse_id_line("123:"), 123);
}

TEST_F(ParseCargoFileTests,InvalidMassLineWithNoIndent){
    EXPECT_THROW(parse_mass_line("mass: 100.0"), std::invalid_argument);
}

TEST_F(ParseCargoFileTests,InvalidMassLineWithNoSemicolon){
    EXPECT_THROW(parse_mass_line("    mass 100.0"), std::invalid_argument);
}

TEST_F(ParseCargoFileTests,InvalidMassLineWithNoMassKeyword){
    EXPECT_THROW(parse_mass_line("    : 100.0"), std::invalid_argument);
}

TEST_F(ParseCargoFileTests,ValidMassLineWithOneSpaceIndent){
    EXPECT_EQ(parse_mass_line(" mass: 100.0"), 100);
}

TEST_F(ParseCargoFileTests,ValidMassLineWithTwoSpaceIndent){
    EXPECT_EQ(parse_mass_line("  mass: 100.0"), 100);
}

TEST_F(ParseCargoFileTests,ValidMassLineWithThreeSpaceIndent){
    EXPECT_EQ(parse_mass_line("   mass: 100.0"), 100);
}

TEST_F(ParseCargoFileTests,ValidMassLineWithIntegerValue){
    EXPECT_EQ(parse_mass_line("    mass: 50"), 50);
}

TEST_F(ParseCargoFileTests,ValidMassLineWithFloatValue){
    EXPECT_FLOAT_EQ(parse_mass_line("    mass: 60.2"), 60.2);
}

TEST_F(ParseCargoFileTests,InvalidVolumeLineWithNoSpaces){
    EXPECT_THROW(parse_volume_line("volume: [1.1, 1.1, 1.1]"), std::invalid_argument);
}

TEST_F(ParseCargoFileTests,InvalidVolumeLineWithNoSemicolon){
    EXPECT_THROW(parse_volume_line("    volume [1.1, 1.1, 1.1]"), std::invalid_argument);
}

TEST_F(ParseCargoFileTests,ValidVolumeLineWithFloats){
    EXPECT_EQ(parse_volume_line("    volume: [1.1, 1.2, 1.3]"), std::vector<float>({1.1,1.2,1.3}));
}

TEST_F(ParseCargoFileTests,ValidVolumeLineWithIntegers){
    EXPECT_EQ(parse_volume_line("    volume: [1, 2, 3]"), std::vector<float>({1,2,3}));
}

TEST_F(ParseCargoFileTests,ValidVolumeLineWithNoSpacesBetweenNumbers){
    EXPECT_EQ(parse_volume_line("    volume: [1,2,3]"), std::vector<float>({1,2,3}));
}