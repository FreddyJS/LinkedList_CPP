#include <gtest/gtest.h>
#include <LinkedList.hpp>

class IntegerListTests : public testing::Test
{
public:	
	LinkedList<int> integerList;

	virtual void SetUp()
	{
		integerList.clear();
	}

	virtual void TearDown()
	{
	}

};

TEST_F( IntegerListTests, IntegersCanBeAddedToTheList )
{
	//given:
	int number = 32;
	
	//when:
	integerList.addLast(number);

	//then:
	EXPECT_EQ(integerList.size, 1);
	EXPECT_EQ(integerList.getLast(), number);
}
