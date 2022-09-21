cmake_minimum_required(VERSION 3.11)

include(../cmake/raylib.cmake)

project(stick_with_it VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp "scenes/scene.h" "scenes/scene_menu" "scenes/scene_game.h" "scenes/scenes.h" "scenes/scene_menu.cpp" "scenes/scene_game.cpp" 
"gamestate.h" "levels/level.h" "levels/levels.h" "levels/level.cpp" "levels/level_1.h" "levels/level_2.h" "levels/level_3.h" "levels/level_4.h"
"levels/level_1.cpp" "levels/level_2.cpp" "levels/level_3.cpp" "levels/level_4.cpp" "levels/level_handler.h" "levels/level_handler.cpp" "actors/actor.h" "actors/actors.h" 
"actors/components/sprite.h" "actors/components/animation_player.h" "actors/components/all_components.h" "actors/components/sprite.cpp" "actors/components/animation_player.cpp"  
"actors/enemies/bat.h" "actors/enemies/bat.cpp" "actors/enemies/bird.h" "actors/enemies/bird.cpp" "actors/enemies/boar.h" "actors/enemies/boar.cpp" "actors/enemies/spider.h" 
"actors/enemies/spider.cpp" "actors/enemies/mushroom.h" "actors/enemies/mushroom.cpp" "actors/players/scarecrow.h" "actors/players/scarecrow.cpp" "actors/players/fly.h" 
"actors/players/fly.cpp"  "actors/spawner.h" "actors/spawner.cpp" "actors/state.cpp" "actors/players/player.h" "actors/players/player.cpp" "actors/enemies/enemy.h" 
"actors/enemies/enemy.cpp" "scenes/scene.cpp" "scenes/windows/window_settings.h" "scenes/windows/window_settings.cpp" "scenes/windows/window_pause.h" "scenes/windows/window_pause.cpp" 
"scenes/windows/window_skilltree.h" "scenes/windows/window_skilltree.cpp" "scenes/windows/window_game_over.h" "scenes/windows/window_game_over.cpp" "scenes/windows/window_game_won.h" 
"scenes/windows/window_game_won.cpp" "scenes/windows/window_next_level.h" "scenes/windows/window_next_level.cpp" "scenes/windows/window.h" "scenes/windows/window.cpp" 
"scenes/windows/windows.h" "scenes/scene_menu.h"     "scenes/button.h" "scenes/button.cpp" "scenes/windows/window_credits.h" 
"scenes/windows/window_credits.cpp" "scenes/windows/skilltrees/tree.h"   "scenes/windows/skilltrees/tree.cpp" "scenes/windows/skilltrees/trees.h" "scenes/windows/skilltrees/tree_scythe.h" 
"scenes/windows/skilltrees/tree_scythe.cpp" "scenes/windows/skilltrees/tree_pitchfork.h" "scenes/windows/skilltrees/tree_pitchfork.cpp" "scenes/windows/skilltrees/tree_shovel.h" 
"scenes/windows/skilltrees/tree_shovel.cpp" "scenes/windows/skilltrees/upgrade.h" "scenes/windows/skilltrees/upgrade.cpp" "gamestate.cpp"   "levels/map.h" "levels/map.cpp"             
"actors/actor.cpp" "scenes/windows/window_blend_out.h" "scenes/windows/window_blend_out.cpp" "actors/components/weapons/weapon.h" "actors/components/weapons/weapon.cpp" 
"actors/components/weapons/scythe.h" "actors/components/weapons/scythe.cpp" "actors/components/weapons/pitchfork.h" "actors/components/weapons/pitchfork.cpp" "actors/components/weapons/shovel.h" 
"actors/components/weapons/shovel.cpp" "actors/components/weapons/weapons.h" "actors/components/pathfinder.h" "actors/components/pathfinder.cpp")

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
