#include "digraph.hxx"
#include "gtest/gtest.h"
#include <string>
//#include <chrono>

class DigraphTest : public testing::Test {
public:
    Digraph d(std::string("test"));
};

TEST_F(DigraphTest, isCreatedEmpty) {
    EXPECT_EQ(0, d.order());
}

TEST_F(DigraphTest, orderUp) {
    EXPECT_EQ(0, d.order());
    d.addVertex(Vertex());
    EXPECT_EQ(1, d.order());
    d.addVertex(Vertex());
    d.addVertex(Vertex());  
    EXPECT_EQ(3, d.order());
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}