cmake_minimum_required(VERSION 3.18.1)

project(somnium_tool LANGUAGES C CXX)

add_executable(
	${PROJECT_NAME}
	"source/tool.cpp"
)

install(
    TARGETS ${PROJECT_NAME}
    CONFIGURATIONS Release Debug
    RUNTIME DESTINATION bin
)