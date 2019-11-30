#include "ArrayDictionary.h"
#include "gtest/gtest.h"

#define PRINT

TEST(dict, array_dict_basic) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(1, 2));
    ASSERT_EQ(hashTable.size(), 1);
    ASSERT_FALSE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(8, 4));
    ASSERT_EQ(hashTable.size(), 2);

    ASSERT_TRUE(hashTable.add(11, 4));
    ASSERT_EQ(hashTable.size(), 2);
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict, array_dict_add_overwrite) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 2));
    ASSERT_TRUE(hashTable.add(2, 4));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.size(), 1);
}

TEST(dict, array_dict_value_set_size) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.valueSetSize(5), 0);
    ASSERT_EQ(hashTable.valueSetSize(2), 2);
    ASSERT_EQ(hashTable.valueSetSize(3), 1);
}

TEST(dict, array_dict_add_get) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    int val = 0;
    ASSERT_TRUE(hashTable.get(2, val));
    ASSERT_EQ(val, 9);
    ASSERT_TRUE(hashTable.get(12, val));
    ASSERT_EQ(val, 8);
    ASSERT_TRUE(hashTable.get(3, val));
    ASSERT_EQ(val, 4);
    ASSERT_FALSE(hashTable.get(7, val));
    ASSERT_EQ(val, 4);
}

TEST(dict, contains) {
    // homework
	// homework
	ArrayDictionary<int, int> hashTable;//make new tables for each set 
	ASSERT_FALSE(hashTable.contain(-1));
	ASSERT_FALSE(hashTable.contain(0));
	ASSERT_FALSE(hashTable.contain(1));

	//set two
	ArrayDictionary<int, int> hashTableTwo(1);
	ASSERT_TRUE(hashTableTwo.add(0,103));
	ASSERT_FALSE(hashTableTwo.contain(2));
	ASSERT_TRUE(hashTableTwo.contain(0));
#ifdef PRINT
	hashTableTwo.print();
#endif
	//set three
	ArrayDictionary<int, int> hashTableThree(2);
	ASSERT_TRUE(hashTableThree.add(0, 103));
	ASSERT_TRUE(hashTableThree.add(1, 105));
	//return
	ASSERT_TRUE(hashTableThree.contain(0));
	ASSERT_TRUE(hashTableThree.contain(1));
	ASSERT_FALSE(hashTableThree.contain(2));
	ASSERT_FALSE(hashTableThree.contain(3));

	//set four
	ArrayDictionary<int, int> hashTableFour(3);
	ASSERT_TRUE(hashTableFour.add(0, 103));
	ASSERT_TRUE(hashTableFour.add(1, 105));
	ASSERT_TRUE(hashTableFour.add(2, 206));
	ASSERT_FALSE(hashTableFour.contain(3));
	ASSERT_TRUE(hashTableFour.contain(1));

	//set Five
	ArrayDictionary<int, int> hashTableFive(3);
	ASSERT_TRUE(hashTableFive.add(0, 103));
	ASSERT_TRUE(hashTableFive.add(1, 105));
	ASSERT_TRUE(hashTableFive.add(2, 206));
	ASSERT_TRUE(hashTableFive.add(4, 407));
	ASSERT_TRUE(hashTableFive.contain(1));
	ASSERT_TRUE(hashTableFive.contain(4));
	ASSERT_FALSE(hashTableFive.contain(7));
	ASSERT_FALSE(hashTableFive.contain(8));
}

TEST(dict, remove) {
    // homework

	//case One
	//test empty dictionary
	ArrayDictionary<int, int> hashTable_One;
	ASSERT_FALSE(hashTable_One.remove(2));

	//set Two
	//key exists in a dictionary that has no collision
	ArrayDictionary<int ,int> hashTable_Two;
	ASSERT_TRUE(hashTable_Two.add(1, 1));
	ASSERT_TRUE(hashTable_Two.add(2, 2));
	ASSERT_TRUE(hashTable_Two.add(3, 3));
	ASSERT_TRUE(hashTable_Two.add(4, 4));
	ASSERT_TRUE(hashTable_Two.remove(2));

	//set Three
	//key does not exists in a dictionary that has no collision
	ArrayDictionary<int, int> hashTable_Three;
	ASSERT_TRUE(hashTable_Three.add(1, 1));
	ASSERT_TRUE(hashTable_Three.add(2, 2));
	ASSERT_TRUE(hashTable_Three.add(3, 3));
	ASSERT_TRUE(hashTable_Three.add(4, 4));
	ASSERT_FALSE(hashTable_Three.remove(5)); // placeholder

	//set four
	//key exists in a dictionary that has collision, key is in the collision.
	ArrayDictionary<int, int> hashTable_Four;
	ASSERT_TRUE(hashTable_Four.add(1, 1));
	ASSERT_TRUE(hashTable_Four.add(2, 2));
	ASSERT_TRUE(hashTable_Four.add(2, 3));
	ASSERT_TRUE(hashTable_Four.add(3, 3));
	ASSERT_TRUE(hashTable_Four.add(4, 4));
	ASSERT_TRUE(hashTable_Four.remove(3));

	//set Five
	//key does not exists in a dictionary that has collision
	ArrayDictionary<int, int> hashTable_Five;
	ASSERT_TRUE(hashTable_Five.add(1, 1));
	ASSERT_TRUE(hashTable_Five.add(2, 2));
	ASSERT_TRUE(hashTable_Four.add(2, 3));
	ASSERT_TRUE(hashTable_Five.add(3, 3));
	ASSERT_TRUE(hashTable_Five.add(4, 4));
	ASSERT_FALSE(hashTable_Five.remove(5));
}
