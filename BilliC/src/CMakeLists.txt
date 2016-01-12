# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 08-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
add_executable(BilliC.out main.c prl.c user.c /
	command.c db.c user_db.c auth.c /
	company.c company_db.c)

target_link_libraries(BilliC.out readline)

include_directories ("${BilliC_SOURCE_DIR}/PLib/src")
target_link_libraries (BilliC.out PLib)

find_package (PkgConfig)
pkg_check_modules (LIBPQ REQUIRED libpq)
include_directories (${LIBPQ_INCLUDE_DIRS})
link_directories (${LIBPQ_LIBRARY_DIRS})
target_link_libraries (BilliC.out ${LIBPQ_LIBRARIES})

# Add personal c flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -g -std=gnu11 ")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -DDEBUG")
