
add_library(dotenv 
    dotenv.cpp
)
add_library(dotenv::dotenv ALIAS dotenv)

target_compile_features(dotenv PUBLIC cxx_std_20)

add_executable(example example.cpp)
target_link_libraries(example dotenv)
target_compile_features(example PUBLIC cxx_std_20)
