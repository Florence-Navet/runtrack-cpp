# Crée l'exécutable à partir des fichiers sources (.cpp)
add_executable(main
    main.cpp
    Aquatique.cpp
    Pingouin.cpp
    Terrestre.cpp
)

# Indique au compilateur où chercher les headers (.hpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
