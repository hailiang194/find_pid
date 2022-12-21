project(example)

add_executable(example example.c)
target_link_libraries(example PUBLIC find_pid)
target_link_directories(example PUBLIC ${find_pid_BINARY_DIR}/include)