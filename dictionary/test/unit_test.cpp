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

	//_____SET ONE_____
	//make new tables for set
	ArrayDictionary<int, int> hashTable;
	ASSERT_FALSE(hashTable.contain(-1));
	ASSERT_FALSE(hashTable.contain(0));
	ASSERT_FALSE(hashTable.contain(1));

  	//_____SET TWO_____
	//make new tables for key
	ArrayDictionary<int, int> hashTableTwo(1);
	ASSERT_TRUE(hashTableTwo.add(0, 103));

	//test if it contains a key
	ASSERT_FALSE(hashTableTwo.contain(2));
	ASSERT_TRUE(hashTableTwo.contain(0));

	//should print one line
#ifdef PRINT
	hashTableTwo.print();
#endif

	//_____SET THREE_____
	//make new tables for set
	ArrayDictionary<int, int> hashTableThree(2);
	ASSERT_TRUE(hashTableThree.add(0, 103));
	ASSERT_TRUE(hashTableThree.add(1, 105));

	//test if it contains the key
	ASSERT_TRUE(hashTableThree.contain(0));
	ASSERT_TRUE(hashTableThree.contain(1));
	ASSERT_FALSE(hashTableThree.contain(2));
	ASSERT_FALSE(hashTableThree.contain(3));

	//_____SET FOUR_____
	//make new tables for set
	ArrayDictionary<int, int> hashTableFour(3);
	ASSERT_TRUE(hashTableFour.add(0, 103));
	ASSERT_TRUE(hashTableFour.add(1, 105));
	ASSERT_TRUE(hashTableFour.add(2, 206));

	//test if it contains the key
	ASSERT_FALSE(hashTableFour.contain(3));
	ASSERT_TRUE(hashTableFour.contain(1));

	//_____SET FIVE_____
	//make new tables for set
	ArrayDictionary<int, int> hashTableFive(3);
	ASSERT_TRUE(hashTableFive.add(0, 103));
	ASSERT_TRUE(hashTableFive.add(1, 105));
	ASSERT_TRUE(hashTableFive.add(2, 206));
	ASSERT_TRUE(hashTableFive.add(4, 407));

	//test if it contains the key
	ASSERT_TRUE(hashTableFive.contain(1));
	ASSERT_TRUE(hashTableFive.contain(4));
	ASSERT_FALSE(hashTableFive.contain(7));
	ASSERT_FALSE(hashTableFive.contain(8));}

TEST(dict, remove) {
    // homework
	//_____CASE ONE_____
	//test empty dictionary
	ArrayDictionary<int, int> hashTable_One(1);
	ASSERT_FALSE(hashTable_One.remove(2));
#ifdef PRINT
	hashTable_One.print();
#endif
	//_____CASE TWO_____
	//key exists in a dictionary that has no collision
	ArrayDictionary<int ,int> hashTable_Two(4);
	ASSERT_TRUE(hashTable_Two.add(1, 1));
	ASSERT_TRUE(hashTable_Two.add(2, 2));
	ASSERT_TRUE(hashTable_Two.add(3, 3));
	ASSERT_TRUE(hashTable_Two.add(4, 4));
#ifdef PRINT
	hashTable_Two.print();
#endif
	//remove key
	ASSERT_TRUE(hashTable_Two.remove(2));
#ifdef PRINT
	hashTable_Two.print();
#endif
	//_____CASE THREE_____
	//key does not exists in a dictionary that has no collision
	ArrayDictionary<int, int> hashTable_Three(4);
	ASSERT_TRUE(hashTable_Three.add(1, 1));
	ASSERT_TRUE(hashTable_Three.add(2, 2));
	ASSERT_TRUE(hashTable_Three.add(3, 3));
	ASSERT_TRUE(hashTable_Three.add(4, 4));

	//remove key
	ASSERT_FALSE(hashTable_Three.remove(5)); 

	//_____CASE FOUR_____
	//key exists in a dictionary that has collision, key is in the collision.
	ArrayDictionary<int, int> hashTable_Four(4);//specify the size
	ASSERT_TRUE(hashTable_Four.add(1, 1));
	ASSERT_TRUE(hashTable_Four.add(2, 2));
	ASSERT_TRUE(hashTable_Four.add(6, 3));
	ASSERT_TRUE(hashTable_Four.add(3, 3));
	ASSERT_TRUE(hashTable_Four.add(4, 4));
#ifdef PRINT
	hashTable_Four.print();
#endif
	//remove key
	ASSERT_TRUE(hashTable_Four.remove(2));
#ifdef PRINT
	hashTable_Four.print();
#endif
	//_____CASE FIVE_____
	//key does not exists in a dictionary that has collision
	ArrayDictionary<int, int> hashTable_Five(4);
	ASSERT_TRUE(hashTable_Five.add(1, 1));
	ASSERT_TRUE(hashTable_Five.add(2, 2));
	ASSERT_TRUE(hashTable_Five.add(6, 3));
	ASSERT_TRUE(hashTable_Five.add(3, 3));
	ASSERT_TRUE(hashTable_Five.add(4, 4));

	//remove key
	ASSERT_FALSE(hashTable_Five.remove(5));
}
