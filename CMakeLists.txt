cmake_minimum_required ( VERSION 2.6 )
# Укажите здесь имя вашего проекта.
# Учитываете установку переменных 
# <project_name>_BINARY_DIR и  <project_name>_SOURCE_DIR
# в значение имени каталога с проектом.
project ( game )
set ( SRC_DIR ${PROJECT_SOURCE_DIR}/src/engine/client )

# Укажите вместо my-project имя своего приложения
# - имя исполняемого файла
set ( APP_NAME game )

set( CMAKE_BUILD_TYPE RELEASE )
FILE(GLOB SOURCES "${SRC_DIR}/*.cpp")
FILE(GLOB HEADERS "${SRC_DIR}/*.h")
#FILE(GLOB TEXTURE_FILES
#	"${TEXTURE_DIR}/*.jpg"
#	"${TEXTURE_DIR}/*.png"
#)

#CONFIGURE_FILE(config.h.in "${PROJECT_BINARY_DIR}/config.h")

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(SDL REQUIRED)
#FIND_PACKAGE(SDL_image REQUIRED)
FIND_PACKAGE(SDL_ttf REQUIRED)

#FILE(COPY ${TEXTURE_FILES} DESTINATION "${TEXTURE_DIR}")

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}
	${OPENGL_INCLUDE_DIR}
	${SDL_INCLUDE_DIR}
	${SDLIMAGE_INCLUDE_DIR}
	${SDLTTF_INCLUDE_DIR}
)
ADD_EXECUTABLE(${APP_NAME} ${SOURCES} ${HEADERS})
TARGET_LINK_LIBRARIES(${APP_NAME}
	${OPENGL_LIBRARIES}
	${SDL_LIBRARY}
	${SDLIMAGE_LIBRARY}
	${SDLTTF_LIBRARY}
)