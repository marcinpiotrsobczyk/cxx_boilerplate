add_library(test_tools tools.cpp)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

target_link_libraries(test_tools Threads::Threads)

target_include_directories(test_tools PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include")
