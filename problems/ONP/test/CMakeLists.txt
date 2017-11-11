find_package(Boost REQUIRED COMPONENTS unit_test_framework)
IF (Boost_FOUND)
  include_directories (${Boost_INCLUDE_DIRS})

  file(GLOB TEST_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

  #Run through each source
  foreach(testSrc ${TEST_SRCS})
    get_filename_component(testName ${testSrc} NAME_WE)
    add_executable(${testName} ${testSrc})
    target_link_libraries(${testName} ${Boost_LIBRARIES} ONP_LIB)
    set_target_properties(${testName} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/test-bin)
    add_test(NAME ${testName} 
              WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test-bin 
              COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/test-bin/${testName} )
  endforeach(testSrc)
ENDIF()