include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})

set(TCC_CFLAGS -I${CMAKE_SOURCE_DIR} -I${CMAKE_SOURCE_DIR}/include -B${CMAKE_BINARY_DIR})
if(WIN32)
  set(TCC_CFLAGS ${TCC_CFLAGS} -I${CMAKE_SOURCE_DIR}/win32/include)
else()
  set(TCC_MATH_LDFLAGS -lm)
  set(LIBTCC_EXTRA_LIBS dl)
  set(LIBTCC_LDFLAGS -ldl -lm -Wl,-rpath=${CMAKE_BINARY_DIR})
endif()

set(MORETESTS
 00_assignment
 01_comment
 02_printf
 03_struct
 04_for
 05_array
 06_case
 07_function
 08_while
 09_do_while
 10_pointer
 11_precedence
 12_hashdefine
 13_integer_literals
 14_if
 15_recursion
 16_nesting
 17_enum
 18_include
 19_pointer_arithmetic
 20_pointer_comparison
 21_char_array
 22_floating_point
 23_type_coercion
 24_math_library
 25_quicksort
 26_character_constants
 27_sizeof
 28_strings
 29_array_address
 31_args
 32_led
 33_ternary_op
 35_sizeof
 36_array_initialisers
 37_sprintf
 38_multiple_array_index
 39_typedef
 40_stdio
 41_hashif
 42_function_pointer
 43_void_param
 44_scoped_declarations
 45_empty_for
 47_switch_return
 48_nested_break
 49_bracket_evaluation
 50_logical_second_arg
 51_static
 52_unnamed_enum
 54_goto
 55_lshift_type
)
if(WIN32)
  list(REMOVE_ITEM MORETESTS 24_math_library)
  list(REMOVE_ITEM MORETESTS 28_strings)
endif()
foreach(testfile ${MORETESTS})
  add_test(NAME ${testfile} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests2
           COMMAND tcc ${TCC_CFLAGS} ${TCC_MATH_LDFLAGS} -run ${testfile}.c - arg1 arg2 arg3 arg4 | ${DIFF} - ${testfile}.expect)
endforeach()
