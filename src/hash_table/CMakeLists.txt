add_library(hash_table hash_table.c hash_table.h)
target_link_libraries(hash_table PUBLIC linked_list)