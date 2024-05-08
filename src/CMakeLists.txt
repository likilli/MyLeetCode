
add_library(struct STATIC "")
target_sources(struct PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/structure/max_heap.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/structure/min_heap.cc
)
target_include_directories(struct PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/structure)

add_executable(leetcode main.cpp)
target_link_libraries(leetcode struct)