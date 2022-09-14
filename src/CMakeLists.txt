cmake_minimum_required(VERSION 3.11)

include(../cmake/raylib.cmake)

project(game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp
#Silas
"config.h" "extras/typedefs.h" "scenes/scene.h" "scenes/scene.cpp" "scenes/game_scene.h" "scenes/game_scene.cpp" "scenes/menu_scene.h" "scenes/menu_scene.cpp" 
"handlers/animation_player.h" "handlers/animation_player.cpp" "handlers/level_handler.h" "handlers/level_handler.cpp" "handlers/pathfinder.h" "handlers/pathfinder.cpp" 
"objects/objects.h" "objects/object.h" "objects/object.cpp" "objects/npc.h" "objects/pc.h" "objects/npc.cpp" "objects/pc.cpp" "objects/npcs/mushroom.h" "objects/npcs/mushroom.cpp" 
"objects/pcs/scarecrow.h" "objects/pcs/scarecrow.cpp" "objects/npcs/bird.h" "objects/npcs/bird.cpp" "objects/pcs/fly.h" "objects/pcs/fly.cpp" 
#Levin

  "extras/textures.h" "scenes/windows/pause_window.h" "scenes/windows/pause_window.cpp" "scenes/windows/skilltree_window.h" "scenes/windows/skilltree_window.cpp" "scenes/windows/settings_window.cpp" "scenes/windows/settings_window.h" "gamestate.h" "scenes/button.cpp" "scenes/button.h" "objects/npcs/bat.h" "objects/npcs/bat.cpp")

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
