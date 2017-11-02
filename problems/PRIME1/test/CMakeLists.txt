find_package(Boost REQUIRED COMPONENTS unit_test_framework)
IF (Boost_FOUND)
    include_directories("${PROJECT_SOURCE_DIR}/include")

    file(GLOB TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/*.cc)
    set(TEST_LIBS PRIME1_LIB)

    add_executable(PRIME1_TESTS ${TEST_SOURCES}) 
    target_link_libraries(PRIME1_TESTS ${TEST_LIBS} ${Boost_LIBRARIES})
    add_test(PrimeGeneratorTest PRIME1_TESTS)
ENDIF()