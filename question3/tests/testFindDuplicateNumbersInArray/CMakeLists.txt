file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testFindDuplicateNumbersInArray ${SRCS})

TARGET_LINK_LIBRARIES(
        testFindDuplicateNumbersInArray
        libgtest
)

add_test(NAME testFindDuplicateNumbersInArray
        COMMAND testFindDuplicateNumbersInArray)
