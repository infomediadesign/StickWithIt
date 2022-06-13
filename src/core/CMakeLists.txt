cmake_minimum_required(VERSION 3.11)

add_library(core STATIC game.h game.cpp store.h scene.h stage.h stage.cpp renderer.h renderer.cpp texture2d.cpp texture2d.h 
sprite.h sprite.cpp sprite_animated.cpp sprite_animated.h actor.cpp actor.h tilesetter.cpp tilesetter.h information.h 
player.cpp player.h level.cpp level.h enemy.cpp enemy.h boar.cpp boar.h mushroom.cpp mushroom.h)

target_include_directories(core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(core raylib raylib_cpp)
