add_subdirectory(linked_lists)
add_subdirectory(stack)
add_subdirectory(queue)
add_subdirectory(hash_table)
add_subdirectory(binary_trees)

add_executable(Basic_data_structures main.c)

target_link_libraries(Basic_data_structures
											linked_list
											doubly_linked_list
											circular_linked_list
											stack
											queue
											hash_table
											binary_tree
											heap)
