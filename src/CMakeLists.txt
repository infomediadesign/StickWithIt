cmake_minimum_required(VERSION 3.11)

include(../cmake/raylib.cmake)

project(game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp   "scenes/scene.h" "scenes/scene.cpp" "scenes/game_scene.h" "scenes/game_scene.cpp" 
"scenes/menu_scene.h" "scenes/menu_scene.cpp" "handlers/level_drawer.h" "handlers/level_drawer.cpp" 
"objects/object.h" "objects/object.cpp" "handlers/combat_handler.h" "handlers/combat_handler.cpp" 
"handlers/level_handler.h" "handlers/level_handler.cpp" "handlers/collision_handler.h" "handlers/collision_handler.cpp" "objects/player_characters/scarecrow.h" 
"objects/player_characters/scarecrow.cpp" "objects/player_characters/player_character.h" "objects/player_characters/player_character.cpp" 
"handlers/animation_handler.h" "handlers/animation_handler.cpp"
#Silas

#Levin

)

# Add config.h.in file
configure_file(config.h.in config.h)
target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

#  Link to Raylib
target_link_libraries(${PROJECT_NAME} raylib)

# Copy assets to assets path
add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_LIST_DIR}/../cmake/copy-assets.cmake"
        )
add_dependencies(${PROJECT_NAME} copy_assets)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

# CPack instructions
# call e.g. cpack -G ZIP -C Debug to create a binary distribution
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${PROJECT_NAME}_Bundle")
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/assets" DESTINATION "${PROJECT_NAME}_Bundle")