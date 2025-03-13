cmake_minimum_required(VERSION 3.30)

project(Basic_data_structures)

add_executable(Basic_data_structures
										main.c
										linked_list.c linked_list.h
										doubly_linked_list.c doubly_linked_list.h
										circular_linked_list.c circular_linked_list.h
										stack.c stack.h
)
