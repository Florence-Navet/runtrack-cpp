# Crée l'exécutable à partir des fichiers sources (.cpp)
add_executable(Job01_main
    main.cpp
    Aquatique.cpp
    Pingouin.cpp
    Terrestre.cpp
)

# Indique au compilateur où chercher les headers (.hpp)
target_include_directories(Job01_main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
