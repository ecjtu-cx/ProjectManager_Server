add_library(LoginRegister)

target_sources(LoginRegister
    PRIVATE
        ./src/LoginModule.cpp
)

target_include_directories(LoginRegister
    PUBLIC
        include
)

target_link_libraries(LoginRegister
    PRIVATE
        -lwfrest -lworkflow -lssl -lcrypto -lcrypt
)